#include "ReportService.h"
#include "Equipo.h"

#include <fstream>
#include <stdexcept>

void ReportService::generar(
    int dia,
    const std::vector<Equipo*>& equipos
) const {

    std::ofstream file("reporte.txt", std::ios::app);

    if (!file)
        throw std::runtime_error("No se pudo abrir reporte.txt");

    file << "Dia " << dia << "\n";

    for (const auto* eq : equipos) {
        file << eq->id()
             << " prioridad: "
             << eq->calcularPrioridad()
             << "\n";
    }

    file << "----------------------\n";
}