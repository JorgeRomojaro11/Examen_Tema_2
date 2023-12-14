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
void agregarMateria(struct Estudiante* estudiante, const char* nombreMateria, float calificacion) {
    estudiante->materias = (struct Materia*)realloc(estudiante->materias, (estudiante->numMaterias + 1) * sizeof(struct Materia));
    strncpy(estudiante->materias[estudiante->numMaterias].nombreMateria, nombreMateria, sizeof(estudiante->materias[estudiante->numMaterias].nombreMateria));
    estudiante->materias[estudiante->numMaterias].calificacion = calificacion;
    estudiante->numMaterias++;
}
void eliminarMateria(struct Estudiante* estudiante, const char* nombreMateria) {
    for (int i = 0; i < estudiante->numMaterias; ++i) {
        if (strcmp(estudiante->materias[i].nombreMateria, nombreMateria) == 0) {
            memmove(&estudiante->materias[i], &estudiante->materias[i + 1], (estudiante->numMaterias - i - 1) * sizeof(struct Materia));
            estudiante->numMaterias--;
            estudiante->materias = (struct Materia*)realloc(estudiante->materias, estudiante->numMaterias * sizeof(struct Materia));
            break;
        }
    }
}
