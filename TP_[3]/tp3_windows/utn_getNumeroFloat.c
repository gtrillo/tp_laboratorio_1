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
#include <ctype.h>
/**
 *\brief lee de stdin hasta que encuentr un \n o hasta que haya copiado en cadena
 *un maximo de 'longitud - 1' caracteres.
 *\param pResultado puntero al espacio en memoria donde se copiara la cadena optenida
 *\param longitud define el tamaño de la cadena
 *\retorna 0 en el caso de que este todo bien y -1 en caso de error
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
	int contSigno = 0;
	int contPuntos = 0;
	while (cadena [i] != '\0' && (retorno == 1))
	{
		if (cadena [i] == '-')
		{
			contSigno++;
		}
		if (cadena [i] == '.')
		{
			contPuntos++;
		}
		if (isdigit (cadena [i]) || (cadena [0] == '-') || (cadena [i] == '.')){
			retorno = 1;
		}
		else
		{
			retorno = 0;
		}
		i++;
	}
	if (contSigno > 1 || contPuntos > 1){
		retorno = 0;
	}
	return retorno;
}
/**
 *\brief funsion para transformar la cadena a un numero float
 *\param pResultado puntero al espacio en memoria donde se almacenara el resultado de la funsion
 *\retorna 0 en el caso de que este todo bien y -1 en caso de error
 */
static int getFloat (float* pResultado)
{
	int retorno;
	char buffer [7500];
	if (myGets(buffer, sizeof (buffer))== 0 && esNumerica(buffer))
	{
		retorno = 0;
		*pResultado = atof(buffer); //se transforma el dato string a un tipo de dato float
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
int utn_getNumeroFloat (float* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
{
	float bufferFloat=-1;
	int retorno;
	int i;

	if (minimo<maximo){
	for (i = 0; i <= reintentos; i++){
		if (pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos != 0){
			printf ("%s", mensaje);
			if (getFloat (&bufferFloat) == 0 && bufferFloat>=minimo && bufferFloat<=maximo){
				*pResultado = bufferFloat;
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
