#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    // Declaración de variables utilizando pid_t
    pid_t mi_pid;
    pid_t pid_padre;

    // Obtener los identificadores correspondientes
    mi_pid = getpid();
    pid_padre = getppid();

    // Al imprimirse, se puede formatear de forma segura usando %d ya que equivale a un entero
    printf("Mi PID es: %d\n", mi_pid);
    printf("El PID de mi padre es: %d\n", pid_padre);

    return 0;
}