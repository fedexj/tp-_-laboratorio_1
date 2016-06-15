#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include "ArrayList.h"


int main()
{
    char seguir='s';
    int opcion=0;
    sMovie* movieX;
    int auxVerify;
    int auxVerify2;
    int auxInt;
    int indexAux;
    int indexAux2;
    ArrayList* pList;
    ArrayList* pSubList;
    pList=al_newArrayList();

    while(seguir=='s')
    {
        do
        {
            printf("1- Agregar pelicula\n");
            printf("2- Borrar pelicula\n");
            printf("3- Modificar pelicula\n");
            printf("4- borrar todo\n");
            printf("5- ordenar\n");
            printf("6- insertar\n");
            printf("7- imprimir sublista\n");
            printf("8- extension de la lista\n");
            printf("9- salir\n");

            scanf("%d",&opcion);
        }while (opcion>0&&opcion<10);


        switch(opcion)
        {
            case 1:
                movieX=(sMovie*)malloc(sizeof(sMovie));
                if (movieX!=NULL)
                {
                    auxVerify2=addMovieFc(movieX);
                    auxVerify=al_add(pList, movieX);
                    if (auxVerify2==1&&auxVerify==0)
                    {
                        printf("pelicula agregada con exito!\n");
                        auxInt=al_len(pList);
                        printf("cantidad total de peliculas:%d\n", auxInt);
                    }
                    else
                    {
                        printf("error al intentar agregar pelicula");
                    }
                }

                break;

            case 2:
                auxInt=al_len(pList);
                printf("tamaño del array:%d\n", auxInt);
                printFc(pList);
                do
                {
                    printf("ingrese indice de la pelicula a borrar (comenzando por 0)");
                    scanf("%d", &indexAux);
                }while (indexAux<0||indexAux>auxInt);
                auxVerify=al_remove(pList,indexAux);
                if(auxVerify==0)
                {
                    printf("nueva lista:");
                    printFc(pList);
                }
                else
                {
                    printf("error al intentar borrar");
                }

                break;

            case 3:
                auxInt=al_len(pList);
                printf("tamaño del array:%d", auxInt);
                printFc(pList);
                do
                {
                    printf("ingrese indice de la pelicula a modificar (comenzando por 0)\n");
                    scanf("%d", &indexAux);
                }while(indexAux<0||indexAux>auxInt);

                movieX=(sMovie*)malloc(sizeof(sMovie));
                if(movieX!=NULL)
                {
                    auxVerify2=addMovieFc(movieX);
                    auxVerify=al_set(pList, indexAux, movieX);
                    if (auxVerify2==1&&auxVerify==0)
                    {
                        "pelicula modificada con exito";
                    }
                    else
                    {
                        "error al intentar modificar";
                    }
                    printf("Array modificado:");
                    printFc(pList);
                }
               break;

            case 4:
                free(movieX);
                al_deleteArrayList(pList);
                break;

            case 5:
                do
                {
                    printf("ingrese 0/1 si desea ordenar desendente/ascendente\n");
                    scanf("%d", &indexAux);
                }while(indexAux!=0||indexAux!=1);
                pList->sort(pList, compareMovie, indexAux);
                printFc(pList);
                break;

            case 6:
                auxInt=al_len(pList);
                printf("tamaño del array:%d", auxInt);
                do
                {
                    printf("ingrese indice donde insertar la pelicula(comenzando por 0)");
                    scanf("%d", &indexAux);
                }while(indexAux<0||indexAux>auxInt);
                movieX=(sMovie*)malloc(sizeof(sMovie));
                if (movieX!=NULL)
                {
                    auxVerify2=addMovieFc(movieX);
                    auxVerify=al_push(pList, indexAux, movieX);

                    if (auxVerify2==1&&auxVerify==0)
                    {
                        printf("pelicula insertada con exito");
                    }
                    else
                    {
                        printf("error al insertar pelicula");
                        break;
                    }
                    printf("Array modificado:\n");
                    printFc(pList);
                }

                break;

            case 7:
                do
                {
                    printf("ingrese indice desde donde mostrar la sublista(inclusivo)");
                    scanf("%d", &indexAux);
                    printf("ingrese indice hasta donde mostrar la sublista(exclusivo)");
                    scanf("%d", &indexAux2);
                }while(indexAux<0||indexAux>=auxInt);
                pSubList=al_subList(pList, indexAux, indexAux);
                if (pSubList!=NULL)
                {
                   printFc(pSubList);
                }

                break;
            case 8:
                seguir = 'n';
                break;
        }
    }

    return 0;
}
