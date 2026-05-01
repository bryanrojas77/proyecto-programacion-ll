#include "ReportService.h"
#include "Equipo.h"
#include "Excepciones.h"

#include <fstream>

void ReportService::guardarReporte(const std::string& nombreArchivo,
                                   const std::vector<Equipo*>& equipos) {

    std::ofstream file(nombreArchivo);

    if (!file) {
        throw ArchivoException("No se pudo abrir el archivo");
    }

    for (const auto* e : equipos) {
        file << e->id()
             << " " << e->calcularPrioridad()
             << "\n";
    }
}