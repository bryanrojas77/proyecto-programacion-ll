//
// Created by eXtreme PC on 1/5/2026.
//

#ifndef SIMULADOR_H
#define SIMULADOR_H

#include <vector>
#include <memory>
#include "ReportService.h"

class Equipo;
class IEstrategia;

class Simulador {
private:
    std::vector<std::unique_ptr<Equipo>> equipos_;
    std::unique_ptr<IEstrategia> estrategia_;
    ReportService report_;

    void quickSort(int low, int high);
    int partition(int low, int high);

public:
    Simulador();

    void ejecutar();
};

#endif