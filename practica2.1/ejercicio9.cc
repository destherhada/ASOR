//Practica 2.1 -- Ejercicio 9 -- Esther Babon y Claudia Lopez-Mingo
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>

int main(){
    printf("UID: %d\n", getuid());
    printf("EUID: %d\n", geteuid());
    //si getuid y geteuid nos dan valores diferentes, entonces esta activado el bit setuid

    return 1;
}
