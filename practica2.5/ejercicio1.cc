//Practica 2.5 -- Ejercicio 1 -- Esther Babon Arcauz y Claudia Lopez-Mingo Moreno
#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netdb.h>
#include <stdlib.h>
#include <string.h>

int main (int argc, char**argv) {

    struct addrinfo hints;
    struct addrinfo *res, *ite;
    
    memset(&hints, 0, sizeof(struct addrinfo));

    hints.ai_family = AF_UNSPEC;
    hints.ai_flags = AI_PASSIVE;

    if (getaddrinfo(argv[1], NULL, &hints, &res) != 0) {
        printf("Error getaddrinfo(): Name or service not known");
        exit(-1);
    }

    for (ite = res; ite != NULL; ite = ite->ai_next) {
        char servi[NI_MAXHOST];
        getnameinfo(ite->ai_addr, ite->ai_addrlen, servi, NI_MAXHOST, NULL, 0, NI_NUMERICHOST);
        printf("%s\t%i\t%i\n", servi, ite->ai_family, ite->ai_socktype);
	}

    freeaddrinfo(res);
    return 0;
}
