/*
 * viviendas.c
 *
 *  Created on: 25 may. 2022
 *      Author: mathi
 */

#include "funcionesCenso.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "UTN.h"

int inicializarViviendas(eVivienda* list, int len)
{
	int retorno = -1;

	if (list != NULL)
	{
		if (len >= 0)
		{
			for (int i = 0; i < len; i++)
			{
				list[i].idViviendas = -1;
			}
			retorno = 0;
		}
	}

	return retorno;
}

int encontrarEspacioLibre(eVivienda* list, int len)
{
	int retorno = -1;

	if (list != NULL)
	{
		if (len >= 0)
		{
			for (int id = 0; id < len; id++)
			{
				if(list[id].idViviendas == -1)
				{
					retorno = id;
					break;
				}
			}
		}
	}

	return retorno;
}

int altaVivienda(eVivienda* list, int len, int id, char calle[], int cantidadPersonas, int cantidadHabitaciones, int tipoVivienda, int legajoCensista)
{
	int retorno = -1;
	int espacioLibre;
	eVivienda aux;

	if (list != NULL)
	{
		if (len >= 0)
		{
			espacioLibre = encontrarEspacioLibre(list, len);
			if (espacioLibre >= 0)
			{
				aux.idViviendas = id;
				strcpy(aux.calle, calle);
				aux.cantidadPersonas = cantidadPersonas;
				aux.cantidadHabitaciones = cantidadHabitaciones;
				aux.tipoVivienda = tipoVivienda;
				aux.legajoCensista = legajoCensista;

				list[espacioLibre] = aux;
				retorno = 0;
			}
		}
	}

	return retorno;
}

int buscarViviendaPorId(eVivienda* list, int len, int id)
{
	int retorno = -1;

	if(list != NULL)
	{
		if(len >= 0 && id >= 20000)
		{
			for(int i = 0; i < len; i++)
			{
				if(list[i].idViviendas == id)
				{
					retorno = i;
					break;
				}
			}
		}
	}

	return retorno;
}

int bajaVivienda(eVivienda* list, int len, int indice)
{
	int retorno = -1;
	if(list != NULL)
	{
		if(len >= 0)
		{
			list[indice].idViviendas = -1;
			retorno = 0;
		}
	}
	return retorno;
}

int ordenarViviendasPorCalle(eVivienda* list, int len)
{
	int retorno = -1;
	eVivienda aux;

	if (list != NULL)
		{
			if (len >= 0)
			{

				for (int i = 0; i < len; i++)
				{
					for(int j = i + 1; j < len - 1; j++)
					{
						if (strcmp(list[i].calle, list[j].calle) > 0)
						{
							aux = list[j];
							list[j] = list[i];
							list[i] = aux;
						}
						if(strcmp(list[i].calle, list[j].calle) == 0)
						{
							if(list[i].cantidadPersonas > list[j].cantidadPersonas)
							{
								aux = list[j];
								list[j] = list[i];
								list[i] = aux;
							}
						}
					}
				}
				retorno = 0;
			}
		}
	return retorno;
}

int mostrarViviendas(eVivienda* list, int len, eCensista* censista, int lenCensista, eTipoDeVivienda* tipoDeVivienda, int lenTipo)
{
	int retorno = -1;

	if (list != NULL)
	{
		if (len >= 0)
		{
			printf("\nCalle\t\t\t ID\t Cantidad de Personas  Cantidad de Habitaciones  Tipo de Vivienda  Censista\n");
			for (int i = 0; i < len; i++)
			{
				if(list[i].idViviendas >= 20000)
				{
					for(int j = 0; j < lenCensista; j++)
					{
						if(list[i].legajoCensista == censista[j].legajoCensista)
						{
							for(int k = 0; k < lenTipo; k++)
							{
								if(list[i].tipoVivienda == tipoDeVivienda[k].tipoVivienda)
								{
									printf("%-24s %-7d %-21d %-25d %-17s %d-%s\n", list[i].calle, list[i].idViviendas, list[i].cantidadPersonas,
											list[i].cantidadHabitaciones, tipoDeVivienda[k].descripcion, censista[j].legajoCensista, censista[j].nombre);
									break;
								}
							}
							break;
						}
					}
					retorno = 0;
				}
			}
		}
	}

	return retorno;
}

int mostrarCensistas (eCensista* censista, int len)
{
	int retorno = -1;

	if(censista != NULL && len > 0)
	{
		printf("\nLegajo\t Nombre\t  Edad\t Numero de telefono\n");
		for(int i = 0; i < len; i++)
		{
			printf("%-8d %-8s %-6d %s\n", censista[i].legajoCensista, censista[i].nombre, censista[i].edad, censista[i].telefono);
		}
		retorno = 0;
	}

	return retorno;
}
