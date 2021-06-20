//Librerias
#include <stdio.h>
#include <stdlib.h>

int ELIS(int *A, int n);
int rInd(int *A, int l, int r, int num);

//Programa principal
int main()
{
    int *A, n, i;
    scanf("%d",&n);
    A = (int*)malloc(n*sizeof(int));
    for(i = 0; i < n; i++)
        scanf("%d", &A[i]);

    printf("%d\n", ELIS(A, n));
    return 0;
}
//Esta funcion encuentra la longitud de la subsecuencia
int ELIS(int *A, int n)
{
    if(n == 0)
        return 0;

    int *L;
    L = (int*)malloc(n*sizeof(int));
    int l = 1; 
    L[0] = A[0];
    int i;
    for(i = 1; i < n; i++)
    {
        if(A[i] < L[0])
            //Elemento menor nuevo
            L[0] = A[i]; 
        else if(A[i] > L[l - 1])  
            //Se agrega un elemento nuevo 
            L[l++] = A[i];
        else    
            //Se remplaza el central y se desechan los del final
            L[rInd(L, -1, l-1, A[i])] = A[i];
    }
    return l;
}
//Esta funcion remplaza el arreglo a partir del indice que se le mande
int rInd(int *A, int l, int r, int num)
{
    while(r-l > 1)
    {
        int m = l + (r - l)/2;
        if(A[m] >= num)
            r = m;
        else
            l = m;    
    }
    return r;
}