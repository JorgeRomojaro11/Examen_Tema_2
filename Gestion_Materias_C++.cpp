#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

struct Materia {
    std::string nombreMateria;
    float calificacion;
};
struct Estudiante {
    std::string nombre;
    int edad;
    float promedio;
    std::vector<Materia> materias;
};

void mostrarEstudiante(const Estudiante& estudiante) {
    std::cout << "Nombre: " << estudiante.nombre << std::endl;
    std::cout << "Edad: " << estudiante.edad << std::endl;
    std::cout << "Promedio: " << estudiante.promedio << std::endl;

    std::cout << "Materias Inscritas:" << std::endl;
    for (const Materia& materia : estudiante.materias) {
        std::cout << " - " << materia.nombreMateria << ", Calificación: " << materia.calificacion << std::endl;
    }
}
void agregarMateria(Estudiante& estudiante, const std::string& nombreMateria, float calificacion) {
    Materia nuevaMateria = {nombreMateria, calificacion};
    estudiante.materias.push_back(nuevaMateria);
}

void eliminarMateria(Estudiante& estudiante, const std::string& nombreMateria) {
    estudiante.materias.erase(
            std::remove_if(
                    estudiante.materias.begin(),
                    estudiante.materias.end(),
                    [&nombreMateria](const Materia& materia) {
                        return materia.nombreMateria == nombreMateria;
                    }),
            estudiante.materias.end());
}
int main() {
    Estudiante estudiante1 = {"Xokas", 36, 34.7};
    agregarMateria(estudiante1, "Matemáticas", 70.0);
    agregarMateria(estudiante1, "Historia", 0.6);
    mostrarEstudiante(estudiante1);

    eliminarMateria(estudiante1, "Historia");
    std::cout << "\nDespués de eliminar Historia:\n";
    mostrarEstudiante(estudiante1);

    return 0;
}