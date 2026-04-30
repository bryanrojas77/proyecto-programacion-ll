//
// Created by kathy on 30/4/2026.
//

#include "MantenimientoDecorator.h"

MantenimientoDecorator::MantenimientoDecorator(std::unique_ptr<Mantenimiento> base)
    : wrappee_(std::move(base)) {}

void MantenimientoDecorator::aplicar(Equipo& eq) {
    if (wrappee_)
        wrappee_->aplicar(eq);
}