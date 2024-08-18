/*********************************************************************
Autor:   Nicolas leon. 
Materia: Sistemas operativos.
Fecha:   25-07-2024.
Tema:    Punteros y NULL
**********************************************************************/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
int main(){
  char*a = NULL;
  char*b = NULL;
  a = function("HI, its fun to learn");
  b = function("system ingineer");
  printf("From main: %s %s\n", a, b);
}

char *function(char *p){
  char q[strlen(p)+1];
  strcpy(q,p);
  printf("From q: the string is %s\n", q);
  return q;
}
  
