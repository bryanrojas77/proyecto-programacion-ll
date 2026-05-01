#include <iostream>
#include <fstream>
#include <vector>
#include <memory>
#include <algorithm>
#include <sstream>
#include "Equipo.h"
#include "EquipoCritico.h"
#include "EquipoNormal.h"
#include "Incidencia.h"
#include "Ordenamiento.h"
#include "Busqueda.h"
#include "ReportService.h"
#include "Excepciones.h"

using namespace std;

int main() {
    try {
        cout << "=== INICIO SISTEMA ===" << endl;

        vector<unique_ptr<Equipo>> equipos;
        ifstream file("equipos.txt");

        if (!file.is_open()) {
            throw ArchivoException("No se pudo abrir equipos.txt");
        }

        string line;
        while (getline(file, line)) {
            stringstream ss(line);
            string id, tipo;
            double estado;

            getline(ss, id, ',');
            getline(ss, tipo, ',');
            ss >> estado;

            if (tipo == "critico") {
                equipos.push_back(make_unique<EquipoCritico>(id, estado));
            } else {
                equipos.push_back(make_unique<EquipoNormal>(id, estado));
            }
        }

        file.close();

        cout << "Datos cargados" << endl;

        vector<Equipo*> raw;
        for (auto& e : equipos) raw.push_back(e.get());

        Ordenamiento::quickSortId(raw, 0, raw.size() - 1);

        Equipo* encontrado = Busqueda::busquedaBinariaPorId(raw, "EQ-1");
        if (encontrado) {
            cout << "Busqueda OK: " << encontrado->getId() << endl;
        }

        cout << endl;
        cout << "=== INICIANDO SIMULACION ===" << endl;

        int backlog = 0;

        for (int dia = 1; dia <= 5; dia++) {
            cout << endl;
            cout << "Dia " << dia << endl;

            for (auto& e : raw) {
                e->degradar();
            }

            Ordenamiento::quickSortPrioridad(raw, 0, raw.size() - 1);

            int limite = min(3, (int)raw.size());

            cout << "Top prioridad : ";
            for (int i = 0; i < limite; i++) {
                cout << raw[i]->getId() << " (" << raw[i]->calcularPrioridad() << ")";
                if (i < limite - 1) cout << ", ";
            }
            cout << endl;

            cout << "Asignados : ";
            for (int i = 0; i < limite; i++) {
                cout << raw[i]->getId();
                if (i < limite - 1) cout << ", ";
            }
            cout << endl;

            backlog = max(0, (int)raw.size() - limite);

            cout << "Backlog pendiente : " << backlog << endl;

            string riesgo;
            if (backlog == 0) riesgo = "BAJO";
            else if (backlog <= 2) riesgo = "MEDIO";
            else riesgo = "ALTO";

            cout << "Riesgo global : " << riesgo << endl;
        }

        ReportService::guardarReporte("reporte.txt", raw);

        cout << endl;
        cout << "Reporte generado correctamente" << endl;
        cout << endl;
        cout << "=== FIN DEL SISTEMA ===" << endl;

    } catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}