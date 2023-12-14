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
void mostrarAsistencia(const struct Estudiante* estudiante) {
    printf("Asistencia de %s:\n", estudiante->nombre);
    for (int i = 0; i < estudiante->numAsistencias; ++i) {
        printf("Fecha: %s, Materia: %s, Estado: %s\n", estudiante->asistencias[i].fecha, estudiante->asistencias[i].materia, estudiante->asistencias[i].estado);
    }
}
int main() {
    struct Estudiante estudiante1 = {"Diego", 19, 75.0, NULL, 0};
    registrarAsistencia(&estudiante1, "2023-01-01", "Matemáticas", "asistió");
    registrarAsistencia(&estudiante1, "2023-01-02", "Historia", "falta");
    registrarAsistencia(&estudiante1, "2023-01-03", "Inglés", "tardanza");

    mostrarAsistencia(&estudiante1);

    free(estudiante1.asistencias);

    return 0;
}
