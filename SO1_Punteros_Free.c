/*********************************************************************
Autor:   Nicolas leon. 
Materia: Sistemas operativos.
Fecha:   25-07-2024.
Tema:    Punteros y Free
**********************************************************************/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
int main(){
  int n, i, *ptr, sum =0;
  printf("Enter number of elements: ");
  scanf("%d", &n);
  ptr = (int*) calloc(n,sizeof(int));
  if(ptr == NULL){
    printf("ERROR! memoty not allocated.");
    exit(0);
  }
  printf("Enter Elements: ");
  for (i=0; i<n; i++){
    scanf("%d", ptr + i);
    sum += *(ptr + i);
  }

  printf("Sum = %d", sum);
  free(ptr);
  return 0;
  return 0;
  
}
