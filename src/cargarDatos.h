/*
 * cargarDatos.h
 *
 *  Created on: 18 may 2022
 *      Author: juanm
 */

#ifndef CARGARDATOS_H_
#define CARGARDATOS_H_

#include "arrayCensista.h"
#include "arrayZona.h"

typedef struct
{
	int idDato;
	int cantidadVirtual;
	int cantidadAusentes;

}Dato;

#endif /* CARGARDATOS_H_ */

int cargarDatos(Censista* pArrayCensista, int lenCencista, Zona* pArrayZona, int lenZona);
