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
	int indexFInal;
	fflush(stdin);
		//stdin lee el archivo temporal de lo que ingresa el usuario por consola
					//longitud de hasta donde leer
	fgets (cadena, longitud, stdin); //esto sirve para reemplazar el scanf
	indexFInal = strlen (cadena) - 1;
	if (cadena [indexFInal] == '\n')
		{
			cadena [indexFInal] = '\0';
 		}
	return 0;

}
/**
 *\brief verifica si un dato es de tipo texto o no
 *\param pResultado es la cadena de caracteres a ser analizada
 *\retorna 0 en caso de ser positivo y 1 en caso de ser negativo
 */

static int esTexto (char* cadena, int lenCadena)
{
	int i= 0;
	int retorno = 1;

	if (cadena != NULL && lenCadena >=0)
	{
		for (i=0; cadena[i] != '\0' && i < lenCadena; i++)
		{
			if (cadena [i] != '.' && cadena [i] != ' ' && (cadena [i] < 'A' || cadena [i] > 'Z') && (cadena [i] < 'a' || cadena [i] > 'z') && (cadena [i] < '0' || cadena [i] > '9'))
			{
				retorno = 0;
				break;
			}
		}
	}
	else
	{
		retorno = -1;
	}
	return retorno;
}
/**
 *\brief solicita una cadena de texto al usuario, luego de verificarlo devuelve el resultado
 *\param pResultado es el punter al espacio en memoria donde se almacenara el resultado de la funsion
 *\param mensaje es el mensaje que se mostrara al usuario
 *\param mensajeError es el mensaje de error que se le mostrara al usuario en caso de que ingrese un dato no valido
 *\param minimo es el minimo que sera aceptado
 *\param maximo es el maximo que sera aceptado
 *\param reintentos son los reintentos que tendra el usuario para ingresar el dato correctamente
 *\return 0 si se optuvo el dato o -1 en el caso de que no
 */
int utn_getTextAlfanumerico(char pResultado[], int len, char* mensaje, char* mensajeError, int reintentos)
{
    int retorno = -1;
    int i;
    for(i=0; i<=reintentos; i++)
    {
        if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && reintentos >= 0)
        {
            printf("%s", mensaje);
            if ((myGets (pResultado, len)==0) && esTexto(pResultado, len) != 0)
            {
                retorno = 0;
                break;
            }
            else
                printf("%s", mensajeError);
        }
    }
    return retorno;
}

