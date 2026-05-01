//
// Created by kathy on 30/4/2026.
//

#include "MantenimientoPreventivo.h"
#include "Equipo.h"

void MantenimientoPreventivo::aplicar(Equipo& eq) {
    MantenimientoDecorator::aplicar(eq);
    eq.degradar();
}