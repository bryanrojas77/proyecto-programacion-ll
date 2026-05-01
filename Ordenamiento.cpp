#include "Ordenamiento.h"
#include "Equipo.h"
#include <utility>

int Ordenamiento::partitionId(std::vector<Equipo*>& arr, int low, int high) {

    std::string pivot = arr[high]->getId();
    int i = low - 1;

    for (int j = low; j < high; ++j) {
        if (arr[j]->getId() < pivot) {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }

    std::swap(arr[i + 1], arr[high]);
    return i + 1;
}

void Ordenamiento::quickSortId(std::vector<Equipo*>& arr, int low, int high) {
    if (low < high) {
        int pi = partitionId(arr, low, high);

        quickSortId(arr, low, pi - 1);
        quickSortId(arr, pi + 1, high);
    }
}