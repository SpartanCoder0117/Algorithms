#include <stdio.h>
#include <stdlib.h>
#ifndef arbolbb
#define arbolbb

typedef struct nodo 		//Creamos una estructura del tipo nodo que tiene como valores
{
	int valor;			//Declaramos una variable del tipo entero
	struct nodo* izq;	//Declaramos un apuntador del tipo estructura a nodo
	struct nodo* der;	//Declaramos un apuntador del tipo estructura a nodo
}Nodo;

typedef Nodo Arbol;		//Re-definimos el nombre de la estructura Nodo a Arbol

Nodo* CrearNodo(int valor);						//Declaramos las funciones que utilizaremos en el documento tipo c
void Insertar(Nodo** arbol, int valor);
void Preorden(Nodo* arbol);
void GuardarRecorridoInOrden(Nodo* arbol,int A[]);
void Postorden(Nodo* arbol);
void OrdenaConArbolBinario(int A[],int n);

#endif