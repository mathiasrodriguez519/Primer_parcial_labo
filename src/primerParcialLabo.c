/*
 ============================================================================
 Name        : primerParcialLabo.c
 Author      : mathi
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "funcionesCenso.h"
#include "UTN.h"

#define TAM_VIVIENDAS 2000
#define TAM_CENSISTAS 3
#define TAM_CALLE 26
#define TAM_TIPOVIVIENDA 4

int main(void)
{
	setbuf(stdout, NULL);

	int opcionMenu;
	char calle[TAM_CALLE];
	int id = 20000;
	int cantPersonas;
	int cantHabitaciones;
	int tipoVivienda;
	int legajoCensista;
	int menuModificar;
	int idAModificar;
	int indiceAModificar;
	int viviendasCargadas = 0;
	int menuListarCensista;

	eVivienda vivienda[TAM_VIVIENDAS];
	eCensista censista[TAM_CENSISTAS] = { {100, "Ana", 34, "1203-2345"}, {101, "Juan", 24, "4301-54678"}, {102, "Sol", 47, "5902-37487"} };
	eTipoDeVivienda TipoDeVivienda[TAM_TIPOVIVIENDA] = { {1, "Casa"}, {2, "Departamento"}, {3, "Casilla"}, {4, "Rancho"} };

	if(inicializarViviendas(vivienda, TAM_VIVIENDAS) != 0)
	{
		printf("\nError, no pudo inicializarse la estructura vivienda.\n");
	}

	do
	{
		printf("\nMenu principal: \n"
			   "1. ALTA de vivienda.\n"
			   "2. MODIFICAR vivienda.\n"
			   "3. BAJA de vivienda.\n"
			   "4. Listar viviendas.\n"
			   "5. Listar censistas.\n"
			   "6. Mostrar censista con mas censos.\n"
			   "7. Salir del menu.\n"
			   "Ingrese una opcion: ");
		fflush(stdin);
		scanf("%d", &opcionMenu);

		switch(opcionMenu)
		{
			case 1:
				if(viviendasCargadas == TAM_VIVIENDAS)
				{
					printf("\nError, no pueden cargarse mas viviendas.\n");
				}
				else
				{
					UTN_getName(calle, "\nIngrese la calle donde vive: ", "Error. Ingrese correctamente la calle.\n", TAM_CALLE);
					UTN_getInt(&cantPersonas, "Ingrese la cantidad de personas que viven en la vivienda: ", "Error, ingrese correctamente la cantidad de personas que viven en la vivienda.\n", 1, 100);
					UTN_getInt(&cantHabitaciones, "Ingrese la cantidad de habitaciones de la vivienda: ", "Error, ingrese correctamente la cantidad de habitaciones de la vivienda.\n", 0,100);
					UTN_getInt(&tipoVivienda, "Ingrese el tipo de vivienda (1 = casa, 2 = departamento, 3 = casilla, 4 = rancho): ", "Error, ingrese correctamente el tipo de vivienda.\n",1,4);
					UTN_getInt(&legajoCensista, "Ingrese el legajo del censista(100 = Ana, 101 = Juan, 102 = Sol): ", "Error, ingrese un legajo de censista valido.\n", 100, 102);

					if(altaVivienda(vivienda, TAM_VIVIENDAS, id, calle, cantPersonas,  cantHabitaciones, tipoVivienda,  legajoCensista) == 0)
					{
						printf("\nSe ha dado de alta a la vivienda.\n");
						id++;
						viviendasCargadas++;
					}
					else
					{
						printf("\nError, no pudo cargarse la vivienda\n");
					}
				}
				break;

			case 2:
				if(viviendasCargadas > 0)
				{
					printf("\nIngrese el id de la vivienda que quiere modificar: ");
					fflush(stdin);
					scanf("%d", &idAModificar);
					indiceAModificar = buscarViviendaPorId(vivienda, TAM_VIVIENDAS, idAModificar);
					fflush(stdin);
					if(indiceAModificar < 0)
					{
						printf("\nError, ingrese un id ya cargado anteriormente.\n");
					}
					else
					{
						do
						{
							UTN_getInt(&menuModificar,"\nMenu Modificar:\n"
								"  1. Modificar la calle.\n"
								"  2. Modificar la cantidad de personas.\n"
								"  3. Modificar la cantidad de habitaciones.\n"
								"  4. Modificar el tipo de vivienda.\n"
								"  5. Volver al menu.\n"
								"Elija una opción: ", "\nError, ingrese una opcion valida.\n",1,5);

							switch(menuModificar)
							{
								case 1:
									UTN_getName(calle, "\nIngrese la modificacion de la calle donde vive: ", "Error, ingrese correctamente la calle.\n", TAM_CALLE);
									strcpy(vivienda[indiceAModificar].calle, calle);
									printf("\nSe ha modificado la calle.\n");
									break;
								case 2:
									UTN_getInt(&cantPersonas, "\nIngrese la modificacion de la cantidad de personas que viven en la vivienda: ", "Error ingrese correctamente la cantidad de personas que viven en la vivienda.\n", 1, 100);
									vivienda[indiceAModificar].cantidadPersonas = cantPersonas;
									printf("\nSe ha modificado la cantidad de personas.\n");
									break;
								case 3:
									UTN_getInt(&cantHabitaciones, "\nIngrese la modificacion de la cantidad de habitaciones de la vivienda: ", "Error ingrese correctamente la cantidad de habitaciones de la vivienda.\n", 0,100);
									vivienda[indiceAModificar].cantidadHabitaciones = cantHabitaciones;
									printf("\nSe ha modificado la cantidad de habitaciones.\n");
									break;
								case 4:
									UTN_getInt(&tipoVivienda, "\nIngrese la modificacion del tipo de vivienda (1 = casa, 2 = departamento, 3 0 casilla, 4 = rancho): ", "Error, Ingrese correctamente el tipo de vivienda.\n",1,4);
									vivienda[indiceAModificar].tipoVivienda = tipoVivienda;
									printf("\nSe ha modificado el tipo de vivienda.\n");
									break;
							}
						}while(menuModificar != 5);
					}
				}
				else
				{
					printf("\nNo hay viviendas cargadas, por favor cargue una vivienda.\n");
				}
				printf("\nVolviendo al menu.\n");
				break;

			case 3:
				if(viviendasCargadas > 0)
				{
					printf("Ingrese el id de la vivienda que quiere dar de baja: ");
					fflush(stdin);
					scanf("%d", &idAModificar);
					indiceAModificar = buscarViviendaPorId(vivienda, TAM_VIVIENDAS, idAModificar);
					if (indiceAModificar > -1)
					{
						if(bajaVivienda(vivienda, TAM_VIVIENDAS, indiceAModificar) == 0)
						{
							printf("\nSe ha dado de baja la vivienda de la calle %s.\n", vivienda[indiceAModificar].calle);
							viviendasCargadas--;
						}
						else
						{
							printf("\nError, no se pudo dar de baja la vivienda.\n");
						}
					}
					else
					{
						printf("\nError, ingrese un id ya cargado anteriormente.\n\n");
					}
				}
				else
				{
					printf("\nNo hay viviendas cargadas, por favor cargue una vivienda.\n");
				}
				printf("\nVolviendo al menu.\n");
				break;

			case 4:
				if(viviendasCargadas > 0)
				{
					if(ordenarViviendasPorCalle(vivienda, TAM_VIVIENDAS) == 0)
					{
						if(mostrarViviendas(vivienda, TAM_VIVIENDAS, censista, TAM_CENSISTAS, TipoDeVivienda, TAM_TIPOVIVIENDA) != 0)
						{
							printf("\nError, no pudo mostrarse el listado de viviendas.\n");
						}
					}
					else
					{
						printf("\nError, no pudieron ordenarse las viviendas.\n");
					}
				}
				else
				{
					printf("\nNo hay viviendas cargadas, por favor cargue una vivienda.\n");
				}
				printf("\nVolviendo al menu.\n");
				break;

			case 5:
				do
				{
					printf("\nMenu listar censistas: \n"
						   "1. Mostrar lista de censistas.\n"
						   "2. Mostrar lista de los censitas y las viviendas que censaron.\n"
						   "3. Salir al menu. \n"
						   "Ingrese una opcion: \n");
					fflush(stdin);
					scanf("%d", &menuListarCensista);

					switch(menuListarCensista)
					{
					 case 1:
						 mostrarCensistas(censista, TAM_CENSISTAS);
						 break;
					 case 2:
						 if(viviendasCargadas > 0)
						 {
							 printf(".");
						 }
						 else
						 {
						 	printf("\nNo hay viviendas cargadas, por favor cargue una vivienda.\n");
						 }
						 break;
					 case 3:
						 printf("Volviendo al menu\n");
						 break;
					 default:
					 	printf("\nError, ingrese una opcion valida.\n");
					}
				}while(menuListarCensista != 3);
				break;

			case 6:
				contadorCensos(censista, vivienda, TAM_CENSISTAS);
				break;

			case 7:
				printf("\nSaliendo.\n");
				break;

			default:
				printf("\nError, ingrese una opcion valida.\n");
		}

	}while(opcionMenu != 7);

	return EXIT_SUCCESS;
}
