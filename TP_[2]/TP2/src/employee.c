#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "employee.h"
#include "utn_pedirCadena.h"

#define LEN_ARRAY 51
#define ESTADO_LIBRE 1
#define ESTADO_OCUPADO 0

static int elegirOpcion (int* opcion);
static void imprimirOpciones (void);
static int modificarSector (int* pArray);
static int modificarSalario (float* pArray);
static int modificarNombre (char array[]);
static int modificarApellido (char array[]);
static int DameUnIdNuevo(void);
static int contadorDeEmpleados (Employee array [], int len, int *resultado);

/** \brief add in a existing list of employees the values received as parameters
* in the first empty position
* \param list employee*
* \param len int
* \param id int
* \param name[] char
* \param lastName[] char
* \param salary float
* \param sector int
* \return int Return (-1) if Error [Invalid length or NULL pointer or without
free space] - (0) if Ok
*/

int initEmployees(Employee* list, int len)
{
	int retorno;
	int i;

	if (list != NULL && len > 0)
	{
		for (i = 0; i < len; i++)
		{
			list[i].flagEmpty = ESTADO_LIBRE;
			retorno = 0;
		}
	}
	else
	{
		retorno = -1;
	}
	return retorno;
}
/** \brief add in a existing list of employees the values received as parameters
* in the first empty position
* \param list employee*
* \param len int
* \param id int
* \param name[] char
* \param lastName[] char
* \param salary float
* \param sector int
* \return int Return (-1) if Error [Invalid length or NULL pointer or without
free space] - (0) if Ok
**/
int addEmployee(Employee* list, int len, int id, char name[],char lastName[],float salary,int sector)
{
	int retorno;
	int sectorAux;
	float salaryAux;
	char nameAux [51];
	char lastNameAux [51];

	if (list != NULL && len >= 0 && id >= 0 && salary >= 0 && sector >= 0)
	{
		if (utn_getText(nameAux, 51, "Ingrese nombre del empleado:\n", "Error de tipeo, Intente nuevamente:\n", 5)==0)
		{
			if (utn_getText(lastNameAux, 51, "Ingrese Apellido:\n", "Error de tipeo, Intente nuevamente:\n", 5)==0)
				{
					if (utn_getNumeroFloat(&salaryAux, "Ingrese salario:\n", "Error de tipeo, El salario solo puede contener numeros", 1, 1000000000, 5)==0)
					{
						if (utn_getNumeroInt(&sectorAux, "Seleccione sector:\n", "sector invalido.", 1, 10, 5)==0)
						{
							strncpy(list->name, nameAux, sizeof (list->name));
							strncpy(list->lastName, lastNameAux, sizeof (list->lastName));
							list->salary = salaryAux;
							list->sector = sectorAux;
							list->id = DameUnIdNuevo();
							list ->flagEmpty = ESTADO_OCUPADO;
							retorno = 0;
						}
					}
				}
		}
	}
	return retorno;
}

static int DameUnIdNuevo(void)
{
	static int contador = 0;

	return contador++;
}
/**
 *\brief funsion que devuelve un lugar libre en el array
 *\param lista employe
 *\param largo de la lista
 *\param retorno de posicion libre
 *\return retorna 0 en el caso de que este todo bien y -1 en caso de error
 */
int DameUnLugarLibre (Employee pEmpleado[], int lenArray, int* retornoPosicionLibre)
{
	int retorno;
	int indice;
	int auxLugarLibre;
	if (pEmpleado != NULL)
	{
		for (indice = 0; indice < lenArray; indice++)
		{
			if (pEmpleado[indice].flagEmpty == 1)
			{
				auxLugarLibre = indice;
				retorno = 0;
				break;
			}
		}
	}
	*retornoPosicionLibre = auxLugarLibre;
	return retorno;
}
/** \brief find an Employee by Id en returns the index position in array.
*
* \param list Employee*
* \param len int
* \param id int
* \return Return employee index position or (-1) if [Invalid length or NULL
pointer received or employee not found]
*
*/
int findEmployeeById(Employee* list, int len,int id)
{
	int retorno = -1;
	int indice;

	if (list != NULL && id >=0 && len >= 0)
	{
		for (indice = 0; indice < len; indice++)
		{
			if (id == list[indice].id && list[indice].flagEmpty == ESTADO_OCUPADO)
			{
				retorno = indice;
				break;
			}
		}
	}
	return retorno;
}
/** \brief Remove a Employee by Id (put isEmpty Flag in 1)
*
* \param list Employee*
* \param len int
* \param id int
* \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
find a employee] - (0) if Ok
*
*/
int removeEmployee(Employee* list, int len, int id)
{
		int retorno = -1;
		int indice;

		for (indice = 0; indice < len; indice++)
		{
			if (id == list[indice].id && list[indice].flagEmpty == ESTADO_OCUPADO)
			{
				list[indice].flagEmpty = ESTADO_LIBRE;
				retorno = 0;
				break;
			}

		}
		return retorno;
}

int printEmployees(Employee* list, int length)
{
	int indice;
	int retorno = -1;
	if (list != NULL && list >= 0)
	{
	for (indice = 0; indice < length; indice++)
	{
		if (list[indice].flagEmpty == ESTADO_OCUPADO)
		{
			printf ("\nID: %d - NOMBRE: %s - APELLIDO: %s - SALARIO: $%.2f - SECTOR: %d", list[indice].id, list[indice].name, list[indice].lastName, list[indice].salary, list[indice].sector);
			retorno = 0;
		}
	}
	}
	return retorno;
}
/**
 *\brief funsion para modificar un empleado
 *\param lista Employee
 *\return retorna 0 en el caso de que este todo bien y -1 en caso de error
 */
int modificarEmpleado(Employee* aEmpleados)
{
	int opcion;
	int retorno = -1;
	int auxSector;
	float auxSalary;
	char auxName[51];
	char auxLastName[51];

	if (aEmpleados != NULL)
	{
		if (elegirOpcion(&opcion) == 0)
		{
			retorno = 1;
			switch (opcion)
			{
				case 1:
					if (modificarSector(&auxSector) == 0)
					{
						aEmpleados->sector = auxSector;
					}
					break;
				case 2:
					if (modificarSalario(&auxSalary) == 0)
					{
						aEmpleados->salary = auxSalary;
					}
					break;
				case 3:
					if (modificarNombre(auxName) == 0)
					{
						strncpy(aEmpleados->name, auxName, LEN_ARRAY);
					}
					break;
				case 4:
					if (modificarApellido(auxLastName) == 0)
					{
						strncpy(aEmpleados->lastName, auxLastName, LEN_ARRAY);
					}
			}
		}
	}
	return retorno;
}
/**
 *\brief funsion seleccionar una opcion del submenu dentro de modificar
 *\param puntero al espacio en memoria de opcion
 *\return retorna 0 en el caso de que este todo bien y -1 en caso de error
 */
static int elegirOpcion (int* opcion)
{
	int retorno = -1;
	int auxOpcion;

	imprimirOpciones();
	if (utn_getNumeroInt(&auxOpcion,"\nUtilice el teclado numerico para seleccionar una opcion:\n","Error",1,4,2) == 0)
	{
		retorno = 0;
		*opcion = auxOpcion;
	}
	return retorno;
}

static void imprimirOpciones (void)
{
	printf ("\n?Que campo desea modificar?");
	printf("\n1. Sector");
	printf("\n2. Salario");
	printf("\n3. Nombre del empleado");
	printf("\n4. Apellido del empleado");
}
/**
 *\brief funsion para modificar sector
 *\param lista Employee
 *\return retorna 0 en el caso de que este todo bien y -1 en caso de error
 */
static int modificarSector (int* pArray)
{
	int retorno = -1;
	char mensaje[100];
	int auxSector;
	strncpy(mensaje, "\nIngrese el sector:",sizeof(mensaje));
	if (utn_getNumeroInt(&auxSector,mensaje,"Error",1,100,2) == 0)
	{
		retorno = 0;
		*pArray = auxSector;
	}
	return retorno;
}
/**
 *\brief funsion para modificar salario
 *\param lista Employee
 *\return retorna 0 en el caso de que este todo bien y -1 en caso de error
 */
static int modificarSalario (float* pArray)
{
	int retorno = -1;
	char mensaje[100];
	float auxSalario;
	strncpy(mensaje, "\nIngrese salario",sizeof(mensaje));
	if (utn_getNumeroFloat(&auxSalario, mensaje, "Error", 0, 10000, 2)== 0)
	{
		retorno = 0;
		*pArray = auxSalario;
	}
	return retorno;
}
/**
 *\brief funsion para modificar nombre
 *\param lista Employee
 *\return retorna 0 en el caso de que este todo bien y -1 en caso de error
 */
static int modificarNombre (char array[])
{
	int retorno = -1;
	char mensaje[100];
	char auxName[LEN_ARRAY];
	strncpy(mensaje, "\nIngrese el nombre",sizeof(mensaje));
	if (utn_getText(auxName, LEN_ARRAY, mensaje, "Error",2) == 0)
	{
		retorno = 0;
		strncpy(array, auxName, LEN_ARRAY);
	}
	return retorno;
}
/**
 *\brief funsion para modificar apellido
 *\param lista Employee
 *\return retorna 0 en el caso de que este todo bien y -1 en caso de error
 */
static int modificarApellido (char array[])
{
	int retorno = -1;
	char mensaje[100];
	char auxApellido[LEN_ARRAY];
	strncpy(mensaje, "\nIngrese apellido",sizeof(mensaje));
	if (utn_getText(auxApellido, LEN_ARRAY, mensaje, "Error",2) == 0)
	{
		retorno = 0;
		strncpy(array, auxApellido,LEN_ARRAY);
	}
	return retorno;
}
/** \brief Sort the elements in the array of employees, the argument order
indicate UP or DOWN order
*
* \param list Employee*
* \param len int
* \param order int [1] indicate UP - [0] indicate DOWN
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int sortEmployees(Employee* list, int len, int order)
{

	int flagSwap;
	int i;
	int retorno = -1;
	Employee buffer;
	int auxiliar;
	if (list != NULL && len >= 0){
		retorno = 0;
	do{
		flagSwap = 0;
		for (i = 0; i < len -1 ; i++){
			if (order == 0)
			{
				if (list[i].flagEmpty || list[i+1].flagEmpty)
				{
					continue;
				}
				auxiliar = strncmp (list[i].lastName,list[i+1].lastName,len);
				if (auxiliar > 0 || (auxiliar == 0 && list [i].sector < list[i+1].sector)){
					flagSwap = 1;
					buffer = list [i];
					list [i] = list [i+1];
					list [i+1] = buffer;
				}
			}
			else
			{
				if (list[i].flagEmpty || list[i+1].flagEmpty)
				{
				continue;
				}
				auxiliar = strncmp (list[i].lastName,list[i+1].lastName,len);
				if (auxiliar < 0 || (auxiliar == 0 && list [i].sector < list[i+1].sector)){
				flagSwap = 1;
				buffer = list [i];
				list [i] = list [i+1];
				list [i+1] = buffer;
				}
			}
		}
	}while (flagSwap);
	}
	return retorno;
}
/** \brief funsion para calcular el promedio de los salarios ingresados
*
* \param lista Employee*
* \param largo del array
* \param puntero al espacion en memoria donde se copiara el resultado
* \retorna 0 en caso de estar bien y -1 en caso de error
*
*/

int promedioSalario (Employee array [], int len, float *resultado, float *retornoAcumSalario)
{
	float acumSalario = 0;
	int i;
	float promedio;
	int retornoContador;
	int retorno = -1;

	if (contadorDeEmpleados(array, len, &retornoContador)==0)
	{
		for (i = 0; i < len; i++)
			{
				if (array[i].flagEmpty == ESTADO_OCUPADO)
				{
				acumSalario = acumSalario + array [i].salary;
				*retornoAcumSalario = acumSalario;
				}
				}
			promedio = (float)acumSalario / retornoContador;
			*resultado = promedio;
			retorno = 0;
	}
	return retorno;
}
/** \brief funsion que cuenta los empleados ingresados al sistema
*
* \param lista Employee*
* \param largo del array
* \param puntero al espacion en memoria donde se copiara el resultado
* \retorna 0 en caso de estar bien y -1 en caso de error
*
*/
static int contadorDeEmpleados (Employee array [], int len, int *resultado)
{
	int retorno = -1;
	int contador = 0;
	int indice;

	for (indice = 0; indice < len; indice++)
	{
		if (array[indice].flagEmpty == ESTADO_OCUPADO)
		{
			contador++;
			retorno = 0;
		}
	}
	*resultado = contador;
	return retorno;
}

/*int empleados_altaForzada (Employee* array, int limite, int indice, int id, char* nombre, char* apellido,float salario, int sector)
{
	int retorno = -1;
	Employee bufferPantalla;
	if (array != NULL && indice >= 0 && indice < limite)
	{
				strncpy(bufferPantalla.name, nombre, sizeof (bufferPantalla.name));
				strncpy(bufferPantalla.lastName, apellido, sizeof (bufferPantalla.lastName));
				bufferPantalla.sector = sector;
				bufferPantalla.salary = salario;
				bufferPantalla.id = id;
				bufferPantalla.flagEmpty = 0;
				array[indice] = bufferPantalla;
				(id)++;
				retorno = 0;
	}
	return retorno;

}
*/
