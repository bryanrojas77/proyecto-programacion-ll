#include "EquipoNormal.h"

using namespace std;

EquipoNormal::EquipoNormal(string id, double estado, IEstrategiaPrioridad* est)
    : Equipo(move(id), 5, estado, est) {}