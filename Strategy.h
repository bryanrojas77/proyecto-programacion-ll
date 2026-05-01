//
// Created by eXtreme PC on 1/5/2026.
//

#ifndef STRATEGY_H
#define STRATEGY_H

class Equipo;

class IEstrategia {
public:
    virtual double calcular(const Equipo& eq) const = 0;
    virtual ~IEstrategia() = default;
};

class EstrategiaPrioridad : public IEstrategia {
public:
    double calcular(const Equipo& eq) const override;
};

#endif