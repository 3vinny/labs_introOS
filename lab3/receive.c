#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define clave 234 
#define MAX 20


int main() {
    int msqid;                      /* identificador de la cola de mensajes */
    // int longitud=20;

    struct {
        long tipo;
        char cadena[MAX];
    } mensaje;

    int longitud=sizeof(mensaje)-sizeof(mensaje.tipo);

    /* Creación de la cola de mensajes */
    if((msqid=msgget(clave, IPC_CREAT | 0600)) == -1) {
        printf("Error al crear la cola de mensajes \n");
        exit(-1);
    }

    /* Contador */
    int cont = 0;
    while (1) {
        /* Recepción del mensaje */
        if(msgrcv(msqid, &mensaje, longitud, 1, 0) == -1) {
            printf("Error al leer un mensaje de la cola de mensajes \n");
            exit(-1);
        }
        printf("El mensaje leido en RECEIVE es: %s\n", mensaje.cadena);

        if (strcmp(mensaje.cadena, "FIN") == 0) {
            printf("FIN\n");
            break;
        }
        cont++;        
    }

    printf("El total de mensajes recibidos es: %d\n", cont);

    /* Borrado de la cola de mensajes */
    if(msgctl(msqid, IPC_RMID, 0) == -1) {
        printf("Error al eliminar la cola de mensajes \n");
        exit(-1);
    }

    printf("Cola eliminada correctamente\n");
    return 0;
}
