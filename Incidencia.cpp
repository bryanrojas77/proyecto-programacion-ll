#include "Incidencia.h"

Incidencia::Incidencia(int sev) : severidad_(sev) {}

int Incidencia::getSeveridad() const {
    return severidad_;
}