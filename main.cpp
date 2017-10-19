#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define reservar_memoria (nodo*)malloc(sizeof(nodo))
struct nodo{
	int dato;
	nodo * siguiente;
};

void menu();
void generarDatos(nodo*&,nodo*&);
void insertarDatosCola(int,nodo*&,nodo*&);
void ordenarDatos(nodo*);
void imprimirDatos(nodo*);


int main(){
	menu();
	return 0;
}
 void menu(){
 	nodo*inicio= NULL;
 	nodo*fin= NULL;
 	int opcion;
	do{
		system("color 0a");
		printf("\n|-------------------------------------------------------------|");
		printf("\n|                        *[  MENU COLA  ]*                    |");
		printf("\n|-------------------------------------------------------------|");
		printf("\n|  1. Generar Datos               |  5.Eliminar               |");
		printf("\n|  2. Ordenar                     |  6.ordenardatos           |");
		printf("\n|  3. listar                      |  0.salir                  |");
		printf("\n|  4.Modidficar                   |                           |");
		printf("\n|-------------------------------------------------------------|");
		printf("\n Seleccione la Opcion: ");
		scanf("%d",&opcion);
		switch(opcion){
	      case 0:
	      	exit(0);
	      	break;
	      case 1:
	      	generarDatos(inicio,fin);
	      	break;
	      case 2:
	      	ordenarDatos(inicio);
	      	break;
	      case 3:
	      	imprimirDatos(inicio);
	      	break;
	    default:
	    	printf("Opcion Invalida\n");
	    }
	 } while (opcion != 0);
 }
 
void generarDatos(nodo*&inicio,nodo*&fin){
	int cantDatos, i,aleatorio;
	printf("ingrese la cantidad de datos a generar \n");
	scanf ("%d", &cantDatos);
	srand(time(NULL));
	for (i=1; i <= cantDatos; i++){
		aleatorio =(rand()%(1999999 + 1)-1000000);
		insertarDatosCola (aleatorio,inicio, fin);
	}
}

void insertarDatosCola(int n,nodo*&inicio,nodo*&fin){
	nodo*nuevo_nodo = reservar_memoria;
	nuevo_nodo -> dato=n;
	nuevo_nodo ->siguiente = NULL;
	if (inicio == fin){
		inicio = nuevo_nodo;
	}else{
		fin->siguiente=nuevo_nodo;
	}
	fin=nuevo_nodo;
}
void ordenarDatos(nodo*inicio){
	        int aux;
			nodo*x = inicio;
			nodo*y = NULL;
	if (inicio ==NULL){
		printf("perfecto \n");
	}else{
		while(x !=NULL){
			nodo*y = inicio-> siguiente;
			while (y != NULL){
				if (x -> dato > y ->dato){
					aux = x -> dato;
					x -> dato = y -> dato; 
					y -> dato = aux;
				}
				y = y -> siguiente;
			}
			x = x -> siguiente;
		}
	}
}
void imprimirDatos(nodo*inicio){
	nodo *aux=inicio;
	if(inicio==NULL){
		printf("esta vacio\n");
	}else{
		while(aux!=NULL){
		printf("%d \n", aux -> dato);
		aux=aux->siguiente;	
		}
	}
}

