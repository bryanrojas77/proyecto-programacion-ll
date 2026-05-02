#include "MantenimientoPreventivo.h"
#include "Equipo.h"

using namespace std;

void MantenimientoPreventivo::aplicar(Equipo& eq) {
    MantenimientoDecorator::aplicar(eq);
    eq.degradar();
}