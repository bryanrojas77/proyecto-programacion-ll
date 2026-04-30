//
// Created by kathy on 30/4/2026.
//

#ifndef PROYECTO_PROGRAMACION_LL_INCIDENCIA_H
#define PROYECTO_PROGRAMACION_LL_INCIDENCIA_H

#include <string>

class Equipo;

class Incidencia {
private:
    std::string tipo_;
    int severidad_;
    Equipo* equipo_;

public:
    Incidencia(std::string tipo, int sev);

    void asignarEquipo(Equipo* eq);
    int severidad() const;
};



#endif //PROYECTO_PROGRAMACION_LL_INCIDENCIA_H
