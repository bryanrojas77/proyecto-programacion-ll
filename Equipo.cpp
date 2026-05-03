#include "Equipo.h"

Equipo::Equipo(string id, int criticidad, double estado, IEstrategiaPrioridad* est)
    : id_(id), criticidad_(criticidad), estado_(estado),
      tiempoInactivo_(0), estrategia_(est) {}

string Equipo::getId() const {
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
    for (const auto& inc : incidencias_) {
        total += inc->getSeveridad();
    }
    return total;
}

void Equipo::agregarIncidencia(unique_ptr<Incidencia> inc) {
    incidencias_.push_back(move(inc));
}

double Equipo::calcularPrioridad() const {
    return estrategia_->calcular(*this);
}

void Equipo::degradar() {
    double perdida = 1 + (criticidad_ * 0.5);

    perdida += getTotalSeveridad() * 0.3;

    estado_ -= perdida;

    if (estado_ < 0) estado_ = 0;

    incrementarInactividad();
}