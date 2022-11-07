//Practica 2.1 -- Ejercicio 4 -- Esther Babon y Claudia Lopez-Mingo

#include <sys/utsname.h>
#include <stdio.h>

int main() {
    struct utsname buf;
    uname(&buf);     //La información del sistema queda almacenada en buf
    printf("Sysname: %s\n", buf.sysname);
    printf("Nodename: %s\n", buf.nodename);
    printf("Release: %s\n", buf.release);
    printf("Version: %s\n", buf.version);
    printf("DomainName: %s\n", buf.__domainname);
    printf("Machine: %s\n", buf.machine);
    return 1;
}
