/*Compilación: "gcc Insercion.c tiempo.o  -o Insercion
  Ejecución: ./Insercion n < numeros10millones.txt >> salidaInsercion.txt
  Codigo que utiliza el metodo de Inserción para ordenar numeros

*/

#include <stdio.h>
#include <stdlib.h>
#include "tiempo.h"
//Declaración de finciones
void Insercion(int A[], int n);
void llenarArreglo(int A[], int n);
void mostrarArreglo(int A[], int n);
void mostrarTiempos(double wtime1, double wtime0, double utime1, double utime0, double stime1, double stime0);

/*Función principal 
Como argumentos recibe el tamaño del arreglo a ordenar
*/
void main(int argc, char *argv[]){
	int n, *a;	//Declaracion de la variable que define el tamaño del arreglo y un apuntador a entero para el arreglo
	double utime0, stime0, wtime0,utime1, stime1, wtime1; //Variables para medición de tiempos
	n = atoi(argv[1]);	//asignnación del tamaño del argumento por parametros
	a = (int *)malloc(n*sizeof(int));	//creacion del arreglo  de tamaño n
	llenarArreglo(a, n);	//llama a la función para llenar el arreglo
	uswtime(&utime0, &stime0, &wtime0);	//obtener los tiempos iniciales del sitema
	Insercion(a, n);	//llama a la función para ordenar por insercion
	uswtime(&utime1, &stime1, &wtime1);	//obtener los tiempos del sitema
	printf("\nN = %d\n", n);
	mostrarArreglo(a, n);	//llama a la función para mostrar el arreglo
	printf("Tiempo total \tTiempo CPU\t Tiempo E/S \tCPU/WALL\n");
	mostrarTiempos(wtime1, wtime0, utime1, utime0, stime1, stime0);	//llama a la función para mostrar los tiempos de ejecución
}

/*Funcion para ordenar por el metodo de insercion
recibe un arreglo y su tamaño
considera que los numeros a la izquierda de la posicion que recorre el arreglo estan ordenados
luego compara y lo inserta donde corresponda*/
void Insercion(int A[], int n){
	int i, j, temp;
	for(i=1; i<n; i++){				//recorrer todos los elementos de arreglo
		j=i-1;						//empezar una posición antes de la actual
		temp = A[i];				//guardar la posicion actual
		while(j>=0 && temp<A[j]){	//recorrer a la izquierda y encontrar la posicion correcta
			A[j+1]=A[j];			//ir cambiando de posicion la seccion "ordenada"
			j--;					//decremento en la posicion del arreglo
		}
		A[j+1]=temp;				//colocarlo en la posicion correcta
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
