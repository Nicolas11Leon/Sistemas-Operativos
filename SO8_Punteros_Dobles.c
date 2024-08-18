/*********************************************************************
Autor:   Nicolas leon. 
Materia: Sistemas operativos.
Fecha:   25-07-2024.
Tema:    Punteros Dobles
**********************************************************************/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define size 10
int main(){

  
  int var =480;
  int *varptr = &var;
  int **doublePtr = &varptr;
  printf("Valor de variable \t\t = %d \n", var);
  printf("Valor del puntero \t\t = %d \n",  *varptr);
  printf("valor del puntero doble \t = %d \n",  **doublePtr);
  
  printf("Direccion de la variable \t = %p \n",  &var);
  printf("Direccion del puntero \t\t = %p \n",  &varptr);
  printf("Direccion de la variable \t = %p \n",  varptr);
  printf("valor del puntero doble \t = %p \n",  doublePtr);
  return 0;
}
