/*********************************************************************
Autor:   Nicolas leon. 
Materia: Sistemas operativos.
Fecha:   25-07-2024.
Tema:    Liberar memoria 2
**********************************************************************/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define size 10
int main(){

  int *vP1 = calloc(4, sizeof(int));
  int *vP2 = calloc(1, sizeof(int[4]));
  int *vP3 = calloc(4, sizeof *vP3);
    if(vP2){
      for(int i=0; i<4; i++)
         printf("vP2[%d]\t == %d\n", i, vP2[i]);
  }
  
  printf("Se libera memoria reservada\n");
    free(vP1);
    free(vP2);
    free(vP3);
  return 0;
}
