#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
* \brief Solicita un número al usuario y lo valida
* \param input Se carga el numero ingresado
* \param message Es el mensaje a ser mostrado
* \param eMessage Es el mensaje a ser mostrado en caso de error
* \param lowLimit Limite inferior a validar
* \param hiLimit Limite superior a validar
* \return Si obtuvo el numero [0] si no [-1]
*
*/
int getInt(int* input,char message[],char eMessage[], int lowLimit, int hiLimit)
{
    int aux;
    int buffer;

    printf("%s", message);
    aux=scanf("%d", &buffer);
    if (aux ==1)
    {
       if (buffer>=lowLimit&&buffer<=hiLimit)
       {
            *input=buffer;
            return 0; //validar
       }
    }
    printf("%s", eMessage);
    return -1;

}

/**
* \brief Solicita un número al usuario y lo valida
* \param input Se carga el numero ingresado
* \param message Es el mensaje a ser mostrado
* \param eMessage Es el mensaje a ser mostrado en caso de error
* \param lowLimit Limite inferior a validar
* \param hiLimit Limite superior a validar
* \return Si obtuvo el numero [0] si no [-1]
*
*/
int getFloat(float* input,char message[],char eMessage[], float lowLimit, float hiLimit)
{
    int aux;
    float buffer;

    printf("%s", message);
    aux=scanf("%f", &buffer);
    if (aux ==1)
    {
       if (buffer>=lowLimit&&buffer<=hiLimit)
       {
            *input=buffer;
            return 0; //validar
       }
    }
    printf("%s", eMessage);
    return -1;
}


/**
* \brief Solicita un caracter al usuario y lo valida
* \param input Se carga el caracter ingresado
* \param message Es el mensaje a ser mostrado
* \param eMessage Es el mensaje a ser mostrado en caso de error
* \param lowLimit Limite inferior a validar
* \param hiLimit Limite superior a validar
* \return Si obtuvo el caracter [0] si no [-1]
*
*/
int getChar(char* input,char message[],char eMessage[])
{
    int aux;
    char buffer[5000];
    int auxLength;

    printf("%s", message);
    fflush(stdin);
    aux=scanf("%s", buffer);

    if (aux ==1&& buffer[0]!='\0'&&buffer[1]=='\0'&&(buffer[0]=='s'||buffer[0]=='n'))
    {
          strcpy(input, buffer);
          return 0;
    }
    printf("%s", eMessage);
    return -1;


}


/**
* \brief Solicita una cadena de caracteres al usuario y la valida
* \param input Se carga el string ingresado
* \param message Es el mensaje a ser mostrado
* \param eMessage Es el mensaje a ser mostrado en caso de error
* \param lowLimit Longitud mínima de la cadena
* \param hiLimit Longitud máxima de la cadena
* \return Si obtuvo la cadena [0] si no [-1]
*
*/
int getString(char* input,char message[],char eMessage[], int lowLimit, int hiLimit)
{
    char aux;
    int auxLength;
    char buffer [4000];
    printf("%s", message);
    fflush(stdin);
    aux=scanf(" %[^\n]", buffer);
    auxLength=strlen(buffer);

    if (aux == 1&&(auxLength>=lowLimit&&auxLength<=hiLimit))
    {
          strcpy(input, buffer);
          fflush(stdin);
          return 0;
    }
    else
    {
        printf("%s", eMessage);
        return -1;
    }



}
