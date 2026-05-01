#include "EquipoCritico.h"
#include "EquipoNormal.h"
#include "Incidencia.h"
#include "MantenimientoBase.h"
#include "MantenimientoPreventivo.h"
#include "MantenimientoCorrectivo.h"

#include <memory>
#include <vector>
#include <iostream>

int main() {

    std::vector<std::unique_ptr<Equipo>> equipos;

    equipos.push_back(std::make_unique<EquipoCritico>("EQ-1", 80));
    equipos.push_back(std::make_unique<EquipoNormal>("EQ-2", 90));

    equipos[0]->agregarIncidencia(std::make_unique<Incidencia>("Falla", 5));
    equipos[1]->agregarIncidencia(std::make_unique<Incidencia>("Error", 2));

    for (const auto& eq : equipos) {
        std::cout << eq->id()
                  << " prioridad: "
                  << eq->calcularPrioridad()
                  << std::endl;
    }
    std::cout << "\n--- Probando Decorator ---\n";

    Equipo* eq = equipos[0].get();

    std::cout << "Antes mantenimiento: "
              << eq->calcularPrioridad() << std::endl;

    std::unique_ptr<Mantenimiento> mantenimiento =
        std::make_unique<MantenimientoBase>();

    mantenimiento = std::make_unique<MantenimientoPreventivo>(
        std::move(mantenimiento)
    );

    mantenimiento = std::make_unique<MantenimientoCorrectivo>(
        std::move(mantenimiento)
    );

    mantenimiento->aplicar(*eq);

    std::cout << "Despues mantenimiento: "
              << eq->calcularPrioridad() << std::endl;
    return 0;
}