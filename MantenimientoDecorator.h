
#ifndef PROYECTO_PROGRAMACION_LL_MANTENIMIENTODECORATOR_H
#define PROYECTO_PROGRAMACION_LL_MANTENIMIENTODECORATOR_H

#include "Mantenimiento.h"
#include <memory>

using namespace std;

class MantenimientoDecorator : public Mantenimiento {
protected:
    unique_ptr<Mantenimiento> base;

public:
    MantenimientoDecorator(unique_ptr<Mantenimiento> base);

    void aplicar(Equipo& eq) override;
};

#endif //PROYECTO_PROGRAMACION_LL_MANTENIMIENTODECORATOR_H
