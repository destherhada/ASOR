//Práctica 2.3 -- Ejercicio 5 -- Esther Babon Arcauz y Claudia Lopez-Mingo Moreno
#include <sched.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(){
    pid_t pid = getpid();
    pid_t ppid = getppid();
    pid_t pgid = getpgid(pid);
    pid_t sid = getsid(pid);
    char *ruta = malloc(sizeof(char)*(2048));
    getcwd(ruta, 2048);
    struct rlimit limit;
    getrlimit(RLIMIT_NOFILE, &limit);

    printf("PID: %i\n", pid);
    printf("PPID: %i\n", ppid);
    printf("PGID: %i\n", pgid);
    printf("SID: %i\n", sid);
    printf("Directorio de trabajo actual: %s\n", ruta);
    printf("Número máximo de ficheros: %li\n", limit.rlim_max);

    return 1;
}
