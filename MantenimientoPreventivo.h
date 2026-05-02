
#ifndef PROYECTO_PROGRAMACION_LL_MANTENIMIENTOPREVENTIVO_H
#define PROYECTO_PROGRAMACION_LL_MANTENIMIENTOPREVENTIVO_H

#include "MantenimientoDecorator.h"

class MantenimientoPreventivo : public MantenimientoDecorator {
public:
    using MantenimientoDecorator::MantenimientoDecorator;

    void aplicar(Equipo& eq) override;
};

#endif //PROYECTO_PROGRAMACION_LL_MANTENIMIENTOPREVENTIVO_H
