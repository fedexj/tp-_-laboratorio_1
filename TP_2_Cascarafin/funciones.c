#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#include "input.h"

int espacioLibreFc(EPersona lista[], int length)
{
    int indexReturn=-1;
    int i;

    for (i=0; i<length;i++)
            {
                if (lista[i].isEmpty == 1)
                {
                    indexReturn=i;
                    break;
                }
            }

    return indexReturn;
}

void isEmptyFc(EPersona lista[],int length)
{
    int i;
    for (i=0; i<length;i++)
            {
                lista[i].isEmpty = 1;
            }
    return ;
}

int addEmployeeFc(EPersona lista[], int length)
{

    int index=-1;
    int auxIsOk=0;
    int auxStrName;
    int auxIntAge;
    int auxIntId;
    int auxduplicateOk;
    int auxDni;

        index = espacioLibreFc(lista, length);
        if (index>=0)
        {
                    do
                    {
                        auxStrName=getString(lista[index].nombre, "ingrese nombre:\n", "error: largo minimo 1, maximo 50\n", 1, 50);
                        fflush(stdin);
                        auxIntAge=getInt(&lista[index].edad, "ingrese edad:\n", "error: inrgese edad mayor a 0\n", 0, 999);
                        fflush(stdin);
                        auxIntId=getInt(&auxDni, "ingrese dni:\n", "error: dni invalido\n", 5000000, 99000000);
                        auxduplicateOk=checkDniFc(auxDni, lista, MAXITEMS);
                        if (auxduplicateOk==0)
                        {
                            printf("error: dni duplicado\n");
                        }
                        else
                        {
                            lista[index].dni=auxDni;
                        }
                        fflush(stdin);
                        if (auxStrName==0 && auxIntId==0 && auxIntAge==0 && auxduplicateOk==1)
                        {
                            lista[index].isEmpty=0;
                        }
                        else
                        {
                            printf("error en el ingreso de datos, vuelva a ingresar todos los campos\n");
                        }

                    }while(auxStrName != 0 || auxIntId!=0 || auxIntAge!=0||auxduplicateOk==0);
        }
        else
        {
            auxIsOk=-1;
        }

    return auxIsOk;
}

int buscarPorDniFc(EPersona lista[],int length)
{
    int indexReturn=-1;
    int auxId;
    int auxGetInt;
    int i;

    do
    {
       auxGetInt=getInt(&auxId, "ingrese dni:\n", "error: dni invalido\n", 5000000, 99000000);
       fflush(stdin);
    }while(auxGetInt!=0);

    for (i=0;i<length ;i++)
    {
        if(lista[i].dni==auxId&&lista[i].isEmpty==0)
        {
            indexReturn=i;
        }
    }
    return indexReturn;
}

int sortEmployeesByNameFc(EPersona lista[], int length)
{
    int auxIsOk=0;
    int i;
    int j;
    EPersona bufferpEmployee;

    if (lista!=NULL && length>=1)
    {
         for (i = 1; i < length; i++)
            {
                for (j = 0; j < length - i; j++)
                {
                    if (strcmp(lista[j].nombre, lista[j + 1].nombre) > 0)
                    {
                        bufferpEmployee = lista[j];
                        lista[j] = lista[j + 1];
                        lista[j + 1] = bufferpEmployee;
                    }
                }
            }
    }
    else
    {
        auxIsOk=-1;
    }
    return auxIsOk;
}


void printEmployeesFc(EPersona lista[], int length)
{
    int i;
    printf("\n*DNI*\t\t*Nombre*\t*EDAD*");
    for(i=0; i< length; i++)
    {
        if(lista[i].isEmpty==0)
            printf("\n%d\t%s\t\t%d\n",lista[i].dni, lista[i].nombre, lista[i].edad);
    }

}

int checkDniFc(int auxDni,EPersona lista[],int length)
{
    int duplicateOk=1;
    int i;

    for (i=0;i<length ;i++)
    {
        if(lista[i].dni==auxDni&&lista[i].isEmpty==0)
        {
            duplicateOk=0;
        }
    }
    return duplicateOk;
}


int groupBuilderFc(EPersona lista[], int length, int lowParameter, int hiParameter)
{
    int i;
    int auxCounterGroup=0;

    for(i=0;i<length;i++)
    {
        if (lista[i].isEmpty==0&&lista[i].edad<=hiParameter&&lista[i].edad>=lowParameter)
        {
            auxCounterGroup++;
        }
    }
    return auxCounterGroup;


}

void printGraphic(int col1, int col2, int col3, int totalBars)
{
    int auxValue[] = {col1, col2, col3};
    int i;
    int j;
    int max=0;
    max = 0;

   for (i = 0; i < totalBars; i++)
      if (auxValue[i] > max)
         max = auxValue[i];

   for (i = max; i > 0; i--)
    {
      for (j = 0; j < totalBars; j++)
         if (auxValue[j] >= i)
            printf("\t*");
         else
            printf("\t ");

      putchar('\n');
    }
    printf("\t<18\t19-35\t>35\n");
}


