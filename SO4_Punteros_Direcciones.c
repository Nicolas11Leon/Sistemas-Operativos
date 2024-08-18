/*********************************************************************
Autor:   Nicolas leon. 
Materia: Sistemas operativos.
Fecha:   25-07-2024.
Tema:    Punteros y direcciones
**********************************************************************/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
int main(){
int variable =123;
  int *ptr = &variable;
  printf("valor de la variable %d \n" , variable);
    printf("Direccion de la emoria de la variabel  %p \n" , &variable);
  printf("Direccion a la que apunta el puntero  %p \n" , (void *) ptr);
   printf("valor de la variable %i \n" ,*ptr);
  return 0;
}
  
