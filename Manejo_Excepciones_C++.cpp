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
        Asistencia nuevaAsistencia = {fecha, materia, estado};
        asistencias.push_back(nuevaAsistencia);
    }

    static void mostrarAsistencia() {
        std::cout << "Registro de Asistencia:\n";
        for (const Asistencia& asistencia : asistencias) {
            std::cout << "Fecha: " << asistencia.fecha << ", Materia: " << asistencia.materia << ", Estado: " << asistencia.estado << "\n";
        }
    }
private:
    static bool materiaRegistrada(const std::string& materia) {
        return (materia == "Matemáticas" || materia == "Historia");
    }

    static std::vector<Asistencia> asistencias;
};

std::vector<Asistencia> GestionAsistencia::asistencias;
int main() {
    try {
        GestionAsistencia::registrarAsistencia("2023-01-01", "Matemáticas", "asistió");
        GestionAsistencia::registrarAsistencia("2023-01-02", "Historia", "falta");
        GestionAsistencia::registrarAsistencia("2023-01-03", "Inglés", "tardanza"); // Esto generará una excepción

        GestionAsistencia::mostrarAsistencia();

    } catch (const FechaInvalidaException& e) {
        std::cerr << "Excepción: " << e.what() << std::endl;
    } catch (const MateriaNoRegistradaException& e) {
        std::cerr << "Excepción: " << e.what() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Excepción general: " << e.what() << std::endl;
    }

    return 0;
}

