#ifndef PROYECTO_PROGRAMACION_LL_EQUIPO_H
#define PROYECTO_PROGRAMACION_LL_EQUIPO_H
#include "Incidencia.h"
#include "IEstrategiaPrioridad.h"
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
    IEstrategiaPrioridad* estrategia_;

public:
    Equipo(std::string id, int criticidad, double estado, IEstrategiaPrioridad* est);
    virtual ~Equipo() = default;

    std::string getId() const;

    double getEstado() const;
    void setEstado(double e);

    int getCriticidad() const;

    int getTiempoInactivo() const;
    void incrementarInactividad();
    void resetInactividad();

    void limpiarIncidencias();
    int getTotalSeveridad() const;

    void agregarIncidencia(std::unique_ptr<Incidencia> inc);

    virtual double calcularPrioridad() const;

    void degradar();
};

#endif //PROYECTO_PROGRAMACION_LL_EQUIPO_H
