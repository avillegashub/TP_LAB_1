/*
 * tp1_funciones.c
 *
 * Version: 1 del 14 de Abril de 2020
 * Autor: Alvaro Villegas
 */

#include <stdio.h>
#include <stdlib.h>

/**
 * \brief Solicita un numero, lo valida, y devuelve el resultado.
 * \param pResultado Puntero para almacenar el resultado.
 * \param mensaje El mensaje mostrado.
 * \param mensajeError Es mensaje mostrado en caso de error.
 * \param minimo Valor minimo aceptado
 * \param maximo Valor maximo aceptado
 * \param reintentos Cantidad de reintentos en el caso de error
 * \return En caso de exito (0), en caso de error (-1)
 *
 */
int tp1_getInt(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
{
	int retorno = -1;
	int num;

	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0)
	{
		do
		{
			printf("%s",mensaje);
			scanf("%d",&num);

			if(num >= minimo && num <= maximo)
			{
				*pResultado = num;
				retorno = 0;
				break;
			}

			else
			{
				printf("%s",mensajeError);
				reintentos--;
			}

		}while(reintentos >= 0);
	}
	return retorno;
}

/**
 * \brief Solicita un Caracter, lo valida, y devuelve el resultado.
 * \param pResultado Puntero para almacenar el resultado.
 * \param mensaje El mensaje mostrado.
 * \param mensajeError Es mensaje mostrado en caso de error.
 * \param minimo Valor minimo aceptado
 * \param maximo Valor maximo aceptado
 * \param reintentos Cantidad de reintentos en el caso de error
 * \return En caso de exito (0), en caso de error (-1)
 *
 */
int tp1_getChar(char* pResultado, char* mensaje,char* mensajeError, char minimo,char maximo,int reintentos)
{
	int retorno = -1;
	char buffer;

	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0)
	{
		do
		{

			printf("%s",mensaje);
			fflush(stdin);
			scanf("%c",&buffer);

			if(buffer >= minimo && buffer <= maximo)
			{

				*pResultado = buffer;
				retorno = 0;
				break;

			}

			printf("%s",mensajeError);
			reintentos--;

		}while(reintentos>=0);

	}

	return retorno;
}

/**
 * \brief Suma dos numeros
 * \param pResultado Puntero para almacenar el resultado.
 * \param num1 Primer numero de la suma.
 * \param num2 Segundo numero de la suma.
 * \return En caso de exito (0), en caso de error (-1).
 *
 */
int tp1_intSum(int *pResultado, int num1, int num2)
{
	int retorno;


	retorno = -1;

	if(pResultado != NULL )
	{
		*pResultado = num1 + num2;

		retorno = 0;
	}

	return retorno;

}

/**
 * \brief Resta dos numeros.
 * \param pResultado Puntero para almacenar el resultado..
 * \param num1 Primer numero de la resta.
 * \param num2 Segundo numero de la resta.
 * \return En caso de exito (0), en caso de error (-1).
 *
 */
int tp1_intSubtract(int *pResultado, int num1, int num2)
{
	int retorno;

	retorno = -1;

	if(pResultado != NULL )
	{
		*pResultado = num1 - num2;

		retorno = 0;
	}

	return retorno;

}

/**
 * \brief Multiplica dos numeros.
 * \param pResultado Puntero para almacenar el resultado.
 * \param num1 Primer numero de la multiplicación.
 * \param num2 Segundo numero de la multiplicación.
 * \return En caso de exito (0), en caso de error (-1).
 *
 */
int tp1_intMult(int *pResultado, int num1, int num2)
{
	int retorno;

	retorno = -1;

	if(pResultado != NULL )
	{
		*pResultado = num1 * num2;

		retorno = 0;
	}

	return retorno;

}

/**
 * \brief Divide un numero por otro.
 * \param pResultado Puntero para almacenar el resultado.
 * \param num1 Dividendo.
 * \param num2 Divisor.
 * \return En caso de exito (0), en caso de error (-1).
 *
 */
int tp1_intDivide(float *pResultado, int num1, int num2)
{
	int retorno;

	retorno = -1;

	if(pResultado != NULL && num2 != 0)
	{
		*pResultado = (float)num1 / num2;

		retorno = 0;
	}

	return retorno;

}

/**
 * \brief Calcula la Factorización de dos números.
 * \param pFactorA Puntero para almacenar el resultado del primer numero.
 * \param pFactorB Puntero para almacenar el resultado del segundo numero.
 * \param num1 Primer Número.
 * \param num2 Segundo Número.
 * \return En caso de exito (0), en caso de error (-1)
 *
 */
int tp1_intFactor(int *pFactorA, int*pFactorB, int num1, int num2)

{
	int retorno;
	int i;
	int factorial;

	retorno = -1;

	if(pFactorA != NULL && pFactorB != NULL)
	{
		if(num1 == 0)
		{
			*pFactorA = 1;
		}
		else
		{
			factorial = num1;

				for(i=1; i < num1; i++)
				{
					factorial = factorial * i;
				}

			*pFactorA = factorial;

		}

		if(num2 == 0)
		{
			*pFactorB = 1;
		}
		else
		{
			factorial = num2;

				for(i=1; i < num2; i++)
				{
					factorial = factorial * i;
				}

			*pFactorB = factorial;

		}

		retorno = 0;

	}

	return retorno;

}

