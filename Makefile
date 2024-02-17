.PHONY: run_program clean

run_program:
	gcc main.c fracciones.c es.c -o executable & ./executable

clean:
	rm -f executable