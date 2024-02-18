#include <stdio.h>
#include <assert.h>

#include "interfaz.h"
#include "fracciones.h"

void la_calculadora_deberia_almacenar_una_fraccion();
void la_calculadora_deberia_eliminar_una_fraccion();

// Fraction calculator should store a fraction
void la_calculadora_deberia_almacenar_una_fraccion() {
    printf("La calculadora debería almacenar una fracción: \n");

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
    
    printf("Fracción almacenada correctamente\n\n");
    fclose(user_input);
}

// Fraction calculator should remove a fraction
void la_calculadora_deberia_eliminar_una_fraccion(){
  printf("La calculadora debería eliminar una fracción: \n");

  int numeradores[MAX_FRACCIONES] = {3, 1, 5};
  int denominadores[MAX_FRACCIONES] = {4, 9, 7};
  int nFracciones = 3;
  FILE *user_input = fopen("test_mocks/2_remove_a_fraction.txt", "r");

  stdin = user_input;
  opcion2(numeradores, denominadores, &nFracciones);
  stdin = stdin;

  assert(nFracciones == 2);
  int expected_numeradores[2] = {3, 5};
  int expected_denominadores[2] = {4, 7};
  for (int i = 0; i < nFracciones; i++) {
      assert(numeradores[i] == expected_numeradores[i]);
      assert(denominadores[i] == expected_denominadores[i]);
  }
  
  printf("Fracción eliminada correctamente\n\n");
  fclose(user_input);
}

int main() {
    la_calculadora_deberia_almacenar_una_fraccion();
    la_calculadora_deberia_eliminar_una_fraccion();

    return 0;
}
