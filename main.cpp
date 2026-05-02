#include <iostream>
#include <vector>
#include <memory>
#include <fstream>
#include <sstream>
#include <filesystem>

#include "Equipo.h"
#include "EquipoCritico.h"
#include "EquipoNormal.h"
#include "EstrategiaPrioridad.h"
#include "Simulador.h"
#include "Ordenamiento.h"
#include "ReportService.h"

using namespace std;

int main() {
    cout << "=== INICIO SISTEMA ===" << endl;

    ifstream file("equipos.txt");
    if (!file.is_open()) {
        cout << "Error abriendo equipos.txt" << endl;
        return 1;
    }

    vector<unique_ptr<Equipo>> equipos;
    vector<Equipo*> raw;

    string line;

    while (getline(file, line)) {
        if (line.empty()) continue;

        stringstream ss(line);
        string id, criticidadStr, estadoStr;

        if (!getline(ss, id, ',')) continue;
        if (!getline(ss, criticidadStr, ',')) continue;
        if (!getline(ss, estadoStr, ',')) continue;

        try {
            int criticidad = stoi(criticidadStr);
            double estado = stod(estadoStr);

            IEstrategiaPrioridad* estrategia = new EstrategiaPrioridad();

            if (criticidad == 1) {
                equipos.push_back(make_unique<EquipoCritico>(id, estado, estrategia));
            } else {
                equipos.push_back(make_unique<EquipoNormal>(id, estado, estrategia));
            }

        } catch (...) {
            continue;
        }
    }

    for (auto& e : equipos) {
        raw.push_back(e.get());
    }

    cout << "Datos cargados: " << raw.size() << " equipos" << endl;

    filesystem::create_directory("reportes");

    cout << "\n=== SIMULACION ===" << endl;

    Simulador simulador;

    for (int dia = 1; dia <= 30; dia++) {
        cout << "\n--- Dia " << dia << " ---" << endl;

        simulador.ejecutarSimulacion(raw, 1);

        Ordenamiento::ordenar(raw);

        cout << "Top 3:" << endl;
        for (int i = 0; i < 3 && i < raw.size(); i++) {
            cout << raw[i]->getId() << " -> "
                 << raw[i]->calcularPrioridad() << endl;
        }

        int backlog = raw.size() - 3;

        string riesgo;
        if (backlog > 100) riesgo = "ALTO";
        else if (backlog > 50) riesgo = "MEDIO";
        else riesgo = "BAJO";

        cout << "Backlog: " << backlog << endl;
        cout << "Riesgo: " << riesgo << endl;

        string nombreArchivo = "reportes/dia_" + to_string(dia) + ".txt";

        ReportService::guardarReporte(
                nombreArchivo,
                raw,
                dia,
                backlog,
                riesgo
        );
    }

    ReportService::guardarReporte(
            "reportes/reporte_final.txt",
            raw,
            30,
            raw.size() - 3,
            "FINAL"
    );

    cout << "Reporte final generado correctamente" << endl;
    cout << "=== FIN DEL SISTEMA ===" << endl;

    return 0;
}