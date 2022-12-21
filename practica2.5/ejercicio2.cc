//Practica 2.5 -- Ejercicio 1 -- Esther Babon Arcauz y Claudia Lopez-Mingo Moreno

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <time.h>


int main (int argc, char**argv) {

    struct addrinfo hints;
    struct addrinfo *res, *ite;

    memset(&hints, 0, sizeof(struct addrinfo));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_DGRAM;
    hints.ai_flags = AI_PASSIVE;

    if (getaddrinfo(argv[1], argv[2], &hints, &res) != 0) {
        printf("Error getaddrinfo(): Name or service not known");
        exit(-1);
    }

    int socketUDP = socket(res->ai_family, res->ai_socktype, res->ai_protocol);

    if (bind(socketUDP, res->ai_addr, res->ai_addrlen) != 0) {
        printf("ERROR: No se ha podido ejecutar el bind.");
        exit(EXIT_FAILURE);
    }

    freeaddrinfo(res);

    char buf[2];
    char host[NI_MAXHOST];
    char servi[NI_MAXSERV];
    struct sockaddr_storage client_addr;
    socklen_t client_addrlen = sizeof(client_addr);

    while(1){
        ssize_t bytes = recvfrom(socketUDP, buf, 2, 0, (struct sockaddr *) &client_addr, &client_addrlen);
        buf[1] = '\0';

        getnameinfo((struct sockaddr *) &client_addr, client_addrlen, host, NI_MAXHOST, servi, NI_MAXSERV, NI_NUMERICHOST|NI_NUMERICSERV);

        printf("%i byte(s) de %s:%s\n", bytes, host, servi);
        time_t tiempo = time(NULL);
        struct tm *tm = localtime(&tiempo);
        size_t max;
        char s[50];

        if (buf[0] == 't'){
            size_t bytesT = strftime(s, max, "%I:%M:%S %p", tm);
            s[bytesT] = '\0';
            sendto(socketUDP, s, bytesT, 0, (struct sockaddr *) &client_addr, client_addrlen);
        }else if (buf[0] =='d'){
            size_t bytesT = strftime(s, max, "%Y-%m-%d", tm);
            s[bytesT] = '\0';
            sendto(socketUDP, s, bytesT, 0, (struct sockaddr *) &client_addr, client_addrlen);
        }else if (buf[0] =='q'){
            printf("Saliendo...\n");
            exit(0);
        }else{
            printf("Comando no soportado: %d...\n", buf[0]);
        }
    }
    return 0;
}
