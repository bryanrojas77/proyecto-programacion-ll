//
// Created by kathy on 30/4/2026.
//

#ifndef PROYECTO_PROGRAMACION_LL_EQUIPONORMAL_H
#define PROYECTO_PROGRAMACION_LL_EQUIPONORMAL_H

#include "Equipo.h"

class EquipoNormal : public Equipo {
public:
    EquipoNormal(std::string id, double estado);
    double calcularPrioridad() const override;
};


#endif //PROYECTO_PROGRAMACION_LL_EQUIPONORMAL_H
