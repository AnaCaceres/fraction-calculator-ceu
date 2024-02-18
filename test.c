#include <stdio.h>
#include <assert.h>

#include "interfaz.h"
#include "fracciones.h"

void la_calculadora_deberia_almacenar_una_fraccion();

// Fraction calculator should store a fraction
void la_calculadora_deberia_almacenar_una_fraccion() {
    printf("Test 1: \n");

    int numeradores[MAX_FRACCIONES] = {3};
    int denominadores[MAX_FRACCIONES] = {4};
    int nFracciones = 1;
    FILE *user_input = fopen("test_mocks/1_store_a_fraction.txt", "r");

    stdin = user_input;
    opcion1(numeradores, denominadores, &nFracciones);
    stdin = stdin;

    assert(nFracciones == 2);
    int expected_numeradores[2] = {3, 2};
    int expected_denominadores[2] = {4, 3};
    for (int i = 0; i < nFracciones; i++) {
        assert(numeradores[i] == expected_numeradores[i]);
        assert(denominadores[i] == expected_denominadores[i]);
    }
    
    printf("Fracción almacenada correctamente\n");
    fclose(user_input);
}

int main() {
    la_calculadora_deberia_almacenar_una_fraccion();

    return 0;
}
