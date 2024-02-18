.PHONY: run_program clean

run_program:
	gcc main.c fracciones.c es.c interfaz.c -o executable && ./executable

run_tests:
	gcc test.c fracciones.c es.c interfaz.c -o tests && ./tests

clean:
	rm -f executable

clean_tests:
	rm -f tests