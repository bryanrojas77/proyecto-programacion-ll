#include "MantenimientoCorrectivo.h"
#include "Equipo.h"

MantenimientoCorrectivo::MantenimientoCorrectivo(std::unique_ptr<Mantenimiento> base)
    : MantenimientoDecorator(std::move(base)) {}

void MantenimientoCorrectivo::aplicar(Equipo& eq) {
    MantenimientoDecorator::aplicar(eq);

    eq.setEstado(eq.getEstado() + 20);
    eq.limpiarIncidencias();
    eq.resetInactividad();
}