#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#include "input.h"



int addMovieFc(sMovie* lista)
{
    int auxStrTitle;
    int auxStrGenre;
    int auxIntlength;
    int auxIntDescription;
    int auxIntScore;
    int auxStrLink;

    int returnAux=0;
    if (lista!= NULL)
    {
        do
        {
            auxStrTitle=getString(lista->titulo, "ingrese titulo:\n", "error: largo minimo 1, maximo 20\n", 1, 20);
            fflush(stdin);
            auxStrGenre=getString(lista->genero, "ingrese genero:\n", "error: largo minimo 1, maximo 20\n", 1, 20);
            fflush(stdin);
            auxIntlength=getInt(&lista->duracion, "ingrese duracion(min.):\n", "error: duracion invalida\n", 1, 3600);
            fflush(stdin);
            auxIntDescription=getString(lista->descripcion, "ingrese descripcion:\n", "error: largo minimo 1, maximo 50\n", 1, 50);
            fflush(stdin);
            auxIntScore=getInt(&lista->puntaje, "ingrese puntaje(1-10):\n", "error: puntaje invalido\n", 1, 10);
            fflush(stdin);
            auxStrLink=getString(lista->linkImagen, "ingrese el link de la imagen:\n", "error: largo minimo 1, maximo 20\n", 1, 50);
            fflush(stdin);

            if (auxStrTitle == 0 || auxStrGenre==0 || auxIntlength==0||auxIntDescription==0|| auxIntScore==0 || auxStrLink==0)
            {
                lista->isEmpty=0;
                returnAux=1;
            }
            else
            {
                printf("error en el ingreso de datos, vuelva a ingresar todos los campos\n");
            }

        }while(auxStrTitle != 0 || auxStrGenre!=0 || auxIntlength!=0||auxIntDescription!=0|| auxIntScore!=0 || auxStrLink!=0);
    }


    return returnAux;
}

int saveMovieFc(sMovie* lista)
{
    FILE* pMoviesFile;
    int auxVerify;
    int returnAux=0;
    if (lista!= NULL)
    {
        pMoviesFile=fopen("moviesStgFile.txt", "ab");
        if (pMoviesFile!=NULL)
        {
            auxVerify=fwrite(lista, sizeof(sMovie), 1, pMoviesFile);
            fclose(pMoviesFile);
            if(auxVerify<1)
            {
                printf("error al tratar de escribir el archivo\n");
            }
            else
            {
                printf("pelicula guardada con exito\n");
                returnAux=1;
            }

        }
        else
        {
            printf("error al abrir el archivo");
            exit(1);
        }
    }
    else
    {
        printf("error al abrir el archivo\n");

    }
    return returnAux;
}

int deleteMovieFc(sMovie* lista)
{
    char auxMovieInput[20];
    int auxVerify;
    FILE* pMoviesFile;
    int returnAux=0;

    if (lista!= NULL)
    {
        pMoviesFile=fopen("moviesStgFile.txt", "r+b");
        if (pMoviesFile!=NULL)
        {
            do
            {
               auxVerify=getString(auxMovieInput, "ingrese el titulo de la pelicula a borrar:\n", "error, ingrese un titulo valido", 1, 20);
            }while(auxVerify!=0);
            rewind(pMoviesFile);
            while(!(feof(pMoviesFile)))
            {
               auxVerify=fread(lista, sizeof(sMovie), 1, pMoviesFile);
               if (lista->isEmpty==0&&(strcmp(auxMovieInput, lista->titulo))==0)
               {
                   lista->isEmpty=1;
                   if((fseek(pMoviesFile, (-1)*sizeof(sMovie), SEEK_CUR))==0);
                   {
                       fwrite(lista, sizeof(sMovie), 1, pMoviesFile);
                       fclose(pMoviesFile);
                       printf("la pelicula ha sido borrada con exito");
                       returnAux=1;
                       break;
                   }
               }

            }
        }
        else
        {
           printf("error al abrir el archivo");
           exit(1);
        }
    }
    return returnAux;
}

int modifyMovieFc(sMovie* lista)
{
    char auxMovieInput[20];
    int auxVerify;
    FILE* pMoviesFile;
    int returnAux=0;


    if (lista!= NULL)
    {
        pMoviesFile=fopen("moviesStgFile.txt", "r+b");
        if (pMoviesFile!=NULL)
        {
            do
            {
               auxVerify=getString(auxMovieInput, "ingrese el titulo de la pelicula a Modificar:\n", "error, ingrese un titulo valido", 1, 20);
            }while(auxVerify!=0);
            rewind(pMoviesFile);
            while(!(feof(pMoviesFile)))
            {
               auxVerify=fread(lista, sizeof(sMovie), 1, pMoviesFile);
               if (lista->isEmpty==0&&(strcmp(auxMovieInput, lista->titulo))==0)
               {
                   addMovieFc(lista);
                   if((fseek(pMoviesFile, (-1)*sizeof(sMovie), SEEK_CUR))==0);
                   {
                       fwrite(lista, sizeof(sMovie), 1, pMoviesFile);
                       fclose(pMoviesFile);
                       printf("la pelicula ha sido modificada con exito");
                       returnAux=1;
                       break;
                   }
               }
            }
        }
        else
        {
           printf("error al abrir el archivo");
           exit(1);
        }
    }
    return returnAux;

}

void generarPagina(sMovie* lista)
{
    FILE* htmlFile;
    FILE* htmlHeader;
    FILE* htmlEnd;
    FILE* pMoviesFile;
    int auxVerify;
    char c;

    htmlHeader=fopen("header_html.html", "rb");
    htmlEnd=fopen("end_html.html", "rb");
    htmlFile=fopen("index.html", "w");
    pMoviesFile=fopen("moviesStgFile.txt", "rb");

    if(htmlHeader!=NULL&&htmlFile!=NULL&&htmlEnd!=NULL&&pMoviesFile!=NULL)
    {
        do
        {
              c = fgetc(htmlHeader);
              if( feof(htmlHeader) )
              {
                 break ;
              }
              else
              {
                  putc(c, htmlFile);
              }
        }while(1);

        while(!(feof(pMoviesFile)))
        {
           auxVerify=fread(lista, sizeof(sMovie), 1, pMoviesFile);
           if (lista->isEmpty==0)
           {
              fprintf(htmlFile, "<article class='col-md-4 article-intro'><a href='#'><img class='img-responsive img-rounded' src=");
              fprintf(htmlFile, lista->linkImagen);
              fprintf(htmlFile, "</a><h3><a href='#'>");
              fprintf(htmlFile, lista->titulo);
              fprintf(htmlFile,"</a></h3><ul><li>");
              fprintf(htmlFile, lista->genero);
              fprintf(htmlFile, "</li><li>");
              fprintf(htmlFile, "%d", lista->puntaje);
              fprintf(htmlFile, "</li><li>");
              fprintf(htmlFile, "%d", lista->duracion);
              fprintf(htmlFile, "</li></ul><p>");
              fprintf(htmlFile, lista->descripcion);
              fprintf(htmlFile,"</article>");
           }
        }

        do
       {
              c = fgetc(htmlEnd);
              if( feof(htmlEnd) )
              {
                 break ;
              }
              else
              {
                  putc(c, htmlFile);
              }
       }while(1);
       fclose(htmlFile);
       fclose(pMoviesFile);
       fclose(htmlEnd);
       fclose(htmlHeader);
    }








}

