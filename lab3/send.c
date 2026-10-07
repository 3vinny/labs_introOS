// EJEMPLO DE ENVIO DE MENSAJES ENTRE PROCESOS, UTILIZANDO PRIMITIVAS
// DE COMUNICACION

// CURSO SISTEMAS OPERATIVOS 
// DEPTO. INGENIERIA EN COMPUTACION
// UNIVERSIDAD DE MAGALLANES
// PROFESOR: EDUARDO PE�A J.

// Compilar gcc send.c -o send
// Ejecutar ./send

//Linux kataix 2.6.18-mmkernel #1 SMP Wed Jun 25 12:19:28 CLT 2008 i686 GNU/Linux
//Debian GNU/Linux 5.0 \n \l
//Linux version 2.6.18-mmkernel (2.6.18-mmkernel-10.00.Custom) (root@kataix)
//gcc version 4.1.2 20061115 (prerelease) (Debian 4.1.1-21)) #1 SMP Wed Jun 25 12:19:28 CLT 2008

//ENVIA MENSAJES DE LARGO DE 20 CARACTERES A TRAVES DE DE LA COLA 234
//CUANDO SE ENVIA EL MENSAJE "FIN" AL PROCESO RECIBE, ESTE CULMINA LA RECEPCION

//Recordar:  ipcs: lee Nos de colas y semaforos utilizados por el usuario que ejecuto este codigo
//           ipcrm -q <No cola leido de ipcs>: Elimina la colo indicada por el usuario
//           ps:   lee procesos activos por el usuario
//           kill <No Procso leido con pS>: Elimina el proceso indicado por usuario


#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

/* FALTA RESPONDER PREGUTNAS XD */

#define clave 234  /* Numero de cola */
#define MAX 20
#define TOTAL 100

int main() {

    int msqid;			/* identificador de la cola de mensajes */

    struct {
        long tipo;
        char cadena[MAX];
    } mensaje;

    int longitud=sizeof(mensaje)-sizeof(mensaje.tipo);

    /* Creaci�n de la cola de mensajes */
    if((msqid=msgget(clave, IPC_CREAT | 0600)) == -1) {
        printf("Error al crear la cola de mensajes \n");
        exit(-1);
    }

    /* Semilla para generar aleatoriedad */
    srand(time(NULL));

    /* Preparaci�n de un mensaje */
    mensaje.tipo=1;

    for (int i=0; i<TOTAL; i++) {
        sprintf(mensaje.cadena, "Hola, mensaje No. %d", i);

        /* Envio de mensaje a la cola clave=234 */
        if(msgsnd(msqid, &mensaje, longitud, 0) == -1) {
            printf("Error al enviar un mensaje a la cola de mensajes \n");
            exit(-1);
        }
        printf("Mensaje enviado desde SEND: %s\n",mensaje.cadena);
        /* Retardo de tiempo de producción aleatorio */
        sleep(rand() % 3);
    }

    /* Aca termina la cadena de mensajes */
    strcpy(mensaje.cadena, "FIN");
    msgsnd(msqid, &mensaje, longitud, 0);
    printf("Enviado y finalizado con mensaje: FIN\n");
    return 0;
}
