#include <stdio.h>
#include <stdlib.h>
#include "arbolbb.h"
#include "tiempo.h"

Nodo* CrearNodo(int valor);
void Insertar(Nodo** arbol, int valor);
void Preorden(Nodo* arbol);
void GuardarRecorridoInOrden(Nodo* arbol,int A[]);
void Postorden(Nodo* arbol);
void OrdenaConArbolBinario(int A[],int n);
void mostrarTiempos(double wtime1, double wtime0, double utime1, double utime0, double stime1, double stime0);
int i=0; 		//Se declara una variable global y se inicializa.


int main(int argc, char const *argv[])
{
	int x,*A,n;		// se crean 2 variables del tipo entero y una del tipo apuntador a entero
	double utime0, stime0, wtime0,utime1, stime1, wtime1; //Variables para medición de tiempos
	/*printf("Numeros N\n");		// se piden el numero de numeros que quiere ordenar
	scanf("%d",&n);*/
	n = atoi(argv[1]);			//Tamaño del arreglo a crear 	
	A = (int *)malloc(n*sizeof(int));	// Creamos el Arreglo
	for (int x = 0; x < n; ++x)
	{
		scanf("%d",&A[x]);			//Los ingresamos en el arreglo
	}
	uswtime(&utime0, &stime0, &wtime0);
	OrdenaConArbolBinario(A,n);
	uswtime(&utime1, &stime1, &wtime1);
	mostrarTiempos(wtime1, wtime0, utime1, utime0, stime1, stime0);
	return 0;
}

Nodo* CrearNodo(int valor){   
	Nodo* nuevoNodo = (Nodo *) malloc(sizeof(Nodo)); //Se crea un apuntador del tipo Nodo y se le asigna memoria dinamicamnete
	nuevoNodo->valor = valor;		//Por medio del operador flecha, asignamos el valor que recibe la funcion al valor del Nodo
	nuevoNodo->izq = nuevoNodo->der = NULL;	//Igualamos los valores de los apuntadores a NULL
	return nuevoNodo; 		// retornamos el Nodo
}

void Insertar(Nodo** arbol, int valor){		// Para insertar un valor al arbol, la funcion insertar recibe un doble apuntador (por la recursividad) y el valor a ingresar.
	if (*arbol == NULL)	//Preguntamos si el Nodo apunta a null (si el arbol esta vacio)
	{
		*arbol = CrearNodo(valor);	//Mandamos a llamar la funcion CrearNodo y le mandamos el valor a ingrear al árbol

	} else {
		int valorRaiz = (*arbol)->valor;		//Creamos un entero donde guardaremos el valor de la raiz
		if (valor < valorRaiz)			//Verificamos si el el valor de la raiz es mayor que el valor que se quiere insertar
		{
			Insertar(&(*arbol)->izq,valor);		//Mandamos recursivamente el valor a ingresar y el nodo izquierdo por ser menor el valor a ingresar
		} else{
			Insertar(&(*arbol)->der,valor);		//Mandamos recursivamente el valor a ingresar y el nodo derecho por ser mayor el valor a ingresar
			}
		}
}

void GuardarRecorridoInOrden(Nodo* arbol,int A[]){		//Se recibe el arbol y el valor a ingresar.
	if (arbol == NULL)		//verificamos que el nodo que se envio este vacio para verificar que sea el ultimo nodo hijo
	{
	//	printf("-");
	} else {
		GuardarRecorridoInOrden(arbol->izq,A);		//Se envia recursivamente el nodo izquierdo
		A[i]= arbol->valor;				// guardamos en el arreglo el valor más a la izquierda del arbol(menor)
		i++;							// incrementamos la variable
		GuardarRecorridoInOrden(arbol->der,A);		//Se envia recursivamente el nodo izquierdo
	}
}

void OrdenaConArbolBinario(int A[],int n){			//Se recibe el arreglo a ordenar junto con el tamaño del mismo
	Nodo *ArbolBinBusqueda = NULL;					//Se crea un arbol vacio
	int i;
	for (i = 0; i <n; ++i)
	{
		Insertar(&ArbolBinBusqueda,A[i]);			//Mandamos a llamar la funcion Insertar para llenar el arbol con los valores del arreglo
	}
	GuardarRecorridoInOrden(ArbolBinBusqueda,A);	//Llamamos la funcion que nos ordenara el arreglo inorden
}
void mostrarTiempos(double wtime1, double wtime0, double utime1, double utime0, double stime1, double stime0){
		//Cálculo del tiempo de ejecución del programa
	/*printf("%.10f \t %.10f \t %.10f \t %.10f",  wtime1 - wtime0, utime1 - utime0, stime1 - stime0, (utime1 - utime0 + stime1 - stime0) / (wtime1 - wtime0));
	printf("\n");*/
	printf("%.10e \t %.10e \t %.10e \t %.10f",  wtime1 - wtime0, utime1 - utime0, stime1 - stime0, (utime1 - utime0 + stime1 - stime0) / (wtime1 - wtime0));
	printf("\n");
}