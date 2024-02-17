.PHONY: run_program clean

run_program:
	gcc main.c fracciones.c es.c -o executable & ./executable

run_parallel_change:
	gcc main_copy.c fracciones.c es.c interfaz.c -o executable_copy & ./executable_copy

clean:
	rm -f executable

clean_parallel_change:
	rm -f ./executable_copy