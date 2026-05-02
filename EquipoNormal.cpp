//
// Created by kathy on 30/4/2026.
//

#include "EquipoNormal.h"

EquipoNormal::EquipoNormal(std::string id, double estado, IEstrategiaPrioridad* est)
    : Equipo(std::move(id), 5, estado, est) {}