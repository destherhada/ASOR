//Practica 2.4 -- Ejercicio 5 -- Esther Babon Arcauz y Claudia Lopez-Mingo Moreno
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/select.h>



int main(){

    mkfifo("tuberia1", 0644);
    mkfifo("tuberia2", 0644);
    char buffer[513];

    int tub1 = open("./tuberia1", O_RDONLY | O_NONBLOCK);
    int tub2 = open("./tuberia2", O_RDONLY | O_NONBLOCK);
    int cambios, tubactual, numtub;

    while (cambios != -1 ) {
        fd_set conjunto;
        FD_ZERO(&conjunto);
        FD_SET(tub1, &conjunto);
        FD_SET(tub2, &conjunto);

        cambios = select((tub1 < tub2) ? tub2 + 1 : tub1 + 1, &conjunto, NULL,NULL,NULL);

        if (cambios > 0){
        if (FD_ISSET(tub1, &conjunto)) {
            numtub = 1;
            tubactual = tub1;
        } 
        else if (FD_ISSET(tub2, &conjunto)) {
            numtub = 2;
            tubactual = tub2;
        }

        ssize_t readsize = 256;
		while (readsize == 256) {
			readsize = read(tubactual, buffer, 256);
			buffer[readsize] = '\0';
			printf("Tuberia %i: %s", numtub, buffer);
		}

        if (readsize != 256 && numtub == 1) {
        close(tub1);
        tub1 = open("./tuberia1", O_RDONLY | O_NONBLOCK);
			if (tub1 == -1) {
				perror("No se pudo abrir la segunda tuberia");
				close(tub1);
				close(tub2);
				return -1;
				}
        }
        else if(readsize != 256 && numtub == 2) {
        close(tub2);
        tub2 = open("./tuberia2", O_RDONLY | O_NONBLOCK);
				if (tub1 == -1) {
					perror("No se pudo abrir la segunda tuberia");
					close(tub1);
					close(tub2);
					return -1;
				}
      }
        }}

  close(tub1);
  close(tub2);

  return 0;
}
