//
// Created by eXtreme PC on 1/5/2026.
//

#ifndef REPORTSERVICE_H
#define REPORTSERVICE_H

#include <vector>
#include <string>
#include "Equipo.h"

class ReportService {
public:
    static void guardarReporte(
            const std::string& nombreArchivo,
            const std::vector<Equipo*>& equipos,
            int dia,
            int backlog,
            const std::string& riesgo
    );
};


#endif