//
// Created by kathy on 30/4/2026.
//

#ifndef PROYECTO_PROGRAMACION_LL_EQUIPO_H
#define PROYECTO_PROGRAMACION_LL_EQUIPO_H

#include "Incidencia.h"
#include <string>
#include <vector>
#include <memory>


class Equipo {
protected:
    std::string id_;
    int criticidad_;
    double estado_;
    int tiempoInactivo_;
    std::vector<std::unique_ptr<Incidencia>> incidencias_;

public:
    Equipo(std::string id, int criticidad, double estado);
    virtual ~Equipo() = default;

    std::string id() const;

    void agregarIncidencia(std::unique_ptr<Incidencia> inc);

    virtual double calcularPrioridad() const = 0;

    void degradar();
};

#endif //PROYECTO_PROGRAMACION_LL_EQUIPO_H
