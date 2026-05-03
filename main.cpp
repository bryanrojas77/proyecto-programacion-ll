#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <memory>
#include <filesystem>
#include <algorithm>

#include "Equipo.h"
#include "EquipoCritico.h"
#include "EquipoNormal.h"
#include "EstrategiaPrioridad.h"
#include "Simulador.h"
#include "Ordenamiento.h"
#include "ReportService.h"
#include "Busqueda.h"
#include "Excepciones.h"

using namespace std;

int main() {
    try {
        cout << "=== INICIO SISTEMA ===" << endl;

        vector<unique_ptr<Equipo>> equipos;
        vector<Equipo*> raw;

        ifstream file("equipos.txt");

        if (!file.is_open()) {
            throw ArchivoException("No se pudo abrir equipos.txt");
        }

        string line;
        EstrategiaPrioridad estrategia;

        while (getline(file, line)) {
            if (line.empty()) continue;

            stringstream ss(line);
            string id, tipo, estadoStr;

            getline(ss, id, ',');
            getline(ss, tipo, ',');
            getline(ss, estadoStr, ',');

            double estado;

            try {
                estado = stod(estadoStr);
            } catch (...) {
                throw ArchivoException("Error convirtiendo estado en linea: " + line);
            }

            if (tipo == "critico") {
                equipos.push_back(make_unique<EquipoCritico>(id, estado, &estrategia));
            } else if (tipo == "normal") {
                equipos.push_back(make_unique<EquipoNormal>(id, estado, &estrategia));
            } else {
                throw ArchivoException("Tipo desconocido: " + tipo);
            }
        }

        for (auto& e : equipos) {
            raw.push_back(e.get());
        }

        cout << "Datos cargados: " << raw.size() << " equipos" << endl;

        // 🔍 ORDENAR POR ID PARA BUSQUEDA BINARIA
        sort(raw.begin(), raw.end(), [](Equipo* a, Equipo* b) {
            return a->getId() < b->getId();
        });

        Equipo* encontrado = Busqueda::busquedaBinariaPorId(raw, "EQ-10");

        if (encontrado != nullptr) {
            cout << "Busqueda OK: " << encontrado->getId() << endl;
        } else {
            cout << "Equipo no encontrado" << endl;
        }

        filesystem::create_directory("reportes");

        Simulador simulador;

        cout << "\n=== SIMULACION ===\n" << endl;

        for (int dia = 1; dia <= 30; dia++) {
            simulador.ejecutarSimulacion(raw, 1);

            Ordenamiento::ordenar(raw);

            cout << "--- Dia " << dia << " ---" << endl;
            cout << "Top 3:" << endl;

            for (int i = 0; i < 3 && i < raw.size(); i++) {
                cout << raw[i]->getId() << " -> "
                     << raw[i]->calcularPrioridad() << endl;
            }

            int backlog = raw.size() - 3;

            string riesgo;
            if (backlog > 50) riesgo = "ALTO";
            else if (backlog > 20) riesgo = "MEDIO";
            else riesgo = "BAJO";

            cout << "Backlog: " << backlog << endl;
            cout << "Riesgo: " << riesgo << endl;

            string ruta = "reportes/reporte_dia_" + to_string(dia) + ".txt";

            ReportService::guardarReporte(ruta, raw, dia, backlog, riesgo);

            cout << endl;
        }

        ReportService::guardarReporte("reportes/reporte_final.txt", raw, 30, raw.size(), "FINAL");

        cout << "Reporte final generado correctamente" << endl;
        cout << "=== FIN DEL SISTEMA ===" << endl;

    } catch (const ArchivoException& e) {
        cout << "Error de archivo: " << e.what() << endl;
    } catch (const exception& e) {
        cout << "Error general: " << e.what() << endl;
    }

    return 0;
}