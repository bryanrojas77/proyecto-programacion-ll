#include "MantenimientoPreventivo.h"
#include "Equipo.h"

MantenimientoPreventivo::MantenimientoPreventivo(std::unique_ptr<Mantenimiento> base)
    : MantenimientoDecorator(std::move(base)) {}

void MantenimientoPreventivo::aplicar(Equipo& eq) {
    MantenimientoDecorator::aplicar(eq);

    eq.setEstado(eq.getEstado() + 5);
}