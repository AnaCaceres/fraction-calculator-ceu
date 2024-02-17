.PHONY: run_program clean

run_program:
	gcc main.c fracciones.c es.c interfaz.c -o executable & ./executable

clean:
	rm -f executable