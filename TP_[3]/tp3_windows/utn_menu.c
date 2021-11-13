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
			if (controller_loadFromBinary("dataBinario.csv", listaEmpleados)==0)
			{
				printf ("Archivo cargado correctamente");
			}
			break;
		case 3:
			controller_addEmployee(listaEmpleados);
			break;
		case 4:
			controller_ListEmployee(listaEmpleados);
			controller_editEmployee(listaEmpleados);
			break;
		case 5:
			controller_ListEmployee(listaEmpleados);
			if (controller_removeEmployee(listaEmpleados)==0)
			{
				printf("El empleado ha sido dado de baja");
			}
			break;
		case 6:
			controller_ListEmployee(listaEmpleados);
			break;
		case 7:
			break;
		case 8:
			controller_saveAsText("data.csv", listaEmpleados);
			break;
		case 9:
			controller_saveAsBinary("dataBinario.csv", listaEmpleados);
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
