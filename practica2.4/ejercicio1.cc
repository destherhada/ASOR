//Practica 2.4 -- Ejercicio 1 -- Esther Babon Arcauz y Claudia Lopez-Mingo Moreno
#include <stdio.h>
#include <unistd.h>
#include <errno.h>

int main(int argc, char **argv){
    /*argv -- 1 = comando1
              2 = argumento1
              3 = comando2
              4 = argumento2*/

    int fd[2];
    int tub = pipe(fd); //crear tuberia

    switch (fork()) {
        case 0:
            close(fd[1]);
            dup2(fd[0],0);
            close(fd[0]);
            execlp(argv[3],argv[3],argv[4], NULL);
            break;
        default:
            close(fd[0]);
            dup2(fd[1],1);
            close(fd[1]);
            execlp(argv[1],argv[1],argv[2], NULL);
            break;
  }
    return 1;
}
