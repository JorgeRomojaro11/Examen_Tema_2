#include <stdio.h>

struct Estudiante {
    char nombre[50];
    int edad;
    float promedio;
};
void mostrarEstudiante(const struct Estudiante* estudiante) {
    printf("Nombre: %s\n", estudiante->nombre);
    printf("Edad: %d\n", estudiante->edad);
    printf("Promedio: %f\n", estudiante->promedio);
}
int main() {
    struct Estudiante estudiante1 = {"Manolo", 24, 87.3};
    mostrarEstudiante(&estudiante1);

    return 0;
}
