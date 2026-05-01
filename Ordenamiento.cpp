#include "Ordenamiento.h"
#include "Equipo.h"
#include <algorithm>

int Ordenamiento::partitionPrioridad(std::vector<Equipo*>& arr, int low, int high) {
    double pivot = arr[high]->calcularPrioridad();
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j]->calcularPrioridad() > pivot) {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }

    std::swap(arr[i + 1], arr[high]);
    return i + 1;
}

void Ordenamiento::quickSortPorPrioridad(std::vector<Equipo*>& arr, int low, int high) {
    if (low < high) {
        int pi = partitionPrioridad(arr, low, high);
        quickSortPorPrioridad(arr, low, pi - 1);
        quickSortPorPrioridad(arr, pi + 1, high);
    }
}

int Ordenamiento::partitionId(std::vector<Equipo*>& arr, int low, int high) {
    std::string pivot = arr[high]->id();
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j]->id() < pivot) {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }

    std::swap(arr[i + 1], arr[high]);
    return i + 1;
}

void Ordenamiento::quickSortPorId(std::vector<Equipo*>& arr, int low, int high) {
    if (low < high) {
        int pi = partitionId(arr, low, high);
        quickSortPorId(arr, low, pi - 1);
        quickSortPorId(arr, pi + 1, high);
    }
}