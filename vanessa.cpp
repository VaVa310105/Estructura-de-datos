#include <stdio.h>

#define N 7 // Número de días

typedef struct {
    char fecha[11];
    float manana;
    float tarde;
    float noche;
} Registro;

void agregar_registro(Registro *registro) {
    printf("Ingrese la fecha (DD/MM/YYYY): ");
    scanf("%s", registro->fecha);
    printf("Ingrese la temperatura de la mañana: ");
    scanf("%f", &registro->manana);
    printf("Ingrese la temperatura de la tarde: ");
    scanf("%f", &registro->tarde);
    printf("Ingrese la temperatura de la noche: ");
    scanf("%f", &registro->noche);
}

float promedio_dia(Registro registro) {
    return (registro.manana + registro.tarde + registro.noche) / 3;
}

float promedio_total(Registro *registros, int n) {
    float suma = 0;
    for (int i = 0; i < n; i++) {
        suma += promedio_dia(registros[i]);
    }
    return suma / n;
}

int main() {
    Registro registros[N];

    // Solicitar al usuario que agregue registros
    for (int i = 0; i < N; i++) {
        printf("\nIngrese los datos para el día %d:\n", i + 1);
        agregar_registro(&registros[i]);
    }

    // Mostrar registros
    for (int i = 0; i < N; i++) {
        printf("\nFecha: %s, Mañana: %.2f°C, Tarde: %.2f°C, Noche: %.2f°C\n",
               registros[i].fecha, registros[i].manana, registros[i].tarde, registros[i].noche);
    }

    // Calcular promedios
    printf("\nPromedio del día 1: %.2f°C\n", promedio_dia(registros[0]));
    printf("Promedio total: %.2f°C\n", promedio_total(registros, N));

    return 0;
}
