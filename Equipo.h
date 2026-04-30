//
// Created by kathy on 30/4/2026.
//

#ifndef PROYECTO_PROGRAMACION_LL_EQUIPO_H
#define PROYECTO_PROGRAMACION_LL_EQUIPO_H

#include <vector>
#include <memory>
#include <string>

class Incidencia;

class Equipo {
protected:
    std::string id_;
    double estado_;
    int tiempoInactivo_;

    std::vector<std::unique_ptr<Incidencia>> incidencias_;

public:
    Equipo(std::string id, double estado);
    virtual ~Equipo() = default;

    virtual double calcularPrioridad() const = 0;

    void degradar();
    void agregarIncidencia(std::unique_ptr<Incidencia> inc);

    const std::string& id() const;
    int totalIncidencias() const;
};

#endif //PROYECTO_PROGRAMACION_LL_EQUIPO_H
