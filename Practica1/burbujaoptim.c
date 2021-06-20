//Compilación: "gcc Insercion.c tiempo.o  -o Insercion

#include <stdio.h>
#include <stdlib.h>
#include "tiempo.h"

void BurbujaOptimizada(int A[],int n);
void llenarArreglo(int A[], int n);
void mostrarArreglo(int A[], int n);
void mostrarTiempos(double wtime1, double wtime0, double utime1, double utime0, double stime1, double stime0);

void main(int argc, char *argv[]){
	int n, *a;
	double utime0, stime0, wtime0,utime1, stime1, wtime1; //Variables para medición de tiempos
	n = atoi(argv[1]);      //Tamaño del arreglo a crear 	
	a = (int *)malloc(n*sizeof(int));
	llenarArreglo(a, n);//Llenamos el arreglo
	uswtime(&utime0, &stime0, &wtime0);//Inicia el proceso para medir el tiempo
	BurbujaOptimizada(a, n);//Llamamos a la funcion
	uswtime(&utime1, &stime1, &wtime1);//Termina el proceso para medir el tiempo
	printf("\nN = %d\n", n);
	//mostrarArreglo(a, n);
	printf("Tiempo total \tTiempo CPU\t Tiempo E/S \tCPU/WALL\n");
	mostrarTiempos(wtime1, wtime0, utime1, utime0, stime1, stime0);
}

/*////////////////////////////////////////////////
BurbujaOptimizada ordena los numeros comparando los elementos del arreglo,
cuando el elemento mayor queda en su pocision no es necesario volver a comparar
////////////////////////////////////////////////*/

void BurbujaOptimizada(int A[],int n){
int i,j,aux,cambios;
i=0;
cambios=1;//Flag
while( (i<n-1) && cambios!=0 ){//Se realizara el while siempre y cuando i no supere el tamaño de n y cambios sea "No"
	cambios=0;
	for(j=0;j<n-1-i;j++){
		if(A[j]>A[j+1]) {//Si el primero es mayor que el segundo los ordena
			aux=A[j];
			A[j]=A[j+1];
			A[j+1]=aux;
			cambios=1;
		}//Fin de If	
			}//Fin de FOR
	i=i+1;	
}//Fin de While

}//Fin de Burbuja Optimizada

/*////////////////////////////////////////////////
llenarArreglo se encarga de ingresar los elementos al arreglo 
////////////////////////////////////////////////*/

void llenarArreglo(int A[], int n)
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
