#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "employee.h"
#include "utn_pedirCadena.h"

static void utn_subMenu (Employee aEmpleados [], int lenArray);
/** \brief funsion de menu
*
* \param lista Employee*
* \param largo del array
*
*/
void utn_menu (Employee aEmpleados [], int lenArray)
{
	int opcion;
	int lugarLibre;
	int IDdarDeBaja;
	float retornoPromedio;
	float acumuladorSalario;
	int ordenOrdenamiento;
	int contadorEmpleados = 0;
	do{
		if (utn_getNumeroInt(&opcion, "\nBienvenido \nUtilice el teclado numerico para elecionar una opcion:\n1)Altas:\n2)Modificar:\n3)Baja:\n4)Informar:\n", "\nA seleccionado una opcion Invalida", 1, 4, 10)==0)
			{
			switch (opcion)
				{
					case 1:
						if (contadorEmpleados <  lenArray)
						{
							if (DameUnLugarLibre(aEmpleados, lenArray, &lugarLibre)==0)
								{
									addEmployee(&aEmpleados[lugarLibre], lenArray, aEmpleados[lugarLibre].id, aEmpleados[lugarLibre].name, aEmpleados[lugarLibre].lastName, aEmpleados[lugarLibre].salary, aEmpleados[lugarLibre].sector);
								}
							contadorEmpleados++;
						}
						else
						{
							printf ("Limite de usuarios creados.");
						}
					break;
					case 2:
						if (contadorEmpleados > 0)
						{
							utn_subMenu(aEmpleados, lenArray);
						}
						else
						{
							printf ("No se puede ingresar a esta opcion sin antes haber dado de alta algun empleado.");
						}
					break;
					case 3:
						if (contadorEmpleados > 0)
						{
							if (printEmployees(aEmpleados, lenArray)==0)
								{
									if (utn_getNumeroInt(&IDdarDeBaja, "\nIngrese ID del empleado que desea darle la baja del sistema: \nVolver al menu principal", "Error opcion incorrecta", 0, 1000, 5)==0)
									{
										if (removeEmployee(aEmpleados, lenArray, IDdarDeBaja)==0)
										{
											printf ("El empleado con ID: %d, ha sido dado de baja.", IDdarDeBaja);
										}
										else
										{
											printf ("El id ingresado no pertenece a ningun empleado.");
										}
									}
								}
						}
						else
						{
							printf ("No se puede ingresar a esta opcion sin antes haber dado de alta algun empleado.");
						}
					break;
					case 4:
						if (contadorEmpleados >1)
							{
							if (utn_getNumeroInt(&ordenOrdenamiento, "Ingrese el orden en el que quiere que se ordene los empleados\n0 para ordenar de forma ascendente y 1 para ordenar de forma descendente:\n", "error solo se permite 0 o 1", 0, 1, 5)==0)
							{
								if (sortEmployees(aEmpleados, lenArray, ordenOrdenamiento)==0)
									{
										printEmployees(aEmpleados, lenArray);
									}
									else
									{
										printf ("\nSe deben ingresar al menos dos empleados para poder listarlos en forma ordenada.");
									}
							}
							if (promedioSalario(aEmpleados, lenArray, &retornoPromedio, &acumuladorSalario)==0)
							{
								printf ("\n1.2. Total de los salarios $ %.2f", acumuladorSalario);
								printf ("\n1.3. Promedio de los salarios ingresados:$ %.2f", retornoPromedio);
							}
						}
						else
						{
							printf ("No se puede ingresar a esta opcion sin antes haber dado de alta algun empleado.");
						}

				break;
				}
			}
	}while (opcion <=4);

}
/** \brief funsion de submenu donde se encuentra la opcion modificar
*
* \param lista Employee*
* \param largo del array
*
*/
static void utn_subMenu (Employee aEmpleados [], int lenArray)
{
	int IDaModificar;

		if (printEmployees(aEmpleados, lenArray)==0)
		{
			if (utn_getNumeroInt(&IDaModificar, "\nIngrese ID del empleado a modificar: \nVolver al menu principal", "Error opcion incorrecta", 0, 1000, 5)==0)
			{
				if(findEmployeeById(aEmpleados, lenArray, IDaModificar)!=-1)
				{
					modificarEmpleado(&aEmpleados[IDaModificar]);
					printEmployees(aEmpleados, lenArray);
				}
				else
				{
					printf ("El ID ingresado es invalido.");
				}
			}
		}
}

