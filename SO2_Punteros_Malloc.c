/*********************************************************************
Autor:   Nicolas leon. 
Materia: Sistemas operativos.
Fecha:   25-07-2024.
Tema:    Punteros y Malloc.
**********************************************************************/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
int main(){
  int *ptr, i, n1, n2;
  printf("Enter size: ");
  scanf("%d", &n1);
  ptr = (int*) malloc(n1 * sizeof(int));
  printf("Addresses of previously allocated memory: ");
  for(i=0; i<n1; i++)
    printf("\n\np = %p\n" , ptr+i);
  printf("\n Enter new size: ");
  scanf("%d" , &n2);
  //relocating memory
  ptr = realloc(ptr, n2 *sizeof(int));
  printf("Addresses of newly allocated memory: ");
  for(i=0; i< n2; ++i)
    printf("\n\np = %p\n" , ptr+i);
  
}
