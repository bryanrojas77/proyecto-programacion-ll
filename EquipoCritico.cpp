//
// Created by kathy on 30/4/2026.
//

#include "EquipoCritico.h"

EquipoCritico::EquipoCritico(std::string id, double estado)
    : Equipo(std::move(id), 10, estado) {}

double EquipoCritico::calcularPrioridad() const {
    return criticidad_ * (100 - estado_) * 1.5;
}