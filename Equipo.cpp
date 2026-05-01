//
// Created by kathy on 30/4/2026.
//

#include "Equipo.h"
#include "Incidencia.h"

Equipo::Equipo(std::string id, int criticidad, double estado)
    : id_(std::move(id)), criticidad_(criticidad), estado_(estado), tiempoInactivo_(0) {}

std::string Equipo::id() const {
    return id_;
}

void Equipo::agregarIncidencia(std::unique_ptr<Incidencia> inc) {
    incidencias_.push_back(std::move(inc));
}

void Equipo::degradar() {
    estado_ -= 1.0;
    if (estado_ < 0) estado_ = 0;
}