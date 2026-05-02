#ifndef BUSQUEDA_H
#define BUSQUEDA_H

#include <vector>
#include <string>
using namespace std;

class Equipo;

class Busqueda {
public:
    static Equipo* busquedaBinariaPorId(const vector<Equipo*>& arr, const string& id);
};

#endif