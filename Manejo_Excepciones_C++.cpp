#include <iostream>
#include <string>
#include <stdexcept>
#include <vector>

// Excepción personalizada para errores en el formato de la fecha
class FechaInvalidaException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Error: Formato de fecha no válido.";
    }
};
