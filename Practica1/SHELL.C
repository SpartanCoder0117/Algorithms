#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "tiempo.h"

void Shell(int A[],int n);
void llenarArreglo(int A[], int n);
void mostrarArreglo(int A[], int n);
void mostrarTiempos(double wtime1, double wtime0, double utime1, double utime0, double stime1, double stime0);

int main(int argc, char const *argv[])
{	int n,b;				//Declaramos 3 variables del tipo entero
	int *A;					//declaramos 1 variable del tipo apuntador a entero
	double utime0, stime0, wtime0,utime1, stime1, wtime1; //Variables para medición de tiempos
	n=atoi(argv[1]);		//Pedimos la cantidad de numero a ordenar
	A = (int *)malloc(n*sizeof(n));		//Reservamos memoria para el arreglo donde guardaremos los numeros
	llenarArreglo(A, n);			//Mandamos a llamar la funcion llenarArreglo donde enviamos el arreglo y la cantidad de elementos a ordenar
	uswtime(&utime0, &stime0, &wtime0);		//Activamos la funcion del tiempo
	Shell(A,n);						//Llamamos la funcion que nos ordenara el arreglo con los numeros
		for (b = 0; b < n; b++)
	{
		printf("%d ",A[b]);				//Se imprime el arreglo ordenado
	}
	uswtime(&utime1, &stime1, &wtime1);//Se detiene la funcion tiempo
	//mostrarArreglo(A, n);
	printf("Tiempo total \tTiempo CPU\t Tiempo E/S \tCPU/WALL\n");		//Mostramos los tiempos
	mostrarTiempos(wtime1, wtime0, utime1, utime0, stime1, stime0);
	return 0;
}


void Shell(int A[],int n){				//Recibimos el arreglo a ordenar y el numero de elementos
	int k,b,i,temp;						//Declaramos 4 variables del tipo entero
	k=trunc(n/2);						//Asignamos a la variable k el valor del tamaño del arreglo divido en 2 sin valores flotantes mediante la funcion trunc 
	printf("k=%d\n",k);					//Imprime el valor que le asignamos a k			
	while(k>=1){						//Entramos en un ciclo donde mientras k sea mayor o igual 1, permaneceremos en el 
		b=1;							//Asignamos a b el valor de 1
		while(b!=0){					//Entramos en un ciclo donde mientras b sea diferente de 1, permaneceremos en el 
			b=0;						//Asignamos a b el valor de 0
			for (i = k;i<=n-1;i++)		//Entramos a un for donde le asigamos el valor de i el de k, y permaneceremos en el for mientras i sea menor o igual al tamaño del arreglo menos 1
			{
				if (A[i-k]>A[i])		//si el valor del arreglo que se encuentra en la posicion i-k es mayor al de la posicon i se hara este proceso
				{
					temp=A[i];			//asignamos el valor de arreglo en la posicion i a una variable temporal
					A[i]=A[i-k];		//intercambiamos los valores del arreglo en la posiocion i e i-k
					A[i-k]=temp;
					b=b+1;				//incrementamos a b
				}
			}
		}
		k=trunc(k/2);					//Disminuimos el valor de k en k/2 redondiando el resultdo hacia abajo(piso) con la funcion trunc
	}

	
}
void llenarArreglo(int A[], int n){
	int i;
	for(i=0; i<n; i++){
		scanf("%d", &A[i]);
	}
}

void mostrarArreglo(int A[], int n){
	int i;
	for(i=0; i<n; i++){
		printf("%d ", A[i]);
	}
	printf("\n");	
}
void mostrarTiempos(double wtime1, double wtime0, double utime1, double utime0, double stime1, double stime0){
		//Cálculo del tiempo de ejecución del programa
	/*printf("%.10f \t %.10f \t %.10f \t %.10f",  wtime1 - wtime0, utime1 - utime0, stime1 - stime0, (utime1 - utime0 + stime1 - stime0) / (wtime1 - wtime0));
	printf("\n");*/
	printf("%.10e \t %.10e \t %.10e \t %.10f",  wtime1 - wtime0, utime1 - utime0, stime1 - stime0, (utime1 - utime0 + stime1 - stime0) / (wtime1 - wtime0));
	printf("\n");
}
