#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Asistencia {
    char fecha[20];
    char materia[50];
    char estado[20];
};
enum ErrorCode {
    OK,
    FECHA_INVALIDA,
    MATERIA_NO_REGISTRADA
};
struct Estudiante {
    char nombre[50];
    int edad;
    float promedio;
    struct Asistencia* asistencias;
    int numAsistencias;
};
int registrarAsistencia(struct Estudiante* estudiante, const char* fecha, const char* materia, const char* estado) {
    if (strlen(fecha) != 10 || fecha[4] != '-' || fecha[7] != '-') {
        return FECHA_INVALIDA;
    }