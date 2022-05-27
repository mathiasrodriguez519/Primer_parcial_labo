/*
 * viviendas.h
 *
 *  Created on: 25 may. 2022
 *      Author: mathi
 */

#ifndef FUNCIONESCENSO_H_
#define FUNCIONESCENSO_H_

typedef struct
{
	int idViviendas;
	char calle [25];
	int cantidadPersonas;
	int cantidadHabitaciones;
	int tipoVivienda;
	int legajoCensista;
}eVivienda;

typedef struct
{
	int legajoCensista;
	char nombre[50];
	int edad;
	char telefono[11];
}eCensista;

typedef struct
{
	int tipoVivienda;
	char descripcion[15];
}eTipoDeVivienda;

/// @brief bandera para comprobar las viviendas ya censadas.
/// @param list eVivienda* puntero al array de viviendas.
/// @param len int tamaño del array.
/// @return int retorna -1 si hubo algún error, si funciona bien retorna 0.
int inicializarViviendas(eVivienda* list, int len);

/// @brief recorre el array buscando un id libre (-1).
/// @param list eVivienda* puntero al array de viviendas
/// @param len int tamaño del array
/// @return int retorna -1 si hubo algún error, si funciona bien retorna el espacio libre.
int encontrarEspacioLibre(eVivienda* list, int len);

/// @brief en el espacio encontrado con encontrarEspacioLibre carga todos los datos.
/// @param list eViviendas* puntero al array de viviendas
/// @param len int tamaño del array
/// @param id int id de la vivienda
/// @param calle char calle de la vivienda
/// @param cantidadPersonas int cantidad de personas de la vivienda
/// @param cantidadHabitaciones int cantidad de habitaciones de la vivienda
/// @param tipoVivienda int tipo de vivienda
/// @param legajoCensista int legajo del censista asignado a la vivienda
/// @return int retorna -1 si hubo algún error, si funciona bien retorna 0.
int altaVivienda(eVivienda* list, int len, int id, char calle[],int cantidadPersonas, int cantidadHabitaciones,int tipoVivienda, int legajoCensista);

/// @brief recorre el array buscando el id ingresado y en caso de encontrarlo lo retorna.
/// @param list eViviendas* puntero al array de viviendas
/// @param len int tamaño del array
/// @param id int id ingresado por el usuario de la vivienda que esta buscando
/// @return int retorna -1 si hubo algún error, si funciona bien retorna el id de la vivienda buscada.
int buscarViviendaPorId(eVivienda* list, int len,int id);

/// @brief cambia el indice a -1 para que quede el espacio libre.
/// @param list eViviendas* puntero al array de viviendas
/// @param len int tamaño del array
/// @param indice int indice donde esta cargada la vivienda que se desea dar de baja
/// @return int retorna -1 si hubo algún error, si funciona bien retorna 0.
int bajaVivienda(eVivienda* list, int len, int indice);

/// @brief ordena mediante un burbujeo a las viviendas por la calle, en caso de ser las mismas calles
/// se usa la cantidad de personas
/// @param list eViviendas* puntero al array de viviendas
/// @param len int tamaño del array
/// @return int retorna -1 si hubo algún error, si funciona bien retorna 0.
int ordenarViviendasPorCalle(eVivienda* list, int len);

/// @brief recorre el array de vivienda, de censista y de tipo de vivienda y muestra los datos
/// de la vivienda correspondiente
/// @param list eViviendas* puntero al array de viviendas
/// @param len int tamaño del array viviendas
/// @param censista eCensista* puntero al array de censista
/// @param lenCensista int tamaño del array censista
/// @param tipoDeVivienda puntero al array de tipo de vivienda
/// @param lenTipo int tamaño del array tipo de vivienda
/// @return int retorna -1 si hubo algún error, si funciona bien retorna 0.
int mostrarViviendas(eVivienda* list, int len, eCensista* censista, int lenCensista, eTipoDeVivienda* tipoDeVivienda, int lenTipo);

/// @brief recorre el array de censista y los muestra en una lista.
/// @param censistas eCensista* puntero al array de censistas
/// @param len int tamaño del array
/// @return int retorna -1 si hubo algún error, si funciona bien retorna 0.
int mostrarCensistas (eCensista* censistas, int len);

/// @brief mediante contadores cuenta cual censista realizo mas censos.
/// @param censista eCensista* puntero al array de censistas
/// @param vivienda eVivienda* puntero al array de vivienda
/// @param len int tamaño del array
/// @return
void contadorCensos(eCensista* censista, eVivienda* vivienda, int len);


#endif /* FUNCIONESCENSO_H_ */
