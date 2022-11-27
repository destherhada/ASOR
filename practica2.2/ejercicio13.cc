//Practica 2.2 -- Ejercicio 13 -- Esther Babon Arcauz y Claudia Lopez-Mingo Moreno
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>


int main(int argc, char **argv) {

    char *e;

    if (argc < 2) {
		 printf("ERROR: Especefica la ruta del archivo en los parámetros del programa.\n");
		 return -1;
	}


    int fd = open(argv[1], O_RDWR);
    if (fd == -1) {
        printf("ERROR: No se ha podido abrir el fichero.\n");
    }

    
    int fd2 = dup2(fd, 1);

	if (setuid(0) == -1){
		 perror(e);
	}
	
    dup2(fd2, fd);

    return 1;
}
