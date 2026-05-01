//
// Created by kathy on 1/5/2026.
//
#include "Simulador.h"
#include "Equipo.h"
#include <iostream>
#include <algorithm>

void Simulador::ejecutarSimulacion(std::vector<Equipo*>& equipos, int dias) {

    for (int d = 1; d <= dias; ++d) {

        // degradar estado
        for (auto& eq : equipos) {
            eq->degradar();
        }

        // ordenar por prioridad
        std::sort(equipos.begin(), equipos.end(),
            [](Equipo* a, Equipo* b) {
                return a->calcularPrioridad() > b->calcularPrioridad();
            });

        std::cout << "\n--- Dia " << d << " ---\n";

        int limite = std::min(3, (int)equipos.size());

        for (int i = 0; i < limite; ++i) {
            std::cout << equipos[i]->getId()
                      << " -> "
                      << equipos[i]->calcularPrioridad()
                      << "\n";
        }
    }
}