#include "MantenimientoCorrectivo.h"
#include "Equipo.h"

using namespace std;

void MantenimientoCorrectivo::aplicar(Equipo& eq) {
    MantenimientoDecorator::aplicar(eq);

    for (int i = 0; i < 5; i++) {
        eq.degradar();
    }
}