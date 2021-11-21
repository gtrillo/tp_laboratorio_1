#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
#define LENNOMBRE 128
#define LENID 25
#define LENHORASTRABAJADAS 25
#define LENSUELDO 25
/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
	Employee* auxpEmployee;
	char auxNombre [128];
	char auxID [LENID];
	char auxHorasTrabajadas [LENHORASTRABAJADAS];
	char auxSueldo [LENSUELDO];
	int retorno = -1;

	if (pFile != NULL && pArrayListEmployee != NULL)
	{
		fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n",auxID,auxNombre,auxHorasTrabajadas,auxSueldo);
		do {
				if (fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n",auxID,auxNombre,auxHorasTrabajadas,auxSueldo)==4)
				{
					auxpEmployee = employee_newParametros(auxID, auxNombre, auxHorasTrabajadas, auxSueldo);
					if (auxpEmployee != NULL)
					{
						ll_add(pArrayListEmployee, auxpEmployee);
						retorno = 0;
					}else
					{
						retorno = -1;
						break;
					}
				}
		}while(feof (pFile) == 0);
	}
    return retorno;

}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{

	    int retorno = -1;
		Employee* auxpEmployee;
		if (pFile != NULL && pArrayListEmployee != NULL)
		{
			do
			{
				auxpEmployee = employee_new();
				if (fread (auxpEmployee, sizeof (Employee),1,pFile)==1)
				{
					if (auxpEmployee != NULL)
					{
						ll_add(pArrayListEmployee, auxpEmployee);
						retorno = 0;
					}
					else
					{
						retorno = -1;
						break;
					}
				}
			}while (feof (pFile)==0);
		}
	    return retorno;
	}
