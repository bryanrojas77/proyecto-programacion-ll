//
// Created by kathy on 30/4/2026.
//

#include "Equipo.h"
#include "Incidencia.h"

Equipo::Equipo(std::string id, double estado)
    : id_(std::move(id)), estado_(estado), tiempoInactivo_(0) {}

void Equipo::degradar() {
    estado_ -= 1;
    tiempoInactivo_++;
}

void Equipo::agregarIncidencia(std::unique_ptr<Incidencia> inc) {
    incidencias_.push_back(std::move(inc));
}

const std::string& Equipo::id() const {
    return id_;
}

int Equipo::totalIncidencias() const {
    return incidencias_.size();
}