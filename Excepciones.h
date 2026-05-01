#ifndef PROYECTO_PROGRAMACION_LL_EXCEPCIONES_H
#define PROYECTO_PROGRAMACION_LL_EXCEPCIONES_H

#include <stdexcept>
#include <string>

class FileException : public std::exception {
private:
    std::string mensaje_;
public:
    explicit FileException(const std::string& mensaje)
        : mensaje_("Error de archivo: " + mensaje) {}

    const char* what() const noexcept override {
        return mensaje_.c_str();
    }
};

class ValidationException : public std::exception {
private:
    std::string mensaje_;
public:
    explicit ValidationException(const std::string& mensaje)
        : mensaje_("Error de validacion: " + mensaje) {}

    const char* what() const noexcept override {
        return mensaje_.c_str();
    }
};

class SimulacionException : public std::exception {
private:
    std::string mensaje_;
public:
    explicit SimulacionException(const std::string& mensaje)
        : mensaje_("Error de simulacion: " + mensaje) {}

    const char* what() const noexcept override {
        return mensaje_.c_str();
    }
};

#endif //PROYECTO_PROGRAMACION_LL_EXCEPCIONES_H
