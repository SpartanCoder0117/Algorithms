#include <stdio.h>
#include <stdlib.h>

int knapsack(int cap, int tam[], int valor[], int n);
int max(int a, int b);

int main()
{
    int cap, n, i;
    scanf("%d %d", &cap, &n);
    int tam[n], valor[n];

    for(i = 0; i < n; i++)
        scanf("%d %d", &tam[i], &valor[i]);

    printf("%d\n", knapsack(cap, tam, valor, n));
    return 0;
}

int max(int a, int b)
{
    return (a > b)? a : b;
}

/*Existen 2 casos
1.- No hay elemento que agregar o no hay capacidad
2.- Si el elemento cabe en la maleta se puede o no incluir*/
int knapsack(int cap, int tam[], int valor[], int n)
{
    int i, j, K[n + 1][cap + 1];
    //Crea la tabla de memoizacion
    for(i = 0; i <= n; i++)
    {
        for(j = 0; j <= cap; j++)
        {
            //Si no hay nada que agregar
            if(i == 0|| j == 0) 
                K[i][j] = 0;
            else if(tam[i - 1] <= j)    
                K[i][j] = max(valor[i - 1] + K[i - 1][j - tam[i - 1]], K[i - 1][j]);
            else
                K[i][j] = K[i - 1][j];
        }
    }
    return K[n][cap];
}