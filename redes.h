#ifndef REDES_H_INCLUDED
#define REDES_H_INCLUDED

typedef struct{
    int id;
    char user[50];
    int likes;
    int dislikes;
    int followers;
}eRedes;

#endif // REDES_H_INCLUDED

//Constructores

/** \brief reserva en memoria una estructura del tipo eRedes
 *
 * \return eRedes*,retorna la direccion en memoria reservada o NULL
 *
 */
eRedes* redes_new();

eRedes* redes_newParametros(int id,char* user,int likes,int dislikes, int followers);



/** \brief reserva en memoria una estructura del tipo eRedes inicialiando sus campos con los parametros
 *
 * \param id int,id a cargar en el campo id de la estructura
 * \param user char*,usuario a cargar en el campo user de la estructura
 * \param likes int, cantidad de likes a cargar en el campo likes de la estructura
 * \param dislikes int, cantidad de dislikes a cargar en el campo dislikes de la estructura
 * \param followers int, cantidad de followers a cargar en el campo followers de la estructura
 * \return eRedes*,retorna la direccion en memoria reservada o NULL
 *
 */
eRedes* redes_newParametrosString(char* id,char* user,char* likes,char* dislikes,char* followers);



/** \brief guarda el id del parametro en el campo id de la estructura del parametro
 *
 * \param this eRedes*, red que se le guarda el parametro id
 * \param id int,id a guardar
 * \return int, se realizo todo correcto 1 sino 0
 *
 */
int redes_setId(eRedes* this,int id);

/** \brief guarda el usuario en el campo user de la estructura del parametro
 *
 * \param this eRedes*, red que se le guarda el parametro titulo
 * \param char*,usuario a guardar
 * \return int, se realizo todo correcto 1 sino 0
 *
 */
int redes_setUser(eRedes* this,char* user);

/** \brief guarda la cantidad del parametro en el campo likes de la estructura del parametro
 *
 * \param this eRedes*, red que se le guarda el parametro likes
 * \param likes int,likes a guardar
 * \return int, se realizo todo correcto 1 sino 0
 *
 */
int redes_setLikes(eRedes* this,int likes);

/** \brief guarda la cantidad del parametro en el campo dislikes de la estructura del parametro
 *
 * \param this eRedes*, red que se le guarda el parametro dislikes
 * \param dislikes int,dislikes a guardar
 * \return int, se realizo todo correcto 1 sino 0
 *
 */
int redes_setDislikes(eRedes* this,int dislikes);

/** \brief guarda la cantidad del parametro en el campo followers de la estructura del parametro
 *
 * \param this eRedes*, red que se le guarda el parametro followers
 * \param followers int,followers a guardar
 * \return int, se realizo todo correcto 1 sino 0
 *
 */
int redes_setFollowers(eRedes* this,int followers);


/** \brief libera de memoria la red del parametro
 *
 * \param red eRedes*,red a liberar
 * \return void
 *
 */
void redes_delete(eRedes* red);


/** \brief libera de memoria una lista de redes
 *
 * \param LinkedList*,lista de redes
 * \return
 *
 */
void redes_deleteLista (LinkedList* redes);




/** \brief Muestra una red
 *
 * \param pass eRedes*
 * \return void
 *
 */
void mostrarRed(eRedes* red);


int filterMejores(void* redes);


int redes_getId(eRedes* this,int* id);
int redes_getUser(eRedes* this,char* usuario);
int redes_getLikes(eRedes* this,int* likes);
int redes_getDislikes(eRedes* this,int* dislikes);
int redes_getFollowers(eRedes* this,int* followers);
int filterHaters(void* redes);
int redes_sortByFollowers(void* red1,void* red2);



