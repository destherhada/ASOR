//Practica 2.1 -- Ejercicio 1 -- Esther Babon y Claudia Lopez-Mingo

#include <unistd.h>
#include <stdio.h>
#include <errno.h>

int main() {
    if (setuid(0) == -1){
        perror("Error");
    }
    return 1;
}
