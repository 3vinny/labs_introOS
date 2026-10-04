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
    /*
    Nuestra variable, x.
    Es un entero, por lo que podemos modificar su valor directamente.
    Imprimiremos su valor en padre e hijo y su dir de memoria.
    */
    int x = 10;
    printf("Antes del fork  | PID %d | Var x = %d | &x = %p\n", getpid(), x, (void *)&x);

    pid_t pid = fork();
    if (pid == 0)
    {
        /* HIJO */
        printf("Hijo (inicio) | PID %d | Var x = %d | &x = %p\n", getpid(), x, (void *)&x);
        x = 99; // modificamos SU COPIA
        printf("Hijo (modificado) | PID %d | Var x = %d | &x = %p\n", getpid(), x, (void *)&x);
        exit(0);
    }

    /* PADRE */
    wait(NULL); // esperamos al HIJO a que modifique su copia
    printf("Padre (despues) | PID %d | Var x = %d | &x = %p\n", getpid(), x, (void *)&x);
    return 0;
}