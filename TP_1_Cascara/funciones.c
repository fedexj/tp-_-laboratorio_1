#include <stdio.h>
#include <stdlib.h>
/** \brief calcula una suma
 *
 * \param operando 1, tipo float
 * \param operando 2, tipo float
 * \return resultado de la suma, tipo float
 *
 */

float sumFc(float numA, float numB)
{
    float auxSum;
    auxSum=numA+numB;
    return auxSum;
}


/** \brief calcula una resta
 *
 * \param operando 1, tipo float
 * \param operando 2, tipo float
 * \return resultado de la resta, tipo float
 *
 */

float substractionFc(float numA, float numB)
{
    float auxSubstraction;
    auxSubstraction=numA-numB;
    return auxSubstraction;

}

//divisionFc: calcula la division de dos operandos float, devuelve un resultado float
/** \brief calcula una division
 *
 * \param operando 1, tipo float
 * \param operando 2, tipo float
 * \return resultado de la division, tipo float
 *
 */

float divisionFc(float numA, float numB)
{
    float auxDivision;
    auxDivision=numA/numB;
    return auxDivision;
}


/** \brief calcula una multiplicacion
 *
 * \param operando 1, tipo float
 * \param operando 2, tipo float
 * \return resultado de la resta, tipo float
 *
 */

float multiplyFc(float numA, float numB)
{
    float auxMultiply;
    auxMultiply=numA*numB;
    return auxMultiply;
}

//factorialFc: calcula el factorial del operando A float, devuelve un resultado float
/** \brief calcula el factorial de un numero
 *
 * \param operando 1, tipo float
 * \return resultado del factorial, tipo float
 *
 */

float factorialFc(float numA)
{
    float factorialAux;
    if (numA ==0)
    {
        return 1;
    }
    else
    {
        factorialAux=numA*factorialFc(numA-1);
        return factorialAux;
    }
}
