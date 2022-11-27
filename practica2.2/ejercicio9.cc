//Practica 2.2 -- Ejercicio 9 -- Esther Babon Arcauz y Claudia Lopez-Mingo Moreno
#include <stdio.h>
#include <sys/stat.h>
#include <sys/sysmacros.h>
#include <time.h>

int main(int argc, char **argv) {

	struct stat buff;
	int statint = stat(argv[1], &buff);
	
	if (argc < 2) {
		 printf("ERROR: Especifica la ruta del archivo en los parámetros del programa.\n");
		 return -1;
	}

	if (statint == -1) {
		printf("ERROR: No existe el directorio.\n");
		return -1;
	}

	printf("El numero MAJOR asociado al dispositivo: %li\n", (long) minor(buff.st_dev));
	printf("El numero MINOR asociado al dispositivo: %li\n", (long) major(buff.st_dev));
	printf("El numero de inodo del fichero: %li\n",buff.st_ino);


	mode_t mode = buff.st_mode;
    if (S_ISDIR(mode)) {
		printf("%s es un directorio.\n", argv[1]);
	}
	else if (S_ISLNK(mode)){
		printf("%s es un enlace simbólico.\n", argv[1]);
	} 
	else if (S_ISREG(mode)) {
		printf("%s es un archivo ordinario.\n", argv[1]);
	} 


	time_t t = buff.st_atime;
	struct tm *tm1= localtime(&t);
	printf("El ultimo acceso ha sido a las: %d:%d\n", tm1->tm_hour, tm1->tm_min);

	return 1;
}
