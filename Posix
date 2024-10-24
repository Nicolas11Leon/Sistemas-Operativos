/* *************************************************************************************************************************************************************
Nombre:Posix
Asignatura: Sistemas Operativos
Tema:Posix
Autor: Nicolás León Parra
Fecha De Inicio: 24/10/2024
Fecha De entrega:
*************************************************************************************************************************************************************
*/


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

// Contador compartido entre hilos
int counter = 0;
// Valor máximo que puede alcanzar el contador
const int max = 10;

// Inicialización de mutex y variables de condición
pthread_mutex_t counter_mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t condVarProd = PTHREAD_COND_INITIALIZER;
pthread_cond_t condVarCons = PTHREAD_COND_INITIALIZER;

// Prototipos de funciones
void *productor(void *arg);
void *consumidor(void *arg);

int main() {
    pthread_t proHilo[5], conHilo[5];

    // Creación de hilos productores y consumidores
    for (int i = 0; i < 5; i++) {
        pthread_create(&proHilo[i], NULL, productor, NULL);
        pthread_create(&conHilo[i], NULL, consumidor, NULL);
    }

    // Esperar a que terminen todos los hilos
    for (int i = 0; i < 5; i++) {
        pthread_join(proHilo[i], NULL);
        pthread_join(conHilo[i], NULL);
    }
    
    return 0; // Fin del programa
}

void *productor(void *arg) {
    while (1) {
        pthread_mutex_lock(&counter_mutex);
        
        // Esperar si el contador es mayor o igual al máximo
        while (counter >= max) {
            pthread_cond_wait(&condVarProd, &counter_mutex);
        }

        // Incrementar el contador y notificar al consumidor
        counter++;
        printf("Soy productor %lu valor contador = %d\n", pthread_self(), counter);
        pthread_cond_signal(&condVarCons);
        
        pthread_mutex_unlock(&counter_mutex);
        sleep(1); // Simular trabajo
    }
}

void *consumidor(void *arg) {
    while (1) {
        pthread_mutex_lock(&counter_mutex);
        
        // Esperar si el contador es cero
        while (counter <= 0) {
            pthread_cond_wait(&condVarCons, &counter_mutex);
        }

        // Decrementar el contador y notificar al productor
        counter--;
        printf("Soy consumidor %lu Valor contador = %d\n", pthread_self(), counter);
        pthread_cond_signal(&condVarProd);
        
        pthread_mutex_unlock(&counter_mutex);
        sleep(1); // Simular trabajo
    }
}


