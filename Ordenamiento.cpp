#include "Ordenamiento.h"
#include <algorithm>

using namespace std;

int partitionId(vector<Equipo*>& arr, int low, int high) {
    string pivot = arr[high]->getId();
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j]->getId() < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void Ordenamiento::quickSortId(vector<Equipo*>& arr, int low, int high) {
    if (low < high) {
        int pi = partitionId(arr, low, high);
        quickSortId(arr, low, pi - 1);
        quickSortId(arr, pi + 1, high);
    }
}

int partitionPrioridad(vector<Equipo*>& arr, int low, int high) {
    double pivot = arr[high]->calcularPrioridad();
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j]->calcularPrioridad() > pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void Ordenamiento::quickSortPrioridad(vector<Equipo*>& arr, int low, int high) {
    if (low < high) {
        int pi = partitionPrioridad(arr, low, high);
        quickSortPrioridad(arr, low, pi - 1);
        quickSortPrioridad(arr, pi + 1, high);
    }
}