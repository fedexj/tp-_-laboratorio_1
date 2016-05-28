#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct{
    char titulo[20];
    char genero[20];
    int duracion;
    char descripcion[50];
    int puntaje;
    char linkImagen[50];
    int isEmpty;
}sMovie;


/**
 *  Agrega una pelicula al archivo binario
 *  @param lista la estructura a ser agregada al archivo
 *  @return retorna 1 o 0 de acuerdo a si pudo agregar la pelicula o no
 */
int addMovieFc(sMovie* lista);

/** \brief guarda una pelicula en un archivo binario a partir de una estructura
 *
 * \param  lista la estructura a ser guardada en el archivo
 * \return retorna 1 o 0 de acuerdo a si pudo agregar la pelicula o no
 *
 */
int saveMovieFc(sMovie* lista);

/**
 *  Borra una pelicula del archivo binario
 *  @param lista la estructura a ser eliminada al archivo
 *  @return retorna 1 o 0 de acuerdo a si pudo eliminar la pelicula o no
 */
int deleteMovieFc(sMovie* lista);

/** \brief modifica una pelicula guardada en un archivo
 *
 * \param lista la estructura a ser modificada en el archivo
 * \return retorna 1 o 0 de acuerdo a si pudo modificar la pelicula o no
 *
 */
int modifyMovieFc(sMovie* lista);

/**
 *  Genera un archivo html a partir de las peliculas cargadas en el archivo binario.
 *  @param lista la lista de peliculas a ser agregadas en el archivo.
 */
void generarPagina(sMovie* lista);

#endif // FUNCIONES_H_INCLUDED
