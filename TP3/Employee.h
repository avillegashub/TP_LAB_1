#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
#define NOMBRE_LEN 50
#include "linkedList.h"

typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;

Employee* employee_new();
Employee* employee_newParametros(char* idStr, char* nombreStr,char* horasTrabajadasStr, char*sueldoStr);

void employee_delete(Employee* this);

int employee_setId(Employee* this,char* id);
int employee_getId(Employee* this,int* id);

int employee_setNombre(Employee* this,char* nombre);
int employee_getNombre(Employee* this,char* nombre);

int employee_setHorasTrabajadas(Employee* this,char* horasTrabajadas);
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

int employee_setSueldo(Employee* this,char* sueldo);
int employee_getSueldo(Employee* this,int* sueldo);

int employee_ultimoId(LinkedList* pArrayListEmployee);
int employee_comparaPorNombre(void* pPersonA,void* pPersonB);
int employee_getElementById(LinkedList* pArrayListEmployee, int pId, int limite);

int employee_printE(Employee* this);
int employee_printArryE(LinkedList* pArrayListEmployee, int limite);

#endif // employee_H_INCLUDED
