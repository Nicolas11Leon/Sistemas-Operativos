/*********************************************************************
Autor:   Nicolas leon. 
Materia: Sistemas operativos.
Fecha:   25-07-2024.
Tema:    Entrada y Salida en c
**********************************************************************/

#include <stdio.h>
#include "funciones.h"
float pi=3.141516;
 /* Smar dos valores que entran por treclado*/
  void sumarEneteros(){
  int a;
  int b;
 
  
  printf("dame dos numeros enteros para sumarlos \n");
  scanf( "%d %d",&a,&b );
  
  int suma = a+b;
  printf("La suma de %d + %d = %d ", a,b,suma);
  }
  
  /*calculr arrÂ¿ea de circulo ingreso pr teclado radio*/
  /*calculr volumen de circunferencia ingreso pr teclado radio*/
  /*calculr volumen de cono ingreso por telado variabes necesarias*/
  /*calculr tangente deingreso por teclado variablesecesesarias*/
  
  void  Calcularareayvolumendcirculos(){
  
  
  float r1;
   
  printf("\n Dame el radio de tu circulo para caluclar el area y el volumen \n");
  scanf( "%f",&r1 );
  float area = (r1*r1*pi);
  float volumen = (r1*r1*r1*pi*1.333333);
  printf("el area de tu circulo es %f ", area);
  printf("\n el volumen es de %f " , volumen);
  }
  
  void Calcularvoumendcilindr(){
  printf(" \n ahora para calcular el volumen de un cono dame su altura \n");
  
  float r2, h;
   
  scanf( "%f", &h);
  
  printf("ahora su radio");
  scanf( "%f",&r2);
  float  v2 = r2*r2*h*pi*0.3333333;
  printf ("\n el volumen del cilindro es %f ", v2);
  }
  
  void calcuartangente(){
  printf("\n ahra vo a calcular la hiortenusa de un trianguo por lo que ecesito que medes dos catetos\n");
  float c1,c2;
  scanf("%f %f", &c1, &c2);
  float hipo= c1*c1*c2*c2;
  printf("\n la hipotenusa es %f " , hipo);
  
  }
  
