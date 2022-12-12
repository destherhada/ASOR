#include <unistd.h>


int main(int argc, char **argv){
    /*argv -- 1 = comando1
              2 = argumento1
              3 = comando2
              4 = argumento2*/

    int tub = pipe(int fd[2]); //crear tuberia

    switch (fork()) {
    case 0:
      dup(fd[0],0);
      close(fd[1]);
      close(fd[0]);
      printf("Ejecuto el hijo (comando2 argumento2)");
      execlp(argc[3],argc[3],argc[4]);
    break;
    default:
      dup(fd[1],1);
      close(fd[1]);
      close(fd[0]);
      printf("Ejecuto el padre (comando1 argumento1)");
      execlp(argc[1],argc[1],argc[2]);
    break;
  }
    return 1;
}
