//Practica 2.2 -- Ejercicio 11 -- Esther Babon Arcauz y Claudia Lopez-Mingo Moreno
#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char **argv) {

	struct stat buff;
	int statint = stat(argv[1], &buff);
	
	if (argc < 2) {
		 printf("ERROR: Especifica la ruta del archivo en los parámetros del programa.\n");
		 return -1;
	}

	if (statint == -1) {
		printf("ERROR: No existe el archivo.\n");
		return -1;
	}


    char* hard = malloc(sizeof(char)*(5 + strlen(argv[1])));
	char* sym = malloc(sizeof(char)*(5 + strlen(argv[1])));
	strcpy(hard, argv[1]);
	strcpy(sym, argv[1]);


	mode_t mode = buff.st_mode;

	if (S_ISREG(mode)) {
	    link(argv[1], strcat(hard, ".hard"));
	    symlink(argv[1], strcat(sym, ".sym"));
	} 
	
	return 1;
}
