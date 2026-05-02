//
// Created by kathy on 30/4/2026.
//
#include "EquipoCritico.h"

EquipoCritico::EquipoCritico(std::string id, double estado, IEstrategiaPrioridad* est)
    : Equipo(std::move(id), 10, estado, est) {}