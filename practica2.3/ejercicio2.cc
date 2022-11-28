//Practica 2.3 -- Ejercicio2 -- Esther Babon Arcauz y Claudia Lopez-Mingo Moreno 
#include <sched.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <stdio.h>

//Para que funcione en el ejercicio 3, pasamos el pid del proceso por parametro
//int main(int argc, char **argv){

int main(){
    
    //int pid = atoi(argv[1]);

    const char *sched_policies[] = {
    "SCHED_NORMAL",
    "SCHED_FIFO",
    "SCHED_RR",
    "SCHED_BATCH",
    "SCHED_IDLE",
    "SCHED_DEADLINE"
    };

    struct sched_param p;

    //donde se pasa 0 habria que pasar pid
    int politica = sched_getscheduler(0);
    printf("La politica de planificacion del proceso actual es: %s\n", sched_policies[politica]);
    sched_getparam(0, &p);
    printf("La prioridad de planificacion del proceso es: %i\n", p.sched_priority);
    //int prioridad = getpriority(PRIO_PROCESS, 0);
    //printf("La prioridad de planificacion del proceso es: %i\n", prioridad);   
    int maximo = sched_get_priority_max(politica);
    int minimo = sched_get_priority_min(politica);
    printf("El valor maximo de la prioridad puede ser: %i\n", maximo);
    printf("El valor minimo de la prioridad puede ser: %i\n",  minimo);


    return 1;
}
