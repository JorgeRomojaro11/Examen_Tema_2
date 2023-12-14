#include <iostream>
#include <string>
#include <stdexcept>
#include <vector>

class FechaInvalidaException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Error: Formato de fecha no válido.";
    }
};
class MateriaNoRegistradaException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Error: Materia no registrada.";
    }
};
struct Asistencia {
    std::string fecha;
    std::string materia;
    std::string estado;
};

