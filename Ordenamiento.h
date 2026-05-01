#ifndef ORDENAMIENTO_H
#define ORDENAMIENTO_H

#include <vector>

class Equipo;

class Ordenamiento {
public:
    static void quickSortPorPrioridad(std::vector<Equipo*>& arr, int low, int high);
    static void quickSortPorId(std::vector<Equipo*>& arr, int low, int high);

private:
    static int partitionPrioridad(std::vector<Equipo*>& arr, int low, int high);
    static int partitionId(std::vector<Equipo*>& arr, int low, int high);
};

#endif