#include "Simulador.h"
#include "Equipo.h"
#include "Incidencia.h"
#include "Strategy.h"
#include "MantenimientoPreventivo.h"
#include "MantenimientoCorrectivo.h"

#include <cstdlib>

Simulador::Simulador() {
    estrategia_ = std::make_unique<EstrategiaPrioridad>();

    for (int i = 0; i < 100; i++) {
        equipos_.push_back(
            std::make_unique<Equipo>("EQ-" + std::to_string(i), rand()%10+1, 80)
        );
    }
}

void Simulador::ejecutar() {

    for (int dia = 1; dia <= 30; dia++) {

        for (auto& eq : equipos_) {
            eq->degradar();

            if (rand()%3 == 0) {
                eq->agregarIncidencia(
                    std::make_unique<Incidencia>("Falla", rand()%5+1)
                );
            }
        }

        quickSort(0, equipos_.size() - 1);

        std::vector<Equipo*> top;

        for (int i = 0; i < 3; i++)
            top.push_back(equipos_[i].get());

        std::vector<std::unique_ptr<Mantenimiento>> acciones;

        for (auto* eq : top) {
            if (estrategia_->calcular(*eq) > 7)
                acciones.push_back(std::make_unique<MantenimientoCorrectivo>());
            else
                acciones.push_back(std::make_unique<MantenimientoPreventivo>());
        }

        for (int i = 0; i < top.size(); i++)
            acciones[i]->aplicar(*top[i]);

        report_.generar(dia, top);
    }
}