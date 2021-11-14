#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Controller.h"
#include "linkedList.h"
#include "utn_pedirCadena.h"
#include "utn_menu.h"

static void imprimirOpciones (void);

/** \brief funsion de menu
* \param lista listSalon*
* \param largo del array arcade
* \param listArcade
* \param largo del array salones
*/
void utn_menu (LinkedList* listaEmpleados, int lenLista)
{
	int opcion;

	do{
		imprimirOpciones();
		utn_getNumeroIntSinMensaje(&opcion, "\n error el dato ingresado es invalido\n", 1, 10, 10);
		switch (opcion)
		{
		case 1:
			if (controller_loadFromText("data.csv", listaEmpleados)==0)
			{
				printf ("Archivo cargado correctamente");
			}
			break;
		case 2:
			if (controller_loadFromBinary("dataBinario.bin", listaEmpleados)==0)
			{
				printf ("Archivo cargado correctamente.");
			}
			else
			{
				printf ("Error al cargar el archivo de texto.");
			}
			break;
		case 3:
			controller_addEmployee(listaEmpleados);
			break;
		case 4:
			if (ll_len(listaEmpleados)>0)
			{
				controller_ListEmployee(listaEmpleados);
				controller_editEmployee(listaEmpleados);
			}else
			{
				printf ("No se puede ingresar a esta opcion sin antes haber dado de alta un empleado.");
			}
			break;
		case 5:
			if (ll_len(listaEmpleados)>0)
			{
				controller_ListEmployee(listaEmpleados);
				if (controller_removeEmployee(listaEmpleados)==0)
				{
					printf("El empleado ha sido dado de baja.");
				}
			}else
			{
				printf ("No se puede ingresar a esta opcion sin antes haber dado de alta un empleado.");
			}
			break;
		case 6:
			if (ll_len(listaEmpleados)>0)
			{
				controller_ListEmployee(listaEmpleados);
			}else
			{
				printf ("No se puede ingresar a esta opcion sin antes haber dado de alta un empleado.");
			}
			break;
		case 7:
			if (ll_len(listaEmpleados)>0)
			{
				if (controller_sortEmployee(listaEmpleados)!=-1)
				{
					controller_ListEmployee(listaEmpleados);
				}
			}else
			{
				printf ("No se puede ingresar a esta opcion sin antes haber dado de alta un empleado.");
			}
			break;
		case 8:
			if (ll_len(listaEmpleados)>0)
			{
				if (controller_saveAsText("data.txt", listaEmpleados)==0)
				{
					printf ("archivo guardado correctamente.");
				}
			}else
			{
				printf ("No se puede ingresar a esta opcion sin antes haber dado de alta un empleado.");
			}
			break;
		case 9:
			if (ll_len(listaEmpleados)>0)
			{
			controller_saveAsBinary("dataBinario.bin", listaEmpleados);
			}else
			{
				printf ("No se puede ingresar a esta opcion sin antes haber dado de alta un empleado.");
			}
			break;
		case 10:
			exit (0);
			break;
		}
	}while (opcion <= 10);
}

static void imprimirOpciones (void)
{
	printf ("\n------------------Bienvenido--------------------");
	printf ("\nUtilice su teclado numerico para seleccionar una opcion:");
	printf("\n1.Cargar los datos de los empleados desde el archivo data.csv (modo texto).");
	printf("\n2.Cargar los datos de los empleados desde el archivo data.csv (modo binario).");
	printf ("\n3.Alta de empleado.");
	printf ("\n4.Modificar datos de empleado.");
	printf ("\n5.Baja de empleado.");
	printf ("\n6.Listar empleados.");
	printf ("\n7.Ordenar empleados.");
	printf ("\n8.Guardar los datos de los empleados en el archivo data.csv (modo texto).");
	printf ("\n9.Guardar los datos de los empleados en el archivo data.csv (modo binario).");
	printf ("\n10.Salir.");
}
