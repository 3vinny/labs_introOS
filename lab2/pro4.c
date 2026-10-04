// 4. Comparar su resultado anterior con la solución secuencial "sin fork()". 
// [version secuencial del proceso 3]
#include <stdio.h>
#include <stdlib.h> // atof()
#include <math.h> // sqrt raiz, fabs valor absoluto
//#include <unistd.h> //fork(), ya no
//#include <sys/wait.h> //wait(), ya no

/* Resuelve una ecuación e imprime el resultado */
void resolver(int n, double a, double b, double c)
{
    if (a == 0)
    {
        printf("EC %d: a=0, no es cuadratica\n", n);
        return;
    }

    /* Casos:
    1) raices reales
    2) un solo raiz real
    3) raices complejas j +- ki 
    */
    double discrim = b*b - 4*a*c;
    if (discrim > 0)
    {
        float x1 = (-b + sqrt(discrim)) / (2*a);
        float x2 = (-b - sqrt(discrim)) / (2*a);
        printf("EC %d: x1=%.2f, x2=%.2f\n", n, x1, x2);
    }
    else if (discrim == 0)
    {
        float x = -b / (2*a);
        printf("EC %d: x = %.2f\n", n, x);
    }
    else
    {
        // RAICES COMPLEJAS
        float j = -b / (2*a);
        float k = sqrt(-discrim) / (2*fabs(a));
        printf("EC %d: raices complejas[j,k]: %.2f +- %.2fi\n", n, j, k);
    }
}

int main(int argc, char *argv[])
{
    FILE *archivo = fopen("ec.txt", "r");
    if (archivo == NULL)
    {
        printf("Error al abrir el archivo ec.txt\n");
        return 1;
    }

    char linea[100];
    int n = 0; /* Cuantas ecuaciones hemos leido */

    while (fgets(linea, sizeof(linea), archivo) != NULL)
    {
        int i = 0;
        // 1.Cambia la coma decimal por punto
        while (linea[i] != '\0')
        {
            if (linea[i] == ',')
                linea[i] = '.';
            i++;
        }

        // Leer a,b,c
        float a, b, c;
        if (sscanf(linea, "%f %f %f", &a, &b, &c) != 3)
        {
            continue;
        }
        n++;

        resolver(n, a, b, c); //resuelve la ecuación
    }
    fclose(archivo);
    return 0; // Programa finalizado con éxito
}