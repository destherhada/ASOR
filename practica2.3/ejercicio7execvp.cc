//Practica 2.3 -- Ejercicio 7 execvp -- Esther Babon Arcauz y Claudia Lopez-Mingo Moreno
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

/*
si ejecutamos con: ./ej7 ps -el funciona perfectamente pero si ejecutamos con
./ej7 “ps -el” el comando "ps -el"  no se ejecuta
*/

int main(int argc, char **argv){


    execvp(argv[1], argv + 1);
    printf("El comando termino de ejecutarse.");

    return 1;
}

