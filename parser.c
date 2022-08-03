#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "LinkedList.h"
#include "redes.h"
#include <time.h>
#include "controller.h"
#include "input.h"
#include "parser.h"


/*
int parser_RedFromText(FILE* pFile , LinkedList* redes,int* pId){
	int datosLeidos = 0;
	int datosCargados=0;
	char buffer [5][50];
    eRedes* redNueva = NULL;
    int mayorId = 0;
    int esPrimero = 1;
    char encabezado[]={"id,usuario,likes,dislikes,followers"};
    char comprobacion[strlen(encabezado)+1];
    fgets(comprobacion,strlen(encabezado)+1,pFile);

    if(!strcmp(comprobacion,"id,usuario,likes,dislikes,followers")){
    	do{
			datosLeidos = fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",buffer[0],buffer[1],buffer[2],buffer[3],buffer[4]);

			if(datosLeidos==5){
				redNueva = redes_newParametros(atoi(buffer[0]),buffer[1],atoi(buffer[2]),atoi(buffer[3]),atoi(buffer[4]));
				if(redNueva){
					if(redNueva->id > mayorId || esPrimero){
						mayorId = redNueva->id;
						esPrimero = 0;
					}
					ll_add(redes,redNueva);
					datosCargados++;
				}
			}
		}while(!feof(pFile));

		(*pId) = mayorId +1;
    }else{
    	printf("Error esta intentando abrir un archivo binario o error en el encabezado del archivo \n");
    	printf("Formato de encabezado: id,titulo,likes,dislikes,followers\n");
    }

	return datosCargados;

}*/


int parser_RedFromText(FILE* pFile , LinkedList* redes)
{
    char buffer[5][20];
	int cant;
	int todoOk = 0;
	//int a; //ver
	eRedes* newRed;

	if(pFile != NULL && redes != NULL)
	{
		fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",buffer[0],buffer[1],buffer[2],buffer[3],buffer[4]); //lectura fantasma

		do{
			cant = fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",buffer[0],buffer[1],buffer[2],buffer[3],buffer[4]);
			if(cant<5)
			{
				break;
			}
			newRed = redes_newParametrosString(buffer[0],buffer[1],buffer[2],buffer[3],buffer[4]);
			ll_add(redes,newRed);
			todoOk = 1;
		} while(!feof(pFile));
	}
    return todoOk;
}
