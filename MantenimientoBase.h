//
// Created by kathy on 30/4/2026.
//

#ifndef PROYECTO_PROGRAMACION_LL_MANTENIMIENTOBASE_H
#define PROYECTO_PROGRAMACION_LL_MANTENIMIENTOBASE_H


#include "Mantenimiento.h"

class MantenimientoBase : public Mantenimiento {
public:
    void aplicar(Equipo& eq) override;
};


#endif //PROYECTO_PROGRAMACION_LL_MANTENIMIENTOBASE_H
