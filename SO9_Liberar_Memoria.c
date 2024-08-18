/*********************************************************************
Autor:   Nicolas leon. 
Materia: Sistemas operativos.
Fecha:   25-07-2024.
Tema:    Liberar memoria
**********************************************************************/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define size 10
int main(){

  

  int *varptr1 = malloc(4*sizeof(int));
  int *varptr2 = malloc(sizeof(int[4]));
  int *varptr3 = malloc(4*sizeof *varptr3);
  if(varptr1){
    for(int i=0; i<4; i++)
      varptr1[i] = i*i;
    for(int i=0; i<4; i++)
       printf("varptr[%d]\t == %d\n",i,  varptr1[i]);
    
  }
  
  printf("Se libera memoria reservada\n");
  free(varptr1);
  free(varptr2);
  free(varptr3);
  return 0;
}
