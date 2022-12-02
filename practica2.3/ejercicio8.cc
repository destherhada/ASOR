//Practica 2.3 -- Ejercicio 8-- Esther Babon Arcauz y Claudia Lopez-Mingo Moreno
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sched.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <fcntl.h>


int main(int argc, char **argv){


    pid_t pid = fork();
    pid_t mi_sid;
    int fd;
    int fd2;
    int fd3;
    int fd4;

    switch (pid){
        case -1:
            perror("fork");
            exit(1);

        case 0:
            mi_sid = setsid(); //Creamos una nueva sesión
            printf("[Hijo] Proceso %i (Padre: %i)\n",getpid(),getppid());
            fd = open("/tmp/daemon.out", O_CREAT | O_RDWR, 00777);
            fd2 = dup2(fd,1);
            fd = open("/tmp/daemon.err", O_CREAT | O_RDWR, 00777);
            fd3 = dup2(fd, 2);
            fd = open("/dev/null", O_CREAT | O_RDWR, 00777);
            fd4 = dup2(fd, 0);
            if (execvp(argv[1], argv + 1) == -1) {
                printf("ERROR: No se ha ejecutado correctamente.\n");
                exit(-1);
            }
            break;
        default:
            printf("[Padre] Proceso %i (Padre: %i)\n",getpid(),getppid());
        break;

    }
    return 1;
}


