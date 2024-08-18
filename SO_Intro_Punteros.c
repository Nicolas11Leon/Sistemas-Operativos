/*********************************************************************
Autor:   Nicolas leon. 
Materia: Sistemas operativos.
Fecha:   25-07-2024.
Tema:    Introduccion a los punteros.
**********************************************************************/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
int main(){
  char *p;
  char *q = NULL;
  printf("Adress of p = %s\n",p);
  
  strcpy(p, "Hello, iÂ´m the best in Operating Systems!!!");
  printf("%s\n",p);
  printf("About to copy\"Godbye\"to q\n");
  strcpy(q,"goodbye");
  printf("String copied\n");
  printf("%s\n",q);
  
}
