#include "Simulador.h"
#include "MantenimientoBase.h"
#include "MantenimientoPreventivo.h"
#include "MantenimientoCorrectivo.h"
#include "Ordenamiento.h"
#include "Incidencia.h"
#include <iostream>
#include <memory>

using namespace std;

void Simulador::ejecutarSimulacion(vector<Equipo*>& equipos, int dias) {

    for (int d = 1; d <= dias; d++) {

        for (auto& eq : equipos) {

            int prob = rand() % 100;

            if (prob < 30) {
                int severidad = (rand() % 5) + 1;

                eq->agregarIncidencia(
                    make_unique<Incidencia>(severidad)
                );
            }

            unique_ptr<Mantenimiento> mantenimiento;

            if (eq->getEstado() < 30) {
                mantenimiento = make_unique<MantenimientoCorrectivo>(
                        make_unique<MantenimientoBase>()
                );
            } else {
                mantenimiento = make_unique<MantenimientoPreventivo>(
                        make_unique<MantenimientoBase>()
                );
            }

            mantenimiento->aplicar(*eq);
        }

        Ordenamiento::ordenar(equipos);
    }
}