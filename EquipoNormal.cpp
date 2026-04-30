//
// Created by kathy on 30/4/2026.
//

#include "EquipoNormal.h"

EquipoNormal::EquipoNormal(std::string id, double estado)
    : Equipo(std::move(id), estado) {}

double EquipoNormal::calcularPrioridad() const {
    return 5 + totalIncidencias() * 0.3 + tiempoInactivo_ * 0.2;
}