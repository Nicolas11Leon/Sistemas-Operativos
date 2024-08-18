/*********************************************************************
Autor:   Nicolas leon. 
Materia: Sistemas operativos.
Fecha:   25-07-2024.
Tema:    Punteros y Vectores
**********************************************************************/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define size 10
int main(int argc, chart **argv){
int *vectorPunteros[3];
  int p=40, q=80, r=120;
  
  vectorPunteros[0] = &p;
    vectorPunteros[1] = &q;
    vectorPunteros[2] = &r;
  
  printf("\n Forma de acceso al vector de punteros : \n");
  for(int i; i<3; i++){
    printf("para la direccion: %p \t el valor = %d\n", vectorPunteros[i], *vectorPunteros[i]);
    
  }
  return 0;}
