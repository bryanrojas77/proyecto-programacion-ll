//
// Created by kathy on 30/4/2026.
//

#ifndef PROYECTO_PROGRAMACION_LL_MANTENIMIENTOCORRECTIVO_H
#define PROYECTO_PROGRAMACION_LL_MANTENIMIENTOCORRECTIVO_H

#include "MantenimientoDecorator.h"
#include "Equipo.h"

class MantenimientoCorrectivo : public MantenimientoDecorator {
public:
    using MantenimientoDecorator::MantenimientoDecorator;

    void aplicar(Equipo& eq) override;
};

#endif //PROYECTO_PROGRAMACION_LL_MANTENIMIENTOCORRECTIVO_H
