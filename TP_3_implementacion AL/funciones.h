#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#include "ArrayList.h"

typedef struct{
    char titulo[20];
    int puntaje;
    int isEmpty;

}sMovie;


/**
 *  Agrega una pelicula al archivo binario
 *  @param movie la estructura a ser agregada al archivo
 *  @return retorna 1 o 0 de acuerdo a si pudo agregar la pelicula o no
 */
int addMovieFc(sMovie* lista);

/**
 *  compara puntajes de peliculas
 *  @param pMovieA puntero a void, del elemento A a comprarar
 *  @param pMovieA puntero a void, del elemento B a comprarar
 *  @return retorna 1 si A>B, -1 si A<B, 0 si son iguales
 */
int compareMovie(void* pMovieA,void* pMovieB);

/**
 *  imprime una lista de peliculas desde el arraylist
 *  @param pList el puntero a arraylist desde donde se imprime
 *  @return void
 */
void printFc(ArrayList* pList);


#endif // FUNCIONES_H_INCLUDED
