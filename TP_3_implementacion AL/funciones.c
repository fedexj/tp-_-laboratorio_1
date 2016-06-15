#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#include "input.h"



int addMovieFc(sMovie* lista)
{
    int auxStrTitle;
    int auxIntScore;
    int returnAux=0;
    if (lista!= NULL)
    {
        do
        {
            auxStrTitle=getString(lista->titulo, "ingrese titulo:\n", "error: largo minimo 1, maximo 20\n", 1, 20);
            fflush(stdin);
            auxIntScore=getInt(&lista->puntaje, "ingrese puntaje(1-10):\n", "error: puntaje invalido\n", 1, 10);
            fflush(stdin);

            if (auxStrTitle == 0 || auxIntScore==0)
            {
                lista->isEmpty=0;
                returnAux=1;
            }
            else
            {
                printf("error en el ingreso de datos, vuelva a ingresar todos los campos\n");
            }

        }while(auxStrTitle != 0 || auxIntScore!=0);

    }


    return returnAux;
}




int compareMovie(void* pMovieA,void* pMovieB)
{

    if(((sMovie*)pMovieA)->puntaje > ((sMovie*)pMovieB)->puntaje)
    {
        return 1;
    }
    if(((sMovie*)pMovieA)->puntaje < ((sMovie*)pMovieB)->puntaje)
    {
        return -1;
    }
    return 0;


}

void printFc(ArrayList* pList)
{
  int i=0;
  int intAux;
  sMovie* movieAux;
  for(i=0;i<pList->len(pList);i++)
  {
      //movieAux=*(pList->pElements+i);
      movieAux=al_get(pList, i);
      intAux=al_indexOf(pList, movieAux);
      printf("titulo:%s, puntaje:%d, indice:%d\n", movieAux->titulo, movieAux->puntaje, intAux);

  }
}


