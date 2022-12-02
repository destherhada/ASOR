//Practica 2.3 -- Ejercicio 12 -- Esther Babon Arcauz y Claudia Lopez-Mingo Moreno
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

volatile int int_count = 0;
volatile int tstp_count = 0;

void hler(int senial){
  if (senial == SIGINT) int_count++;
  if (senial == SIGTSTP) tstp_count++;
}

int main(){

    struct sigaction a;

    sigaction(SIGINT, NULL, &a); 
    a.sa_handler = hler;
    sigaction(SIGINT, &a, NULL); 
   
    sigaction(SIGTSTP, NULL, &a); 
    a.sa_handler = hler;
    sigaction(SIGTSTP, &a, NULL); 

    sigset_t set;
	sigemptyset(&set);

	while (int_count + tstp_count < 10)
		sigsuspend(&set);

	printf("Numero de señales tipo SIGINT capturadas: %i\n", int_count);
	printf("Numero de señales tipo SIGTSTP capturadas: %i\n", tstp_count);

  return 1;
}
