
#ifndef PROYECTO_PROGRAMACION_LL_INCIDENCIA_H
#define PROYECTO_PROGRAMACION_LL_INCIDENCIA_H

#include <string>
using namespace std;

class Incidencia {
protected:
    int severidad_;

public:
    Incidencia(int sev);

    int getSeveridad() const;
};

#endif //PROYECTO_PROGRAMACION_LL_INCIDENCIA_H
