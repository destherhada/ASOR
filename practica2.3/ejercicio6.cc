//ASOR -- PRACTICA 2.3 -- EJERCICIO 6 -- ESTHER BABON ARCAUZ Y CLAUDIA LOPEZ-MINGO MORENO
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sched.h>
#include <sys/time.h>
#include <sys/resource.h>

/*
Cuando el proceso padre termina antes que el hijo (Sin sleep(100)), el pid del padre se  pone a 1, cuando el proceso hijo termina antes el pid del padre se 
mantiene en el valor original.*/
int main(){

    pid_t pid;
    pid = fork();
    pid_t mi_sid;
    pid_t ppid;
    pid_t pgid;
    pid_t sid;
    char *ruta;
    struct rlimit limit;

    switch (pid){
        case -1:
            perror("fork");
            exit(1);

        case 0:
            mi_sid = setsid();
            chdir("/tmp");
            printf("[Hijo] Proceso %i (Padre: %i)\n",getpid(),getppid());
            pid = getpid();
            ppid = getppid();
            pgid = getpgid(pid);
            sid = getsid(pid);
            ruta = (char *)malloc(2048);
            getcwd(ruta, 2048);
            getrlimit(RLIMIT_NOFILE, &limit);
            printf("Datos del proceso hijo: ");
            printf("PID: %i\n", pid);
            printf("PPID: %i\n", ppid);
            printf("PGID: %i\n", pgid);
            printf("SID: %i\n", sid);
            printf("Directorio de trabajo actual: %s\n", ruta);
            printf("Número máximo de ficheros: %li\n", limit.rlim_max);
        
            break;

        default:
            printf("[Padre] Proceso %i (Padre: %i)\n",getpid(),getppid());
            pid = getpid();
            ppid = getppid();
            pgid = getpgid(pid);
            sid = getsid(pid);
            ruta = (char *)malloc(2048);
            getcwd(ruta, 2048);
            limit;
            getrlimit(RLIMIT_NOFILE, &limit);
            printf("Datos del proceso padre: ");
            printf("PID: %i\n", pid);
            printf("PPID: %i\n", ppid);
            printf("PGID: %i\n", pgid);
            printf("SID: %i\n", sid);
            printf("Directorio de trabajo actual: %s\n", ruta);
            printf("Número máximo de ficheros: %li\n", limit.rlim_max);
            //sleep(100);
            break;
    }


    return 1;
}
