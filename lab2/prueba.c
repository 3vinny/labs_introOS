#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    // pid almacena el resultado de la llamada al sistema fork()
    pid_t pid = fork();

    if (pid < 0) {
        // Error al crear el proceso hijo
        perror("Error al ejecutar fork()");
        return 1;
    } else if (pid == 0) {
        // Código que solo ejecuta el proceso HIJO
        printf("[Hijo] ¡Hola! Mi PID es %d y el PID de mi padre es %d.\n", 
               getpid(), getppid());
    } else {
        // Código que solo ejecuta el proceso PADRE
        printf("[Padre] He creado un hijo con PID %d. Mi propio PID es %d.\n", 
               pid, getpid());

        // wait(NULL) hace que el padre espere a que el hijo termine antes de salir
        wait(NULL);
        printf("[Padre] Mi hijo ha finalizado. Terminando ejecución.\n");
    }

    return 0;
}