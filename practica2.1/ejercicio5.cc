//Practica 2.1 -- Ejercicio 5 -- Esther Babon y Claudia Lopez-Mingo
#include <sys/utsname.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>


int main() {
    struct utsname buf;
    if(uname(&buf) == -1){
      printf("ERROR(%d): %s\n", errno, strerror(errno));  
    }
    printf("Sysname: %s\n", buf.sysname);
    printf("Nodename: %s\n", buf.nodename);
    printf("Release: %s\n", buf.release);
    printf("Version: %s\n", buf.version);
    printf("DomainName: %s\n", buf.__domainname);
    printf("Machine: %s\n", buf.machine);
    return 1;
}
