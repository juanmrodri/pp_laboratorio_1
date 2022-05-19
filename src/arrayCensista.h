/*
 * arrayCencista.h
 *
 *  Created on: 15 may 2022
 *      Author: jmrodri
 */

#ifndef ARRAYCENSISTA_H_
#define ARRAYCENSISTA_H_

typedef struct
{
	int dia; // > 0 y < 32
	int mes; // > 0 y < 13
	int anio; // > 1950 y < 2004 es decir entre 72 y 18 anios

} fechaNacimiento;

typedef struct
{
	char calle[31];
	int altura;

}direccion;

typedef struct
{
	int id;
	char nombre[51];
	char apellido[51];
	fechaNacimiento fecha;
	int edad;
	direccion dir;
	int estado; // 1 activo(dado de alta y disponible para asignacion de zona) - 2 liberado(id disponible para una nueva asignacion de zona) - 3 inactivo(dado de baja, id no disponible)
	int idZona;
	int isEmpty;

} Censista;

void forceLoadCensista(Censista* pArray, int len, char nombre[], char apellido[], int dia, int mes, int anio, char calle[], int altura, int estado, int idZona); //

int initArrayCensista(Censista* pArray, int len); //

int findEmptyCensistaPos(Censista* pArray, int len); //

int findCensistaById(Censista* pArray, int len, int id); //

int findCensistaNullId(Censista* pArray, int len, int id);

int isCensistaAdded(Censista* pArray, int len); //

int loadCensista(Censista* pArray, int len); //

int addCensista(Censista* pArray, int len, int id, char nombre[], char apellido[], int dia, int mes, int anio, int edad, char calle[], int altura, int estado); //

int modCensista(Censista* pArray, int len, int pos, int id, int opcion);

int printCensista(Censista* pArray); //

int printCensistas(Censista* pArray, int len); //

int removeCensista(Censista* pArray, int len, int id); //

int sortCensista(Censista* pArray, int len, int order);

int sortCensistaByStatus(Censista* pArray, int len, int stat);



#endif /* ARRAYCENCISTA_H_ */
