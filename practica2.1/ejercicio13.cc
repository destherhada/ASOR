#include <sys/time.h>
#include <stddef.h>
#include <stdio.h>

int main(){
  struct timeval tv; //Para medir el tiempo antes del bucle
  struct timeval tv2; //Para medir el tiempo después del bucle
  int var = 0;        //Variable a incrementar
  int total = 0;      //Variable auxiliar para cálculos
  gettimeofday(&tv, NULL);    //Sacamos tiempo antes de bucle
  while (var < 1000000){
    var++;            //Incrementamos variable
  }
  gettimeofday(&tv2, NULL);   //Sacamos tiempo después de bucle
  
  total += tv2.tv_usec - tv.tv_usec;  //Calculamos los microsegundos
  total += (tv2.tv_sec - tv.tv_sec)*1000000;
  //Imprimimos en pantalla
  printf("Tiempo en incrementar variable: %d\n", total);
  
  return 1;
}
