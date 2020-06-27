#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "utn.h"
#include <string.h>


static Employee* controller_getData( int bufferId);

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *  \param path char* puntero dirección al archivo a leer
 *  \param pArrayListEmployee LinkedList* puntero a la lista de Punteros
 *  \return retorna 0 si los punteros son validos, -1 si no.
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
	int retorno=-1;
	FILE* fpArchivo;

	if(pArrayListEmployee != NULL && path != NULL)
		{
			if(!ll_isEmpty(pArrayListEmployee))
			{
				ll_clear(pArrayListEmployee);
			}
			retorno = 0;
			fpArchivo = fopen(path,"r");

			if(fpArchivo != NULL)
			{

				if(parser_EmployeeFromText(fpArchivo, pArrayListEmployee)> 0)
				{
					printf("\nCarga Exitosa\n");
				}
				else{
					printf("\nLista Vacia\n");
					}
			}
			else{
					printf("\nNo se encuentra Archivo\n");
				}
			fclose(fpArchivo);
		}
    return retorno;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 *  \param path char* puntero dirección al archivo a leer
 *  \param pArrayListEmployee LinkedList* puntero a la lista de Punteros
 *  \return int (0) si la verificación es correcta (-1) si da error.
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)

{
	int retorno = -1;
	FILE* fpArchivo;
	if(pArrayListEmployee != NULL && path != NULL)
			{
			retorno = 0;
				if(!ll_isEmpty(pArrayListEmployee))
				{
					ll_clear(pArrayListEmployee);
				}
				fpArchivo = fopen(path,"rb");
				if(fpArchivo != NULL && parser_EmployeeFromBinary(fpArchivo, pArrayListEmployee) == 0)
				{
					printf("\nCarga Exitosa\n");
				}
				else{
					printf("\nLista Vacia\n");
					}
			}
	fclose(fpArchivo);

    return retorno;
}

/** \brief Alta de empleados añade un elemento a la lista.
 *
 *  \param pArrayListEmployee LinkedList* puntero a la lista de Punteros
 * \return int (0) si la verificación es correcta (-1) si da error.
 *
 */


int controller_addEmployee(LinkedList* pArrayListEmployee)
{
	Employee* this = NULL;
	int retorno =-1;
	int ultimoId;

	if(pArrayListEmployee !=NULL)
	{
		ultimoId = employee_ultimoId( pArrayListEmployee);
		this = controller_getData( ultimoId+1);
				if ( this != NULL  && !(ll_add(pArrayListEmployee, this)) )
				{
					retorno = 0;
					printf("\nAlta Exitosa\n");
				}
				else{
					printf("\nError\n");
				}
	}
    return retorno;
}

/** \brief Modificar datos de un elemento de la lista
 *
 *  \param pArrayListEmployee LinkedList* puntero a la lista de Punteros
 * \return int (0) si la verificación es correcta (-1) si da error.
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
	int bufferId= -1;
	int indice;
	int listaLen;
	Employee* this;

	listaLen = ll_len(pArrayListEmployee);
	if( pArrayListEmployee != NULL && listaLen > 0)
	{
		utn_getNumero(&bufferId, "\nIngrese Id: ","Rango Inválido", 1, employee_ultimoId( pArrayListEmployee), 2);
		indice = employee_getElementById(pArrayListEmployee, bufferId, listaLen);

		if(indice >= 0)
		{
			this = (Employee*)ll_get(pArrayListEmployee,indice);
			employee_getId(this, &bufferId);
			printf("\n El empleado:");
			employee_printE( this);
			printf("\n Va a ser modificado.\n");

			this = controller_getData(bufferId);

			if(this != NULL &&
				utn_getNumero(&bufferId, "\nPresione [1] para confirmar modificación: "," ", 1, 1, 0)== 0 &&
				!ll_set(pArrayListEmployee, indice, this))
			{
				printf("\nModificado\n");
			}
			else
			{
				printf("\nNo se puedo modificar\n");
			}
		}
	}
	else if(listaLen<=0)
	{
		printf("\nNo hay elementos para modificar\n");
	}
    return 0;
}

/** \brief Elmina un elemento de la lista.
 *
 * \param pArrayListEmployee LinkedList* puntero a la lista de Punteros
 * \return int (0) si la verificación es correcta (-1) si da error.
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
	int bufferId;
	int listaLen;
	int indice;
	Employee* this;
	int confirm;

	listaLen = ll_len(pArrayListEmployee);

	if( pArrayListEmployee != NULL &&
		listaLen > 0 &&
		!utn_getNumero(&bufferId, "\nIngrese Id: ","Rango Inválido", 0, employee_ultimoId( pArrayListEmployee), 2))
	{
		indice = employee_getElementById(pArrayListEmployee, bufferId, listaLen);
		this = (Employee*)ll_get(pArrayListEmployee,indice);
		printf("\n La siguiente entrada: ");
		employee_printE( this);
		printf("\n Va a ser eliminada.\n");

		if(indice >= 0 && !utn_getNumero( &confirm,"\nPresione [1] para confirmar baja: ", "\nModificacion Cancelada\n", 1, 1, 0))
		{
			employee_delete(this);
			ll_remove(pArrayListEmployee,indice);
			printf("\nBaja exitosa\n");
		}
	}
	return 1;
}

/** \brief Imprime la lista.
 *  \param pArrayListEmployee LinkedList* puntero a la lista de Punteros
 * \return int (0) si la verificación es correcta (-1) si da error.
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{

	int  retorno = -1;
	int listaLen;

	listaLen = ll_len(pArrayListEmployee);
	if(pArrayListEmployee != NULL && listaLen > 0)
	{
		retorno = 0;
		employee_printArryE( pArrayListEmployee, listaLen);
	}
	else
	{
		printf("\nError\n");
		if(listaLen == 0)
		{
			printf(" - Lista Vacia\n");
		}
	}
    return retorno;
}



/** \brief Ordenar los elementos de la lista
 *
 *  \param pArrayListEmployee LinkedList* puntero a la lista de Punteros
 * \return int (0) si la verificación es correcta (-1) si da error.
 *
 */

int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
	if(pArrayListEmployee != NULL && !(ll_sort(pArrayListEmployee, employee_comparaPorNombre, 1)) && ll_len(pArrayListEmployee)>0)
	{
		printf("\nOrdenado por Nombre\n");
	}
	else{
		printf("\nVacio\n");
	}

    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *  \param path char* puntero dirección al archivo a leer
 *  \param pArrayListEmployee LinkedList* puntero a la lista de Punteros
 *  \return retorna 0 si los punteros son validos, -1 si no.
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
	int retorno=-1;
	int i;
	FILE* fpArchivo;
	Employee* this;
	int auxiliarId;
	char auxiliarNombre[NOMBRE_LEN];
	int auxHoras;
	int auxSueldo;
	int listaLen;

	if(pArrayListEmployee != NULL  && path != NULL)
	{
		fpArchivo = fopen(path,"w");
		listaLen = ll_len(pArrayListEmployee);
		if(fpArchivo != NULL && listaLen > 0)
		{
			retorno=0;
			for(i=0;i<listaLen;i++)
			{
				this= ll_get(pArrayListEmployee, i);

					if(	!employee_getId(this, &auxiliarId) &&
						!employee_getNombre(this, auxiliarNombre) &&
						!employee_getHorasTrabajadas(this, &auxHoras)	&&
						!employee_getSueldo(this, &auxSueldo)	)
					{
						fprintf(fpArchivo,"%d,%s,%d,%d\n",auxiliarId,auxiliarNombre,auxHoras, auxSueldo);

					}

			}
			fclose(fpArchivo);
			if(retorno ==0)
			{
				printf("\nLista Guardada\n");
			}
			else
			{
				printf("\nLista Vacia\n");

			}
		}
	}
	return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *  \param path char* puntero dirección al archivo a leer
 *  \param pArrayListEmployee LinkedList* puntero a la lista de Punteros
 *  \return retorna 0 si los punteros son validos, -1 si no.
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
	FILE* fp;
	fp = fopen(path,"wb");

	int retorno;
	int i;
	void* aux;

	if(fp!=NULL && path != NULL)
	{
		for(i=0; i<ll_len(pArrayListEmployee);i++)
		{
			aux = ll_get(pArrayListEmployee,i);
			fwrite(aux,sizeof(Employee),1,fp);

		}
	}
		if(ll_len(pArrayListEmployee)>0)
		{
			printf("\nLista Guardada.\n");
			retorno = 0;
		}
		else{
			printf("\nLista Vacia.\n");

		}
	fclose(fp);
    return retorno;

}


/** \brief Obtiene los datos ingresados por el usuario.
 *  \param int bufferId el ID correspondiente a los datos del nuevo elemento
 *  \return Employee* puntero al elemento conteniendo los datos obtenidos
 *
 */
static Employee* controller_getData( int bufferId)
{
	Employee* this;
	char bufferNombre[NOMBRE_LEN];
		int	bufferSueldo;
		int bufferHorasTrabajadas;
		char auxSueldo[128];
		char auxHorasTrabajadas[128];
		char auxId[128];

	if( bufferId > 0)
	{
		if(	!utn_getNombre(bufferNombre, NOMBRE_LEN, "\nIngrese Nombre: ", "Nombre Inválido", 2) &&
			!utn_getNumero(&bufferHorasTrabajadas, "\nIngrese horas trabajadas: ","Rango Inválido", 0, 744, 2) &&
			!utn_getNumero(&bufferSueldo, "\nIngrese sueldo: ","Rango Inválido", 0, 1000000000, 2) )
		{
			snprintf(auxSueldo, sizeof(auxSueldo), "%d", bufferSueldo);
			snprintf(auxHorasTrabajadas, sizeof(auxHorasTrabajadas), "%d", bufferHorasTrabajadas);
			snprintf(auxId, sizeof(auxId), "%d", bufferId);

			this = employee_newParametros(auxId, bufferNombre, auxHorasTrabajadas, auxSueldo);
		}
		else
		{
			this=NULL;
		}
	}
	 return this;

}

/** \brief Muestra el Menu de Opciones y devuelve la opcion ingresada por el usuario
 *
 * 	\return int retorna la opcion ingresada por el usuario.
 *
 */
int controller_menu( )
{
	int opcion;
	utn_getNumero(&opcion,"\n1. Cargar data.csv (modo texto)."
						  "\n2. Cargar data.csv (modo binario)."
						  "\n3. Alta de empleado."
						  "\n4. Modificar datos de empleado."
						  "\n5. Baja de empleado."
						  "\n6. Listar empleados."
				 	 	  "\n7. Ordenar empleados."
						  "\n8. Guardar data.csv (modo texto)."
						  "\n9. Guardar data.csv (modo binario)."
						  "\n10. Salir    ",
						  "\nOpcion invalida\n",1,10,2);
	return opcion;
}


