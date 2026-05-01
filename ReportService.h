#ifndef PROYECTO_PROGRAMACION_LL_REPORTSERVICE_H
#define PROYECTO_PROGRAMACION_LL_REPORTSERVICE_H

#include <string>
#include <vector>
#include "Equipo.h"
#include "Excepciones.h"

class ReportService {
private:
    std::string carpetaReportes_;

public:
    explicit ReportService(const std::string& carpeta = "reportes");

//Reporte diario
    void generarReporteDiario(
        int dia,
        const std::vector<Equipo*>& atendidos,
        const std::vector<Equipo*>& pendientes,
        double riesgoGlobal
    );

//Reporte 30 dias
    void generarReporteFinal(
        const std::vector<Equipo*>& equipos,
        int totalDias
    );

private:
    std::string obtenerNivelRiesgo(double riesgo) const;
    void crearCarpetaSiNoExiste() const;
};

#endif //PROYECTO_PROGRAMACION_LL_REPORTSERVICE_H
