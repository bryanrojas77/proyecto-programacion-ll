//
// Created by kathy on 30/4/2026.
//

#include "MantenimientoCorrectivo.h"
#include "Equipo.h"

void MantenimientoCorrectivo::aplicar(Equipo& eq) {
    MantenimientoDecorator::aplicar(eq);

    for (int i = 0; i < 5; i++) {
        eq.degradar();
    }
}