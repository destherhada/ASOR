//Practica 2.3 -- Ejercicio 7 System -- Esther Babon Arcauz y Claudia Lopez-Mingo Moreno
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//funciona de la misma manera para las opciones: ./ej7 ps -el y ./ej7 “ps -el”

int main(int argc, char **argv){

    int length = 1;
    for(int i = 1; i < argc; i++){
        length += strlen(argv[i]) + 1;
    }

    char *command = (char *)malloc(sizeof(char) * length);
    strcpy(command, "");

    for (int i = 1; i < argc; i++){
        strcat(command, argv[i]);
        strcat(command, " ");
    }

    system(command);
    printf("El comando termino de ejecutarse.");

    return 1;
}
