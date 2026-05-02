#include "Ordenamiento.h"
#include <algorithm>

void Ordenamiento::ordenar(std::vector<Equipo*>& equipos) {
    std::sort(equipos.begin(), equipos.end(), [](Equipo* a, Equipo* b) {
        return a->calcularPrioridad() > b->calcularPrioridad();
    });
}