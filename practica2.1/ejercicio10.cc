//Practica 2.1 -- Ejercicio 10 -- Esther Babon y Claudia Lopez-Mingo
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <pwd.h>

int main(){
    struct passwd *pass;
    pass = getpwuid(getuid());

    printf("UID: %d\n", getuid());
    printf("EUID: %d\n", geteuid());
    printf("Nombre de usuario: %s\n", pass->pw_name);
    printf("Directorio home: %s\n", pass->pw_dir);
    printf("Descripcion del usuario: %s\n", pass->pw_gecos);

    return 1;
}
