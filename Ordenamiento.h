#ifndef ORDENAMIENTO_H
#define ORDENAMIENTO_H

#include <vector>
using namespace std;

class Equipo;

class Ordenamiento {
public:
    static void ordenar(vector<Equipo*>& equipos);
};

#endif