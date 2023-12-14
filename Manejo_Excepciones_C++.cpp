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
class GestionAsistencia {
public:
    static void registrarAsistencia(const std::string& fecha, const std::string& materia, const std::string& estado) {
        if (fecha.size() != 10 || fecha[4] != '-' || fecha[7] != '-') {
            throw FechaInvalidaException();
        }

        if (!materiaRegistrada(materia)) {
            throw MateriaNoRegistradaException();
        }

