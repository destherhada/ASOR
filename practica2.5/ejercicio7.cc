// Practica 2.5 -- ejercicio 7 -- Esther Babon Arcauz y Claudia Lopez-Mingo Moreno
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>

int main(int argc, char **argv){

  
    struct addrinfo hints;
    struct addrinfo *result;

    char bufin[256];
    char bufout[256];
    char host[NI_MAXHOST];
    char serv[NI_MAXSERV];
    ssize_t c;

    memset(&hints,0,sizeof(struct addrinfo));
    hints.ai_family = AF_UNSPEC; 
    hints.ai_socktype = SOCK_STREAM; 
    hints.ai_flags = AI_PASSIVE;

    int socketTCP = socket(result->ai_family, result->ai_socktype, 0);
    connect(socketTCP,(struct sockaddr *)result->ai_addr, result->ai_addrlen);
    freeaddrinfo(result);


    while (1) {
        c = read(0,bufout, 255);
        bufout[c] = '\0';
        send(socketTCP,bufout, c, 0);


        if ((bufout[1] == 'q') && (c == 2)) {
        printf("Conexión terminada\n");
        break;
        }

        c = recv(socketTCP, bufin, 255, 0);
        bufin[c] = '\0';
        printf("[OUT]:%s\n", bufin);
    }

    close(socketTCP);

    
    return 1;
}
