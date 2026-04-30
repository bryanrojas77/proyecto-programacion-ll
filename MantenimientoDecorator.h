//
// Created by kathy on 30/4/2026.
//

#ifndef PROYECTO_PROGRAMACION_LL_MANTENIMIENTODECORATOR_H
#define PROYECTO_PROGRAMACION_LL_MANTENIMIENTODECORATOR_H

#include "Mantenimiento.h"
#include <memory>

class MantenimientoDecorator : public Mantenimiento {
protected:
    std::unique_ptr<Mantenimiento> wrappee_;

public:
    explicit MantenimientoDecorator(std::unique_ptr<Mantenimiento> base);

    void aplicar(Equipo& eq) override;
};

#endif //PROYECTO_PROGRAMACION_LL_MANTENIMIENTODECORATOR_H
