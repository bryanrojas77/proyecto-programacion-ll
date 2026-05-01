//
// Created by kathy on 30/4/2026.
//

#include "EquipoNormal.h"

EquipoNormal::EquipoNormal(std::string id, double estado)
    : Equipo(std::move(id), 5, estado) {}

double EquipoNormal::calcularPrioridad() const {
    return criticidad_ * (100 - estado_);
}