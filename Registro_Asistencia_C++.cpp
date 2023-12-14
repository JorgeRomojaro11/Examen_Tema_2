#include <iostream>
#include <string>
#include <vector>

struct Asistencia {
    std::string fecha;
    std::string materia;
    std::string estado;
};
struct Estudiante {
    std::string nombre;
    int edad;
    float promedio;
    std::vector<Asistencia> asistencias;
};
class GestionAsistencia {
public:
    static void registrarAsistencia(Estudiante& estudiante, const std::string& fecha, const std::string& materia, const std::string& estado) {
        Asistencia nuevaAsistencia = {fecha, materia, estado};
        estudiante.asistencias.push_back(nuevaAsistencia);
    }
    static void mostrarAsistencia(const Estudiante& estudiante) {
        std::cout << "Asistencia de " << estudiante.nombre << ":\n";
        for (const Asistencia& asistencia : estudiante.asistencias) {
            std::cout << "Fecha: " << asistencia.fecha << ", Materia: " << asistencia.materia << ", Estado: " << asistencia.estado << "\n";
        }
    }
};
int main() {
    Estudiante estudiante1 = {"Rustero", 34, 50.0};
    GestionAsistencia::registrarAsistencia(estudiante1, "2023-01-01", "Matemáticas", "asistió");
    GestionAsistencia::registrarAsistencia(estudiante1, "2023-01-02", "Historia", "falta");
    GestionAsistencia::registrarAsistencia(estudiante1, "2023-01-03", "Inglés", "tardanza");

    GestionAsistencia::mostrarAsistencia(estudiante1);

    return 0;
}