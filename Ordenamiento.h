#ifndef ORDENAMIENTO_H
#define ORDENAMIENTO_H

#include <vector>

class Equipo;

class Ordenamiento {
public:
    static void quickSortId(std::vector<Equipo*>& arr, int low, int high);

private:
    static int partitionId(std::vector<Equipo*>& arr, int low, int high);
};
#endif