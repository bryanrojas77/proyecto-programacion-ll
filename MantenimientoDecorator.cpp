#include "MantenimientoDecorator.h"

using namespace std;

MantenimientoDecorator::MantenimientoDecorator(unique_ptr<Mantenimiento> base)
    : wrappee_(move(base)) {}

void MantenimientoDecorator::aplicar(Equipo& eq) {
    if (wrappee_)
        wrappee_->aplicar(eq);
}