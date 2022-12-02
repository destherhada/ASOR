//Practica 2.3 -- Ejercicio 11-- Esther Babon Arcauz y Claudia Lopez-Mingo Moreno
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

//export SLEEP_SECS="120"

int main(int argc, char **argv) {

  sigset_t set;
  sigemptyset(&set);
  sigaddset(&set, SIGINT);
  sigaddset(&set, SIGTSTP);

  sleep(120);

  sigset_t pending;
  sigpending(&pending);

  if (sigismember(&pending, SIGINT) == 1){
    printf("Se ha recibido la señal SIGINT\n");
    sigdelset(&set, SIGINT);
  } 

  else {
      printf("No se ha recibido la señal SIGINT\n");
  }

  if (sigismember(&pending, SIGTSTP) == 1) {
    printf("Se ha recibido la señal SIGTSTP\n");
    sigdelset(&set, SIGTSTP);
  } 
  else {
    printf("No se ha recibido la señal SIGTSTP\n");
  }

  sigprocmask(SIG_UNBLOCK, &set, NULL);

  return 1;
}
