#ifndef FRACCIONES_H
#define FRACCIONES_H

#define MAX_FRACCIONES 50

void inicializaFracciones(int* nFracciones);
void introduceFraccion(int numerador, int denominador, int numeradores[], int denominadores[], int* nFracciones);
void eliminaFraccion(int posicion, int numeradores[], int denominadores[], int* nFracciones);
int hayEspacio(int nFracciones);
int hayFracciones(int nFracciones);
float valorReal(int posicion, int numeradores[], int denominadores[]);
void simplifica(int numerador, int denominador, int* numeradorRes, int* denominadorRes);
void sumaFracciones(int posicion, int posicion2, int numeradores[], int denominadores[], int* numRes, int* denRes);
void restaFracciones(int posicion, int posicion2, int numeradores[], int denominadores[], int* numRes, int* denRes);
void multiplicaFracciones(int posicion, int posicion2, int numeradores[], int denominadores[], int* numRes, int* denRes);
void divideFracciones(int posicion, int posicion2, int numeradores[], int denominadores[], int* numRes, int* denRes);

#endif

