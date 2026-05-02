#include "MantenimientoBase.h"
#include "Equipo.h"

using namespace std;

void MantenimientoBase::aplicar(Equipo& eq) {
    double nuevoEstado = eq.getEstado() + 20;
    if (nuevoEstado > 100) nuevoEstado = 100;

    eq.setEstado(nuevoEstado);
    eq.limpiarIncidencias();
    eq.resetInactividad();
}