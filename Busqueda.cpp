#include "Busqueda.h"
#include "Equipo.h"

Equipo* Busqueda::busquedaBinariaPorId(const std::vector<Equipo*>& arr, const std::string& id) {
    int left = 0;
    int right = arr.size() - 1;

    while (left <= right) {
        int mid = (left + right) / 2;

        if (arr[mid]->id() == id) {
            return arr[mid];
        }

        if (arr[mid]->id() < id) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return nullptr;
}