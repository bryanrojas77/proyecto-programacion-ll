#include "MantenimientoBase.h"
#include "Equipo.h"

void MantenimientoBase::aplicar(Equipo& eq) {
    eq.degradar();
}