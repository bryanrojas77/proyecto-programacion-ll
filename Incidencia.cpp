#include "Incidencia.h"

using namespace std;

Incidencia::Incidencia(string tipo, int severidad)
    : tipo_(move(tipo)), severidad_(severidad) {}

int Incidencia::severidad() const {
    return severidad_;
}