#include "Ordenamiento.h"
#include <algorithm>

using namespace std;

void Ordenamiento::ordenar(vector<Equipo*>& equipos) {
    sort(equipos.begin(), equipos.end(), [](Equipo* a, Equipo* b) {
        return a->calcularPrioridad() > b->calcularPrioridad();
    });
}