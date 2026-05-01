#include "ReportService.h"
#include "Equipo.h"
#include "Excepciones.h"
#include <fstream>

using namespace std;

void ReportService::guardarReporte(const string& nombre, const vector<Equipo*>& equipos) {
    ofstream file(nombre);

    if (!file.is_open()) {
        throw ArchivoException("No se pudo crear el archivo de reporte");
    }

    for (const auto& e : equipos) {
        file << e->getId() << " - Prioridad: " << e->calcularPrioridad() << endl;
    }

    file.close();
}