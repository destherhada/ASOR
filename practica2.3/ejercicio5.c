//Práctica 2.3 -- Ejercicio 3 -- Esther Babon Arcauz y Claudia Lopez-Mingo Morenp
#include <sched.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <stdio.h>
#include <unistd.h>

int main(){
    pid_t pid = getpid();
    pid_t ppid = getppid();
    pid_t pgid = getpgid(pid);
    pid_t sid = getsid(pid);
    char ruta;
    getcwd(ruta, 1024);

    return 1;
}
