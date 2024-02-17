#include "fracciones.h"

#include <stdio.h>

void inicializaFracciones(int* nFracciones) {
    *nFracciones = 0;
}

void introduceFraccion(int numerador, int denominador, int numeradores[], int denominadores[], int* nFracciones) {
    numeradores[*nFracciones] = numerador;
    denominadores[*nFracciones] = denominador;
    (*nFracciones)++;
}

void eliminaFraccion(int posicion, int numeradores[], int denominadores[], int* nFracciones) {
    int i;

    for (i = posicion; i < *nFracciones - 1; i++) {
        numeradores[i] = numeradores[i + 1];
        denominadores[i] = denominadores[i + 1];
    }

    (*nFracciones)--;
}

int hayEspacio(int nFracciones) {
    return nFracciones < MAX_FRACCIONES;
}

int hayFracciones(int nFracciones) {
    return nFracciones > 0;
}

float valorReal(int posicion, int numeradores[], int denominadores[]) {
    return numeradores[posicion] / (float) denominadores[posicion]; // conversion explicita
                                                                    // para que la division
                                                                    // sea real
}

void simplifica(int numerador, int denominador, int* numeradorRes, int* denominadorRes) {
    int i;
    int primero;

    *numeradorRes = numerador;
    *denominadorRes = denominador;

    if (*numeradorRes < *denominadorRes) {
        primero = *numeradorRes;
    } else {
        primero = *denominadorRes;
    }

    for (i = primero; i > 1; i--) {
        if (*numeradorRes % i == 0 && *denominadorRes % i == 0) {
            *numeradorRes = *numeradorRes / i;
            *denominadorRes = *denominadorRes / i;
        }
    }
}

void sumaFracciones(int posicion, int posicion2, int numeradores[], int denominadores[], int* numRes, int* denRes) {
    int num1;
    int den1;
    int num2;
    int den2;

    num1 = numeradores[posicion];
    den1 = denominadores[posicion];
    num2 = numeradores[posicion2];
    den2 = denominadores[posicion2];

    *numRes = num1 * den2 + num2 * den1;
    *denRes = den1 * den2;
}

void restaFracciones(int posicion, int posicion2, int numeradores[], int denominadores[], int* numRes, int* denRes) {
    int num1;
    int den1;
    int num2;
    int den2;

    num1 = numeradores[posicion];
    den1 = denominadores[posicion];
    num2 = numeradores[posicion2];
    den2 = denominadores[posicion2];

    *numRes = num1 * den2 - num2 * den1;
    *denRes = den1 * den2;
}

void multiplicaFracciones(int posicion, int posicion2, int numeradores[], int denominadores[], int* numRes, int* denRes) {
    int num1;
    int den1;
    int num2;
    int den2;

    num1 = numeradores[posicion];
    den1 = denominadores[posicion];
    num2 = numeradores[posicion2];
    den2 = denominadores[posicion2];

    *numRes = num1 * num2;
    *denRes = den1 * den2;
}

void divideFracciones(int posicion, int posicion2, int numeradores[], int denominadores[], int* numRes, int* denRes) {
    int num1;
    int den1;
    int num2;
    int den2;

    num1 = numeradores[posicion];
    den1 = denominadores[posicion];
    num2 = numeradores[posicion2];
    den2 = denominadores[posicion2];

    *numRes = num1 * den2;
    *denRes = num2 * den1;
}




