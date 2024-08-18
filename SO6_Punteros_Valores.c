/*********************************************************************
Autor:   Nicolas leon. 
Materia: Sistemas operativos.
Fecha:   25-07-2024.
Tema:    Punteros y Valores
**********************************************************************/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define size 10
int main(){

  
  int valor1, valor2;
   int *ptrV1, *ptrV2;
  
  ptrV1 = &valor1;
  ptrV2 = &valor2;
  
  printf("\n Ingrese dos valores a ser sumados \n");
  scanf("%d %d", &valor1, &valor2);
  
  printf("\n La suma es =%d\n", *ptrV1 + *ptrV2);
  return 0;
}
