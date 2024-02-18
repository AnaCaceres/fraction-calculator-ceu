#include <stdio.h>
#include <assert.h>

#include "interfaz.h"
#include "fracciones.h"

void test_opcion1();

void test_opcion1() {
    printf("Test 1: \n");

    int numeradores[MAX_FRACCIONES] = {3};
    int denominadores[MAX_FRACCIONES] = {4};
    int nFracciones = 1;
    FILE *user_input = fopen("test_mocks/opcion_1_mock.txt", "r");

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
    test_opcion1();

    return 0;
}
