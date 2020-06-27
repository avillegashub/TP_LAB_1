#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"

/****************************************************
    Menu:
      1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
      2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
      3. Alta de empleado
      4. Modificar datos de empleado
      5. Baja de empleado
      6. Listar empleados
      7. Ordenar empleados
      8. Aumentar sueldos
      9. Filtrar por horas
     10. Contar por horas
     11. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     12. Guardar los datos de los empleados en el archivo data.csv (modo binario).
     13. Salir
*****************************************************/



int main()
{
	setbuf(stdout,NULL);
	int option = 0;
	//int asd;

    LinkedList* listaEmpleados = ll_newLinkedList();

    do{
    	option = controller_menu( );
        switch(option)
        {


            case 1:
                controller_loadFromText("data2.csv",listaEmpleados);
                break;
            case 2:
                controller_loadFromBinary("data2.csv",listaEmpleados);
                break;
            case 3:
                controller_addEmployee(listaEmpleados);
                break;
            case 4:
                controller_editEmployee(listaEmpleados);
                break;
            case 5:
            	controller_removeEmployee(listaEmpleados);
                break;
            case 6:
            	controller_ListEmployee(listaEmpleados);
                break;
            case 7:
            	controller_sortEmployee(listaEmpleados);
                break;
            case 8:
            	controller_aumentarSueldos(listaEmpleados);
                           break;
            case 9:
            	controller_Filtrar(listaEmpleados);
                           break;
            case 10:
            	controller_Contar(listaEmpleados);
                           break;
            case 11:
            	controller_saveAsText("data2.csv" , listaEmpleados);
                           break;
            case 12:
            	controller_saveAsBinary("data2.csv" , listaEmpleados);
                           break;
            case 13:
            	printf("\nAdios\n");
                           break;

        }
    }while(option != 20);
    return 0;
}

