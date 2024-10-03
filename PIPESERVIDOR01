/* *************************************************************************************************************************************************************
Nombre: Pipeservidor01
Asignatura: Sistemas Operativos
Tema: PIPEDNAMED
Autor: Nicolás León Parra
Fecha De Inicio: 03/10/2024
Fecha De entrega:
*************************************************************************************************************************************************************
*/
#include <string.h>  // Biblioteca estándar para trabajar con cadenas de caracteres (strlen, strcmp, etc.)
#include <stdio.h>    // Biblioteca para funciones de entrada/salida, como printf
#include <stdlib.h>   // Incluye funciones generales, como exit
#include <unistd.h>   // Aquí están las funciones del sistema UNIX, como read, write y close
#include <sys/types.h>  // Define tipos de datos como pid_t
#include <sys/stat.h>   // Permite trabajar con propiedades de archivos
#include <fcntl.h>   // Control de archivos, necesario para abrir archivos con open

// Definimos el nombre de nuestro FIFO (es como un canal por donde enviamos datos entre procesos)
#define FIFO_FILE "MYFIFO"

int main() {
    int ArchivoDesc; // Aquí vamos a guardar el "descriptor" del archivo, que es como una referencia al FIFO abierto
    char BusMensaje[80];  // Esta es la cadena que va a recibir el mensaje que llega por el FIFO
    char final[10];  // Para comparar si recibimos la palabra "fin" y terminar el ciclo
    int cantidadBytes;  // Guardamos la cantidad de bytes que leemos desde el FIFO
    int fin;  // Variable para chequear si recibimos "fin"

    printf("\n \t\t >>>>>>>>>>> Inicio servidor<<<<<<<<<<<<<");

    /* 
    Creamos el FIFO solo si no existe ya.
    mkfifo crea una tubería con nombre (FIFO) que básicamente es un archivo especial donde dos procesos pueden escribir y leer.
    Le damos permisos 0640, que significa:
    - El propietario puede leer y escribir (6).
    - El grupo puede leer (4).
    - Otros no tienen permisos (0).
    */
    mkfifo(FIFO_FILE, 0640);  // Creamos la tubería con permisos

    strcpy(final, "fin");  // Guardamos la palabra "fin" en la variable 'final' para hacer comparaciones después

    while (1) {
        /* 
        Abrimos el archivo FIFO en modo solo lectura (O_RDONLY) porque el servidor solo va a leer los mensajes que otros procesos envían.
        open nos devuelve un descriptor de archivo, que es como una "puerta" para interactuar con el FIFO.
        */
        ArchivoDesc = open(FIFO_FILE, O_RDONLY);

        /* 
        Leemos lo que llega por el FIFO.
        La función read recibe tres argumentos:
        1. El descriptor del archivo (en este caso, nuestro FIFO).
        2. El buffer donde vamos a almacenar los datos (BusMensaje).
        3. El tamaño máximo de lo que queremos leer.
        */
        cantidadBytes = read(ArchivoDesc, BusMensaje, sizeof(BusMensaje));

        /* 
        Una vez leemos el mensaje, debemos asegurarnos de que termine con '\0', que es el carácter de fin de cadena.
        Esto es importante porque si no hacemos esto, podríamos imprimir "basura" adicional cuando imprimimos la cadena.
        */
        BusMensaje[cantidadBytes] = '\0';  // Terminamos el mensaje recibido

        /* 
        Mostramos el mensaje que recibimos y también cuántos bytes hemos leído.
        strlen calcula la longitud real del mensaje (sin contar el carácter '\0').
        */
        printf("Cadena Recibida: \"%s\" y cantidad de bytes %d\n", BusMensaje, (int) strlen(BusMensaje));

        /* 
        Comparamos el mensaje recibido con la palabra "fin" usando strcmp.
        strcmp devuelve 0 si ambas cadenas son iguales, así que si el mensaje es "fin", fin será 0.
        */
        fin = strcmp(BusMensaje, final);

        /* 
        Si recibimos "fin", cerramos el FIFO y salimos del ciclo.
        */
        if (fin == 0) {
            close(ArchivoDesc);  // Cerramos el descriptor de archivo
            break;  // Salimos del bucle infinito
        }
    }

    return 0;  // Terminamos el programa
}
