#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "validaciones.h"

int validarEntero(char* pIngreso)
{
    int status = 0;

    if(strlen(pIngreso) > 0)
    {
        for(int i = 0;i< strlen(pIngreso);i++)
        {
            if(isdigit(pIngreso[i]) == -1)
            {
                if(i == 0)
                {
                    if(pIngreso[0] != '-')
                    {
                        status = -1;
                        break;
                    }
                }
                else
                {
                    status = 0;
                }
            }
        }
    }
    else
    {
        status = -1;
    }

    return status;
}
int esNombre (char cadena[])
{
	int retorno;
	int i;

	retorno=-1;
	i=0;

	if(cadena!=NULL&&strlen(cadena)>0)
	{
		retorno=0;
		while(cadena[i]!='\0')
		{
			if((cadena[i]>='A'&&cadena[i]<='z')||cadena[i]==32||cadena[i]=='.'||cadena[i]==',')
			{
				if(cadena[i]>'Z'&&cadena[i]<'a')
				{
					retorno=-1;
					break;
				}
				i++;

			} else
			{
				retorno=-1;
				break;
			}

		}
	}
	return retorno;
}

