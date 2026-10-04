/*
* 5. Compare valores de una variable creada por Ud en proceso padre con la misma variable del proceso hijo. 
* Es el mismo valor? Justifique
*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char** argv)
{
    int x = 10;
    printf("Antes del fork  | PID %d | x = %d | &x = %p\n", getpid(), x, (void *)&x);

    pid_t pid = fork();
    if (pid == 0)
    {
        /* HIJO */
        printf("Hijo (inicio) | PID %d | x = %d | &x = %p\n", getpid(), x, (void *)&x);
        x = 99; // modificamos SU COPIA
        printf("Hijo (modificado) | PID %d | x = %d | &x = %p\n", getpid(), x, (void *)&x);
        exit(0);
    }

    /* PADRE */
    wait(NULL); // esperamos al HIJO a que modifique su copia
    printf("Padre (despues) | PID %d | x = %d | &x = %p\n", getpid(), x, (void *)&x);
    return 0;
}