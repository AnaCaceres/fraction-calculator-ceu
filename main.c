#include "es.h"
#include "fracciones.h"

#define MAX_RUTA_ARCHIVO 50

void opcion1(int numeradores[], int denominadores[], int* nFracciones);
void opcion2(int numeradores[], int denominadores[], int* nFracciones);
void opcion3(int numeradores[], int denominadores[], int nFracciones);
void opcion4(int numeradores[], int denominadores[], int nFracciones);
void opcion5(int numeradores[], int denominadores[], int nFracciones);
void opcion6(int numeradores[], int denominadores[], int* nFracciones);
void opcion7(int numeradores[], int denominadores[], int* nFracciones);
void opcion8(int numeradores[], int denominadores[], int* nFracciones);
void opcion9(int numeradores[], int denominadores[], int* nFracciones);
void opcion10(int numeradores[], int denominadores[], int* nFracciones);


void opcion1(int numeradores[], int denominadores[], int* nFracciones) {
    int numerador;
    int denominador;

    if (hayEspacio(*nFracciones)) {
        numerador = pideNumerador();
        denominador = pideDenominador();
        introduceFraccion(numerador, denominador, numeradores, denominadores, nFracciones);
        muestraResultadoCorrecto();
    } else {
        muestraResultadoIncorrecto();
    }
}

void opcion2(int numeradores[], int denominadores[], int* nFracciones) {
    int posicion;

    if (hayFracciones(*nFracciones)) {
        posicion = pidePosicion(*nFracciones);
        eliminaFraccion(posicion, numeradores, denominadores, nFracciones);
        muestraResultadoCorrecto();
    } else {
        muestraResultadoIncorrecto();
    }
}

void opcion3(int numeradores[], int denominadores[], int nFracciones) {
    int posicion;

    if (hayFracciones(nFracciones)) {
        posicion = pidePosicion(nFracciones);
        muestraFraccion(posicion, numeradores, denominadores);
    } else {
        muestraResultadoIncorrecto();
    }
}

void opcion4(int numeradores[], int denominadores[], int nFracciones) {
    if (hayFracciones(nFracciones)) {
        muestraFracciones(numeradores, denominadores, nFracciones);
    } else {
        muestraResultadoIncorrecto();
    }
}

void opcion5(int numeradores[], int denominadores[], int nFracciones) {
    int posicion;
    float valor;

    if (hayFracciones(nFracciones)) {
        posicion = pidePosicion(nFracciones);
        valor = valorReal(posicion, numeradores, denominadores);
        muestraValor(valor);
    } else {
        muestraResultadoIncorrecto();
    }
}

void opcion6(int numeradores[], int denominadores[], int* nFracciones) {
    int posicion;
    int numerador;
    int denominador;

    if (hayFracciones(*nFracciones) && hayEspacio(*nFracciones)) {
        posicion = pidePosicion(*nFracciones);
        simplifica(numeradores[posicion], denominadores[posicion], &numerador, &denominador);
        introduceFraccion(numerador, denominador, numeradores, denominadores, nFracciones);
        muestraFraccion(*nFracciones - 1, numeradores, denominadores);
    } else {
        muestraResultadoIncorrecto();
    }
}

void opcion7(int numeradores[], int denominadores[], int* nFracciones) {
    int posicion1;
    int posicion2;
    int numeradorSuma;
    int denominadorSuma;
    int numeradorSimpl;
    int denominadorSimpl;

    if (hayFracciones(*nFracciones) && hayEspacio(*nFracciones)) {
        posicion1 = pidePosicion(*nFracciones);
        posicion2 = pidePosicion(*nFracciones);
        sumaFracciones(posicion1, posicion2, numeradores, denominadores, &numeradorSuma, &denominadorSuma);
        simplifica(numeradorSuma, numeradorSuma, &numeradorSimpl, &denominadorSimpl);
        introduceFraccion(numeradorSimpl, denominadorSimpl, numeradores, denominadores, nFracciones);
        muestraFraccion(*nFracciones - 1, numeradores, denominadores);
    } else {
        muestraResultadoIncorrecto();
    }
}

void opcion8(int numeradores[], int denominadores[], int* nFracciones) {
    int posicion1;
    int posicion2;
    int numeradorSuma;
    int denominadorSuma;
    int numeradorSimpl;
    int denominadorSimpl;

    if (hayFracciones(*nFracciones) && hayEspacio(*nFracciones)) {
        posicion1 = pidePosicion(*nFracciones);
        posicion2 = pidePosicion(*nFracciones);
        restaFracciones(posicion1, posicion2, numeradores, denominadores, &numeradorSuma, &denominadorSuma);
        simplifica(numeradorSuma, numeradorSuma, &numeradorSimpl, &denominadorSimpl);
        introduceFraccion(numeradorSimpl, denominadorSimpl, numeradores, denominadores, nFracciones);
        muestraFraccion(*nFracciones - 1, numeradores, denominadores);
    } else {
        muestraResultadoIncorrecto();
    }
}

void opcion9(int numeradores[], int denominadores[], int* nFracciones) {
    int posicion1;
    int posicion2;
    int numeradorSuma;
    int denominadorSuma;
    int numeradorSimpl;
    int denominadorSimpl;

    if (hayFracciones(*nFracciones) && hayEspacio(*nFracciones)) {
        posicion1 = pidePosicion(*nFracciones);
        posicion2 = pidePosicion(*nFracciones);
        multiplicaFracciones(posicion1, posicion2, numeradores, denominadores, &numeradorSuma, &denominadorSuma);
        simplifica(numeradorSuma, numeradorSuma, &numeradorSimpl, &denominadorSimpl);
        introduceFraccion(numeradorSimpl, denominadorSimpl, numeradores, denominadores, nFracciones);
        muestraFraccion(*nFracciones - 1, numeradores, denominadores);
    } else {
        muestraResultadoIncorrecto();
    }
}

void opcion10(int numeradores[], int denominadores[], int* nFracciones) {
    int posicion1;
    int posicion2;
    int numeradorSuma;
    int denominadorSuma;
    int numeradorSimpl;
    int denominadorSimpl;

    if (hayFracciones(*nFracciones) && hayEspacio(*nFracciones)) {
        posicion1 = pidePosicion(*nFracciones);
        posicion2 = pidePosicion(*nFracciones);
        divideFracciones(posicion1, posicion2, numeradores, denominadores, &numeradorSuma, &denominadorSuma);
        simplifica(numeradorSuma, numeradorSuma, &numeradorSimpl, &denominadorSimpl);
        introduceFraccion(numeradorSimpl, denominadorSimpl, numeradores, denominadores, nFracciones);
        muestraFraccion(*nFracciones - 1, numeradores, denominadores);
    } else {
        muestraResultadoIncorrecto();
    }
}




int main() {
    int numeradores[MAX_FRACCIONES];
    int denominadores[MAX_FRACCIONES];
    int nFracciones;
    int opcion;

    inicializaFracciones(&nFracciones);

    do {
        opcion = menu();

        if (opcion == 1) {
            opcion1(numeradores, denominadores, &nFracciones);
        } else if (opcion == 2) {
            opcion2(numeradores, denominadores, &nFracciones);
        } else if (opcion == 3) {
            opcion3(numeradores, denominadores, nFracciones);
        } else if (opcion == 4) {
            opcion4(numeradores, denominadores, nFracciones);
        } else if (opcion == 5) {
            opcion5(numeradores, denominadores, nFracciones);
        } else if (opcion == 6) {
            opcion6(numeradores, denominadores, &nFracciones);
        } else if (opcion == 7) {
            opcion7(numeradores, denominadores, &nFracciones);
        } else if (opcion == 8) {
            opcion8(numeradores, denominadores, &nFracciones);
        } else if (opcion == 9) {
            opcion9(numeradores, denominadores, &nFracciones);
        } else if (opcion == 10) {
            opcion10(numeradores, denominadores, &nFracciones);
        }

    } while (opcion != 11);

    return 0;
}

