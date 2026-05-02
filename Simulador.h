//
// Created by kathy on 1/5/2026.
//

#ifndef PROYECTO_PROGRAMACION_LL_SIMULADOR_H
#define PROYECTO_PROGRAMACION_LL_SIMULADOR_H

#include <vector>
#include "Equipo.h"

class Simulador {
public:
    void ejecutarSimulacion(std::vector<Equipo*>& equipos, int dias);
};


#endif //PROYECTO_PROGRAMACION_LL_SIMULADOR_H
