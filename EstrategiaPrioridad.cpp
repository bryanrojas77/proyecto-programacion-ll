//
// Created by kathy on 1/5/2026.
//

#include "EstrategiaPrioridad.h"
#include "Equipo.h"

double EstrategiaPrioridad::calcular(const Equipo& e) const {
    return (e.getCriticidad() * 0.5)
         + (e.getTotalSeveridad() * 0.3)
         + (e.getTiempoInactivo() * 0.2)
         + (100 - e.getEstado());
}