//practica 2.5 -- ejercicio 8 -- Esther Babon Arcauz y Claudia Lopez-Mingo Moreno
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>

int main(int argc, char **argv){

    pid_t pid;
    struct addrinfo hints;
    struct addrinfo *result;
    struct sockaddr_storage cli;
    socklen_t clen = sizeof(cli);
    char buf[81];
    int cli_sd;
    char host[NI_MAXHOST];
    char serv[NI_MAXSERV];
    ssize_t c;

    memset(&hints,0,sizeof(struct addrinfo));
    hints.ai_family = AF_UNSPEC; 
    hints.ai_socktype = SOCK_STREAM; 
    hints.ai_flags = AI_PASSIVE;

    int socketTCP = socket(result->ai_family, result->ai_socktype, 0);
    bind(socketTCP, result->ai_addr, result->ai_addrlen);
    freeaddrinfo(result);
    listen(socketTCP, 5);

    while (1) {

        cli_sd = accept(socketTCP,(struct sockaddr *) &cli, &clen);
        pid = fork();

        if (pid == 0) {
        while (1) {

            getnameinfo((struct sockaddr *)&cli, clen, host, NI_MAXHOST, serv, NI_MAXSERV, NI_NUMERICHOST);
            printf("[PID: %i] Conexión desde %s:%s\n", getpid(), host, serv);

            c = recv(cli_sd, buf, 80, 0);
            buf[c] = '\0';
            if ((buf[0] == 'Q') && (c == 2)) {
            printf("Conexión terminada\n");
            break;
            }

            send(cli_sd, buf, c, 0);
        }

        close(cli_sd);

        } 
        else {
        close(cli_sd);
        }
    }

    return 1;
}
