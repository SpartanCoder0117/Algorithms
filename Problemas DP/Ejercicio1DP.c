//LIBRERIAS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//Funciones
int max(int a, int b);
int LCS(char *cadena1, char *cadena2, int m, int n);
//PROGRAMA PRINCIPAL
int main()
{
    char *cadena1, *cadena2, c;
    int i = 0, j = 1;
    cadena1 = (char*)malloc(sizeof(char));
    cadena2 = (char*)malloc(sizeof(char));

    while(c = getc(stdin), c!='\n')
    {
        cadena1 = (char*)realloc(cadena1, j * sizeof(char));
        cadena1[i] = c;
        i++;
        j++;
    }
    cadena1[i] = '\0';
    i = 0;
    j = 1;

    while(c = getc(stdin), c!='\n')
    {
        cadena2 = (char*)realloc(cadena2, j * sizeof(char));
        cadena2[i] = c;
        i++;
        j++;
    }
    cadena2[i] = '\0';
    printf("%d\n", LCS(cadena1, cadena2, strlen(cadena1), strlen(cadena2)));
    return 0;
}

int max(int a, int b)
{
    return (a > b)? a : b;
}

int LCS(char *cadena1, char *cadena2, int m, int n)
{
    int i, j, L[m + 1][n + 1];
    for(i = 0; i <= m; i++)
    {
        for(j = 0; j <= n; j++)
        {
            if(i == 0 || j == 0)
            {
                L[i][j] = 0;
            }else if(cadena1[i - 1] == cadena2[j - 1])            
                L[i][j] = L[i - 1][j - 1] + 1;
            else
                L[i][j] = max(L[i - 1][j], L[i][j - 1]);
        }
    }
    return L[m][n];
}