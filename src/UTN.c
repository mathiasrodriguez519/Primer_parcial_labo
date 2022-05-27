/*
 * utn.c
 *
 *  Created on: 25 may. 2022
 *      Author: mathi
 */


#include "UTN.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int myGets(char *cadena, int longitud)
{
	int retorno = -1;
	if (cadena != NULL && longitud > 0 && fgets(cadena, longitud, stdin) == cadena)
	{
		fflush(stdin);
		if (cadena[strlen(cadena) - 1] == '\n')
		{
			cadena[strlen(cadena) - 1] = '\0';
		}
		retorno = 0;
	}
	return retorno;
}

int tomarEntero(int *pResultado)
{
	int retorno = -1;
	char buffer[64];

	if (pResultado != NULL)
	{
		if (myGets(buffer, sizeof(buffer)) == 0 && chequearNumeros(buffer))
		{
			*pResultado = atoi(buffer);
			retorno = 0;
		}
	}
	return retorno;
}

int chequearNumeros(char *cadena)
{
	int i = 0;
	int retorno = 1;
	if (cadena != NULL && strlen(cadena) > 0)
	{
		while (cadena[i] != '\0')
		{
			if (isalpha(cadena[i]) != 0)
			{
				retorno = 0;
				break;
			}
			i++;
		}
	}
	return retorno;
}

int UTN_getInt(int *pResultado, char *mensaje, char *mensajeError, int minimo, int maximo)
{
	int bufferInt;
	int retorno = -1;

	while (retorno != 0)
	{
		printf("%s", mensaje);
		if (tomarEntero(&bufferInt) == 0)
		{
			if (bufferInt >= minimo && bufferInt <= maximo)
			{
				*pResultado = bufferInt;
				retorno = 0;
				break;
			}
		}
		printf("%s", mensajeError);
	}
	return retorno;
}

int tomarFloat(float *pResultado)
{
	int retorno = -1;
	char buffer[64];

	if (pResultado != NULL)
	{
		if (myGets(buffer, sizeof(buffer)) == 0 && chequearNumeros(buffer))
		{
			*pResultado = atof(buffer);
			retorno = 0;
		}
	}
	return retorno;
}

int UTN_getFloat(float *pResultado, char *mensaje, char *mensajeError, float minimo, float maximo)
{
	float bufferFloat;
	int retorno = -1;

	while (retorno != 0)
	{
		printf("%s", mensaje);
		if (tomarFloat(&bufferFloat) == 0)
		{
			if (bufferFloat >= minimo && bufferFloat <= maximo)
			{
				*pResultado = bufferFloat;
				retorno = 0;
				break;
			}
		}
		printf("%s", mensajeError);
	}
	return retorno;
}

int UTN_getName(char* cadena, char* mensaje, char* mensajeError, int len)
{
	int retorno = 1;

	if(cadena != NULL && strlen(cadena) < len)
	{
		while(retorno != 0)
		{
			printf(mensaje);
			fflush(stdin);
			gets(cadena);
			for (int i = 0; i < strlen(cadena); i++)
			{
				if(isalnum(cadena[i]) == 0 && isspace(cadena[i]) == 0 && cadena[i] != 'ñ')
				{
					retorno = 1;
					printf(mensajeError);
					break;
				}
				retorno = 0;
			}
		}
	}
	chequearMayuscula(cadena);

	return retorno;
}

void chequearMayuscula(char* cadena)
{
	strlwr(cadena);

	cadena[0] = toupper(cadena[0]);

	for(int i = 0; i < strlen(cadena); i++)
	{
		if (cadena[i] == ' ')
		{
			cadena[i + 1] = toupper(cadena[i + 1]);
		}
	}
}
