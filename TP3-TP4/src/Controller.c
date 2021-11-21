#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Controller.h"
#include "LinkedList.h"
#include "parser.h"
#include "Employee.h"
#include "utn_pedirCadena.h"
#define LENNOMBRE 128
#define LENID 25
#define LENHORASTRABAJADAS 25
#define LENSUELDO 25
static int elergirOpcion (int* opcion);
static void imprimirOpciones (void);
static int modificarNombre (char pNombre[]);
static int modificarSueldo (int* pSueldo);
static int modificarHorasTrabajadas (int* pCantidadHorasTrabajadas);
int controller_dameUnIdNuevo(LinkedList* pArrayListEmployee);
static void controller_imprimirOpciones();
static int controller_subSort(void* primerNombre, void* segundoNombre);
/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	FILE* archivo = fopen (path, "r");
	if (archivo != NULL)
	{
		if (parser_EmployeeFromText(archivo, pArrayListEmployee)==0)
		{
			retorno = 0;
		}else
		{
			printf ("\nerror al cargar el archivo de texto");
		}
		fclose(archivo);
	}
	return retorno;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
		int retorno;
		FILE* archivo = fopen (path, "rb");
		if (archivo != NULL)
		{
			if (parser_EmployeeFromBinary(archivo, pArrayListEmployee)==0)
			{
				retorno = 0;
			}
			else
			{
				printf ("\nError al cargar el archivo");
			}
			fclose(archivo);
		}
	    return retorno;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
	char auxNombre [LENNOMBRE];
	int horasTrabajadas;
	int sueldo;
	int retorno = -1;
	Employee* auxEmployee;
	int id = controller_dameUnIdNuevo(pArrayListEmployee);
	if (pArrayListEmployee != NULL)
	{
		if (utn_getText(auxNombre, LENNOMBRE, "Ingrese nombre del empleado:\n", "Caracter invalido:\n", 5)==0)
		{
			if (utn_getNumeroInt(&horasTrabajadas, "Ingrese horas trabajadas:\n", "Error caracter invalido:\n", 1, 10000, 5)==0)
			{
				if (utn_getNumeroInt(&sueldo, "Ingrese sueldo:\n", "Error caracter invalido:\n", 1, 10000000, 5)==0)
				{
						auxEmployee = employee_new();
						if (auxEmployee != NULL)
						{
							employee_setId(auxEmployee, id);
							employee_setNombre(auxEmployee, auxNombre);
							employee_setHorasTrabajadas(auxEmployee, horasTrabajadas);
							employee_setSueldo(auxEmployee, sueldo);
							ll_add(pArrayListEmployee, auxEmployee);
							retorno = 0;
					}
				}
			}
		}
	}
    return retorno;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    int opcion;
    int retorno = -1;
    char auxNombre[LENNOMBRE];
    int auxHorasTrabajadas;
    int auxSueldo;
    int idIngresado;
    Employee* auxPListEmployee;
    int largoLista = ll_len(pArrayListEmployee);
    if (pArrayListEmployee != NULL)
    {
    	if (utn_getNumeroInt(&idIngresado, "\nIngrese el ID del empleado a modificar", "Error. el id es invalido:\n", 0, largoLista, 5)!=-1)
    	{
    		if (controller_buscarPorId(pArrayListEmployee, idIngresado)!=-1)
    		{
    			auxPListEmployee = ll_get(pArrayListEmployee, idIngresado);
    			if (elergirOpcion(&opcion)==0)
					{
						retorno = 1;
						switch (opcion)
						{
							retorno = 0;
						case 1:
							if (modificarNombre(auxNombre)==0)
							{
								employee_setNombre(auxPListEmployee, auxNombre);
							}
							break;
						case 2:
							if (modificarHorasTrabajadas(&auxHorasTrabajadas)==0)
							{
								employee_setHorasTrabajadas(auxPListEmployee, auxHorasTrabajadas);
							}
							break;
						case 3:
							if (modificarSueldo(&auxSueldo)==0)
							{
								employee_setSueldo(auxPListEmployee, auxSueldo);
							}
							break;
						}
					}
				}

    	}
  }
	return retorno;
}
static int elergirOpcion (int* opcion)
{
	int retorno = -1;
	int auxiliarOpcion;
	imprimirOpciones();
	if (utn_getNumeroInt(&auxiliarOpcion, "\nSeleccion una opcion:\n", "Error opcion invalida", 1, 3, 5)==0)
	{
		 *opcion = auxiliarOpcion;
		 retorno = 0;
	}
	return retorno;
}

static void imprimirOpciones (void)
{
	printf ("\n¿Que campo desea modificar?");
	printf ("\n Nombre del empleado");
	printf ("\n Horas trabajadas");
	printf ("\n Sueldo");
}

static int modificarNombre (char pNombre[])
{
	int retorno = -1;
	char mensaje[100];
	char auxNombre[LENNOMBRE];
	strncpy(mensaje, "\nIngrese el nombre del empleado",sizeof(mensaje));
	if (utn_getText(auxNombre, 63, mensaje, "Error",2) == 0)
	{
		retorno = 0;
		strncpy(pNombre, auxNombre, 63);
	}
	return retorno;
}

static int modificarSueldo (int* pSueldo)
{
	int retorno = -1;
	char mensaje[100];
	int auxSalario;
	strncpy(mensaje, "\nIngrese sueldo:\n",sizeof(mensaje));
	if (utn_getNumeroInt(&auxSalario, mensaje, "Error", 0, 10000, 2)== 0)
	{
		retorno = 0;
		*pSueldo = auxSalario;
	}
	return retorno;
}

static int modificarHorasTrabajadas (int* pCantidadHorasTrabajadas)
{
	int retorno = -1;
	char mensaje[100];
	int horasTrabajadas;
	strncpy(mensaje, "\nIngrese horas trabajadas:\n",sizeof(mensaje));
	if (utn_getNumeroInt(&horasTrabajadas, mensaje, "Error", 0, 10000, 2)== 0)
	{
		retorno = 0;
		*pCantidadHorasTrabajadas = horasTrabajadas;
	}
	return retorno;
}
/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int retorno;
    int IDIngresado;
    int lenll = ll_len(pArrayListEmployee);
   if (pArrayListEmployee!= NULL)
   {
	   if(utn_getNumeroInt(&IDIngresado,"\nIngrese el ID Del empleado que desea dar de baja:\n", "El ID ingresado es invalido, Intente nuevamente:\n", 0, lenll, 5)==0)
	   {
		   if (controller_buscarPorId(pArrayListEmployee, IDIngresado)-1)
		   {
			   ll_get(pArrayListEmployee, IDIngresado);
			   employee_delete(pArrayListEmployee, IDIngresado);
			   retorno = 0;
		   }
	   }
   }
    return retorno;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	int i;
	Employee* auxiliar;
	int auxId;
	  if(pArrayListEmployee != NULL && ll_len(pArrayListEmployee) > 0)
	    {
	    	for(i = 0; i < ll_len(pArrayListEmployee); i++)
			{
				auxiliar = ll_get(pArrayListEmployee, i);
				if(auxiliar != NULL)
				{
					if(employee_getId(auxiliar, &auxId) == 0)
					   {
						controller_printEmployee(pArrayListEmployee, auxId);
					   }
				}
			}
	    }
    return retorno;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
	int opcion;
	int retorno = -1;

	if (pArrayListEmployee != NULL && ll_len(pArrayListEmployee)>0)
	{
		controller_imprimirOpciones();
		if(utn_getNumeroInt(&opcion, "opcion:\n", "Error. opcion:\n", 0, 1, 5)==0)
		{
			retorno = ll_sort(pArrayListEmployee, controller_subSort, opcion);
		}
	}

	return retorno;
}

static void controller_imprimirOpciones()
{
	printf ("\nIngrese 0 o 1:");
	printf ("\n0-ordenar nombre de manera descendente:\n");
	printf ("\n1-ordenar nombre de manera ascendente:\n");
}

static int controller_subSort(void* primerNombre, void* segundoNombre)
{
	int retorno;
	char auxPrimerNombre [LENNOMBRE];
	char auxSegundoNombre [LENNOMBRE];
	Employee* primero = (Employee*) primerNombre;
	Employee* segundo = (Employee*) segundoNombre;

	if (employee_getNombre(primero, auxPrimerNombre) != -1 && employee_getNombre(segundo, auxSegundoNombre)!= -1)
	{
		retorno = strcmp (auxPrimerNombre, auxSegundoNombre);
	}


	return retorno;
}
/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	Employee* auxpEmployee;
	FILE* archivo = fopen (path, "wb");
	char auxNombre [128];
	int auxID;
	int auxHorasTrabajadas;
	int auxSueldo;
	int i;
	if (path != NULL && pArrayListEmployee != NULL && archivo != NULL)
	{
		fprintf(archivo,"id,nombre,horasTrabajadas,sueldo\n");
		for (i = 0; i < ll_len(pArrayListEmployee); i++)
		{
			auxpEmployee = ll_get(pArrayListEmployee, i);
			if (auxpEmployee != NULL)
			{
				retorno = 0;
				employee_getId(auxpEmployee, &auxID);
				employee_getNombre(auxpEmployee, auxNombre);
				employee_getHorasTrabajadas(auxpEmployee, &auxHorasTrabajadas);
				employee_getSueldo(auxpEmployee, &auxSueldo);
				//printf ("%d,%s,%d,%d\n",auxID, auxNombre, auxHorasTrabajadas, auxSueldo);
				fprintf (archivo, "%d,%s,%d,%d\n",auxID, auxNombre, auxHorasTrabajadas, auxSueldo);
			}
		}
		fclose(archivo);
	}
	return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	Employee* auxEmployee = employee_new();
	int i;
	if (pArrayListEmployee != NULL)
		{
			FILE* archivo = fopen (path, "wb");
			if (path != NULL && archivo != NULL)
			{
				for (i = 0; i < ll_len(pArrayListEmployee); i++)
				{
					auxEmployee = ll_get(pArrayListEmployee, i);
					if(auxEmployee != NULL)
					{
						fwrite(auxEmployee,sizeof(Employee),1,archivo);
					}
				}
			}
			fclose (archivo);
		}
		return retorno;
}

int controller_buscarPorId(LinkedList* pArrayListEmployee, int id)
{
    int status = -1;
    int i;
    int auxId;
    Employee* aux;
    if(pArrayListEmployee != NULL && ll_len(pArrayListEmployee) > 0 && id >= 0)
    {
        for(i = 0; i < ll_len(pArrayListEmployee); i++)
        {
            aux = ll_get(pArrayListEmployee, i);
            if(aux != NULL)
            {
                if(employee_getId(aux, &auxId)== 0)
                {
                    if(id == auxId)
                    {
                        status = i;
                        break;
                    }
                }
            }
        }

    }

    return status;
}

int controller_printEmployee (LinkedList* pArrayListEmployee, int id)
{
	int retorno;
	int indice;
	char auxNombre [LENNOMBRE];
	int auxID;
	int auxHorasTrabajadas;
	int auxSueldo;
    Employee* auxiliarEmployee;
	if (pArrayListEmployee != NULL && id >=0 && ll_len(pArrayListEmployee)>0)
	{
		indice = controller_buscarPorId(pArrayListEmployee, id);
		if (indice != -1)
		{
			auxiliarEmployee = ll_get(pArrayListEmployee, indice);
			if (auxiliarEmployee != NULL)
			{
				employee_getId(auxiliarEmployee, &auxID);
				employee_getNombre(auxiliarEmployee, auxNombre);
				employee_getHorasTrabajadas(auxiliarEmployee, &auxHorasTrabajadas);
				employee_getSueldo(auxiliarEmployee, &auxSueldo);
				printf("\nID: %d | NOMBRE: %s | HORAS TRABAJADAS : %d | SUELDO: %d|", auxID, auxNombre, auxHorasTrabajadas, auxSueldo);
				retorno = 0;
			}
		}
	}
	return retorno;
}
/** \brief Genera un numero id nuevo.
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_dameUnIdNuevo(LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	int largoLista;
	int idNuevo;

	if (pArrayListEmployee != NULL)
	{
		largoLista = ll_len(pArrayListEmployee);
		idNuevo = largoLista ++;
		retorno = idNuevo;
	}
	return retorno;
}

