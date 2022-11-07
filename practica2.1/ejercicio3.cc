//Practica 2.1 -- Ejercicio 3 -- Esther Babon y Claudia Lopez-Mingo

#include <stdio.h>
#include <string.h>

int main() {
    for (int i = 0; i < 255; i++){
         printf("ERROR(%d): %s\n", i, strerror(i));
    }
    return 1;
}
