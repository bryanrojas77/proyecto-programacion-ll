//
// Created by eXtreme PC on 1/5/2026.
//

#ifndef REPORTSERVICE_H
#define REPORTSERVICE_H

#include <vector>
#include <string>

class Equipo;

class ReportService {
public:
    static void guardarReporte(const std::string& nombreArchivo,
                               const std::vector<Equipo*>& equipos);
};

#endif