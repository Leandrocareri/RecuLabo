#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "LinkedList.h"
#include "redes.h"
#include <time.h>
#include "controller.h"

eRedes* redes_new(){
	eRedes* nuevaRed = (eRedes*) malloc(sizeof(eRedes));
    return nuevaRed;
}


eRedes* redes_newParametros(int id,char* user,int likes,int dislikes, int followers){
	eRedes* nuevaRed= redes_new();
    if(nuevaRed != NULL && user != NULL){
        if(!(redes_setId(nuevaRed,id) &&
        	 redes_setUser(nuevaRed,user) &&
			 redes_setLikes(nuevaRed,likes) &&
             redes_setDislikes(nuevaRed,dislikes) &&
			 redes_setFollowers(nuevaRed,followers))){
        		redes_delete(nuevaRed);
                nuevaRed = NULL;
           }
    }
    return nuevaRed;
}

eRedes* redes_newParametrosString(char* id,char* user,char* likes,char* dislikes,char* followers)
{
    	return redes_newParametros(atoi(id),user,atoi(likes),atoi(dislikes),atoi(followers));
}


eRedes* redes_newRed (eRedes red){
    return redes_newParametros(red.id,red.user,red.likes,red.dislikes,red.followers);
}


int redes_setId(eRedes* this,int id){
    int todoOk = 0;
    if(this != NULL && id >= 1 && id <= 9999 ){ //VALIDACION DE ID
    	this->id = id;
        todoOk = 1;
    }
    return todoOk;
}
int redes_getId(eRedes* this,int* id){
    int todoOk = 0;
    if(this != NULL && id!= NULL){
        (*id) = this->id;
        todoOk = 1;
    }
    return todoOk;
}

int redes_setUser(eRedes* this,char* usuario){
    int todoOk = 0;
    if(this != NULL && usuario != NULL && strlen(usuario) > 1 && strlen(usuario) < 50){ //VALIDAR NOMBRE
        strcpy(this->user,usuario);
        todoOk = 1;
    }
    return todoOk;
}

int redes_getUser(eRedes* this,char* usuario){
    int todoOk = 0;
    if(this != NULL && usuario!=NULL){
        strcpy(usuario,this->user);
        todoOk = 1;
    }
    return todoOk;
}

int redes_setLikes(eRedes* this,int likes){
    int todoOk = 0;
    if(this != NULL && likes>= 0){
    	this->likes = likes;
        todoOk = 1;
    }
    return todoOk;
}
int redes_getLikes(eRedes* this,int* likes){
    int todoOk = 0;
    if(this != NULL && likes!= NULL){
        (*likes) = this->likes;
        todoOk = 1;
    }
    return todoOk;
}


int redes_setDislikes(eRedes* this,int dislikes){
    int todoOk = 0;
    if(this != NULL && dislikes>= 0){
    	this->dislikes = dislikes;
        todoOk = 1;
    }
    return todoOk;
}
int redes_getDislikes(eRedes* this,int* dislikes){
    int todoOk = 0;
    if(this != NULL && dislikes!= NULL){
        (*dislikes) = this->dislikes;
        todoOk = 1;
    }
    return todoOk;
}


int redes_setFollowers(eRedes* this,int followers){
    int todoOk = 0;
    if(this != NULL && followers>= 0){
    	this->followers= followers;
        todoOk = 1;
    }
    return todoOk;
}
int redes_getFollowers(eRedes* this,int* followers){
    int todoOk = 0;
    if(this != NULL && followers!= NULL){
        (*followers) = this->followers;
        todoOk = 1;
    }
    return todoOk;
}


void redes_delete(eRedes* red){
	free(red);
}




void redes_deleteLista (LinkedList* redes){
    	int cursor = 0;
        eRedes* redActual;
        int tamanioLista = ll_len(redes);
         while( tamanioLista > cursor){
             redActual = ll_get(redes,cursor);
             redes_delete(redActual);
             cursor++;
         }
         ll_clear(redes);
        printf("Se limpiaron %d redes de un total de %d cargadas en la lista \n",cursor,tamanioLista);
}



void mostrarRed(eRedes* red)
{
    if(red!=NULL){
    	printf("%6d %22s %15d %15d %15d\n",red->id,red->user,red->likes,red->dislikes,red->followers);
    }else{
        printf("No hay redes para mostrar\n");
        system("pause");
    }
}



int filterMejores(void* redes)
{
    int todoOk=0;
    if(redes!=NULL)
    {
        eRedes* redes = (eRedes*) redes;
        if(redes->likes>=4000)
        {
            todoOk=1;
        }
    }
    return todoOk;
}



int filterHaters(void* redes)
{
    int todoOk=0;
    if(redes!=NULL)
    {
        eRedes* redes = (eRedes*) redes;
        if(redes->likes<redes->dislikes)
        {
            todoOk=1;
        }
    }
    return todoOk;
}


int redes_sortByFollowers(void* red1,void* red2)
{
	int todoOk = 0;
	    eRedes* r1 = redes_new();
	    eRedes* r2 = redes_new();

	    if(r1 != NULL && r2 != NULL)
	    {
	        r1=(eRedes*)red1;
	        r2=(eRedes*)red2;

	        if(r1->followers< r2->followers)
	        {
	            todoOk=1;
	        }
	        else if(r1->followers> r2->followers)
	        {
	            todoOk = -1;
	        }
	        else
	        {
	            todoOk=0;
	        }
	    }
	    return todoOk;
}
