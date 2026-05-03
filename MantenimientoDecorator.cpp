#include "MantenimientoDecorator.h"

MantenimientoDecorator::MantenimientoDecorator(unique_ptr<Mantenimiento> base)
    : base(move(base)) {}

void MantenimientoDecorator::aplicar(Equipo& eq) {
    if (base) {
        base->aplicar(eq);
    }
}