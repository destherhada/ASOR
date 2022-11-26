
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(){
    mode_t prev = umask(027); // 027
  
    open("/home/cursoredes/Desktop/practica2.1/prueba5.txt", O_CREAT, 0645);

    return 1;
}
