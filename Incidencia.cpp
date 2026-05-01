//
// Created by kathy on 30/4/2026.
//

#include "Incidencia.h"

Incidencia::Incidencia(std::string tipo, int severidad)
    : tipo_(std::move(tipo)), severidad_(severidad) {}

int Incidencia::severidad() const {
    return severidad_;
}