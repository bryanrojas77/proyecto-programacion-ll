#include "Simulador.h"
#include "MantenimientoBase.h"
#include "MantenimientoCorrectivo.h"
#include "MantenimientoPreventivo.h"
#include "Incidencia.h"
#include <cstdlib>
#include <memory>

using namespace std;

void Simulador::ejecutarSimulacion(vector<Equipo*>& equipos, int dias) {
    for (int d = 0; d < dias; d++) {
        for (auto& e : equipos) {
            e->incrementarInactividad();

            double nuevoEstado = e->getEstado() - (rand() % 3);
            if (nuevoEstado < 0) nuevoEstado = 0;
            e->setEstado(nuevoEstado);

            if (rand() % 3 == 0) {
                int sev = rand() % 10 + 1;
                e->agregarIncidencia(make_unique<Incidencia>("falla", sev));
            }

            if (e->calcularPrioridad() > 80) {
                unique_ptr<Mantenimiento> mantenimiento;

                if (rand() % 2 == 0) {
                    mantenimiento = make_unique<MantenimientoCorrectivo>(
                        make_unique<MantenimientoBase>()
                    );
                } else {
                    mantenimiento = make_unique<MantenimientoPreventivo>(
                        make_unique<MantenimientoBase>()
                    );
                }

                mantenimiento->aplicar(*e);
            }
        }
    }
}