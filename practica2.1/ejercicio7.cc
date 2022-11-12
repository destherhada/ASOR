//Practica 2.1 -- Ejercicio 7 -- Esther Babon y Claudia Lopez-Mingo
#include <unistd.h>
#include <stdio.h>

int main(){

    printf("Numero maximo de enlaces: %li\n", pathconf(".", _PC_LINK_MAX));
    printf("Longitud maxima de la ruta: %li\n", pathconf(".", _PC_PATH_MAX));
    printf("Longitud maxima del nombre de fichero: %li\n", pathconf(".", _PC_NAME_MAX));

    return 1;
}
