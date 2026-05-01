//
// Created by eXtreme PC on 1/5/2026.
//

#ifndef REPORTSERVICE_H
#define REPORTSERVICE_H

#include <vector>
#include <string>
class Equipo;

class ReportService{
public:
    void generar(int dia, const std::vector<Equipo*>& equipos) const;
};

#endif