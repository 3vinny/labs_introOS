#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t pid_padre = fork();

    if (pid_padre < 0) {
        perror("Error en el primer fork");
        return 1;
    }

    if (pid_padre == 0) {
        // --- Estamos dentro del PADRE ---
        printf("[Padre] Creado por el Abuelo. PID: %d, PID de mi padre (Abuelo): %d\n",
               getpid(), getppid());

        // El padre ejecuta fork() para crear al nieto (su hijo)
        pid_t pid_nieto = fork();

        if (pid_nieto < 0) {
            perror("Error en el segundo fork");
            return 1;
        }

        if (pid_nieto == 0) {
            // --- Estamos dentro del NIETO (Hijo del Padre) ---
            printf("[Nieto] ¡Hola! PID: %d, PID de mi padre: %d\n",
                   getpid(), getppid());
            exit(0); // El nieto termina su ejecución
        } else {
            // El padre espera a que termine su propio hijo (el nieto)
            wait(NULL);
            printf("[Padre] Mi hijo (el nieto) ha terminado. Saliendo...\n");
            exit(0); // El padre termina su ejecución
        }

    } else {
        // --- Estamos dentro del ABUELO ---
        printf("[Abuelo] Proceso raíz iniciado. PID: %d (creé al padre con PID: %d)\n",
               getpid(), pid_padre);

        // El abuelo espera a que termine su hijo (el padre)
        wait(NULL);
        printf("[Abuelo] Mi hijo (el padre) ha terminado. Programa finalizado con éxito.\n");
    }

    return 0;
}