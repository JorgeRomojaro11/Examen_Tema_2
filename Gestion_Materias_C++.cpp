#include <iostream>
#include <string>
#include <vector>

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