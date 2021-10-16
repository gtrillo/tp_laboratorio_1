/*
 * utn.c
 *
 *  Created on: 21 sep. 2021
 *      Author: Gonzalo
 *      Contenido: funsiones de solicitud de datos al usuario :3
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
 *\brief lee de stdin hasta que encuentr un \n o hasta que haya copiado en cadena
 *un maximo de 'longitud - 1' caracteres.
 *\param pResultado puntero al espacio en memoria donde se copiara la cadena optenida
 *\param longitud define el tamaño de la cadena
 *\return  0 en el caso de que este todo bien y -1 en caso de error
 */
static int myGets (char* cadena, int longitud)
{

	fflush(stdin);
		//stdin lee el archivo temporal de lo que ingresa el usuario por consola
					//longitud de hasta donde leer
	fgets (cadena, longitud, stdin); //esto sirve para reemplazar el scanf
	cadena [strlen (cadena) - 1] = '\0';

	return 0;

}
/**
 *\brief verifica si un dato es de tipo numerico o no
 *\param pResultado es la cadena de caracteres a ser analizada
 *\retorna 0 en caso de ser falso y 1 en caso de ser positivo
 */
static int esNumerica (char* cadena)
{
	int retorno = 1;
	int i=0;
	if (cadena [0] == '-') //si en la posicion 0 el usuario ingresa un - el array comienza a almacenar los numeros desde la pocision 1
	{
		i = 1;
	}
	for (;cadena [i] > '\0'; i++){
		if (cadena [i] < '0' || cadena [i] > '9')  //solo se pueden ingresar numeros del 0 al 9
		{
			retorno = 0;
			break;
		}
	}
	return retorno;
}
/**
 *\brief funsion para transformar la cadena a una variable de tipo int
 *\param pResultado puntero al espacio en memoria donde se almacenara el resultado de la funsion
 *\return retorna 0 en el caso de que este todo bien y -1 en caso de error
 */
static int getInt (int* pResultado)
{
	int retorno;
	char buffer [7500];
	if (myGets(buffer, sizeof (buffer))== 0 && esNumerica(buffer))
	{
		retorno = 0;
		*pResultado = atoi(buffer); //se transforma el dato string a un tipo de dato int
	}
	return retorno;
}
/**
 *\brief solicita un numero al usuario, luego de verificarlo devuelve el resultado
 *\param pResultado es el punter al espacio en memoria donde se almacenara el resultado de la funsion
 *\param mensaje es el mensaje que se mostrara al usuario
 *\param mensajeError es el mensaje de error que se le mostrara al usuario en caso de que ingrese un dato no valido
 *\param minimo es el minimo que sera aceptado
 *\param maximo es el maximo que sera aceptado
 *\param reintentos son los reintentos que tendra el usuario para ingresar el dato correctamente
 *\return 0 si se optuvo el dato o -1 en el caso de que no
 */
int utn_getNumeroInt (int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
{
	int bufferInt = -1;
	int retorno;
	int i;

	if (minimo<maximo){
	for (i = 0; i <= reintentos; i++){
		if (pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos != 0){
			printf ("%s", mensaje);
			if (getInt (&bufferInt) == 0 && bufferInt>=minimo && bufferInt<=maximo){
				*pResultado = bufferInt;
				retorno = 0;
				break;
				}else{
					retorno = 1;
					printf ("%s\n",mensajeError);}
		}
	}
	}
	return retorno;
}
