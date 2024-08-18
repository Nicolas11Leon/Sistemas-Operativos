#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>


void Info_Almcenamiento(const int *siguiente, const int *anterior, int valores){
  if (siguiente)
    printf("%s ubicacion %p. TamaÃ±o reservado: %d valores ( %ld bytes) \n.",
           (siguiente=!anterior ? "Nuevo " : "Anterior"), (void*)siguiente, valores,
           valores*sizeof(int));
}
int main(){
  const int patron[] = {1,2,3,4,5,6,7,8};
  const int patron_size = sizeof patron/ sizeof(int);
  int *siguiente NULL, *anterior = NULL; 
 
    if((siguiente = (int *)malloc(patron_size*sizeof *siguiente))){            //asigna el vector
      memcpy(siguiente, patron, sizeof patron);                                //llena el vector
      Info_almacenamiento(siguiente, anterior, patron_size);
  } else {
      return EXIT_FAILURE;
     
    //Reasigna los valores de vector en el siguiente ciclo
      cons int realloc_size[] = {10,20,30,40,50,60,70,80};
      for(int i = 0; i!= sizeof realloc_size / sizeof (int); i++){
        if ((siguiente = (int *)realloc)(anterior =siguiente, realloc_size[i]*sizeof(int)))
         Info_almacenamiento(siguiente, anterior, realloc_size[i]);
         assert(!memcmp(siguiente, patron, sizeof patron ));
      } else{
          
  printf("Se libera memoria reservada\n");
    free(siguiente);
    return EXIT_FAILURE;
      }
      
    }
    free(anterior); //libera almacenamiento
  return 0;
}
