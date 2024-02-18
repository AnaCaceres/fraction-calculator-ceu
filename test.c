#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include "interfaz.h"
#include "fracciones.h"
#include "es.h"

void assert_int_equal(int expected, int received);
void assert_string_equal(const char *expected, const char *received);
void la_calculadora_deberia_almacenar_una_fraccion();
void la_calculadora_deberia_eliminar_una_fraccion();
void la_calculadora_deberia_mostrar_una_fraccion();
void la_calculadora_deberia_mostrar_todas_las_fracciones();
void la_calculadora_deberia_mostrar_un_valor_real();
void la_calculadora_deberia_simplificar_una_fraccion();
void la_calculadora_deberia_sumar_dos_fracciones();
void la_calculadora_deberia_restar_dos_fracciones();
void la_calculadora_deberia_multiplicar_dos_fracciones();
void la_calculadora_deberia_dividir_dos_fracciones();
void la_calculadora_deberia_mostrar_un_mensaje_de_error_cuando_no_hay_fracciones_almacenadas();
void la_calculadora_deberia_mostrar_menu();
void la_calculadora_deberia_mostrar_un_mensaje_de_error_cuando_selecciona_una_opcion_invalida();
void la_calculadora_deberia_mostrar_un_mensaje_de_error_cuando_la_opcion_insertada_no_es_numerica();

void assert_int_equal(int expected, int received) {
  if (expected != received) {
    fprintf(stderr, "FAILED\nSe esperaba: %d\nSe recibió: %d\n\n", expected, received);
  } else {
    printf("PASS\n\n");
  }
}

void assert_string_equal(const char *expected, const char *received) {
  if (strcmp(expected, received) != 0) {
    fprintf(stderr, "FAILED\nSe esperaba: %s\nSe recibió: %s\n\n", expected, received);
  } else {
    printf("PASS\n\n");
  }
}

// Fraction calculator should store a fraction
void la_calculadora_deberia_almacenar_una_fraccion() {
    printf("La calculadora debería almacenar una fracción: \n");

    int numeradores[MAX_FRACCIONES] = {3};
    int denominadores[MAX_FRACCIONES] = {4};
    int nFracciones = 1;
    FILE *user_input = fopen("test_user_input/1_store_a_fraction.txt", "r");

    stdin = user_input;
    opcion1(numeradores, denominadores, &nFracciones);
    stdin = stdin;

    assert_int_equal(2, nFracciones);
    int expected_numeradores[2] = {3, 2};
    int expected_denominadores[2] = {4, 3};
    for (int i = 0; i < nFracciones; i++) {
        assert_int_equal(expected_numeradores[i], numeradores[i]);
        assert_int_equal(expected_denominadores[i], denominadores[i]);
    }
    
    fclose(user_input);
}

// Fraction calculator should remove a fraction
void la_calculadora_deberia_eliminar_una_fraccion(){
  printf("La calculadora debería eliminar una fracción: \n");

  int numeradores[MAX_FRACCIONES] = {3, 1, 5};
  int denominadores[MAX_FRACCIONES] = {4, 9, 7};
  int nFracciones = 3;
  FILE *user_input = fopen("test_user_input/2_remove_a_fraction.txt", "r");

  stdin = user_input;
  opcion2(numeradores, denominadores, &nFracciones);
  stdin = stdin;

  assert_int_equal(2, nFracciones);
  int expected_numeradores[2] = {3, 5};
  int expected_denominadores[2] = {4, 7};
  for (int i = 0; i < nFracciones; i++) {
      assert_int_equal(expected_numeradores[i], numeradores[i]);
      assert_int_equal(expected_denominadores[i], denominadores[i]);
  }
  
  fclose(user_input);
}

// Fraction calculator should show a fraction
void la_calculadora_deberia_mostrar_una_fraccion(){
  printf("La calculadora debería mostrar una fracción: \n");

  int numeradores[MAX_FRACCIONES] = {3, 1, 5, 2};
  int denominadores[MAX_FRACCIONES] = {4, 9, 7, 3};
  int nFracciones = 4;
  FILE *user_input = fopen("test_user_input/3_show_a_fraction.txt", "r");

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
  // Obtener el tamaño del archivo
  fseek(file, 0, SEEK_END);
  long tamaño = ftell(file);
  fseek(file, 0, SEEK_SET);
  // Asignar memoria para almacenar el contenido del archivo
  char *contenido = (char *)malloc(tamaño + 1);
  // Leer el archivo completo
  fread(contenido, 1, tamaño, file);
  // Cerrar el archivo
  fclose(file);
  // Restaura stdout
  remove("output.txt");
  dup2(stdout_original, STDOUT_FILENO);
  close(stdout_original);

  char expected_output[] = "Introduce posicion (1-4): 5/7\n";
  assert_string_equal(expected_output, contenido);
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
  // Obtener el tamaño del archivo
  fseek(file, 0, SEEK_END);
  long tamaño = ftell(file);
  fseek(file, 0, SEEK_SET);
  // Asignar memoria para almacenar el contenido del archivo
  char *contenido = (char *)malloc(tamaño + 1);
  // Leer el archivo completo
  fread(contenido, 1, tamaño, file);
  // Cerrar el archivo
  fclose(file);
  // Restaura stdout
  remove("output.txt");
  dup2(stdout_original, STDOUT_FILENO);
  close(stdout_original);

  char expected_output[] = "Posicion 1: 3/4\nPosicion 2: 1/9\nPosicion 3: 5/7\nPosicion 4: 2/3\n";
  assert_string_equal(expected_output, contenido);
}

// Fraction calculator should show a real value
void la_calculadora_deberia_mostrar_un_valor_real(){
  printf("La calculadora debería mostrar un valor real: \n");

  int numeradores[MAX_FRACCIONES] = {3, 1, 5, 2};
  int denominadores[MAX_FRACCIONES] = {4, 9, 7, 3};
  int nFracciones = 4;
  FILE *user_input = fopen("test_user_input/5_show_real_value.txt", "r");

  int stdout_original = dup(STDOUT_FILENO);
  FILE *file = fopen("output.txt", "w");
  // Redirige stdout al archivo temporal
  dup2(fileno(file), fileno(stdout));
  fclose(file);

  stdin = user_input;
  opcion5(numeradores, denominadores, nFracciones);
  stdin = stdin;
  
  // Lee el contenido del archivo temporal
  file = fopen("output.txt", "r");
  // Obtener el tamaño del archivo
  fseek(file, 0, SEEK_END);
  long tamaño = ftell(file);
  fseek(file, 0, SEEK_SET);
  // Asignar memoria para almacenar el contenido del archivo
  char *contenido = (char *)malloc(tamaño + 1);
  // Leer el archivo completo
  fread(contenido, 1, tamaño, file);
  // Cerrar el archivo
  fclose(file);
  // Restaura stdout
  remove("output.txt");
  dup2(stdout_original, STDOUT_FILENO);
  close(stdout_original);

  char expected_output[] = "Introduce posicion (1-4): El valor real es 0.714286\n";
  assert_string_equal(expected_output, contenido);
}

// ToExplain: Principio de menor sorpresa
// Fraction calculator should simplify a fraction
void la_calculadora_deberia_simplificar_una_fraccion(){
  printf("La calculadora debería simplificar una fracción: \n");

  int numeradores[MAX_FRACCIONES] = {2};
  int denominadores[MAX_FRACCIONES] = {4};
  int nFracciones = 1;
  FILE *user_input = fopen("test_user_input/6_simplify_fraction.txt", "r");

  int stdout_original = dup(STDOUT_FILENO);
  FILE *file = fopen("output.txt", "w");
  // Redirige stdout al archivo temporal
  dup2(fileno(file), fileno(stdout));
  fclose(file);

  stdin = user_input;
  opcion6(numeradores, denominadores, &nFracciones);
  stdin = stdin;

  // Lee el contenido del archivo temporal
  file = fopen("output.txt", "r");
  // Obtener el tamaño del archivo
  fseek(file, 0, SEEK_END);
  long tamaño = ftell(file);
  fseek(file, 0, SEEK_SET);
  // Asignar memoria para almacenar el contenido del archivo
  char *contenido = (char *)malloc(tamaño + 1);
  // Leer el archivo completo
  fread(contenido, 1, tamaño, file);
  // Cerrar el archivo
  fclose(file);
  // Restaura stdout
  remove("output.txt");
  dup2(stdout_original, STDOUT_FILENO);
  close(stdout_original);

  char expected_output[] = "Introduce posicion (1-1): 1/2\n";
  assert_string_equal(expected_output, contenido);
  
  // assert(2, nFracciones);
  // int expected_numeradores[2] = {2, 1};
  // int expected_denominadores[2] = {4, 2};
  // for (int i = 0; i < nFracciones; i++) {
  //   assert(expected_numeradores[i], numeradores[i]);
  //   assert(expected_denominadores[i], denominadores[i]);
  // }
  
  fclose(user_input);
}

// Fraction calculator should add two fractions
void la_calculadora_deberia_sumar_dos_fracciones(){
  printf("La calculadora debería sumar dos fracciones: \n");

  int numeradores[MAX_FRACCIONES] = {3, 1, 5, 2};
  int denominadores[MAX_FRACCIONES] = {4, 9, 7, 3};
  int nFracciones = 4;
  FILE *user_input = fopen("test_user_input/7_add_two_fractions.txt", "r");

  int stdout_original = dup(STDOUT_FILENO);
  FILE *file = fopen("output.txt", "w");
  // Redirige stdout al archivo temporal
  dup2(fileno(file), fileno(stdout));
  fclose(file);

  stdin = user_input;
  opcion7(numeradores, denominadores, &nFracciones);
  stdin = stdin;

  // Lee el contenido del archivo temporal
  file = fopen("output.txt", "r");
  // Obtener el tamaño del archivo
  fseek(file, 0, SEEK_END);
  long tamaño = ftell(file);
  fseek(file, 0, SEEK_SET);
  // Asignar memoria para almacenar el contenido del archivo
  char *contenido = (char *)malloc(tamaño + 1);
  // Leer el archivo completo
  fread(contenido, 1, tamaño, file);
  // Cerrar el archivo
  fclose(file);
  // Restaura stdout
  remove("output.txt");
  dup2(stdout_original, STDOUT_FILENO);
  close(stdout_original);

  char expected_output[] = "Introduce posicion (1-4): Introduce posicion (1-4): 52/63\n";
  assert_string_equal(expected_output, contenido);
}

// Fraction calculator should subtract two fractions
void la_calculadora_deberia_restar_dos_fracciones(){
  printf("La calculadora debería restar dos fracciones: \n");

  int numeradores[MAX_FRACCIONES] = {3, 1, 5, 2};
  int denominadores[MAX_FRACCIONES] = {4, 9, 7, 3};
  int nFracciones = 4;
  FILE *user_input = fopen("test_user_input/8_subtract_two_fractions.txt", "r");

  int stdout_original = dup(STDOUT_FILENO);
  FILE *file = fopen("output.txt", "w");
  // Redirige stdout al archivo temporal
  dup2(fileno(file), fileno(stdout));
  fclose(file);

  stdin = user_input;
  opcion8(numeradores, denominadores, &nFracciones);
  stdin = stdin;

  // Lee el contenido del archivo temporal
  file = fopen("output.txt", "r");
  // Obtener el tamaño del archivo
  fseek(file, 0, SEEK_END);
  long tamaño = ftell(file);
  fseek(file, 0, SEEK_SET);
  // Asignar memoria para almacenar el contenido del archivo
  char *contenido = (char *)malloc(tamaño + 1);
  // Leer el archivo completo
  fread(contenido, 1, tamaño, file);
  // Cerrar el archivo
  fclose(file);
  // Restaura stdout
  remove("output.txt");
  dup2(stdout_original, STDOUT_FILENO);
  close(stdout_original);

  char expected_output[] = "Introduce posicion (1-4): Introduce posicion (1-4): 1/21\n";
  assert_string_equal(expected_output, contenido);
}

// Fraction calculator should multiply two fractions
void la_calculadora_deberia_multiplicar_dos_fracciones(){
  printf("La calculadora debería multiplicar dos fracciones: \n");

  int numeradores[MAX_FRACCIONES] = {3, 1, 5, 2};
  int denominadores[MAX_FRACCIONES] = {4, 9, 7, 3};
  int nFracciones = 4;
  FILE *user_input = fopen("test_user_input/9_multiply_two_fractions.txt", "r");

  int stdout_original = dup(STDOUT_FILENO);
  FILE *file = fopen("output.txt", "w");
  // Redirige stdout al archivo temporal
  dup2(fileno(file), fileno(stdout));
  fclose(file);

  stdin = user_input;
  opcion9(numeradores, denominadores, &nFracciones);
  stdin = stdin;

  // Lee el contenido del archivo temporal
  file = fopen("output.txt", "r");
  // Obtener el tamaño del archivo
  fseek(file, 0, SEEK_END);
  long tamaño = ftell(file);
  fseek(file, 0, SEEK_SET);
  // Asignar memoria para almacenar el contenido del archivo
  char *contenido = (char *)malloc(tamaño + 1);
  // Leer el archivo completo
  fread(contenido, 1, tamaño, file);
  // Cerrar el archivo
  fclose(file);
  // Restaura stdout
  remove("output.txt");
  dup2(stdout_original, STDOUT_FILENO);
  close(stdout_original);

  char expected_output[] = "Introduce posicion (1-4): Introduce posicion (1-4): 15/28\n";
  assert_string_equal(expected_output, contenido);
}

// Fraction calculator should divide two fractions
void la_calculadora_deberia_dividir_dos_fracciones(){
  printf("La calculadora debería dividir dos fracciones: \n");

  int numeradores[MAX_FRACCIONES] = {3, 1, 5, 2};
  int denominadores[MAX_FRACCIONES] = {4, 9, 7, 3};
  int nFracciones = 4;
  FILE *user_input = fopen("test_user_input/10_divide_two_fractions.txt", "r");

  int stdout_original = dup(STDOUT_FILENO);
  FILE *file = fopen("output.txt", "w");
  // Redirige stdout al archivo temporal
  dup2(fileno(file), fileno(stdout));
  fclose(file);

  stdin = user_input;
  opcion10(numeradores, denominadores, &nFracciones);
  stdin = stdin;

  // Lee el contenido del archivo temporal
  file = fopen("output.txt", "r");
  // Obtener el tamaño del archivo
  fseek(file, 0, SEEK_END);
  long tamaño = ftell(file);
  fseek(file, 0, SEEK_SET);
  // Asignar memoria para almacenar el contenido del archivo
  char *contenido = (char *)malloc(tamaño + 1);
  // Leer el archivo completo
  fread(contenido, 1, tamaño, file);
  // Cerrar el archivo
  fclose(file);
  // Restaura stdout
  remove("output.txt");
  dup2(stdout_original, STDOUT_FILENO);
  close(stdout_original);

  char expected_output[] = "Introduce posicion (1-4): Introduce posicion (1-4): 27/4\n";
  assert_string_equal(expected_output, contenido);
}

// Fraction calculator should display an error message when no fraction is stored
void la_calculadora_deberia_mostrar_un_mensaje_de_error_cuando_no_hay_fracciones_almacenadas(){
  printf("La calculadora debería mostrar un mensaje de error cuando no hay fracciones almacenadas: \n");

  int numeradores[MAX_FRACCIONES] = {};
  int denominadores[MAX_FRACCIONES] = {};
  int nFracciones = 0;

  int stdout_original = dup(STDOUT_FILENO);
  FILE *file = fopen("output.txt", "w");
  // Redirige stdout al archivo temporal
  dup2(fileno(file), fileno(stdout));
  fclose(file);

  opcion2(numeradores, denominadores, &nFracciones);
  opcion3(numeradores, denominadores, nFracciones);
  opcion4(numeradores, denominadores, nFracciones);
  opcion5(numeradores, denominadores, nFracciones);
  opcion6(numeradores, denominadores, &nFracciones);
  opcion7(numeradores, denominadores, &nFracciones);
  opcion8(numeradores, denominadores, &nFracciones);
  opcion9(numeradores, denominadores, &nFracciones);
  opcion10(numeradores, denominadores, &nFracciones);

  // Lee el contenido del archivo temporal
  file = fopen("output.txt", "r");
  // Obtener el tamaño del archivo
  fseek(file, 0, SEEK_END);
  long tamaño = ftell(file);
  fseek(file, 0, SEEK_SET);
  // Asignar memoria para almacenar el contenido del archivo
  char *contenido = (char *)malloc(tamaño + 1);
  // Leer el archivo completo
  fread(contenido, 1, tamaño, file);
  // Cerrar el archivo
  fclose(file);
  // Restaura stdout
  remove("output.txt");
  dup2(stdout_original, STDOUT_FILENO);
  close(stdout_original);

  char expected_output[10000];
  for (int i = 0; i < 9; i++) {
    strcat(expected_output, "No se ha podido realizar la operacion\n");
  }
  
  assert_string_equal(expected_output, contenido);
}

// Fraction calculator should display menu
void la_calculadora_deberia_mostrar_menu(){
  printf("La calculadora debería mostrar el menú: \n");

  int stdout_original = dup(STDOUT_FILENO);
  FILE *file = fopen("output.txt", "w");
  // Redirige stdout al archivo temporal
  dup2(fileno(file), fileno(stdout));
  fclose(file);

  stdin = fopen("test_user_input/11_show_menu.txt", "r");
  menu();
  stdin = stdin;

  // Lee el contenido del archivo temporal
  file = fopen("output.txt", "r");
  // Obtener el tamaño del archivo
  fseek(file, 0, SEEK_END);
  long tamaño = ftell(file);
  fseek(file, 0, SEEK_SET);
  // Asignar memoria para almacenar el contenido del archivo
  char *contenido = (char *)malloc(tamaño + 1);
  // Leer el archivo completo
  fread(contenido, 1, tamaño, file);
  // Cerrar el archivo
  fclose(file);
  // Restaura stdout
  remove("output.txt");
  dup2(stdout_original, STDOUT_FILENO);
  close(stdout_original);

  char expected_output[] = "\n1. Introducir fraccion\n2. Eliminar una fraccion\n3. Mostrar una fraccion\n4. Mostrar todas las fracciones almacenadas\n5. Mostrar valor real\n6. Simplificar fraccion\n7. Sumar fracciones\n8. Restar fracciones\n9. Multiplicar dos fracciones\n10. Dividir dos fracciones\n11. Salir\n";
  assert_string_equal(expected_output, contenido);
}

// Fraction calculator should show error message when an invalid option is selected
void la_calculadora_deberia_mostrar_un_mensaje_de_error_cuando_selecciona_una_opcion_invalida(){
  printf("La calculadora debería mostrar un mensaje de error cuando selecciona una opción inválida: \n");

  int stdout_original = dup(STDOUT_FILENO);
  FILE *file = fopen("output.txt", "w");
  // Redirige stdout al archivo temporal
  dup2(fileno(file), fileno(stdout));
  fclose(file);

  stdin = fopen("test_user_input/12_invalid_option.txt", "r");
  menu();
  stdin = stdin;

  // Lee el contenido del archivo temporal
  file = fopen("output.txt", "r");
  // Obtener el tamaño del archivo
  fseek(file, 0, SEEK_END);
  long tamaño = ftell(file);
  fseek(file, 0, SEEK_SET);
  // Asignar memoria para almacenar el contenido del archivo
  char *contenido = (char *)malloc(tamaño + 1);
  // Leer el archivo completo
  fread(contenido, 1, tamaño, file);
  // Cerrar el archivo
  fclose(file);
  // Restaura stdout
  remove("output.txt");
  dup2(stdout_original, STDOUT_FILENO);
  close(stdout_original);

  char expected_output[] = "\n1. Introducir fraccion\n2. Eliminar una fraccion\n3. Mostrar una fraccion\n4. Mostrar todas las fracciones almacenadas\n5. Mostrar valor real\n6. Simplificar fraccion\n7. Sumar fracciones\n8. Restar fracciones\n9. Multiplicar dos fracciones\n10. Dividir dos fracciones\n11. Salir\nIntroduzca una opcion: Opcion incorrecta\n\n1. Introducir fraccion\n2. Eliminar una fraccion\n3. Mostrar una fraccion\n4. Mostrar todas las fracciones almacenadas\n5. Mostrar valor real\n6. Simplificar fraccion\n7. Sumar fracciones\n8. Restar fracciones\n9. Multiplicar dos fracciones\n10. Dividir dos fracciones\n11. Salir\n";
  assert_string_equal(expected_output, contenido);
}

// Fraction calculator should display an error message when option inserted is nor numerical
void la_calculadora_deberia_mostrar_un_mensaje_de_error_cuando_la_opcion_insertada_no_es_numerica(){
  printf("La calculadora debería mostrar un mensaje de error cuando la opción insertada no es numérica: \n");

  int stdout_original = dup(STDOUT_FILENO);
  FILE *file = fopen("output.txt", "w");
  // Redirige stdout al archivo temporal
  dup2(fileno(file), fileno(stdout));
  fclose(file);

  stdin = fopen("test_user_input/13_non_numerical_option.txt", "r");
  menu();
  stdin = stdin;

  // Lee el contenido del archivo temporal
  file = fopen("output.txt", "r");
  // Obtener el tamaño del archivo
  fseek(file, 0, SEEK_END);
  long tamaño = ftell(file);
  fseek(file, 0, SEEK_SET);
  // Asignar memoria para almacenar el contenido del archivo
  char *contenido = (char *)malloc(tamaño + 1);
  // Leer el archivo completo
  fread(contenido, 1, tamaño, file);
  // Cerrar el archivo
  fclose(file);
  // Restaura stdout
  remove("output.txt");
  dup2(stdout_original, STDOUT_FILENO);
  close(stdout_original);

  char expected_output[] = "\n1. Introducir fraccion\n2. Eliminar una fraccion\n3. Mostrar una fraccion\n4. Mostrar todas las fracciones almacenadas\n5. Mostrar valor real\n6. Simplificar fraccion\n7. Sumar fracciones\n8. Restar fracciones\n9. Multiplicar dos fracciones\n10. Dividir dos fracciones\n11. Salir\nIntroduzca una opcion: Opcion incorrecta\n\n1. Introducir fraccion\n2. Eliminar una fraccion\n3. Mostrar una fraccion\n4. Mostrar todas las fracciones almacenadas\n5. Mostrar valor real\n6. Simplificar fraccion\n7. Sumar fracciones\n8. Restar fracciones\n9. Multiplicar dos fracciones\n10. Dividir dos fracciones\n11. Salir\n";
  assert_string_equal(expected_output, contenido);
}

int main() {
    la_calculadora_deberia_almacenar_una_fraccion();
    la_calculadora_deberia_eliminar_una_fraccion();
    la_calculadora_deberia_mostrar_una_fraccion();
    la_calculadora_deberia_mostrar_todas_las_fracciones();
    la_calculadora_deberia_mostrar_un_valor_real();
    la_calculadora_deberia_simplificar_una_fraccion();
    la_calculadora_deberia_sumar_dos_fracciones();
    la_calculadora_deberia_restar_dos_fracciones();
    la_calculadora_deberia_multiplicar_dos_fracciones();
    la_calculadora_deberia_dividir_dos_fracciones();
    la_calculadora_deberia_mostrar_un_mensaje_de_error_cuando_no_hay_fracciones_almacenadas();
    la_calculadora_deberia_mostrar_menu();
    la_calculadora_deberia_mostrar_un_mensaje_de_error_cuando_selecciona_una_opcion_invalida();
    la_calculadora_deberia_mostrar_un_mensaje_de_error_cuando_la_opcion_insertada_no_es_numerica();

    return 0;
}
