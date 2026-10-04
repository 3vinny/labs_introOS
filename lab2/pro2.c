// 2. Ingresar por paso de parámetros tres valores enteros, indicar al padre que duplique el primer valor, al abuelo que eleve  a la potencia 3 el segundo valor y que el hijo obtenga la raíz del tercer valor.
#include <stdio.h>
#include <unistd.h>
#include <math.h>
// para usar exit() y atoi()
#include <stdlib.h>
// para usar wait()
#include <sys/wait.h>

int main(int argc, char *argv[])
{
    if (argc != 4)
    {
        printf("Uso: %s valor1 valor2 valor3\n", argv[0]);
        return 1;
    }

    int valor[3];
    printf("Inicia programa. Ingrese 3 valores.\n");
    for (int i=0; i<3; i++)
    {
        valor[i] = atoi(argv[i + 1]);
    }

    // Muestra los pids de los procesos
    printf("Abuelo PID: %d | PPID: %d\n", getpid(), getppid());
    // Abuelo: eleva a 3 el segundo valor
    long v = valor[1];
    printf("Valor abuelo [%d^3]: %d\n", valor[1], v*v*v);
    
    pid_t padre = fork();
    if (padre == 0)
    {
        printf("Padre PID: %d | PPID (abuelo): %d\n", getpid(), getppid());
        printf("Valor Padre [%d*2]: %d\n", valor[0],2*valor[0]);
        
        pid_t hijo = fork();
        if (hijo == 0)
        {
            // Muestra los pids de los procesos
            printf("Hijo PID: %d | PPID (padre): %d\n", getpid(), getppid());

            // Hijo: obtiene la raíz del tercer valor | Comprobacion raiz
            if (valor[2] < 0)
            {
                printf("Hijo: raiz cuadrada de un negativo es imaginario.\n");
            }
            else
            {
                printf("Valor Hijo [raiz(%d)]: %.2f\n", valor[2], sqrtf(valor[2]));
            }
            exit(0);
        }
        wait(NULL);
        exit(0);
    }
    wait(NULL);
    return 0;
}