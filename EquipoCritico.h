
#ifndef PROYECTO_PROGRAMACION_LL_EQUIPOCRITICO_H
#define PROYECTO_PROGRAMACION_LL_EQUIPOCRITICO_H

#include "Equipo.h"
using namespace std;

class EquipoCritico : public Equipo {
public:
    EquipoCritico(string id, double estado, IEstrategiaPrioridad* est);
};

#endif
