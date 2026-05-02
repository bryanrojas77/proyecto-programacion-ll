//
// Created by kathy on 1/5/2026.
//

#ifndef PROYECTO_PROGRAMACION_LL_IESTRATEGIAPRIORIDAD_H
#define PROYECTO_PROGRAMACION_LL_IESTRATEGIAPRIORIDAD_H


class Equipo;

class IEstrategiaPrioridad {
public:
    virtual double calcular(const Equipo& e) const = 0;
    virtual ~IEstrategiaPrioridad() = default;
};


#endif //PROYECTO_PROGRAMACION_LL_IESTRATEGIAPRIORIDAD_H
