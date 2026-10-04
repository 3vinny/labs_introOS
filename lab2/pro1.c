/*
* Lab 2: Creación y duplicación de procesos
* 1. Realizar un programa [hijo_padre_abuelo] que muestre a través de sus ID la creación de ellos.
*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main(void)
{
    printf("Abuelo PID: %d | PPID[Del terminal]: %d\n", getpid(), getppid());
    pid_t padre = fork(); //usamos fork
    
    if (padre == 0)
    {
         // Proceso padre
        printf("Padre PID: %d | PPID[abuelo]: %d\n", getpid(), getppid()); //get parent pid

        pid_t hijo = fork();
        if (hijo == 0)
        {
            // Proceso hijo
            printf("Hijo PID: %d | PPID: %d\n", getpid(), getppid());
            exit(0);
        }
        wait(NULL); // padre espera al hijo
        exit(0);
    }
    wait(NULL); // abuelo espera al padre
    printf("Abuelo PID=%d termino de esperar al padre\n", getpid());
    return 0;
}