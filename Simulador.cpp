//
// Created by kathy on 1/5/2026.
//

#include "Simulador.h"
#include "Equipo.h"
#include "Ordenamiento.h"
#include "ReportService.h"
#include "Excepciones.h"

#include <iostream>

void Simulador::ejecutarSimulacion(std::vector<Equipo*>& equipos, int dias) {

    if (dias <= 0) {
        throw SimulacionException("Dias invalidos");
    }

    for (int d = 1; d <= dias; d++) {

        std::cout << "\n--- Dia " << d << " ---\n";

        for (auto* e : equipos) {
            e->degradar();
        }

        Ordenamiento::quickSortPorPrioridad(equipos, 0, equipos.size() - 1);

        std::cout << "Top 3:\n";
        for (int i = 0; i < 3 && i < equipos.size(); i++) {
            std::cout << equipos[i]->id()
                      << " -> "
                      << equipos[i]->calcularPrioridad()
                      << "\n";
        }

        std::string nombre = "reporte_dia_" + std::to_string(d) + ".txt";
        ReportService::guardarReporte(nombre, equipos);
    }
}