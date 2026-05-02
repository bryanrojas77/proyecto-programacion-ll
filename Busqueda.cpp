#include "Busqueda.h"
#include "Equipo.h"

using namespace std;

Equipo* Busqueda::busquedaBinariaPorId(const vector<Equipo*>& arr, const string& id) {
    int left = 0;
    int right = (int)arr.size() - 1;

    while (left <= right) {
        int mid = (left + right) / 2;

        if (arr[mid]->getId() == id) {
            return arr[mid];
        }

        if (arr[mid]->getId() < id) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return nullptr;
}