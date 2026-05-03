
#ifndef PROYECTO_PROGRAMACION_LL_MANTENIMIENTO_H
#define PROYECTO_PROGRAMACION_LL_MANTENIMIENTO_H

class Equipo;

class Mantenimiento {
public:
    virtual void aplicar(Equipo& eq) = 0;
    virtual ~Mantenimiento() = default;
};

#endif //PROYECTO_PROGRAMACION_LL_MANTENIMIENTO_H
