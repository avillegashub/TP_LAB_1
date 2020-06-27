#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"


static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void)
{
    LinkedList* this= NULL;

    this = (LinkedList*)malloc(sizeof(LinkedList));
    if (this!=NULL)
    {
    	this->pFirstNode = NULL;
    	this->size=0;
    }
    return this;
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* this)
{
    int returnAux = -1;
    if(this!=NULL)
    {
    	returnAux = this->size;
    }
    return returnAux;
}


/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pNode) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex)
{
	Node* aux = NULL;
	int indice;
	if(this !=NULL && nodeIndex >= 0 &&  nodeIndex <  ll_len(this))
	{
		aux = this->pFirstNode;
		indice = 0;
		do
		{
			if(indice == nodeIndex)
			{
				break;
			}
			else
			{
				aux = aux->pNextNode;
				indice++;
			}
		}while(aux != NULL);
	}
    return aux;
}

/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(LinkedList* this, int nodeIndex)
{
    return getNode(this, nodeIndex);
}


/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    int returnAux = -1;
    Node* nodo;
    Node* aux;
    if(this!=NULL && nodeIndex >= 0 &&  nodeIndex <=  ll_len(this))
    {
		nodo=malloc(sizeof(Node));
		nodo->pElement = pElement;
		returnAux = 0;
			if( nodeIndex == 0)
			{
				nodo->pNextNode = this->pFirstNode;
				this->pFirstNode = nodo;
			}
			else if(nodeIndex ==  ll_len(this))
			{
				aux = getNode(this, nodeIndex-1);
				nodo->pNextNode = aux->pNextNode;
				aux->pNextNode = nodo;
			}
			else
			{
				aux = getNode(this, nodeIndex);
				nodo->pNextNode = aux;
				aux = getNode(this, nodeIndex-1);
				aux->pNextNode = nodo;
			}
    	this->size++;
    }
    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
  * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}


/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList* this, void* pElement)
{
    int returnAux = -1;

    if(this != NULL )
    {
    	addNode(this, ll_len(this), pElement);
    	returnAux = 0;
    }

    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList* this, int index)
{
    void* returnAux = NULL;
    Node* nodeAux;
    if(this != NULL && index >= 0 &&  index < ll_len(this))
    {
    	nodeAux = getNode(this, index);
    	returnAux = nodeAux->pElement;
    }

    return returnAux;
}


/** \brief Modifica un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_set(LinkedList* this, int index,void* pElement)
{

    int returnAux = -1;
    Node* aux = NULL;

    if(this != NULL && index >= 0 &&  index < ll_len(this))
        {
    		aux =  getNode(this, index);
    		aux->pElement = pElement;
    		returnAux = 0;
    	}

    return returnAux;
}


/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList* this,int index)
{
    int returnAux = -1;
    Node* aux = NULL;
    Node* auxRemove = NULL;
    if(this != NULL && ll_len(this) > 0 && index >= 0  && index < ll_len(this))
    {
   			auxRemove = getNode(this, index);

    		if(index == 0)
    		{
    			this->pFirstNode = auxRemove->pNextNode;
    		}
       		else
    		{
       			aux = getNode(this, index-1);
    			aux->pNextNode = auxRemove->pNextNode;
    		}
			free(auxRemove);
			this->size--;
			returnAux = 0;
    }

    return returnAux;
}


/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList* this)
{
    int returnAux = -1;
    int list;

    list = ll_len(this);

    if(this != NULL && list > 0)
    {
    do
    {
    	list--;
    	ll_remove(this, list);
    }while(list>0);
    returnAux = 0;
    }

    return returnAux;
}


/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(LinkedList* this)
{
    int returnAux = -1;
    if(this!=NULL)
    {
    	ll_clear(this);
    	free(this);
    	returnAux = 0;
    }

    return returnAux;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    int list;
    int i=0;
    list = ll_len(this);
    void* aux;

    if(this != NULL && list>0)
    {
    	do
    	{

    	aux = ll_get(this, i);
    	if(aux == pElement)
    	{
    		returnAux = i;
    		break;
    	}
    	i++;

    	}while(i< list);

    }

    return returnAux;
}

/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList* this)
{
    int returnAux = -1;
    int list = ll_len(this);
    if(this != NULL && list >= 0)
    {
    	returnAux = 1;
    	if(list >0)
    	{
    		returnAux = 0;
    	}
    }

    return returnAux;
}

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_push(LinkedList* this, int index, void* pElement)
{
    int returnAux = -1;

    if(this != NULL && index >= 0 && index <= ll_len(this))
    {
		returnAux = 0;
		addNode(this, index, pElement);
    }
    return returnAux;
}


/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList* this,int index)
{
    void* returnAux = NULL;
    Node* auxPoped = NULL;
    if(this != NULL && ll_len(this)> 0 && index >= 0 && index < ll_len(this))
	{
    	auxPoped = getNode(this, index);
    	returnAux = auxPoped->pElement;
    	ll_remove(this, index);
    }
    return returnAux;
}


/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
*/
int ll_contains(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    int i=0;
    void* aux = NULL;
    int list = ll_len(this);

    if(this != NULL )
        {
        		returnAux = 0;
        	do
        	{
        	aux = ll_get(this, i);
        	if(aux == pElement)
        	{
        		returnAux = 1;
        		break;
        	}
        	i++;

        	}while(i< list);

        }

    return returnAux;
}

/** \brief  Determina si todos los elementos de la lista (this2)
            estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
                        ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
*/
int ll_containsAll(LinkedList* this,LinkedList* this2)
{
	int returnAux = -1;
	int i;
	void* aux = NULL;


	    if(this != NULL && this2 != NULL )
	    {
	    			returnAux = 1;
	    	for(i=0 ; i < ll_len(this2); i++)
	    	{
	    		aux = ll_get(this2, i);
	    		if(ll_contains(this, aux) != 1)
	    		{
	    			returnAux = 0;
	    			break;
	    		}

	    	}
	    }
    return returnAux;
}

/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                         (puntero a la nueva lista) Si ok
*/
LinkedList* ll_subList(LinkedList* this,int from,int to)
{
    LinkedList* cloneArray = NULL;
    int i;
    void* aux;
    if(this != NULL && from >= 0 && to <= ll_len(this))
    {
    	cloneArray = ll_newLinkedList();
    	for(i = from ; i < to ; i++)
    	{
    		aux = ll_get(this, i);
    		ll_add(cloneArray, aux);
    	}
    }

    return cloneArray;
}



/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* this)
{
    LinkedList* cloneArray = NULL;
    if(this != NULL)
    {
    cloneArray = ll_subList(this, 0, ll_len(this));
    }
    return cloneArray;
}


/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order)
{
	int returnAux =-1;
	int flagSwap;
	int i;
	void* fElement;
	void* nElement;
	void* aux;
	int thisLen = ll_len(this);
	int fResult;

   if(this != NULL &&   order >= 0 && order <= 1 && pFunc != NULL)
   {
   	returnAux = 0;
		do
		{
			flagSwap = 0;
			for(i=0;i<thisLen-1;i++)
			{
				fElement = ll_get(this,i );
				nElement = ll_get(this,i+1);
				fResult = pFunc(fElement, nElement);
   				if( fResult == 0)
				{
					continue;
				}
				else
				{
					flagSwap = 1;
					if((order == 1 && fResult == 1) || (order == 0 && fResult == -1))
					{
					aux = fElement;
					ll_set(this, i, nElement);
					ll_set(this, i+1, aux);
					}
				}
			}
			thisLen--;
		}while(flagSwap);
	}
   return returnAux;
}

/** \brief Modifica los Elementos de la lista utilizando la funcion criterio recibida como parametro
 * 	\param pList LinkedList* Puntero a la lista
 *	\param pFunc (*pFunc) Puntero a la funcion criterio
 * 	\return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int ll_map(LinkedList* this, int (*pFunc)(void*))
{

	int returnAux =-1;
	int i;
	void* pElement;
	int thisLen = ll_len(this);
	if(this != NULL && pFunc != NULL && thisLen > 0)
	{
	returnAux = 0;
			for(i=0;i<=thisLen-1;i++)
			{
				pElement = ll_get(this, i);
				if(pFunc(pElement) == -1)
				{
					returnAux = -1;
					break;
				}
			}
	}
	return returnAux;
}


/** \brief Obtiene un Dato de los Elementos de la lista utilizando la funcion criterio recibida como parametro
 * 	\param pList LinkedList* Puntero a la lista
 *	\param pFunc (*pFunc) Puntero a la funcion criterio
 * 	\return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                int returnAux Retorna el Dato, si tuvo Éxito.
 */
int ll_reduce(LinkedList* this, int (*pFunc)(void*))
{

		int returnAux =-1;
		int data=0;
		int i;
		void* pElement;
		int thisLen = ll_len(this);

		if(this != NULL && pFunc != NULL && thisLen > 0)
		{
		returnAux = 0;
				for(i=0;i<=thisLen-1;i++)
				{
					pElement = ll_get(this, i);
					if(pFunc(pElement)==0)
					{
						data++;
					}
				}
			returnAux = data;
		}
		return returnAux;
}



/** \brief Filtra los Elementos de la lista utilizando la funcion criterio recibida como parametro
 * 	\param pList LinkedList* Puntero a la lista
 *	\param pFunc (*pFunc) Puntero a la funcion criterio
 * 	\return int Retorna  NULL Error: si el puntero a la listas es NULL
                         LinkedList* thisFiltered Si ok
 */
LinkedList* ll_filter(LinkedList* this, int (*pFunc)(void*))
{

	LinkedList* thisFiltered = NULL;
	void* pElement;
	int i;
	int thisLen = ll_len(this);

	    if(this != NULL && pFunc != NULL && thisLen > 0)
	    {
	    	thisFiltered = ll_newLinkedList();
	    	for(i=0;i<=thisLen-1;i++)
	    	{
	    		pElement = ll_get(this, i);
	    		if(pFunc(pElement) == 0)
	    		{
	    			ll_add(thisFiltered, pElement);
	    		}
	    	}
	   	}
	return thisFiltered;
}
