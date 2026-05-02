//
// Created by kathy on 30/4/2026.
//

#include "MantenimientoBase.h"
#include "Equipo.h"

void MantenimientoBase::aplicar(Equipo& eq) {

    double nuevoEstado = eq.getEstado() + 20;
    if (nuevoEstado > 100) nuevoEstado = 100;

    eq.setEstado(nuevoEstado);

    eq.limpiarIncidencias();

    eq.resetInactividad();
}