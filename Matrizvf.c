/*********************************************************************
Autor:     Nicolas Leon.
Materia:   Sistemas operativos.
Fecha:     15-08-2024.
Tema:      GestiÃ³n de memoria.
Programa:  Matriz Vector final.
**********************************************************************/

#include <stdlib.h>
#include <stdio.h>

void impresion(int *matriz, int size, int n);
void inicializacion(int *matriz, int size, int valor);
void multiplicarMatrices(int *ma, int *mb, int *mc, int n);

  
int main(int argc, char *argv[]){
  printf(" %s ", argv[0]);
  printf(" %s ", argv[1]);
  
  if(argc<2){
    printf("\n Argumentos validos: $ejecutable sizeofMatriz\n");
      exit(0);
  }
  
  int n = atoi(argv[1]);
  int size = n*n;
  int ma[size];
  int mb[size];
  int mc[size];


    int valorA, valorB;
    
  
    printf("Ingrese el valor con el que desea llenar la matriz A: ");
    scanf("%d", &valorA);

    printf("Ingrese el valor con el que desea llenar la matriz B: ");
    scanf("%d", &valorB);

    /* InicializaciÃ³n */
    inicializacion(ma, size, valorA);
    inicializacion(mb, size, valorB);  

    /* ImpresiÃ³n de matrices */
    printf("Matriz A:\n");
    impresion(ma, size, n);
    printf("Matriz B:\n");
    impresion(mb, size, n);

    /* MultiplicaciÃ³n de matrices */
    multiplicarMatrices(ma, mb, mc, n);

    printf("Matriz C (resultado de A x B):\n");
    impresion(mc, size, n);

    printf("\n\n\n...........Fin del programa\n");
    return 0;
}

void impresion(int *matriz, int size, int n) {
    for(int i = 0; i < size; i++) {
        if(i % n == 0) printf("\n");
        printf("%d ", matriz[i]);
    }
    printf("\n");
}

void inicializacion(int *matriz, int size, int valor) {
    for(int i = 0; i < size; i++) {
        matriz[i] = valor; 
    }
}

void multiplicarmatrices(int *ma, int *mb, int *mc, int n) {
    for(int i = 0; i < n; i++) { // Filas 
        for(int j = 0; j < n; j++) { // Columnas
            mc[i * n + j] = 0;
            for(int k = 0; k < n; k++) { // FilasXcolumnas
                mc[i * n + j] += ma[i * n + k] * mb[k * n + j];
            }
        }
    }
}
