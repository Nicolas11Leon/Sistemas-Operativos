/*********************************************************************
Autor:   Nicolas leon. 
Materia: sistemas operativos.
Fecha:   18

-07-2024.
Tema:    Introduccion allenguaje C y los entornos.
         -Entorno en la web(cloud/Nube).
         -Comandos principales de Linux.
         -Programa 1: Bloques basicos de la programacion.
**********************************************************************/


#include <stdlib.h>
#include <stdio.h>


int main(int argc, char *argv[]){
  int x;
  int suma = 0;
  do{
    scanf("%d", &x);
    suma += x;
    
  }while (x!=0);
  printf ("la suma es %d \n", suma);
  return 0;
}
