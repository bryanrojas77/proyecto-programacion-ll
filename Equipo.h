#ifndef PROYECTO_PROGRAMACION_LL_EQUIPO_H
#define PROYECTO_PROGRAMACION_LL_EQUIPO_H
#include "Incidencia.h"
#include "IEstrategiaPrioridad.h"
#include <string>
#include <vector>
#include <memory>
using namespace std;

class Equipo {
protected:
    string id_;
    int criticidad_;
    double estado_;
    int tiempoInactivo_;
    vector<unique_ptr<Incidencia>> incidencias_;
    IEstrategiaPrioridad* estrategia_;

public:
    Equipo(string id, int criticidad, double estado, IEstrategiaPrioridad* est);
    virtual ~Equipo() = default;

    string getId() const;

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

#endif
