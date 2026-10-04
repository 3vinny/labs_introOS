#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void)
{
    printf("Antes del fork: solo existo yo , el padre( PID %d)\n", getpid());

    pid_t pid = fork();

    if (pid == 0) // si es una copia
    {
        printf("Soy el HIJO (PID %d)\n", getpid());
        exit(0);
    }

    wait(NULL);
    printf("Soy el PADRE (PID %d), mi hijo ya termino\n", getpid());
    return 0;
}