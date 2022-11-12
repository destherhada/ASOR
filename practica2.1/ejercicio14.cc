
#include <time.h>
#include <stdio.h>
#include <stddef.h>

int main(){
    time_t tiempo = time(NULL);
    struct tm *res = localtime(&tiempo);
    printf("Año: %d\n", res->tm_year + 1900);   //Hay que sumar 1900 porque localtime calcula desde el Epoch
    return 1;
}
