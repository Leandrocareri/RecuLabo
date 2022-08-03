#ifndef INPUT_H_INCLUDED
#define INPUT_H_INCLUDED



#endif // INPUT_H_INCLUDED


/** \brief pide al usuario una opcion del menu general
 *
 * \return int, retorna el valor ingresado por el usuario
 *
 */
int pedirMenu();



/** \brief pide por consola al usuario un path valido
 *
 * \param path char*,cadena donde se almacena el path ingreado
 * \return int, si se realizo de manera correcta 1 sino 0
 *
 */
int pedirPath(char* path);
