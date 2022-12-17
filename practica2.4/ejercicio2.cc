//Practica 2.4 -- Ejercicio 2 -- Esther Babon Arcauz y Claudia Lopez-Mingo Moreno
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>


int main(){

    int p_h[2];
    int h_p[2];
    pipe(p_h);
    pipe(h_p);
    char pmsg[1] = {'l'};

    switch (fork()){
        case 0:
            close(p_h[1]);
            close(h_p[0]);
            char rmsg[1025];
            
            for(int i = 0; i < 10; i++){
                ssize_t size = read(p_h[0], rmsg, 1024);
                rmsg[size] = '\0';
                printf("[Hijo] Mensaje : %s", rmsg);
                sleep(1);

                if(i == 9){
                    pmsg[0] = 'q';
                }
                size = write(h_p[1], pmsg, 1);
            }
            close(p_h[0]);
            close(h_p[1]);
            exit(0);
            break;


        default:
            close(p_h[0]);
            close(h_p[1]);
            char msg[1025];
            char cmsg[1] = {'l'};

            while (cmsg[0] != 'q'){
                printf("[Padre] Escribe nuevo mensaje: \n");
                ssize_t psize = read(0, msg, 1024);
                msg[psize] = '\0';
                psize = write(p_h[1], msg, psize + 1);
                if (psize == -1) {
					perror("[Padre] Error al escribir en la tuberia");
					exit(-1);
				}
                while (cmsg[0] != 'l' && cmsg[0] != 'q') {
					psize = read(h_p[0], cmsg, 1);
				}
            }
            close(p_h[1]);
			close(h_p[0]);
            exit(0);
    }

  return 0;
}
