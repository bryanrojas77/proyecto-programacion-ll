//
// Created by kathy on 30/4/2026.
//

#ifndef PROYECTO_PROGRAMACION_LL_EQUIPONORMAL_H
#define PROYECTO_PROGRAMACION_LL_EQUIPONORMAL_H

#include "Equipo.h"
using namespace std;

class EquipoNormal : public Equipo {
public:
    EquipoNormal(string id, double estado, IEstrategiaPrioridad* est);
};
#endif
