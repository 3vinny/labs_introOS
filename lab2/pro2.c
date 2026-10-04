// 2. Ingresar por paso de parámetros tres valores enteros, indicar al padre que duplique el primer valor, al abuelo que eleve  a la potencia 3 el segundo valor y que el hijo obtenga la raíz del tercer valor.
#include <stdio.h>
#include <unistd.h>
#include <math.h>
// para usar wait()
#include <sys/wait.h>

int main()
{
    int valor[3];
    printf("Inicia programa. Ingrese 3 valores.\n");
    for (int i=0; i<3; i++)
    {
        scanf("%d", &valor[i]);
    }

    // Muestra los pids de los procesos
    printf("Abuelo PID: %d PPID: %d\n", getpid(), getppid());
    // Abuelo: eleva a 3 el segundo valor
    printf("Abuelo: %d\n", valor[1]*valor[1]*valor[1]);
    
    pid_t padre = fork();

    if (padre == 0)
    {
        printf("Padre: %d\n", 2*valor[0]);
        pid_t hijo = fork();
        if (hijo == 0)
        {
            // Muestra los pids de los procesos
            printf("Hijo PID: %d PPID: %d\n", getpid(), getppid());

            // Hijo: obtiene la raíz del tercer valor
            // Comprobacion raiz
            if (valor[2] < 0)
            {
                printf("Hijo: raiz cuadrada de un negativo es imaginario.\n");
            }
            else
            {
                printf("Hijo: %.2f\n", sqrtf(valor[2]));
            }
        }
        wait(NULL);
    }
    wait(NULL);
    return 0;
}