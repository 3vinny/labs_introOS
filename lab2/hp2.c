/*
    Lab 2: Creación y duplicación de procesos
    1. Realizar un programa [hijo_padre_abuelo] que muestre a través de sus ID la creación de ellos.
    2. Ingresar por paso de parámetros tres valores enteros, indicar al padre que duplique el primer valor, al abuelo que eleve  a la potencia 3 el segundo valor y que el hijo obtenga la raíz del tercer valor.
    3. Dado un conjunto de valores del tipo {a,b,c} obtener las raíces de una ecuación cuadrática cuyos factores son a,b,c.  Resolver utilizando hilos (fork())
    4. Comparar su resultado anterior con la solución secuencial "sin fork()"
    5. Compare valores de una variable creada por Ud en proceso padre con la misma variable del proceso hijo. Es el mismo valor? Justifique
*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char** argv)
{
    int valor1 = 0;
    scanf("%d", &valor);
    return 0;
}