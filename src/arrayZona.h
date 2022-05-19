/*
 * arrayZona.h
 *
 *  Created on: 15 may 2022
 *      Author: jmrodri
 */

#ifndef ARRAYZONA_H_
#define ARRAYZONA_H_

#include "localidades.h"

typedef struct
{
	int id;
	char calleUno[21];
	char calleDos[21];
	char calleTres[21];
	char calleCuatro[21];
	int localidad;
	int estado;	// 1 pendiente (sin censar) - 2 finalizada (zona censada)
	int idCensista;
	int isEmpty;

}Zona;


#endif /* ARRAYZONA_H_ */

void ForceLoadZona(Zona* pArray, int len, char calleUno[], char calleDos[], char calleTres[], char calleCuatro[], int estado, int idCensista, int localidad);

int initArrayZona(Zona* pArray, int len);

int findEmptyZonaPos(Zona* pArray, int len);

int findZonaById(Zona* pArray, int len, int id);

int isZonaAdded(Zona* pArray, int len);

int loadZona(Zona* pArray, int len);

int addZona(Zona* pArray, int len, int id, char calleUno[], char calleDos[], char calleTres[], char calleCuatro[], int localidad);

int printZona(Zona* pArray, Localidad* pArrayLocalidades, int lenLocalidad);

int printZonas(Zona* pArray, int len, Localidad* pArrayLocalidades, int lenLocalidad);

int buscarNombreLocalidad(Localidad* pArrayLocalidades, int lenLocalidad, char nombre[], int auxlocalidad);
