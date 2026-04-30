//
// Created by kathy on 30/4/2026.
//

#include "Incidencia.h"

Incidencia::Incidencia(std::string tipo, int sev)
    : tipo_(std::move(tipo)), severidad_(sev), equipo_(nullptr) {}

void Incidencia::asignarEquipo(Equipo* eq) {
    equipo_ = eq;
}

int Incidencia::severidad() const {
    return severidad_;
}