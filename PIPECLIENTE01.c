/* *************************************************************************************************************************************************************
Nombre: PipeClientes01
Asignatura: Sistemas Operativos
Tema: PIPENAMED
Autor: Nicolás León Parra
Fecha De Inicio: 03/10/2024
Fecha De entrega:
*************************************************************************************************************************************************************
*/
#include <stdio.h>    // Biblioteca estándar para funciones como printf y fgets
#include <stdlib.h>   // Para usar funciones generales, como exit
#include <unistd.h>   // Incluye las funciones de UNIX, como write y close
#include <sys/types.h> // Define tipos de datos como pid_t
#include <string.h>   // Biblioteca para trabajar con cadenas de caracteres (strlen, strcmp, etc.)
#include <fcntl.h>    // Para controlar el acceso a archivos, necesario para open

// Definimos el nombre del FIFO que también usó el servidor, ambos deben coincidir
#define FIFO_FILE "MYFIFO"

int main() {
    int ArchivoDesc;  // El descriptor del archivo FIFO, se usa para escribir en él
    int fin_proceso;  // Variable para determinar si se ha ingresado "fin" y así terminar el programa
    int cadena;       // Longitud de la cadena que ingresamos
    char BusMensaje[80];  // Este buffer almacena el mensaje que vamos a enviar
    char senalFin[5];     // Aquí guardamos "fin" para comparar y finalizar el ciclo

    /* 
    Al inicio damos un mensaje al usuario explicando cómo funciona el programa.
    Le indicamos que puede enviar mensajes infinitamente, pero si escribe "fin", el cliente terminará.
    */
    printf("FIFO_CLIENT: Enviar mensajes infinitamente, para terminar, ingrese \"fin\"\n");

    /* 
    Abrimos el FIFO en modo solo escritura (O_WRONLY).
    Aquí es donde el cliente enviará los mensajes que luego el servidor leerá.
    */
    ArchivoDesc = open(FIFO_FILE, O_WRONLY);  // Abre el FIFO solo para escribir

    /* 
    Guardamos la palabra "fin" en la variable `senalFin` para poder comparar más tarde con lo que el usuario escriba.
    */
    strcpy(senalFin, "fin");

    while (1) {
        /* 
        Pedimos al usuario que ingrese una cadena de texto.
        Utilizamos fgets para leer la entrada del usuario, guardándola en el buffer `BusMensaje`.
        */
        printf("Ingrese cadena: ");
        fgets(BusMensaje, sizeof(BusMensaje), stdin);

        /* 
        Calculamos la longitud de la cadena ingresada. 
        Como `fgets` añade un salto de línea '\n' al final, lo eliminamos para evitar que sea parte del mensaje enviado.
        */
        cadena = strlen(BusMensaje);  
        BusMensaje[cadena - 1] = '\0';  // Reemplazamos el salto de línea con el carácter nulo '\0'

        /* 
        Comparamos la cadena ingresada con la palabra "fin" usando strcmp.
        Si `strcmp` devuelve 0, significa que las cadenas son iguales, es decir, que el usuario quiere terminar.
        */
        fin_proceso = strcmp(BusMensaje, senalFin);

        /* 
        Si el usuario no ingresó "fin", enviamos el mensaje por el FIFO.
        Usamos la función `write` para escribir en el FIFO, enviando el mensaje al servidor.
        */
        if (fin_proceso != 0) {
            write(ArchivoDesc, BusMensaje, strlen(BusMensaje));  // Envía el mensaje
            printf("Cadena enviada: \"%s\" y longitud de la cadena es %d\n", BusMensaje, (int) strlen(BusMensaje));
        } else {
            /* 
            Si el usuario ingresó "fin", también lo enviamos para que el servidor sepa que debe terminar.
            Después de eso, cerramos el archivo FIFO y salimos del bucle.
            */
            write(ArchivoDesc, BusMensaje, strlen(BusMensaje));  // Envía el último mensaje
            printf("Cadena enviada: \"%s\" y longitud de la cadena es %d\n", BusMensaje, (int) strlen(BusMensaje));
            close(ArchivoDesc);  // Cerramos el archivo FIFO
            break;  // Salimos del ciclo infinito
        }
    }

    return 0;  // El programa termina correctamente
}
