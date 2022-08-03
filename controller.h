#ifndef CONTROLLER_H_INCLUDED
#define CONTROLLER_H_INCLUDED



#endif // CONTROLLER_H_INCLUDED


int controller_loadFromText(char* path , LinkedList* redes);
int controller_ListRedes(LinkedList* redes);
LinkedList* controller_setLikes(LinkedList* redes);
void* likes (void* redesSinLikes);
int controller_saveAsText(char* path , LinkedList* redes);
int controller_filterMejores(LinkedList* redes);
int controller_filterHaters(LinkedList* redes);
int controller_sortByFollowers(LinkedList* redes);



