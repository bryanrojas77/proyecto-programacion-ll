
#ifndef PROYECTO_PROGRAMACION_LL_MANTENIMIENTOCORRECTIVO_H
#define PROYECTO_PROGRAMACION_LL_MANTENIMIENTOCORRECTIVO_H

#include "MantenimientoDecorator.h"

class MantenimientoCorrectivo : public MantenimientoDecorator {
public:
    MantenimientoCorrectivo(unique_ptr<Mantenimiento> base);

    void aplicar(Equipo& eq) override;
};

#endif //PROYECTO_PROGRAMACION_LL_MANTENIMIENTOCORRECTIVO_H
