/*
 ============================================================================

* Programa: TP_2
* Objetivo:
*
*
* Version:
* Autor: Alvaro Villegas
*
 ============================================================================
 */
#define CANTIDAD_EMPLEADOS 1000

#include <stdio.h>
#include <stdlib.h>
#include "Employee.h"
#include "utn.h"

int main(void)
{

	setbuf(stdout,NULL);



		Employee arrayEmpleados[CANTIDAD_EMPLEADOS];
		int idEmpleados=0;
		int opcion;
		int auxIndice;
		int auxId;
		int contadorEmpleados= 0;



		if(emp_inicializarArray(arrayEmpleados,CANTIDAD_EMPLEADOS) == 0)
			{
				printf("Array inicializado correctamente. \n\n");
			}

/*
		emp_altaForzadaArray( arrayEmpleados,CANTIDAD_EMPLEADOS, 0, &idEmpleados, "RAMON", "CARRERO", 		100 , 2, &contadorEmpleados);
		emp_altaForzadaArray( arrayEmpleados,CANTIDAD_EMPLEADOS, 1, &idEmpleados, "RAMON", "DAVILA",  		100 , 2, &contadorEmpleados);
		emp_altaForzadaArray( arrayEmpleados,CANTIDAD_EMPLEADOS, 2, &idEmpleados, "RAMON", "HERRERA", 		 10 , 1, &contadorEmpleados);
		emp_altaForzadaArray( arrayEmpleados,CANTIDAD_EMPLEADOS, 3, &idEmpleados, "RAMON", "VEGAS",   		 10 , 1, &contadorEmpleados);
		emp_altaForzadaArray( arrayEmpleados,CANTIDAD_EMPLEADOS, 4, &idEmpleados, "DAVID", "CARRERO", 		100 , 1, &contadorEmpleados);
		emp_altaForzadaArray( arrayEmpleados,CANTIDAD_EMPLEADOS, 5, &idEmpleados, "RAMON", "CARRERO",		 40 , 4, &contadorEmpleados);
		emp_altaForzadaArray( arrayEmpleados,CANTIDAD_EMPLEADOS, 6, &idEmpleados, "RAMON", "BUSTAMANTE", 	100 , 1, &contadorEmpleados);
		emp_altaForzadaArray( arrayEmpleados,CANTIDAD_EMPLEADOS, 7, &idEmpleados, "RAMON", "MARQUES", 		 80 , 1, &contadorEmpleados);
		emp_altaForzadaArray( arrayEmpleados,CANTIDAD_EMPLEADOS, 8, &idEmpleados, "RAMON", "AVILA", 		  0 , 1, &contadorEmpleados);
		emp_altaForzadaArray( arrayEmpleados,CANTIDAD_EMPLEADOS, 9, &idEmpleados, "RAMON", "ZAPATA", 		 33 , 1, &contadorEmpleados);
		emp_altaForzadaArray( arrayEmpleados,CANTIDAD_EMPLEADOS,10, &idEmpleados, "RAMON", "AVILA", 		 78 , 1, &contadorEmpleados);
*/

	do
		{
			if(!utn_getNumero(	&opcion,
								"\n\n1. ALTAS"
								  "\n2. MODIFICAR"
								  "\n3. BAJA"
								  "\n4. INFORMAR"
							      "\n5. SALIR    \n",
								  "\nError opcion invalida",1,5,2) )
			{
				switch(opcion)
				{
				case 1:
					auxIndice = emp_getEmptyIndex(arrayEmpleados,CANTIDAD_EMPLEADOS);
					if(auxIndice >= 0)
					{
						if(emp_altaArray(arrayEmpleados,CANTIDAD_EMPLEADOS,auxIndice,&idEmpleados, &contadorEmpleados) == 0)
						{
							printf("\nCarga exitosa\n");
						}
					}
					else
					{
						printf("\nSin Espacio");
					}
					break;
				case 2:
					if(contadorEmpleados > 0)
					{
						emp_imprimirArray(arrayEmpleados,CANTIDAD_EMPLEADOS);
						if(utn_getNumero(&auxId,"\n\nIndique el ID del empleado a modificar: ","\nID invalido",0,idEmpleados,0) == 0)
						{
							auxIndice = emp_buscarId(arrayEmpleados,CANTIDAD_EMPLEADOS,auxId);
							if(	auxIndice >= 0 &&
									emp_modificarArray(arrayEmpleados,CANTIDAD_EMPLEADOS,auxIndice) == 0)
							{
								printf("\nModificacion exitosa\n");
							}
							else
							{
								printf("\nNo se pudo Modificar\n");
							}
						}
					}
				break;
				case 3:
					if(contadorEmpleados > 0)
					{
						emp_imprimirArray(arrayEmpleados,CANTIDAD_EMPLEADOS);
						if(utn_getNumero(&auxId,"\n\nIndique el ID del Empleado a eliminar: ","\nID invalido",0,idEmpleados,0)==0)
						{
							auxIndice = emp_buscarId(arrayEmpleados,CANTIDAD_EMPLEADOS,auxId);
							if(	auxIndice >= 0 &&
									emp_bajaArray(arrayEmpleados,CANTIDAD_EMPLEADOS,auxIndice, &contadorEmpleados)== 0)
							{
								printf("\nBaja realizada con exito\n");
							}
						}
					}
					break;
				case 4:
					if(	contadorEmpleados > 0 &&
						utn_getNumero(	&opcion,
						"\n\n1) Listado de los empleados ordenados alfabéticamente por Apellido y Sector."
						"\n2) Total y promedio de los salarios, y cuántos empleados superan el salario promedio.",
						"\nError opcion invalida",1,2,2)  == 0)
										{
											switch(opcion)
											{//
											case 1:
												emp_ordenarPorNombreSector(arrayEmpleados,contadorEmpleados);
												emp_imprimirArray(arrayEmpleados, contadorEmpleados);
											break;
											case 2:
												emp_promedio(arrayEmpleados, contadorEmpleados);
											break;

											}//
										}
					break;
				case 5:
					printf("Adios");
				break;
				}
			}
		}while(opcion != 5);

		return EXIT_SUCCESS;
	}




