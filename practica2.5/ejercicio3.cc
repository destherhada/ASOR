//Practica 2.5 -- Ejercicio 3 -- Esther Babon Arcauz y Claudia Lopez-Mingo Moreno

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>

int main (int argc, char**argv) {

    struct addrinfo hints;
    struct addrinfo *res;
    memset(&hints, 0, sizeof(struct addrinfo));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_DGRAM;
    hints.ai_flags = AI_PASSIVE;

    if (getaddrinfo(argv[1], argv[2], &hints, &res) != 0) {
        printf("Error getaddrinfo(): Name or service not known");
        exit(-1);
    }

    int socketUDP = socket(res->ai_family, res->ai_socktype, res->ai_protocol);

    freeaddrinfo(res);

    char buf[2];
    char host[NI_MAXHOST];
    char serv[NI_MAXSERV];

    struct sockaddr_storage client_addr;
    socklen_t client_addrlen = sizeof(client_addr);

    sendto(socketUDP, argv[3], 2, 0, res->ai_addr, res->ai_addrlen);

    printf("%s\n", argv[3]);

    if (*argv[3] == 'd' || *argv[3] == 't'){
        char s[50];
        ssize_t bytes = recvfrom(socketUDP, s, 50, 0, (struct sockaddr *) &client_addr, &client_addrlen);
        s[bytes] = '\0';
        printf("%s\n", s);
    }
    
    return 0;
}
