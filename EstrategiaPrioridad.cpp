#include "EstrategiaPrioridad.h"
#include "Equipo.h"

double EstrategiaPrioridad::calcular(const Equipo& eq) const {
    return eq.getEstado()
           + eq.getCriticidad() * 5
           - eq.getTiempoInactivo() * 3
           - eq.getTotalSeveridad() * 2;
}