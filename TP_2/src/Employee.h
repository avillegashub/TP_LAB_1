#ifndef EMPLOYEE_H_
#define EMPLOYEE_H_

#define NOMBRE_LEN 51



typedef struct
{
	int id;
	char name[NOMBRE_LEN];
	char lastName[NOMBRE_LEN];
	float salary;
	int sector;
	int isEmpty;

}Employee;

int emp_imprimir(Employee* auxProducto);
int emp_inicializarArray(Employee* array,int limite);
int emp_altaArray(Employee* array,int limite, int indice, int* id, int* contador);
int emp_getEmptyIndex(Employee* array,int limite);
int emp_imprimirArray(Employee* array,int limite);
int emp_buscarId(Employee* array, int limite, int valorBuscado);
int emp_idSearch(Employee* array, int limite, int valorBuscado);
int emp_modificarArray(Employee* array,int limite, int indice);
int emp_bajaArray(Employee* array,int limite, int indice, int* contador);
int emp_ordenarPorNombre(Employee* array,int limite);
int emp_ordenarPorSector(Employee* array,int limite);
int emp_promedio(Employee* array, int cantidadEmpleados);
int pan_ordenarPorNombrePrecio(Employee* array,int limite);
int emp_ordenarPorNombreSector(Employee* array,int limite);
int emp_altaForzadaArray(Employee* array,int limite, int indice, int* id,char* nombre,char* apellido, float salario ,int sector, int* contador);



#endif /* EMPLOYEE_H_ */
