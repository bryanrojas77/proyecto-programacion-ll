#include "ReportService.h"
#include <fstream>

void ReportService::guardarReporte(
        const std::string& nombreArchivo,
        const std::vector<Equipo*>& equipos,
        int dia,
        int backlog,
        const std::string& riesgo
) {
    std::ofstream file(nombreArchivo);

    file << "Dia: " << dia << "\n";
    file << "Top 3:\n";

    for (int i = 0; i < 3 && i < equipos.size(); i++) {
        file << equipos[i]->getId() << " -> "
             << equipos[i]->calcularPrioridad() << "\n";
    }

    file << "Backlog: " << backlog << "\n";
    file << "Riesgo: " << riesgo << "\n";

    file.close();
}