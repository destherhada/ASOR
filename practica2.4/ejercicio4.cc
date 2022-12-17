//Practica 2.4 -- Ejercicio 4 -- Esther Babon Arcauz y Claudia Lopez-Mingo Moreno
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>



int main(int argc, char **argv){

    mkfifo("./tuberia", 0777);
    int tub = open("./tuberia", O_WRONLY);
    size_t len = strlen(argv[1]);
    ssize_t w = write(tub, argv[1], len);
    close(tub);


  return 0;
}
