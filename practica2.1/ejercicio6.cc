//Practica 2.1 -- Ejercicio 6 -- Esther Babon y Claudia Lopez-Mingo
#include <unistd.h>
#include <stdio.h>

int main(){
    printf("Longitud maxima de argumentos: %li\n", sysconf(_SC_ARG_MAX));
    printf("Numero maximo de hijos: %li\n", sysconf(_SC_CHILD_MAX));
    printf("Numero maximo de ficheros abiertos: %li\n", sysconf(_SC_OPEN_MAX));

    return 1;
}
