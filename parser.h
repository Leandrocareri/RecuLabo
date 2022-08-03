#ifndef PARSER_H_INCLUDED
#define PARSER_H_INCLUDED



#endif // PARSER_H_INCLUDED

/** \brief lee desde el puntero a archivo las redes validando su estructura y las carga en la LinkedList
 *
 * \param pFile FILE*,puntero a archivo donde se encuentran en formato texto
 * \param redes LinkedList*,lista de redes
 * \param pId int*,puntero a variable que lleva el control del id, guarda el mayor id que se lee del archivo +1
 * \return int, retorna la cantidad de peliculas leidas con exito
 *
 */
//int parser_RedFromText(FILE* pFile , LinkedList* peliculas,int* pId);

int parser_RedFromText(FILE* pFile , LinkedList* redes);

