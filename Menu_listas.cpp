#include <iostream>
#include<stdlib.h>
#include<stdio.h>

using namespace std;

struct nodo{
	int dato;
	nodo *next;
};

void insertnodo();
void mostrarpila();
void buscarnodo();
void modificarnodo();
void eliminarnodo();
void ordenarDatos(nodo*prila);
void ordenar(nodo*prila);
nodo *prila=NULL;


int main() {
	int opcion=0;
	do{
		system("color 0a");
		printf("\n|-------------------------------------------------------------|");
		printf("\n|                        *[  MENU PILA  ]*                    |");
		printf("\n|-------------------------------------------------------------|");
		printf("\n|  1. Insertar                    |  5.Eliminar               |");
		printf("\n|  2. Buscar                      |  6.ordenardatos           |");
		printf("\n|  3. listar                      |  0.salir                  |");
		printf("\n|  4.Modidficar                   |                           |");
		printf("\n|-------------------------------------------------------------|");
		printf("\n Seleccione la Opcion: ");
		scanf("%d",&opcion);
		switch(opcion){
			case 1:{
				insertnodo();
				break;
			   }
			   case 2:{
			    buscarnodo();
				break;
			   }
			   case 3:{
			    mostrarpila();
				break;
			   }
			   case 4:{
			    modificarnodo();
				break;
			   }
			   case 5:{
			   	eliminarnodo();
				break;
			   }
			   case 6:{
			   	void ordenar(nodo*prila);
				break;
			   }
				case 0:{
					exit(0);
					break;
				}
				default:{
					printf("\n Opcion no valida");
					break;
				}
		}
		
		
	}while(opcion!=0);

	system("pause");
	return 0;
}

// 23,20,18
// prila =null
// 18-> null

void insertnodo(){
	int cant,dato,i;
	nodo *nuevo= (nodo*)malloc(sizeof(nodo));
	printf("ingrese la cantidad de datos a ingresar: \n ");
	scanf("%d",&cant);
	
		for(i=0;i<=cant;i++){
			printf("ingrese el valor deseado:");
			nodo *nuevo= (nodo*)malloc(sizeof(nodo));
			scanf("%d",&nuevo->dato);
			nuevo->next=prila;
	        prila=nuevo;
		}
		
}

void mostrarpila(){
	nodo *actual=(nodo*)malloc(sizeof(nodo));
	actual=prila;
	if(prila!=NULL){
		while(actual!=NULL){
			printf("\n %d \n",actual->dato);
			actual=actual->next;
		}
	}else{
		printf(" la pila esta vacia");
	}
}

void buscarnodo(){
	nodo *actual=(nodo*)malloc(sizeof(nodo));
	actual=prila;
	int nodogoogle=0, gotin=0;
	printf("\n Ingrese el dato del Nodo a Buscar: ");
	scanf("%d",&nodogoogle);
	if(prila!=NULL){
		while(actual!=NULL){
			
			if(actual->dato == nodogoogle){
				printf("\n El dato(%d) fue encontrado \n",nodogoogle);
				gotin=1;
			}
			
			printf("\n %d \n",actual->dato);
			actual=actual->next;
		}
		if(gotin == 0){
			printf("\n Nodo no encontrado \n");
	   }
	}else{
		printf(" la pila esta vacia");
	}
}

void modificarnodo(){
	nodo *actual=(nodo*)malloc(sizeof(nodo));
	actual=prila;
	bool gotin=false;
	int change,nodogoogle;
	printf("\n Ingrese el dato del Nodo a Buscar  para su modidficacion: ");
	scanf("%d",&nodogoogle);
	if(prila!=NULL){
		while(actual!=NULL && gotin!=true){
			
			if(actual->dato == nodogoogle){
				printf("\n El dato(%d) fue encontrado \n",nodogoogle);
				printf("\n Ingrese el nuevo dato del nodo a modificar: \n");
				scanf("%d",&change);
				actual->dato=change;
				printf("Nodo modificado \n ");
				gotin=true;
			}
			printf("\n %d \n",actual->dato);
			actual=actual->next;
		}
		if(!gotin){
			printf("\n Nodo no encontrado \n");
	   }
	}else{
		printf(" la pila esta vacia");
	}
}

void eliminarnodo(){
	nodo *actual=(nodo*)malloc(sizeof(nodo));
	nodo *anterior=(nodo*)malloc(sizeof(nodo));
	actual=prila;
	anterior=NULL;
	int nodogoogle=0;
	bool gotin=false;
	printf("\n Ingrese el dato del Nodo a Buscar  para eliminarlo: ");
	scanf("%d",&nodogoogle);
	if(prila!=NULL){
		while(actual!=NULL){
			
			if(actual->dato == nodogoogle){
				printf("\n El dato(%d) fue encontrado \n",nodogoogle);
				
				if(actual == prila){
					prila=prila->next;
				}else{
					anterior->next=actual->next;
				
				}
				
				printf("El nodo fue eliminado ");
				gotin=true;
			}
			
			printf("\n %d \n",actual->dato);
			anterior=actual;
			actual=actual->next;
		}
		if(gotin == 0){
			printf("\n Nodo no encontrado \n");
	   }
	}else{
		printf(" la pila esta vacia");
	}
}

void ordenarDatos(nodo*prila){
	        int aux;
			nodo*x = prila;
			nodo*y = prila;
		    while(x !=NULL){
			y = x -> next;
		    	while (y != NULL){
				   if (x -> dato > y ->dato){
					aux = x -> dato;
					x -> dato = y -> dato; 
					y -> dato = aux;
				}
				y = y -> next;
			}
			x = x -> next;
		}
	}
	
	void ordenar(nodo*prila){
		int n;
		if(prila==NULL){
			printf(" la pila esta vacia \n");
		}else{
			mostrarpila();
			nodo*aux=prila;
			while(aux != NULL){
				nodo * aux2 = aux -> next;
				while(aux2 != NULL){
					if(aux -> dato > aux2 -> dato){
						n=aux2 -> dato;
						aux2 -> dato = aux ->dato;
						aux ->dato = n;
					}
					aux2 = aux2 -> next;
				}
				aux = aux -> next;
			}
			printf("\n Datos Ordenados \n");
			mostrarpila();
		}
	       
	}
