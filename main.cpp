#include <iostream>
#include <memory>
#include <vector>
#include "EquipoNormal.h"
#include "EquipoCritico.h"
#include "Incidencia.h"
#include "Ordenamiento.h"
#include "Busqueda.h"
#include "Simulador.h"

int main() {
    try {
        std::cout << "=== INICIO SISTEMA ===\n";
        std::vector<std::unique_ptr<Equipo>> equipos;

        auto eq1 = std::make_unique<EquipoCritico>("EQ-1", 80.0);
        eq1->agregarIncidencia(std::make_unique<Incidencia>("Falla", 5));
        eq1->agregarIncidencia(std::make_unique<Incidencia>("Error", 3));

        auto eq2 = std::make_unique<EquipoNormal>("EQ-2", 90.0);
        eq2->agregarIncidencia(std::make_unique<Incidencia>("Warning", 2));

        equipos.push_back(std::move(eq1));
        equipos.push_back(std::move(eq2));

        std::cout << "Datos cargados\n";

        std::vector<Equipo*> vista;

        for (auto& e : equipos) {
            vista.push_back(e.get());
        }

        Ordenamiento::quickSortPorPrioridad(vista, 0, vista.size() - 1);

        std::cout << "\n--- Equipos priorizados ---\n";
        for (auto* e : vista) {
            std::cout << e->id()
                      << " -> " << e->calcularPrioridad()
                      << std::endl;
        }

        Ordenamiento::quickSortPorId(vista, 0, vista.size() - 1);

        Equipo* encontrado = Busqueda::busquedaBinariaPorId(vista, "EQ-1");

        if (encontrado) {
            std::cout << "\nBusqueda OK: "
                      << encontrado->id()
                      << std::endl;
        }

        std::cout << "\n=== INICIANDO SIMULACION ===\n";

        Simulador::ejecutarSimulacion(vista, 5);

        std::cout << "\n=== FIN DEL SISTEMA ===\n";
    }
    catch (const std::exception& e) {
        std::cout << "\nERROR GLOBAL: "
                  << e.what() << std::endl;
    }

    return 0;
}