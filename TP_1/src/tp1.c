/*
 ============================================================================

* Programa: TP_1
* Objetivo:
*
*	Hacer una calculadora.
*
* Version: 1 del 14 de Abril de 2020
* Autor: Alvaro Villegas
*
 ============================================================================
 */


#include <stdio.h>
#include <stdlib.h>

#include "tp1_funciones.h"										//Inclución de la Biblioteca Local

#define RETRYS 2
#define NUMBER_MAX 10											//DEFINES
#define NUMBER_MIN 0



int main(void)
{
	setbuf(stdout,NULL);

		// Declaración de Variables.

	int numeroA;
	int numeroB;
	int resultado;
	float resultadoDiv;
	int factorA;
	int factorB;
	char operador;
	int opcion;
	int opcionMax;
	int opcionMin;

		//	Inicialización las variables.

	opcionMax = 5;
	opcionMin = 1;
	numeroA = 0;
	numeroB = 0;


	do	// Inicio del bucle del Menu Principal
	{
		printf(		"\n1. Ingresar 1er operando (A = %d)"
					"\n2. Ingresar 2do operando (B = %d)"
					"\n3. Operaciones"
					"\n4. Informar resultado"
					"\n5. Salir",
					numeroA,
					numeroB);

		if (tp1_getInt(&opcion,"\n\n   Ingrese Una Opción: ", "\nError! Opción Invalida", opcionMin , opcionMax, RETRYS )== 0 && opcion !=5)
		{

			switch(opcion)	//Inicio Switch del Menu Principal
			{

				case 1:
				{
					tp1_getInt(&numeroA,"\nIngrese un numero: ", "\nError! Numero fuera de rango ", NUMBER_MIN , NUMBER_MAX, RETRYS );
					break;
				}

				case 2:
				{
					tp1_getInt(&numeroB,"\nIngrese un numero: ", "\nError! Numero fuera de rango ", NUMBER_MIN , NUMBER_MAX, RETRYS );
					break;
				}

				case 3:
				case 4:
				{
							if(opcion == 3)	//---------- Si eligen la Opción 4 No se muestra el Menu Secundario---------
							{
									tp1_getChar	( &operador,
												"\na) Calcular la suma (A+B)"
												"\nb) Calcular la resta (A-B)"
												"\nc) Calcular la division (A/B)"
												"\nd) Calcular la multiplicacion (A*B)"
												"\ne) Calcular el factorial (A!) y (B!)\n"
												"\n"
												"Ingrese una Opcion: ",
												"\nError: Opcion Inválida.\n ",
												'a',
												'e',
												RETRYS);
							}

					switch(operador)	// Inicio Switch Menu Secundario
					{

							case 'a':

								if(tp1_intSum(&resultado, numeroA, numeroB)==0)
								{
									printf("\nEl resultado de A+B es: %d\n", resultado);
								}
								break;

							case 'b':
								if(tp1_intSubtract(&resultado, numeroA, numeroB)== 0)
								{
									printf("\nEl resultado de A-B es: %d\n", resultado);
								}
								break;

							case 'c':
								if(tp1_intDivide(&resultadoDiv, numeroA, numeroB)== -1)
								{
									printf("\nOperación invalida - División por 0\n");				//Validacion de Divición
								}
								else
								{
									printf("\nEl resultado de A/B es: %.2f\n", resultadoDiv);
								}
								break;

							case 'd':
								if(tp1_intMult(&resultado, numeroA, numeroB)== 0)
								{
									printf("\nEl resultado de A*B es: %d\n", resultado);
								}
								break;

							case 'e':
								if(tp1_intFactor(&factorA, &factorB,  numeroA, numeroB)== 0)
								{
									printf("\nEl factorial de A es: %d y El factorial de B es: %d\n", factorA , factorB);
								}
								break;

							default :
								{
									printf("\nError: Elija una Operación\n");
								break;
								}

					} // Fin Menu Secundario

				}//Fin Case 4

			}//Fin Switch Menu Principal

		}


	}while (opcion != 5); //Fin del bucle de Menu Principal

	printf("\n			Adios");

		return EXIT_SUCCESS;
}

