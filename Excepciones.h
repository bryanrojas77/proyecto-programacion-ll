#ifndef PROYECTO_PROGRAMACION_LL_EXCEPCIONES_H
#define PROYECTO_PROGRAMACION_LL_EXCEPCIONES_H

#include <stdexcept>

class ArchivoException : public std::runtime_error {
public:
    explicit ArchivoException(const std::string& msg)
        : std::runtime_error(msg) {}
};

class SimulacionException : public std::runtime_error {
public:
    explicit SimulacionException(const std::string& msg)
        : std::runtime_error(msg) {}
};

#endif //PROYECTO_PROGRAMACION_LL_EXCEPCIONES_H
