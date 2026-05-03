
#ifndef PROYECTO_PROGRAMACION_LL_MANTENIMIENTOPREVENTIVO_H
#define PROYECTO_PROGRAMACION_LL_MANTENIMIENTOPREVENTIVO_H

#include "MantenimientoDecorator.h"

class MantenimientoPreventivo : public MantenimientoDecorator {
public:
    MantenimientoPreventivo(unique_ptr<Mantenimiento> base);

    void aplicar(Equipo& eq) override;
};

#endif //PROYECTO_PROGRAMACION_LL_MANTENIMIENTOPREVENTIVO_H
