#include <time.h>
#include <stdio.h>
#include <stddef.h>
#include <locale.h>

int main(){
    
    time_t tiempo = time(NULL);
    struct tm *res = localtime(&tiempo);
    char s[100];
    setlocale(LC_ALL, "es_ES");
    strftime(s,100, "%A, %d de %B de %Y, %H:%M", res);
    printf("%s\n", s);
    return 1;
}
