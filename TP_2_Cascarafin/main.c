#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include <string.h>
#include "input.h"



int main()
{
    char seguir='s';
    int opcion=0;
    EPersona sEmployees[MAXITEMS];
    int index;
    int inputOK;
    char opcionBorrar;
    int elementsBar1;
    int elementsBar2;
    int elementsBar3;


    isEmptyFc(sEmployees, MAXITEMS);

    while(seguir=='s')
    {
        printf("1- Agregar persona\n");
        printf("2- Borrar persona\n");
        printf("3- Imprimir lista ordenada por  nombre\n");
        printf("4- Imprimir grafico de edades\n\n");
        printf("5- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                inputOK=addEmployeeFc(sEmployees, MAXITEMS);
                fflush(stdin);
                if (inputOK==-1)
                {
                    printf("no hay espacio en memoria\n");
                }

                break;
            case 2:
                index=buscarPorDniFc(sEmployees, MAXITEMS);
                if (index==-1)
                {
                    printf("no existe el DNI buscado\n");
                }
                else
                {
                    printf("persona: %s\tedad:%d\tDNI:%d\n", sEmployees[index].nombre, sEmployees[index].edad, sEmployees[index].dni);
                    do
                    {
                        inputOK=getChar(&opcionBorrar, "seguro desea borrar esta persona?s/n\n", "error: ingrese s o n\n");
                        fflush(stdin);
                    }while (inputOK!=0);

                    if (opcionBorrar=='s')
                    {
                        sEmployees[index].isEmpty=1;
                    }

                }
                break;
            case 3:
                sortEmployeesByNameFc(sEmployees, MAXITEMS);
                printEmployeesFc(sEmployees, MAXITEMS);
                break;
            case 4:
                elementsBar1=groupBuilderFc(sEmployees, MAXITEMS, 0, 18);
                elementsBar2=groupBuilderFc(sEmployees, MAXITEMS, 19, 35);
                elementsBar3=groupBuilderFc(sEmployees, MAXITEMS, 35, 150);
                printGraphic(elementsBar1, elementsBar2, elementsBar3, 3);
                break;
            case 5:
                seguir = 'n';
                break;
            default:
            printf("error, no ingreso una opcion valida\n");
        }
    }

    return 0;
}
