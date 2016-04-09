#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
//libreria que incluye la funcion fmod
#include <math.h>

int main()
{
    char seguir='s';
    int opcion=0;
    // variables de los operandos, inicializadas en 0 como una calculadora
    float numberA=0;
    float numberB=0;
    //variables resultado de cada operacion
    float sum;
    float subtraction;
    float division;
    float multiply;
    float factorial;
    //variable auxiliar para validar que no se ingrese decimal en factorial
    float decimal;



    while(seguir=='s')
    {
        //agrego mascaras en el printf del menu (1y2) para mostrar el dato elegido
        printf("CALCULADORA: MENU\n");
        printf("1- Ingresar 1er operando (A=%.2f)\n", numberA);
        printf("2- Ingresar 2do operando (B=%.2f)\n", numberB);
        printf("3- Calcular la suma (A+B)\n");
        printf("4- Calcular la resta (A-B)\n");
        printf("5- Calcular la division (A/B)\n");
        printf("6- Calcular la multiplicacion (A*B)\n");
        printf("7- Calcular el factorial (A!)\n");
        printf("8- Calcular todas las operacione\n");
        printf("9- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:

                    printf("ingrese el el operando A: ");
                    scanf("%f", &numberA);
                    fflush(stdin);

                break;
            case 2:

                    printf("ingrese el el operando B: ");
                    scanf("%f", &numberB);
                    fflush(stdin);

                break;
            case 3:


                   sum= sumFc(numberA, numberB);
                   printf("Sumatoria: %.2f+%.2f=%.2f\n", numberA, numberB, sum);


                break;
            case 4:


                   subtraction= substractionFc(numberA, numberB);
                   printf("Resta: %.2f - %.2f=%.2f\n", numberA, numberB, subtraction);

                break;
            case 5:



                   while (numberB==0)
                   {
                       printf("error, no se puede dividir por 0, reingrese operando B: \n");
                       scanf("%f", &numberB);
                   }
                   division= divisionFc(numberA, numberB);
                   printf("Division: %.2f / %.2f=%.2f\n", numberA, numberB, division);


                break;
            case 6:


                    multiply= multiplyFc(numberA, numberB);
                    printf("Multiplicacion: %.2f * %.2f = %.2f\n", numberA, numberB, multiply);
                    break;

            case 7:

                    //funcion float=fmod(float, float): calcula el resto de la division entre los dos parametros, pero acepta parametros float.
                    //utilizo fmod en el while para validar que no se ingresen numeros decimales (no es lo mismo que decir float)
                    decimal=fmod(numberA, 1);
                    //validacion de ingreso de numeros enteros y positivos.
                    while (numberA<0||decimal!=0)
                    {
                        printf("error, no existe factorial de numero negativo y/o decimal, reingrese operando A: \n");
                        scanf("%f", &numberA);
                        fflush(stdin);
                        decimal=fmod(numberA, 1);

                    }

                    factorial=factorialFc(numberA);
                    printf("Factorial de %.0f = %.2f\n", numberA, factorial);

                break;
            case 8:


                   sum= sumFc(numberA, numberB);
                   printf("Sumatoria: %.2f+%.2f=%.2f\n", numberA, numberB, sum);


                   subtraction= substractionFc(numberA, numberB);
                   printf("Resta: %.2f - %.2f=%.2f\n", numberA, numberB, subtraction);


                   multiply= multiplyFc(numberA, numberB);
                   printf("Multiplicacion: %.2f * %.2f = %.2f\n", numberA, numberB, multiply);


                   while (numberB==0)
                   {
                       printf("error, no se puede dividir por 0, reingrese operando B: \n");
                       scanf("%f", &numberB);
                   }
                   division= divisionFc(numberA, numberB);
                   printf("Division: %.2f / %.2f=%.2f\n", numberA, numberB, division);



                   decimal=fmod(numberA, 1);
                   while (numberA<0||decimal!=0)
                   {
                        printf("error, no existe factorial de numero negativo y/o decimal, reingrese operando A: \n");
                        scanf("%f", &numberA);
                        fflush(stdin);
                        decimal=fmod(numberA, 1);

                   }

                   factorial=factorialFc(numberA);
                   printf("Factorial de %.0f = %.2f\n", numberA, factorial);




                break;
            case 9:
                {

                        seguir='n';

                }
        }
    }

    return 0;
}
