#include "es.h"

#include <stdio.h>

int menu() {
    int opcion;

    do {
        printf("\n");
        printf("1. Introducir fraccion\n");
        printf("2. Eliminar una fraccion\n");
        printf("3. Mostrar una fraccion\n");
        printf("4. Mostrar todas las fracciones almacenadas\n");
        printf("5. Mostrar valor real\n");
        printf("6. Simplificar fraccion\n");
        printf("7. Sumar fracciones\n");
        printf("8. Restar fracciones\n");
        printf("9. Multiplicar dos fracciones\n");
        printf("10. Dividir dos fracciones\n");
        printf("11. Salir\n");
        printf("Introduzca una opcion: ");
        scanf("%d", &opcion);

        if (opcion < 1 || opcion > 11) {
            printf("Opcion incorrecta\n");
        }
    } while (opcion < 1 || opcion > 11);

    printf("\n");

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


