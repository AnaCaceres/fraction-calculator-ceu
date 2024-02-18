#include "es.h"

#include <stdio.h>
#include <stdbool.h>

int menu() {
    int opcion = 0;
    const char *opciones[] = {
        "Introducir fraccion",
        "Eliminar una fraccion",
        "Mostrar una fraccion",
        "Mostrar todas las fracciones almacenadas",
        "Mostrar valor real",
        "Simplificar fraccion",
        "Sumar fracciones",
        "Restar fracciones",
        "Multiplicar dos fracciones",
        "Dividir dos fracciones",
        "Salir"
    };
    int cantidad_de_opciones = sizeof(opciones) / sizeof(opciones[0]);

    do {
        printf("\n");
        for (int i = 0; i < cantidad_de_opciones; i++) {
            printf("%d. %s\n", i + 1, opciones[i]);
        }
        printf("Introduzca una opcion: ");
        
        if (scanf("%d", &opcion) != 1 || opcion < 1 || opcion > 11) {
            printf("Opcion incorrecta\n");
			// Limpia el búfer de entrada
            int c;
            while ((c = getchar()) != '\n' && c != EOF);
        }
    } while (opcion < 1 || opcion > 11);

    return opcion;
}

int pideNumerador() {
    int numerador;

    printf("Introduce numerador: ");
    scanf("%d", &numerador);

    return numerador;
}

int pideDenominador() {
    int denominador;

    printf("Introduce denominador: ");
    scanf("%d", &denominador);

    return denominador;
}

void muestraResultadoCorrecto() {
    printf("Operacion realizada correctamente\n");
}

void muestraResultadoIncorrecto() {
    printf("No se ha podido realizar la operacion\n");
}

int pidePosicion(int nFracciones) {
    int posicion;

    do {
        printf("Introduce posicion (1-%d): ", nFracciones);
        scanf("%d", &posicion);

        if (posicion < 1 || posicion > nFracciones) {
            printf("Valor incorrecto\n");
        }
    } while (posicion < 1 || posicion > nFracciones);

    posicion--; // para convertir del rango 1..nFracciones del usuario al rango
                // 0..nFracciones-1, ya que la primera posicion de los arrays
                // es la 0

    return posicion;
}

void muestraFraccion(int posicion, int numeradores[], int denominadores[]) {
    printf("%d/%d\n", numeradores[posicion], denominadores[posicion]);
}

void muestraFracciones(int numeradores[], int denominadores[], int nFracciones) {
    int i;

    for (i = 0; i < nFracciones; i++) {
        printf("Posicion %d: ", (i + 1));
        muestraFraccion(i, numeradores, denominadores);
    }
}

void muestraValor(float valor) {
    printf("El valor real es %f\n", valor);
}


