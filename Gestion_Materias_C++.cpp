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