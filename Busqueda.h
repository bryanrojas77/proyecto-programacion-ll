#ifndef BUSQUEDA_H
#define BUSQUEDA_H

#include <vector>
#include <string>

class Equipo;

class Busqueda {
public:
    static Equipo* busquedaBinariaPorId(const std::vector<Equipo*>& arr, const std::string& id);
};

#endif