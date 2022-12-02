//Practica 2.3 -- Ejercicio 13 -- Esther Babon Arcauz y Claudia Lopez-Mingo Moreno
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

volatile int stop = 0;

void hler(int senial){
  if (senial == SIGUSR1) stop = 1;
}

int main(int argc, char **argv) {

    sigset_t mask;
    sigemptyset(&mask);
    sigaddset(&mask, SIGUSR1);
    sigprocmask(SIG_UNBLOCK, &mask, NULL);

    struct sigaction act;
    sigaction(SIGUSR1, NULL, &act);
    act.sa_handler = hler;
    sigaction(SIGUSR1, &act, NULL); 

    int segundos = atoi(argv[1]);
    printf("Se va a borrar el ejecutable en: %i segundos\n", segundos);
    printf("Para detener el borrado manda una señar SIGUSR1 al proceso");

    int i = 0;
    while (i < segundos && stop == 0) {
        i++;
        sleep(1);
    }

    if (stop == 0) {
        printf("Se ha borrado el ejecutable tras: %i segundos\n", segundos);
        unlink(argv[0]);
    } 
    else {
        printf("Has detenido el borrado del ejecutable");
    }

  return 1;
}
