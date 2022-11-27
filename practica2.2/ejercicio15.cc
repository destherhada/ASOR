//Practica 2.2 -- Ejercicio 15 -- Esther Babon Arcauz y Claudia Lopez-Mingo Moreno
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <time.h>
#include <string.h>

int main(int argc, char ** argv) {

    char *e;
    
    if (argc < 2) {
        printf("ERROR: Especefica la ruta del archivo en los parámetros del programa.\n");
        return -1;
    }

    int fd = open(argv[1], O_RDWR);
    
    if (fd == -1) {
        printf("ERROR: No se ha podido abrir el fichero.\n");
        return -1;
    }

    struct flock lock;

    lock.l_type = F_UNLCK;
    lock.l_whence = SEEK_SET;
    lock.l_start = 0;
    lock.l_len = 0;
    lock.l_pid = getpid();


    int status = fcntl(fd, F_GETLK, &lock);

    if (lock.l_type == F_UNLCK) {
        
        lock.l_type = F_RDLCK;
        lock.l_whence = SEEK_SET;
        lock.l_start = 0;
        lock.l_len = 0;
        lock.l_pid = getpid();
    }

    if (fcntl(fd, F_GETLK, &lock) != -1) {
        
        //si consigue bloquear el fichero muestra la hora actual
        time_t tim = time(NULL);
        struct tm *tm = localtime(&tim);
        printf("Hora: %d:%d\n", tm->tm_hour, tm->tm_min);
        
        //suspende su ejecucion
        sleep(10);
        
        //desbloquea 
        lock.l_type = F_UNLCK;
        lock.l_whence = SEEK_SET;
        lock.l_start = 0;
        lock.l_len = 0;
        lock.l_pid = getpid();
        
        //suspende su ejecucion
        sleep(10);
        
        // y termina
        close(fd);
    }
    

    else if (fcntl(fd, F_GETLK, &lock) == -1){
        perror(e);
    }

    return 1;
}
