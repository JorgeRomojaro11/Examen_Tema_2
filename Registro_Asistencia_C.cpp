#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Asistencia {
    char fecha[20];
    char materia[50];
    char estado[20];
};
struct Estudiante {
    char nombre[50];
    int edad;
    float promedio;
    struct Asistencia* asistencias;
    int numAsistencias;
};
void registrarAsistencia(struct Estudiante* estudiante, const char* fecha, const char* materia, const char* estado) {
    estudiante->asistencias = (struct Asistencia*)realloc(estudiante->asistencias, (estudiante->numAsistencias + 1) * sizeof(struct Asistencia));
    strncpy(estudiante->asistencias[estudiante->numAsistencias].fecha, fecha, sizeof(estudiante->asistencias[estudiante->numAsistencias].fecha));
    strncpy(estudiante->asistencias[estudiante->numAsistencias].materia, materia, sizeof(estudiante->asistencias[estudiante->numAsistencias].materia));
    strncpy(estudiante->asistencias[estudiante->numAsistencias].estado, estado, sizeof(estudiante->asistencias[estudiante->numAsistencias].estado));
    estudiante->numAsistencias++;
}

