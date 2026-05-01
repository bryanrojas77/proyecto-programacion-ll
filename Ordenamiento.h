#ifndef ORDENAMIENTO_H
#define ORDENAMIENTO_H

#include <vector>
#include "Equipo.h"

class Ordenamiento {
public:
    static void quickSortId(std::vector<Equipo*>& arr, int low, int high);
    static void quickSortPrioridad(std::vector<Equipo*>& arr, int low, int high);
};
#endif