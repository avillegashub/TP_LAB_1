#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos de los empleados desde el archivo data.csv (modo texto).
 *  \param path char* puntero dirección al archivo a leer
 *  \param pArrayListEmployee LinkedList* puntero a la lista de Punteros
 *  \return retorna 0 si los punteros son validos, -1 si no.
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	char auxiliarId[4096];
	char auxiliarNombre[NOMBRE_LEN];
	char auxiliarHoras[4096];
	char auxiliarSueldo[4096];
	Employee* this;
	if(pArrayListEmployee != NULL && pFile != NULL )
	{

		retorno = 0;
			do
			{
				if(fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",auxiliarId,auxiliarNombre,auxiliarHoras, auxiliarSueldo)== 4)
				{
					this = employee_newParametros(auxiliarId, auxiliarNombre, auxiliarHoras, auxiliarSueldo);
							if ( this != NULL  && !(ll_add(pArrayListEmployee, this)))
					{
							retorno++;
					}
				}
			}while(!feof(pFile));
	}
    return retorno;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *  \param path char* puntero dirección al archivo a leer
 *  \param pArrayListEmployee LinkedList* puntero a la lista de Punteros
 *  \return retorna 0 si los punteros son validos, -1 si no.
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
	Employee* aux;
	int retorno = -1;
	int contador=0;

	if(pFile != NULL && pArrayListEmployee != NULL)
	{
		do
		{
			aux = employee_new();
			if(fread (aux, sizeof(Employee), 1, pFile)>0)
			{
				ll_add(pArrayListEmployee, aux);
				contador++;
			}
		}while(feof(pFile)==0);
		if(contador>0)
		{
			retorno = 0;
		}
	}
    return retorno;
}
