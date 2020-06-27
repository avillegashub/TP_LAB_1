#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Employee.h"
#include "utn.h"


/**
 * \brief Inicializa el array
 * \param array Array de empleados a ser actualizado
 * \param limite Limite del array de empleados
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int emp_inicializarArray(Employee* array,int limite)
{
	int respuesta = -1;
	int i;
	if(array != NULL && limite > 0)
	{
		respuesta = 0;
		for(i=0;i<limite;i++)
		{
			array[i].isEmpty = 1;
		}
	}
	return respuesta;


}

/**
 * \brief Da de alta un empleado en una posicion del array
 * \param array Array de empleados a ser actualizado
 * \param limite Limite del array de empleados
 * \param indice Posicion a ser actualizada
 * \param id Identificador a ser asignado al  empleado
 * \param contador puntero al espacio del Contador de Empleados
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int emp_altaArray(Employee* array,int limite, int indice, int* id,  int* contador)
{
	int respuesta = -1;
	Employee bufferEmpleado;

	if(array != NULL && limite > 0 && indice < limite && indice >= 0 && id != NULL)
	{
		if(	utn_getNombre(bufferEmpleado.lastName,NOMBRE_LEN,"\nApellido: \n","\nERROR\n",2) == 0 &&
			utn_getNombre(bufferEmpleado.name,NOMBRE_LEN,"\nNombre: \n","\nERROR\n",2) == 0 &&
			utn_getNumeroFlotante(&bufferEmpleado.salary,"\nSalario: \n","\nERROR\n",0,10000,2) == 0 &&
			utn_getNumero(&bufferEmpleado.sector,"\nSector: ","Rango invalido!",0,10,2)==0)
		{
			respuesta = 0;
			bufferEmpleado.id = *id;
			bufferEmpleado.isEmpty = 0;
			array[indice] = bufferEmpleado;
			(*id)++;
			(*contador)++;
		}
	}
	return respuesta;
}

/** \brief Busca un ID en un array y devuelve la posicion en que se encuentra
* \param array Array de empleados
* \param limite int Tamaño del array
* \param posicion int* puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int emp_buscarId(Employee* array, int limite, int valorBuscado)
{
	int respuesta = -1;
	int i;
	if(array != NULL && limite > 0 && valorBuscado >= 0)
	{
		for(i=0;i<limite;i++)
		{
			if(array[i].id == valorBuscado)
			{
				respuesta = i;
				break;
			}
		}
	}
	return respuesta;
}

/**
 * \brief Imprime los datos de un empleado
 * \param pElemento Puntero al empleado que se busca imprimir
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int emp_imprimir(Employee* pElemento)
{
	int retorno=-1;
	if(pElemento != NULL && pElemento->isEmpty == 0)
	{
		retorno=0;
		printf("\n  %4d - %10.10s - %10.10s - %8.2f   - %4d",pElemento->id,pElemento->lastName ,pElemento->name, pElemento->salary, pElemento->sector);
	}
	return retorno;
}

/**
 * \brief Imprime el array de empleados
 * \param array Array de empleados a ser actualizado
 * \param limite Limite del array de empleados
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int emp_imprimirArray(Employee* array,int limite)
{
	int respuesta = -1;
	int i;
	if(array != NULL && limite > 0)
	{
		respuesta = 0;
		printf("\n   ID  - Apellido   -Nombre      -   Salario  - Sector");
		for(i=0;i<limite;i++)
		{
			emp_imprimir(&array[i]);
		}
	}
	return respuesta;
}




/**
 * \brief Actualiza los datos de un cliente en una posicion del array
 * \param array Array de empleados a ser actualizado
 * \param limite Limite del array de empleados
 * \param indice Posicion a ser actualizada
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int emp_modificarArray(Employee* array,int limite, int indice)
{
	int respuesta = -1;
	Employee bufferEmpleado;

	if(array != NULL && limite > 0 && indice < limite && indice >= 0 && array[indice].isEmpty == 0)
	{
		if(	utn_getNombre(bufferEmpleado.lastName,NOMBRE_LEN,"\nApellido: \n","\nERROR\n",2) == 0 &&
			utn_getNombre(bufferEmpleado.name,NOMBRE_LEN,"\nNombre: \n","\nERROR\n",2) == 0 &&
			utn_getNumeroFlotante(&bufferEmpleado.salary,"\nSalario: \n","\nERROR\n",0,10000,2) == 0 &&
			utn_getNumero(&bufferEmpleado.sector,"\nSector: ","Rango invalido",0,10,2)==0)
		{
			respuesta = 0;
			bufferEmpleado.id = array[indice].id;
			bufferEmpleado.isEmpty = 0;
			array[indice] = bufferEmpleado;
		}
	}
	return respuesta;
}

/**
 * \brief Actualiza una posicion del array
 * \param array Array de empleados a ser actualizado
 * \param limite Limite del array de empleados
 * \param indice Posicion a ser actualizada
 * \param contador puntero al espacio del Contador de Empleados
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int emp_bajaArray(Employee* array,int limite, int indice, int* contador)
{
	int respuesta = -1;
	if(array != NULL && limite > 0 && indice < limite && indice >= 0 && array[indice].isEmpty == 0)
	{
		array[indice].isEmpty = 1;
		respuesta = 0;
		(*contador)--;
	}
	return respuesta;
}



/**
 * \brief Buscar primer posicion vacia
 * \param array Array de empleados
 * \param limite Limite del array de empleados
 * \return Retorna el incice de la posicion vacia y -1 (ERROR)
 *
 */
int emp_getEmptyIndex(Employee* array,int limite)
{
	int respuesta = -1;
	int i;
	if(array != NULL && limite > 0)
	{
		for(i=0;i<limite;i++)
		{
			if(array[i].isEmpty == 1)
			{
				respuesta = i;
				break;
			}
		}
	}
	return respuesta;
}

/**
 * \brief Ordenar el array de empleados por nombre
 * \param array Array de empleados
 * \param limite Limite del array de empleados
 * \return 0  y -1 (ERROR)
 *
 */
int emp_ordenarPorNombre(Employee* array,int limite)
{
	int respuesta = -1;
	int flag;
	int i;
	Employee buffer;
	if(array != NULL && limite > 0)
	{
		do
		{
			flag = 0;
			for(i=0;i<limite-1;i++)
			{
				if(array[i].isEmpty || array[i+1].isEmpty)
				{
					continue;
				}
				if(strncmp(array[i].lastName,array[i+1].lastName,NOMBRE_LEN) > 0)
				{
					flag = 1;
					buffer = array[i];
					array[i] = array[i+1];
					array[i+1]=buffer;
				}
			}
			limite--;
		}while(flag);
	}
	return respuesta;
}

/**
 * \brief Ordenar el array de empleados por sector
 * \param array Array de empleados
 * \param limite Limite del array de empleados
 * \return 0  y -1 (ERROR)
 *
 */
int emp_ordenarPorSector(Employee* array,int limite)
{
	int respuesta = -1;
	int flag;
	int i;
	Employee buffer;
	if(array != NULL && limite > 0)
	{
		do
		{
			flag = 0;
			for(i=0;i<limite-1;i++)
			{
				if(array[i].isEmpty || array[i+1].isEmpty)
				{
					continue;
				}
				if(array[i].sector > array[i+1].sector)
				{
					flag = 1;
					buffer = array[i];
					array[i] = array[i+1];
					array[i+1]=buffer;
				}
			}
			limite--;
		}while(flag);
	}
	return respuesta;
}






/**
 * \brief Da de alta un empleado en una posicion del array
 * \param array Array de empleados a ser actualizado
 * \param limite Limite del array de empleados
 * \param indice Posicion a ser actualizada
 * \param id Identificador a ser asignado al empleado
 * \return Retorna 0  y -1 (ERROR)
 *
 */
int emp_altaForzadaArray(Employee* array,int limite, int indice, int* id,char* nombre,char* apellido, float salario ,int sector, int* contador)

{
	int respuesta = -1;
	Employee bufferEmpleado;

	if(array != NULL && limite > 0 && indice < limite && indice >= 0 && id != NULL)
	{
			strncpy(bufferEmpleado.name,nombre,NOMBRE_LEN);
			strncpy(bufferEmpleado.lastName,apellido,NOMBRE_LEN);
			bufferEmpleado.salary = salario;
			bufferEmpleado.sector = sector;
			respuesta = 0;
			bufferEmpleado.id = *id;
			bufferEmpleado.isEmpty = 0;
			array[indice] = bufferEmpleado;
			(*id)++;
			(*contador)++;
	}

	return respuesta;
}


/**
 * \brief Imprime el promedio de sueldos y cantidad de empleados arriba del promedio
 * \param array Array de empleados
 * \param cantidad de empleados Limite del array de empleados
 * \return Retorna 0 si se hizo el calculo  y -1 (ERROR)
 *
 */
int emp_promedio(Employee* array, int cantidadEmpleados)
{
	int retorno = -1;
	int i;
	float promedioSueldos;
	float sumaSueldo = 0;
	int contArribaPromedio = 0;
	int contEmpleados = 0;

	if (array != NULL && cantidadEmpleados > 0)
	{//1
		retorno = 0;
			for(i=0; i < cantidadEmpleados ; i++)
			{//2
				if(array[i].isEmpty == 0)
				{
					sumaSueldo = sumaSueldo + array[i].salary;
					contEmpleados++;
				}
			}//2
				promedioSueldos = sumaSueldo /contEmpleados;
					for(i=0; i<= contEmpleados ; i++)
					{//3
						if(array[i].salary > promedioSueldos && array[i].isEmpty == 0)
						{
							contArribaPromedio++;
						}
					}//3
		printf("\nEl salario Promedio es:   %.2f\nEmpleados con Salarios Arriba del promedio: %d", promedioSueldos, contArribaPromedio);

	}//1
	return retorno;

}





/**
 * \brief Ordenar el array de empleados por nombre y sector
 * \param array Array de empleados
 * \param limite Limite del array de empleados
 * \return 0  y -1 (ERROR)
 *
 */

int emp_ordenarPorNombreSector(Employee* array,int limite)
{
	int respuesta = -1;
		int flag;
		int i;
		Employee buffer;

		if(array != NULL && limite > 0)
		{
			do
			{
				flag = 0;
				for(i=0;i<limite-1;i++)
				{//1

					if(array[i].isEmpty || array[i+1].isEmpty)
					{//2
						continue;
					}//2
					if(strncmp(array[i].lastName,array[i+1].lastName,NOMBRE_LEN) > 0)
					{//3
						flag = 1;
						buffer = array[i];
						array[i] = array[i+1];
						array[i+1]=buffer;
					}//3
					else if(strncmp(array[i].lastName,array[i+1].lastName,NOMBRE_LEN) == 0)
					{//4
						if(array[i].sector > array[i+1].sector)
						{//5
							flag = 1;
							buffer = array[i];
							array[i] = array[i+1];
							array[i+1]=buffer;
						}//5
					}//4

				}//1
				limite--;
			}while(flag);
		}
		return respuesta;
	}
