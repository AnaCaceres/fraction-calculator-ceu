#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include "interfaz.h"
#include "fracciones.h"

void la_calculadora_deberia_almacenar_una_fraccion();
void la_calculadora_deberia_eliminar_una_fraccion();
void la_calculadora_deberia_mostrar_una_fraccion();
void la_calculadora_deberia_mostrar_todas_las_fracciones();

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

// Fraction calculator should show a fraction
void la_calculadora_deberia_mostrar_una_fraccion(){
  printf("La calculadora debería mostrar una fracción: \n");

  int numeradores[MAX_FRACCIONES] = {3, 1, 5, 2};
  int denominadores[MAX_FRACCIONES] = {4, 9, 7, 3};
  int nFracciones = 4;
  FILE *user_input = fopen("test_mocks/3_show_a_fraction.txt", "r");

  int stdout_original = dup(STDOUT_FILENO);
  FILE *file = fopen("output.txt", "w");
  // Redirige stdout al archivo temporal
  dup2(fileno(file), fileno(stdout));
  fclose(file);

  stdin = user_input;
  opcion3(numeradores, denominadores, nFracciones);
  stdin = stdin;
  
  // Lee el contenido del archivo temporal
  file = fopen("output.txt", "r");
  char buffer[100];
  fgets(buffer, sizeof(buffer), file);
  fclose(file);
  // Restaura stdout
  remove("output.txt");
  dup2(stdout_original, STDOUT_FILENO);
  close(stdout_original);
  fclose(user_input);

  char expected_output[] = "Introduce posicion (1-4): 3\n5/7";
  assert(strcmp(buffer, expected_output));
  
  printf("%s\n", expected_output);
  printf("Fracción mostrada correctamente\n\n");
}

// Fraction calculator should show all fractions
void la_calculadora_deberia_mostrar_todas_las_fracciones(){
  printf("La calculadora debería mostrar todas las fracciones: \n");

  int numeradores[MAX_FRACCIONES] = {3, 1, 5, 2};
  int denominadores[MAX_FRACCIONES] = {4, 9, 7, 3};
  int nFracciones = 4;

  int stdout_original = dup(STDOUT_FILENO);
  FILE *file = fopen("output.txt", "w");
  // Redirige stdout al archivo temporal
  dup2(fileno(file), fileno(stdout));
  fclose(file);

  opcion4(numeradores, denominadores, nFracciones);

  // Lee el contenido del archivo temporal
  file = fopen("output.txt", "r");
  char buffer[100];
  fgets(buffer, sizeof(buffer), file);
  fclose(file);
  // Restaura stdout
  remove("output.txt");
  dup2(stdout_original, STDOUT_FILENO);
  close(stdout_original);

  char expected_output[] = "Posicion 1: 3/4\nPosicion 2: 1/9\nPosicion 3: 5/7\nPosicion 4: 2/3";
  assert(strcmp(buffer, expected_output));
  
  printf("%s\n", expected_output);
  printf("Fracciones mostradas correctamente\n\n");
}

int main() {
    la_calculadora_deberia_almacenar_una_fraccion();
    la_calculadora_deberia_eliminar_una_fraccion();
    la_calculadora_deberia_mostrar_una_fraccion();
    la_calculadora_deberia_mostrar_todas_las_fracciones();

    return 0;
}
