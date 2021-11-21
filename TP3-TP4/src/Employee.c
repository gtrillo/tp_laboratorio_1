#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "Employee.h"
#include "validaciones.h"
#define LENNOMBRE 128
#define LENID 25
#define LENHORASTRABAJADAS 25
#define LENSUELDO 25
Employee* employee_new()
{
		Employee* pEmployee = (Employee*)malloc(sizeof(Employee));
		return pEmployee;
}

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr)
{
	Employee* pEmployee = NULL;
	pEmployee = employee_new();
	if (pEmployee != NULL && idStr  != NULL && nombreStr != NULL  && horasTrabajadasStr != NULL)
	{
			employee_setId(pEmployee, atoi(idStr));
			employee_setNombre(pEmployee, nombreStr);
			employee_setHorasTrabajadas(pEmployee, atoi(horasTrabajadasStr));
			employee_setSueldo(pEmployee, atoi(sueldoStr));
	}
		return pEmployee;
}

int employee_setId(Employee* this,int id)
{
	int retorno = -1;
	char aux [LENID];

	sprintf (aux, "%d", id);
	if (this != NULL && id >=0)
	{
		if (validarEntero(aux)==0)
		{
			retorno = 0;
			this->id = id;
		}
	}
	return retorno;
}

int employee_getId(Employee* this,int* id)
{
	int retorno = -1;
	if (this != NULL && id >= 0)
	{
		retorno = 0;
		*id = this->id;
	}
	return retorno;
}

int employee_setNombre(Employee* this,char* nombre)
{
	int retorno;
	if (this != NULL && nombre != NULL)
	{
		if (esNombre(nombre)==0)
		{
			retorno = 0;
			strncpy (this->nombre, nombre, LENNOMBRE);
		}
	}
	return retorno;
}

int employee_getNombre(Employee* this,char* nombre)
{
	int retorno;
	if (this != NULL && nombre != NULL)
	{
			retorno = 0;
			strncpy (nombre, this->nombre, LENNOMBRE);
	}
	return retorno;
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
	int retorno = -1;
	char aux [25];
	sprintf (aux, "%d", horasTrabajadas);

	if (this != NULL && horasTrabajadas >0)
		{
			if (validarEntero(aux)==0)
			{
				retorno = 0;
				this->horasTrabajadas = atoi (aux);
			}

		}
	return retorno;
}

int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
	int retorno = -1;
	if (this != NULL && horasTrabajadas != NULL)
	{
		retorno = 0;
		*horasTrabajadas = this -> horasTrabajadas;
	}
	return retorno;
}

int employee_setSueldo(Employee* this,int sueldo)
{
	int retorno = -1;
	char aux [25];

		sprintf (aux, "%d", sueldo);

		if (this != NULL && sueldo >=0)
		{
			if (validarEntero(aux)==0)
			{
				retorno = 0;
				this->sueldo = atoi (aux);
			}

		}
		return retorno;
}

int employee_getSueldo(Employee* this,int* sueldo)
{
	int retorno = -1;
		if (this != NULL && sueldo != NULL)
		{
			retorno = 0;
			*sueldo = this -> sueldo;
		}
		return retorno;
}

void employee_delete(LinkedList* this, int indice)
{
	if (this != NULL && ll_len(this)>0 && indice >=0)
	{
		 ll_remove(this, indice);
	}
}
