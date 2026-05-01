#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>


#include "Equipo.h"
#include "EquipoCritico.h"
#include "EquipoNormal.h"
#include "Ordenamiento.h"
#include "Busqueda.h"
#include "Simulador.h"
#include "ReportService.h"
#include "Excepciones.h"

using namespace std;

int main() {
    try {
        cout << "=== INICIO SISTEMA ===" << endl;

        vector<Equipo*> equipos;

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
                equipos.push_back(new EquipoCritico(id, estado)); // criticidad ya la define la clase
            } else {
                equipos.push_back(new EquipoNormal(id, estado));
            }
        }

        file.close();

        cout << "Datos cargados" << endl;

        Ordenamiento::quickSortId(equipos, 0, equipos.size() - 1);

        Equipo* encontrado = Busqueda::busquedaBinariaPorId(equipos, "EQ-1");

        if (encontrado) {
            cout << "Busqueda OK: " << encontrado->getId() << endl;
        }

        cout << "\n=== INICIANDO SIMULACION ===" << endl;

        Simulador::ejecutarSimulacion(equipos, 5);

        ReportService::guardarReporte("reporte.txt", equipos);

        cout << "\nReporte generado correctamente" << endl;

        for (auto e : equipos) {
            delete e;
        }

        cout << "\n=== FIN DEL SISTEMA ===" << endl;

    } catch (const ArchivoException& e) {
        cout << "Error de archivo: " << e.what() << endl;
    } catch (const SimulacionException& e) {
        cout << "Error de simulacion: " << e.what() << endl;
    } catch (const exception& e) {
        cout << "Error inesperado: " << e.what() << endl;
    }

    return 0;
}