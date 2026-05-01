//
// Created by kathy on 30/4/2026.
//

#ifndef PROYECTO_PROGRAMACION_LL_EQUIPOCRITICO_H
#define PROYECTO_PROGRAMACION_LL_EQUIPOCRITICO_H

#include "Equipo.h"

class EquipoCritico : public Equipo {
public:
    EquipoCritico(std::string id, double estado);

    double calcularPrioridad() const override;
};

#endif //PROYECTO_PROGRAMACION_LL_EQUIPOCRITICO_H
