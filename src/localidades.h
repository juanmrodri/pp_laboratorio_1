/*
 * localidades.h
 *
 *  Created on: 18 may 2022
 *      Author: juanm
 */

#ifndef LOCALIDADES_H_
#define LOCALIDADES_H_

#define EMPTY 1
#define OCCUP 0

typedef struct
{
	int id;
	char nombre[21];
	int isEmpty;

}Localidad;

#endif /* LOCALIDADES_H_ */

int initArrayLocalidad(Localidad* pArray, int len);

void forceLoadLocalidad(Localidad* pArray, int len, char nombre[]);

int findEmptyLocalidadPos(Localidad* pArray, int len);

int findLocalidadById(Localidad* pArray, int len, int id);

void printLocalidad(Localidad* pArray);

int printLocalidades(Localidad* pArray, int len);
