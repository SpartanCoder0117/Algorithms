/*Compilación: "gcc Seleccion.c tiempo.o  -o seleccion
  Ejecución: ./seleccion n < numeros10millones.txt >> salidaSeleccion.txt
  Codigo que utiliza el metodo de Inserción para ordenar numeros*/

#include <stdio.h>
#include <stdlib.h>
#include "tiempo.h"

void Selecccion(int A[], int n);
void llenarArreglo(int A[], int n);
void mostrarArreglo(int A[], int n);
void mostrarTiempos(double wtime1, double wtime0, double utime1, double utime0, double stime1, double stime0);
/*Función principal 
Como argumentos recibe el tamaño del arreglo a ordenar
*/
void main(int argc, char *argv[]){
	int n, *a;	//Declaracion de la variable que define el tamaño del arreglo y un apuntador a entero para el arreglo
	double utime0, stime0, wtime0,utime1, stime1, wtime1; //Variables para medición de tiempos
	n = atoi(argv[1]); //asignnación del tamaño del argumento por parametros
	a = (int *)malloc(n*sizeof(int)); //creacion del arreglo  de tamaño n
	llenarArreglo(a, n); //llama a la función para llenar el arreglo
	uswtime(&utime0, &stime0, &wtime0); //obtener los tiempos iniciales del sitema
	Selecccion(a, n); //llama a la función para ordenar por selecion
	uswtime(&utime1, &stime1, &wtime1); //obtener los tiempos del sitema
	printf("\nN = %d\n", n);
	mostrarArreglo(a, n); //llama a la función para mortrar el arreglo
	mostrarTiempos(wtime1, wtime0, utime1, utime0, stime1, stime0); //llama a la función para mostrar los tiempos de ejecución
}
/*Funcion para ordenar por el metodo de seleccion
recibe un arreglo y su tamaño
Recorre el arreglo y busca el n-esimo menor y lo coloca en la posicion n*/
void Selecccion(int A[], int n){
	int k, p, i, temp;				//creacion de varibles para recorrer el arreglo y guardar temporalmente un valor
	for(k=0; k<=n-2; k++){			//recorrer todo el arreglo
		p=k;						//guardar en p la posicion actual del arreglo
		for(i=k+1; i<=n-1; i++){	//Recorrer el resto de elementos para buscar el menor
			if(A[i]<A[p]){			//comparar si el elemento actual es mayor al del segundo recorrido
				p=i;				//hacer el cambio deonde p es la posicion del menor
			}
		}
		temp = A[p];				//realizar el cambio entre la posicion actual y el numero menor
		A[p] = A[k];
		A[k] = temp;
	}
}

/*Funcion para llenar un arreglo recibe el arreglo y su tamaño*/
void llenarArreglo(int A[], int n){	
	int i;				//variable para ir rrecorrriendo el arreglo
	for(i=0; i<n; i++){	//recorrer el arreglo
		scanf("%d", &A[i]);	//llenar los elementos del arreglo por entrada estandar
	}
}
/*Funcion para poder ver el arreglo ya ordenado recibe el arreglo y su tamaño*/
void mostrarArreglo(int A[], int n){
	int i;			//variable para ir recorriendo el arreglo
	for(i=0; i<n; i++){	//recorrer el arreglo 
		printf("%d ", A[i]); //mostrar los miembros del arreglo
	}
	printf("\n");	
}
/*Funcion para mostrar los tiempos de ejecucion del programa
recibe los tiempos iniciales y finales obtenidos*/
void mostrarTiempos(double wtime1, double wtime0, double utime1, double utime0, double stime1, double stime0){
		//Cálculo del tiempo de ejecución del programa
	/*printf("%.10f \t %.10f \t %.10f \t %.10f",  wtime1 - wtime0, utime1 - utime0, stime1 - stime0, (utime1 - utime0 + stime1 - stime0) / (wtime1 - wtime0));
	printf("\n");*/
	printf("%.10e \t %.10e \t %.10e \t %.10f",  wtime1 - wtime0, utime1 - utime0, stime1 - stime0, (utime1 - utime0 + stime1 - stime0) / (wtime1 - wtime0));
	printf("\n");
}