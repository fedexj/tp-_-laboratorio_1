#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"


int main()
{
    char seguir='s';
    int opcion=0;
    sMovie* movieX;
    int auxVerify;
    int auxVerify2;

    while(seguir=='s')
    {
        printf("1- Agregar pelicula\n");
        printf("2- Borrar pelicula\n");
        printf("3-Modificar pelicula\n");
        printf("4- Generar pagina web\n");
        printf("5- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                movieX=(sMovie*)malloc(sizeof(sMovie));
                auxVerify=addMovieFc(movieX);
                auxVerify2=saveMovieFc(movieX);
                if (auxVerify2==1&&auxVerify==1)
                {
                    printf("pelicula agregada con exito!\n");
                }
                else
                {
                    printf("error al intentar agregar pelicula");
                }
                free(movieX);
                break;
            case 2:
                movieX=(sMovie*)malloc(sizeof(sMovie));
                deleteMovieFc(movieX);
                free(movieX);
                break;
            case 3:
                movieX=(sMovie*)malloc(sizeof(sMovie));
                modifyMovieFc(movieX);
                free(movieX);
               break;
            case 4:
                movieX=(sMovie*)malloc(sizeof(sMovie));
                generarPagina(movieX);
                free(movieX);
                break;
            case 5:
                seguir = 'n';
                break;
        }
    }

    return 0;
}
