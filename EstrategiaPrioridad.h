//
// Created by kathy on 1/5/2026.
//

#ifndef PROYECTO_PROGRAMACION_LL_ESTRATEGIAPRIORIDAD_H
#define PROYECTO_PROGRAMACION_LL_ESTRATEGIAPRIORIDAD_H

#include "IEstrategiaPrioridad.h"

class EstrategiaPrioridad : public IEstrategiaPrioridad {
public:
    double calcular(const Equipo& e) const override;
};


#endif //PROYECTO_PROGRAMACION_LL_ESTRATEGIAPRIORIDAD_H
