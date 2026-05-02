#include "Equipo.h"

Equipo::Equipo(std::string id, int criticidad, double estado, IEstrategiaPrioridad* est)
    : id_(std::move(id)),
      criticidad_(criticidad),
      estado_(estado),
      tiempoInactivo_(0),
      estrategia_(est) {}

std::string Equipo::getId() const {
    return id_;
}

double Equipo::getEstado() const {
    return estado_;
}

void Equipo::setEstado(double e) {
    estado_ = e;
    if (estado_ > 100) estado_ = 100;
    if (estado_ < 0) estado_ = 0;
}

int Equipo::getCriticidad() const {
    return criticidad_;
}

int Equipo::getTiempoInactivo() const {
    return tiempoInactivo_;
}

void Equipo::incrementarInactividad() {
    tiempoInactivo_++;
}

void Equipo::resetInactividad() {
    tiempoInactivo_ = 0;
}

void Equipo::limpiarIncidencias() {
    incidencias_.clear();
}

int Equipo::getTotalSeveridad() const {
    int total = 0;
    for (const auto& i : incidencias_) {
        total += i->severidad();
    }
    return total;
}

void Equipo::agregarIncidencia(std::unique_ptr<Incidencia> inc) {
    incidencias_.push_back(std::move(inc));
}

double Equipo::calcularPrioridad() const {
    return estrategia_->calcular(*this);
}

void Equipo::degradar() {
    estado_ -= 1.0;
    if (estado_ < 0) estado_ = 0;
}