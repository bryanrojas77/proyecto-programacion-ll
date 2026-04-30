//
// Created by kathy on 30/4/2026.
//

#include "EquipoCritico.h"

EquipoCritico::EquipoCritico(std::string id, double estado)
   : Equipo(std::move(id), estado) {}

double EquipoCritico::calcularPrioridad() const {
    return 10 + totalIncidencias() * 0.5 + tiempoInactivo_ * 0.3;
}