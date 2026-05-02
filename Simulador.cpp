#include "Simulador.h"

void Simulador::ejecutarSimulacion(std::vector<Equipo*>& equipos, int dias) {
    for (int d = 0; d < dias; d++) {
        for (auto& e : equipos) {
            e->incrementarInactividad();

            double nuevoEstado = e->getEstado() - 0.5;
            if (nuevoEstado < 0) nuevoEstado = 0;

            e->setEstado(nuevoEstado);
        }
    }
}