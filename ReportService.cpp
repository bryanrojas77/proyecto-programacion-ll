#include "ReportService.h"
#include <fstream>
#include <iostream>

ReportService::ReportService(const std::string& carpeta)
    : carpetaReportes_(carpeta) {
}

void ReportService::generarReporteDiario(
    int dia,
    const std::vector<Equipo*>& atendidos,
    const std::vector<Equipo*>& pendientes,
    double riesgoGlobal) {

    std::string nombreArchivo = carpetaReportes_ + "/dia_" + std::to_string(dia) + ".txt";
    std::ofstream archivo(nombreArchivo);

    if (!archivo.is_open()) {
        throw FileException("No se pudo crear el reporte del dia " + std::to_string(dia));
    }

    archivo << "==============================\n";
    archivo << "REPORTE DIA " << dia << "\n";
    archivo << "==============================\n\n";

    archivo << "Equipos atendidos (" << atendidos.size() << "):\n";
    for (const auto& eq : atendidos) {
        archivo << "  - " << eq->id()
                << " | Prioridad: " << eq->calcularPrioridad()
                << " | Incidencias: " << eq->totalIncidencias() << "\n";
    }

    archivo << "\nEquipos pendientes (" << pendientes.size() << "):\n";
    for (const auto& eq : pendientes) {
        archivo << "  - " << eq->id()
                << " | Prioridad: " << eq->calcularPrioridad()
                << " | Incidencias: " << eq->totalIncidencias() << "\n";
    }

    archivo << "\nRiesgo global: " << obtenerNivelRiesgo(riesgoGlobal)
            << " (" << riesgoGlobal << ")\n";

    archivo.close();
}

void ReportService::generarReporteFinal(
    const std::vector<Equipo*>& equipos,
    int totalDias) {

    std::string nombreArchivo = carpetaReportes_ + "/reporte_final.txt";
    std::ofstream archivo(nombreArchivo);

    if (!archivo.is_open()) {
        throw FileException("No se pudo crear el reporte final");
    }

    archivo << "==============================\n";
    archivo << "REPORTE FINAL - " << totalDias << " DIAS\n";
    archivo << "==============================\n\n";

    archivo << "Total de equipos: " << equipos.size() << "\n\n";

    int criticos = 0;
    int normales = 0;
    for (const auto& eq : equipos) {
        if (eq->calcularPrioridad() >= 7.0) criticos++;
        else normales++;
    }

    archivo << "Equipos con prioridad alta: " << criticos << "\n";
    archivo << "Equipos con prioridad normal: " << normales << "\n";

    archivo << "\nEstado final de equipos:\n";
    for (const auto& eq : equipos) {
        archivo << "  - " << eq->id()
                << " | Prioridad final: " << eq->calcularPrioridad()
                << " | Incidencias: " << eq->totalIncidencias() << "\n";
    }

    archivo.close();
}

std::string ReportService::obtenerNivelRiesgo(double riesgo) const {
    if (riesgo >= 7.0) return "ALTO";
    if (riesgo >= 4.0) return "MEDIO";
    return "BAJO";
}

void ReportService::crearCarpetaSiNoExiste() const {
}
