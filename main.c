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

int main()
{
    srand(time(NULL));
    int respuesta;
    LinkedList* redes = ll_newLinkedList();
    LinkedList* redesConLikes= NULL;
   // LinkedList* redesOrdenadas=NULL;

    char path[30];
   // int id = 1;
    int cantidadRedes = 0;
    int flagEstadisticas = 0;

    do
    {
        cantidadRedes = ll_len(redes);

        switch(respuesta = pedirMenu())
        {
        case 1:
            if(pedirPath(path))
                controller_loadFromText(path,redes);
            break;
        case 2:
            if(cantidadRedes==0)
            {
                printf("No hay redes para mostrar\n");
            }
            else{
                if(!controller_ListRedes(redes))
                {
                    printf("No se pudo mostrar el listado\n");
                }
            }
            system("pause");
           break;
        case 3:
            if(cantidadRedes > 0 && (redesConLikes= controller_setLikes(redes))){
                    ll_deleteLinkedList(redes);
                    redes = redesConLikes;
                    controller_ListRedes(redes);
                flagEstadisticas=1;
                 }
            break;
        case 4:
            if(cantidadRedes>0 && flagEstadisticas==1)
            {
                controller_filterMejores(redes);
            }
            else{
                printf("No hay likes asignados\n");
            }
            system("pause");
            break;
        case 5:
             if(cantidadRedes>0 && flagEstadisticas==1)
            {
                controller_filterHaters(redes);
            }
            else{
                printf("No hay dislikes asignados\n");
            }
            system("pause");

            break;
        case 6: // ordenar por cantidad followers descendiente
            if(cantidadRedes>0 && flagEstadisticas==1)
            {
                controller_sortByFollowers(redes);
                controller_ListRedes(redes);

            }
            else
            {
                printf("No hay estadisticas asignadas para ordenar\n");
            }

            break;
        case 7:


            break;
        case 8:
            printf("Cerrando programa\n");
            break;
        default:
            printf("Opcion del menu erronea, vuelva a ingresar \n");
            break;
        }
        if(respuesta>1 && respuesta<8 && cantidadRedes<1)
        {
            printf("No hay redes cargadas\n");
        }
        system("pause");
        system("cls");
    }
    while(respuesta!=8);

    return 0;

}
