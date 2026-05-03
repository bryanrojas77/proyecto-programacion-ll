#include "Ordenamiento.h"
#include "Equipo.h"
#include <algorithm>

void Ordenamiento::ordenar(vector<Equipo*>& equipos) {
    sort(equipos.begin(), equipos.end(),
         [](Equipo* a, Equipo* b) {
             return a->calcularPrioridad() > b->calcularPrioridad();
         });
}