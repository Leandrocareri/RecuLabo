#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "LinkedList.h"
#include "redes.h"
#include <time.h>
#include "controller.h"
#include "parser.h"
#include "input.h"




int controller_loadFromText(char* path , LinkedList* redes)
{
	int todoOk=0;
	FILE* f;
	if(path != NULL && redes!= NULL)
	{
		f = fopen(path,"r");
		if(f != NULL)
		{
			parser_RedFromText(f,redes);
			fclose(f);
			todoOk = 1;
		}
	}
	return todoOk;
}
/*
int controller_loadFromText(char* path , LinkedList* redes,int* pId)
{
	int todoOk =0;
	int contador=0;
	char confirmacion = 's';
	FILE* f = fopen(path,"r");

	if(redes!=NULL && pId!=NULL && path!=NULL){
		if(f == NULL){
			printf("No se pudo abrir el archivo %s \n",path);

		}else{
			if(ll_len(redes) > 0){
				printf("Hay redes cargadas, desea sobrescribirlos ? s-n \n");
				fflush(stdin);
				scanf("%c",&confirmacion);
				fflush(stdin);
				confirmacion = tolower(confirmacion);
			}
			if(confirmacion == 's'){
				redes_deleteLista(redes);
				contador = parser_RedFromText(f,redes,pId);
				printf("Cantidad de redes cargados desde el archivo de texto: %s es: %d \n",path,contador);
				todoOk=1;
			}else
				printf("Se cancelo la carga de datos desde el archivo de texto \n");
		}
	}
	fclose(f);
    return todoOk;
}*/


int controller_ListRedes(LinkedList* redes)
{
	int todoOk = 0;

	if(redes != NULL)
	{
		todoOk = 1;
		eRedes* auxRed;
		int tam = ll_len(redes);

		printf("%6s %22s %15s %15s %15s\n","ID","USER","LIKES","DISLIKES","FOLLOWERS");
		printf("%6s %22s %15s %15s %15s\n","--","--------","-------------","------------","------------");
		for(int i=0;i<tam;i++)
		{
			auxRed = (eRedes*)ll_get(redes,i);
			mostrarRed(auxRed);
		}
		if(tam==0)
		{
			printf("No hay redes cargadas para mostrar.\n");
		}
		system("pause");
	}
	return todoOk;
}



LinkedList* controller_setLikes(LinkedList* redes){
    LinkedList* todoOk = NULL;
    if(redes!=NULL){
         LinkedList* redesConLikes= ll_map(redes,likes);
         if(redesConLikes!=NULL){
            todoOk = redesConLikes;
         }
    }
    return todoOk;
}


void* likes (void* redesSinLikes){
    eRedes* redesConLikes= (eRedes*) redesSinLikes;
    int min = 500;
    int max = 5000;
    int minD = 300;
    int maxD = 3500;
    int minF = 10000;
    int maxF = 20000;
    if(redesConLikes!=NULL){
        redesConLikes->likes= (int)((rand()%(max-min+1)) + min)/10;
        redesConLikes->dislikes= (int)((rand()%(maxD-minD+1)) + minD)/10;
        redesConLikes->followers= (int)((rand()%(maxF-minF+1)) + minF)/10;
    }
    return redesConLikes;
}


int controller_filterMejores(LinkedList* redes)
{
    int todoOk=0;
    char path[30];
    LinkedList* listaMejores = NULL;
    if(redes!=NULL)
    {
        listaMejores = ll_filter(redes,filterMejores);
    }

    if(listaMejores!=NULL)
    {
        pedirPath(path);
        controller_saveAsText(path,listaMejores);
        todoOk=1;
    }
    return todoOk;
}


int controller_filterHaters(LinkedList* redes)
{
    int todoOk=0;
    char path[30];
    LinkedList* listaHaters = NULL;
    if(redes!=NULL)
    {
        listaHaters = ll_filter(redes,filterHaters);
    }

    if(listaHaters!=NULL)
    {
        pedirPath(path);
        controller_saveAsText(path,listaHaters);
        todoOk=1;
    }
    return todoOk;
}


int controller_sortByFollowers(LinkedList* redes){
    int todoOk = 0;
    if(redes!=NULL){
        if(ll_sort(redes,redes_sortByFollowers,1)){
            controller_ListRedes(redes);
            todoOk = 1;
        }

    }
    return todoOk;
}


int controller_saveAsText(char* path , LinkedList* redes)
{
    int todoOk = 0;
    if(path != NULL && redes!= NULL)
    {
    	FILE* f = fopen(path,"w");

    	if(f != NULL)
    	{
    		int auxId;
    		char auxUser[30];
            int auxLikes;
            int auxDislikes;
            int auxFollowers;

			for(int i=0; i<ll_len(redes); i++)
			{
				eRedes* auxRed = (eRedes*)ll_get(redes,i);

				redes_getId(auxRed,&auxId);
				redes_getUser(auxRed,auxUser);
				redes_getLikes(auxRed,&auxLikes);
				redes_getDislikes(auxRed,&auxDislikes);
				redes_getFollowers(auxRed,&auxFollowers);

				fprintf(f,"%d,%s,%d,%d,%d\n",auxId,auxUser,auxLikes,auxDislikes,auxFollowers);
			}
			fclose(f);
			todoOk = 1;
		}
    }
	return todoOk;
}
