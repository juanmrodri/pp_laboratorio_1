/*
 * asignarZona.h
 *
 *  Created on: 18 may 2022
 *      Author: juanm
 */

#ifndef ASIGNARZONA_H_
#define ASIGNARZONA_H_

#include <stdio.h>
#include <stdlib.h>
#include "arrayCensista.h"
#include "arrayZona.h"
#include "utn.h"

int asignarCensista(Censista* pArrayCensista, int lenCencista, int posCensista, Zona* pArrayZona, int lenZona);

int tieneZonaCencista(Censista* pArrayCensista, int lenCencista, int posCensista);

#endif /* ASIGNARZONA_H_ */
