#include "EquipoCritico.h"

using namespace std;

EquipoCritico::EquipoCritico(string id, double estado, IEstrategiaPrioridad* est)
    : Equipo(move(id), 10, estado, est) {}