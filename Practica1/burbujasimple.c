//Compilación: "gcc Insercion.c tiempo.o  -o Insercion

#include <stdio.h>
#include <stdlib.h>
#include "tiempo.h"

void BurbujaSimple(int A[],int n);
void llenarArreglo(int A[], int n);
void mostrarArreglo(int A[], int n);
void mostrarTiempos(double wtime1, double wtime0, double utime1, double utime0, double stime1, double stime0);


void main(int argc, char *argv[]){
	int n, *a;
	double utime0, stime0, wtime0,utime1, stime1, wtime1; //Variables para medición de tiempos
	n = atoi(argv[1]);
	a = (int *)malloc(n*sizeof(int));
	llenarArreglo(a, n);
	uswtime(&utime0, &stime0, &wtime0);//Inicia el proceso para medir el tiempo
	BurbujaSimple(a, n);Llamamos a la funcion
	uswtime(&utime1, &stime1, &wtime1);//Termina el proceso para medir el tiempo
	printf("\nN = %d\n", n);
	//mostrarArreglo(a, n);
	printf("Tiempo total \tTiempo CPU\t Tiempo E/S \tCPU/WALL\n");
	mostrarTiempos(wtime1, wtime0, utime1, utime0, stime1, stime0);


}//Fin de main
/*////////////////////////////////////////////////
BurbujaSimple ordena los numeros comparando todos los elementos del arreglo,
compara todos los elementos contra todos
////////////////////////////////////////////////*/
void BurbujaSimple(int A[],int n){
int i,j,aux;

for(i=0;i<=(n-2);i++)//Primer ciclo
  {
	for(j=0;j<(n-2)-i;j++)//Segundo ciclo, que va hasta
	{
	if(A[j]>A[j+1]){//Si uno es mayor a otro los intercambia de pocision
		aux=A[j];	
		A[j]=A[j+1];
		A[j+1]=aux;
		}//fin de si
	}
  }	
}//FIn de BurbujaSimple

/*////////////////////////////////////////////////
llenarArreglo se encarga de ingresar los elementos al arreglo 
////////////////////////////////////////////////*/

void llenarArreglo(int A[], int n){
	int i;
	for(i=0; i<n; i++){
		scanf("%d", &A[i]);
	}
}
/*////////////////////////////////////////////////
 mostrarArreglo se encarga de mostrar los elementos del arreglo 
////////////////////////////////////////////////*/
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

