#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Materia {
    char nombreMateria[50];
    float calificacion;
};
struct Estudiante {
    char nombre[50];
    int edad;
    float promedio;
    struct Materia* materias;
    int numMaterias;
};
void mostrarEstudiante(const struct Estudiante* estudiante) {
    printf("Nombre: %s\n", estudiante->nombre);
    printf("Edad: %d\n", estudiante->edad);
    printf("Promedio: %f\n", estudiante->promedio);

    printf("Materias Inscritas:\n");
    for (int i = 0; i < estudiante->numMaterias; ++i) {
        printf(" - %s, Calificación: %f\n", estudiante->materias[i].nombreMateria, estudiante->materias[i].calificacion);
    }
}
