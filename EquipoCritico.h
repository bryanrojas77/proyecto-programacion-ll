
#ifndef PROYECTO_PROGRAMACION_LL_EQUIPOCRITICO_H
#define PROYECTO_PROGRAMACION_LL_EQUIPOCRITICO_H

#include "Equipo.h"

class EquipoCritico : public Equipo {
public:
    EquipoCritico(std::string id, double estado, IEstrategiaPrioridad* est);
};

#endif //PROYECTO_PROGRAMACION_LL_EQUIPOCRITICO_H
