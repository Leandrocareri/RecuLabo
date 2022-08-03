#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "LinkedList.h"
#include "redes.h"
#include <time.h>
#include "controller.h"
#include "input.h"


int pedirMenu(){
    int respuesta;
    printf("----------------------------\n");
    printf("1) Cargar archivo \n");
    printf("2) Imprimir lista \n");
    printf("3) Asignar estadisticas \n");
    printf("4) Filtrar por mejores posteos\n");
    printf("5) Filtrar por haters\n");
    printf("6) Ordenar por cantidad de followers\n");
    printf("7) Mostrar mas popular \n");
    printf("8) Salir \n");
    printf("----------------------------\n");
    printf("Ingrese opcion: ");
    fflush(stdin);
    scanf("%d",&respuesta);
    fflush(stdin);
    printf("----------------------------\n");

    return respuesta;
}



int pedirPath(char* path){
	int todoOk = 0;
	char pathAux [30];
	if(path!=NULL){
		 path[0]='\0';
		 printf("Ingrese el Path: ");
		 fflush(stdin);
		 gets(pathAux);
		 fflush(stdin);
		 while(strlen(pathAux) <= 0 || strlen(pathAux) >= 30){
			 printf("Ingrese un Path mas corto/largo: ");
			 fflush(stdin);
			 gets(pathAux);
			 fflush(stdin);
		 }
		 strcat(path,pathAux);
		 todoOk = 1;
	}
     printf("----------------------------\n");
	 return todoOk;
}

