//Practica 2.1 -- Ejercicio 2 -- Esther Babon y Claudia Lopez-Mingo

#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

int main() {
    if (setuid(0) == -1){
        printf("ERROR(%d): %s\n", errno, strerror(errno));
    }
    return 1;
}
