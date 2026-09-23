// 2. Ingresar por paso de parámetros tres valores enteros, indicar al padre que duplique el primer valor, al abuelo que eleve  a la potencia 3 el segundo valor y que el hijo obtenga la raíz del tercer valor.
#include <stdio.h>
#include <unistd.h>
#include <math.h>

int main()
{
    int valor[3];
    printf("Inicia programa. Ingrese 3 valores.\n");
    for (int i=0; i<3; i++)
    {
        scanf("%d", &valor[i]);
    }

    //
    printf("Abuelo: %d\n", valor[2]*valor[2]*valor[1]);
    
    pid_t padre = fork();

    if (padre == 0)
    {
        printf("Padre: %d\n", 2*valor[0]);
        pid_t hijo = fork();
        //
        if (hijo == 0)
        {
            printf("Hijo: %.2f\n", sqrtf(valor[2]));
            //
        }
    }
    //printf("Identificador de proceso PID %d\n", getpid());
}