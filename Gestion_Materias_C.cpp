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

