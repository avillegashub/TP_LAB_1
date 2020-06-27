#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Employee.h"
#include "utn.h"
#include "linkedList.h"


#define NOMBRE_LEN 50

static int esNumerica(char* cadena, int limite);
static int isValidNombre(char* cadena,int longitud);


/** \brief indica el Id más alto que se consiga en la lista.
 * \param pArrayListEmployee LinkedList* puntero a la lista de Punteros
 * \return int retorna el id mayor de la lista.
 */
int employee_ultimoId(LinkedList* pArrayListEmployee)
{
	int retorno = 0;
	Employee* this;
	int ultimoId = 0;
	int idAux;
	int i;
	int listaLen;
		listaLen = ll_len(pArrayListEmployee);

	if(pArrayListEmployee != NULL && listaLen > 0)
	{
			for(i=0; i < listaLen; i++)
			{
				this = (Employee*)ll_get(pArrayListEmployee, i);
				employee_getId(this, &idAux);
					if(idAux > ultimoId)
					{
						ultimoId = idAux;
					}
			}
			retorno = ultimoId;
	}

	return retorno;
}



/** \brief Crea el espacio de memoria del nuevo elemento
 *
 * \return Employee* retorna el puntero al espacio creado.
 */
Employee* employee_new(){
	Employee* this = NULL;
	this = (Employee*) malloc(sizeof(Employee));
	return this;
}
/** \brief Crea un elemento con los parámetros previamente obtenidos.
 *
 * \param path char* puntero dirección al archivo a leer
 * \param pArrayListEmployee LinkedList* puntero a la lista de Punteros
 * \param char* idStr puntero a dato
 * \param char* nombreStr puntero a dato
 * \param char* horasTrabajadasStr puntero a dato
 * \param char*sueldoStr puntero a dato
 * \return Employee* retorna el elemento creado.
 *
 */
Employee* employee_newParametros(char* idStr, char* nombreStr,char* horasTrabajadasStr, char*sueldoStr)
{
	Employee* this = NULL;

	this = employee_new();
		if(this != NULL && idStr != NULL && nombreStr != NULL && horasTrabajadasStr != NULL && sueldoStr != NULL)
		{
			if(	employee_setId( this, idStr) == -1 ||
				employee_setNombre(this,nombreStr) == -1 ||
				employee_setHorasTrabajadas(this, horasTrabajadasStr) == -1 ||
				employee_setSueldo(this, sueldoStr) == -1)
			{
				employee_delete(this);
				this = NULL;
			}
		}

		return this;
}

/** \brief Libera el espacio del elemento de la lista que se quiere elimiar
 *
 * \param Employee* this dirección del elemento a ser liberado.
 * \return void
 *
 */
void employee_delete( Employee* this)
{
	if(this != NULL)
		{
			free(this);
		}
}

/** \brief Inserta un dato en la dirección del elemento correspondiente
 *
 * \param char* id dato a ser insertado
 * \param Employee* this dirección del elemento donde va el dato
*  \return retorna 0 si los punteros son validos, -1 si no.
 *
 */
int employee_setId(Employee* this, char* id)
{
	int retorno = -1;
	if(this != NULL && id != NULL)
	{
		if(esNumerica(id,10))
		{
			retorno = 0;
			this->id = atoi(id);
		}
	}
	return retorno;
}

/** \brief obtiene un dato en la dirección del elemento correspondiente
 *
 * \param Employee* this dirección del elemento donde va el dato
 * \param int* id puntero a la dirección donde se va a guardar el dato.
*  \return retorna 0 si los punteros son validos, -1 si no.
 *
 */
int employee_getId(Employee* this, int* id)
{

	int retorno = -1;
		if(this != NULL && id >= 0)
		{
			retorno = 0;
			*id = this->id;
				}
		return retorno;
}
/** \brief Inserta un dato en la dirección del elemento correspondiente
 *
 * \param char* nombre dato a ser insertado
 * \param Employee* this dirección del elemento donde va el dato
*  \return retorna 0 si los punteros son validos, -1 si no.
 *
 */
int employee_setNombre(Employee* this,char* nombre)
{
	int retorno = -1;
	if(this != NULL && nombre != NULL)
	{
		if(isValidNombre(nombre,NOMBRE_LEN))
		{
			retorno = 0;
			strncpy(this->nombre,nombre,NOMBRE_LEN);
		}
	}
	return retorno;
}
/** \brief valida una cadena de caracteres y verifica que sea un nombre valido
 *
 * \param char*cadena cadena de caracteres a ser verificada
 * \param int* limite de caracteres a ser verificados
*  \return retorna 0 si los punteros son validos, -1 si no.
 *
 */
static int isValidNombre(char* cadena,int longitud)
{
	int i=0;
	int retorno = 1;

	if(cadena != NULL && longitud > 0)
	{
		for(i=0 ; cadena[i] != '\0' && i < longitud; i++)
		{
			if((cadena[i] < 'A' || cadena[i] > 'Z' ) && (cadena[i] < 'a' || cadena[i] > 'z' ))
			{
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}
/** \brief obtiene un dato en la dirección del elemento correspondiente
 *
 * \param Employee* this dirección del elemento donde va el dato
 * \param char* nombre puntero a la dirección donde se va a guardar el dato.
*  \return retorna 0 si los punteros son validos, -1 si no.
 *
 */
int employee_getNombre(Employee* this,char* nombre)
{
	int retorno = -1;
	if(this != NULL && nombre != NULL)
	{
		retorno = 0;
		strncpy(nombre,this->nombre,NOMBRE_LEN);
			}
	return retorno;

}
/** \brief Inserta un dato en la dirección del elemento correspondiente
 *
 * \param char* horasTrabajadas dato a ser insertado
 * \param Employee* this dirección del elemento donde va el dato
*  \return retorna 0 si los punteros son validos, -1 si no.
 *
 */
int employee_setHorasTrabajadas(Employee* this,char* horasTrabajadas)
{
	int retorno = -1;
	if(this != NULL && horasTrabajadas != NULL)
	{
		if(esNumerica(horasTrabajadas,10))
		{
			retorno = 0;
			this->horasTrabajadas = atoi (horasTrabajadas);
		}
	}
	return retorno;
}
/** \brief obtiene un dato en la dirección del elemento correspondiente
 *
 * \param Employee* this dirección del elemento donde va el dato
 * \param int* horasTrabajadas puntero a la dirección donde se va a guardar el dato.
*  \return retorna 0 si los punteros son validos, -1 si no.
 *
 */
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
	int retorno = -1;
			if(this != NULL && horasTrabajadas >= 0)
			{
				retorno = 0;
				*horasTrabajadas = this->horasTrabajadas;
					}
			return retorno;
}
/** \brief Inserta un dato en la dirección del elemento correspondiente
 *
 * \param char* sueldo dato a ser insertado
 * \param Employee* this dirección del elemento donde va el dato
*  \return retorna 0 si los punteros son validos, -1 si no.
 *
 */
int employee_setSueldo(Employee* this,char* sueldo)
{
	int retorno = -1;
	float auxiliarSueldo;
	if(this != NULL && sueldo >= 0)
	{
		if(esNumerica(sueldo,1000000000))
		{
			auxiliarSueldo = atoi(sueldo);
			if(auxiliarSueldo >= 0)
			{
				retorno = 0;
				this->sueldo = auxiliarSueldo;
			}
		}
	}
	return retorno;
}
/** \brief obtiene un dato en la dirección del elemento correspondiente
 *
 * \param Employee* this dirección del elemento donde va el dato
 * \param int* sueldo puntero a la dirección donde se va a guardar el dato.
*  \return retorna 0 si los punteros son validos, -1 si no.
 *
 */
int employee_getSueldo(Employee* this,int* sueldo)
{
	int retorno = -1;
			if(this != NULL && sueldo >= 0)
			{
				retorno = 0;
				*sueldo = this->sueldo;
					}
			return retorno;
}



/** \brief valida una cadena de caracteres y verifica que sea numérica
 *
 * \param char*cadena cadena de caracteres a ser verificada
 * \param int* limite de caracteres a ser verificados
 *  \return retorna 0 si los punteros son validos, -1 si no.
 *
 */
static int esNumerica(char* cadena, int limite)
{
	int retorno = -1;
	int i;
	if(cadena != NULL && limite > 0)
	{
		retorno = 1;
		for(i=0;i<limite && cadena[i] != '\0';i++)
		{
			if(i==0 && (cadena[i] == '+' || cadena[i] == '-'))
			{
				continue;
			}
			if(cadena[i] < '0'||cadena[i] > '9')
			{
				retorno = 0;
				break;
			}

		}

	}
	return retorno;
}
/** \brief Compara los nombre de dos Elementos en la lista.
 *
 * \param void* pPersonaA puntero al elemento A
 * \param void* pPersonaB puntero al elemento B
 *  \return retorna 0 si son iguales, 1 si son diferentes
 *
 */
int employee_comparaPorNombre(void* pPersonA,void* pPersonB)
{
	Employee* personaA;
	Employee* personaB;

	personaA = (Employee*)pPersonA;
	personaB = (Employee*)pPersonB;

	return strcmp(personaA->nombre,personaB->nombre);
}

/** \brief Obtiene un elemento de la lista por su ID
 *
 * \param pArrayListEmployee LinkedList* puntero a la lista de Punteros
 * \param int idElemento ID del elemento que se quiere obtener
 * \param int limite tamaño de la lista
 * \return retorna el indice del elemento buscado - (-1) si no existe el elemento
 *
 */
int employee_getElementById(LinkedList* pArrayListEmployee, int idElemento, int limite)
{
		int idAux;
		int i;
		Employee* this;
		int retorno=-1;

		if( pArrayListEmployee != NULL &&
			limite > 0 )
		{
			for(i =0 ; i<= limite; i++)
			{
				this = (Employee*)ll_get(pArrayListEmployee,i);
				if(!employee_getId(this, &idAux) && idElemento == idAux)
				{
					retorno = i;
				}

			}
			if(limite > 0 && retorno == -1)
				{
					printf("\nId no se encuentra\n");
				}
		}

	return retorno;
}
/** \brief Imprime un elemento de la lista.
 *
 * \param Employee* this elemento a ser impreso.
 * \return retorna 1 si tuvo exito - (-1) si no se pudo imprimir.
 *
 */
int employee_printE(Employee* this)
{
		char nombreAux[NOMBRE_LEN];
		int idAux;
		int sueldoAux;
		int horasAux;
		int  retorno = -1;

		if(this != NULL)
		{
			retorno = 0;
			if( !employee_getId(this, &idAux) &&
				!employee_getNombre(this, nombreAux) &&
				!employee_getSueldo(this, &sueldoAux) &&
				!employee_getHorasTrabajadas(this, &horasAux))
			{
				printf("\n ID: %.4d - Nombre: %-10s - HorasT: %4d - Sueldo: %9d", idAux, nombreAux, horasAux, sueldoAux );
			}
		}
	return retorno;
}
/** \brief Imprime todos los elementos de la lista.
 *
 * \param int idElemento ID del elemento que se quiere obtener
 * \param int limite tamaño de la lista
 * \return retorna 1 si tuvo exito - (-1) si hay error.
 *
 */
int employee_printArryE(LinkedList* pArrayListEmployee, int limite)
{
	int retorno = -1;
	int i;
	Employee* this;
	if(pArrayListEmployee != NULL && limite >= 0)
	{
		retorno = 0;
		for(i=0; i < limite  ; i++)
		{
			this = (Employee*)ll_get(pArrayListEmployee,i);
			employee_printE( this);
		}
	}
	return retorno;
}
