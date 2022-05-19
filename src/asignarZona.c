/*
 * asignarZona.c
 *
 *  Created on: 18 may 2022
 *      Author: juanm
 */

#include <stdio.h>
#include <stdlib.h>
#include "asignarZona.h"
#include "arrayCensista.h"
#include "arrayZona.h"
#include "utn.h"

int asignarCensista(Censista* pArrayCensista, int lenCencista, int posCensista, Zona* pArrayZona, int lenZona)
{
	int ret=-1;
	int auxIdZonaAsig;
	int auxZonaPos;
	int auxCensistaZona;

	if(pArrayCensista!=NULL && lenCencista>0 && posCensista>0 && pArrayZona!=NULL && lenZona>0)
	{
		auxCensistaZona = tieneZonaCencista(pArrayCensista, lenCencista, posCensista);
		printf("\n\n\tEl censista tiene zona?: %d\n\n", auxCensistaZona);
		if(tieneZonaCencista(pArrayCensista, lenCencista, posCensista)==0)
		{
			printf("\n\tUsted le asignara su zona a: \n");
			printCensista(&pArrayCensista[posCensista]);
			printf("\n\n\t----------------------------------------------\n\n");
			//printZonas(pArrayZona, lenZona, pArrayCensista, lenCencista);
			if(utn_getNumber(&auxIdZonaAsig, "\n\tPor favor ingrese el Id de la Zona para asignar al censista: ", "\n\tError al ingresar el dia\n", 1, 9999, 2)==0)
				{
					if(findZonaById(pArrayZona, lenZona, auxIdZonaAsig)>-1)
					{
						// la zona seleccionada existe
						auxZonaPos = findZonaById(pArrayZona, lenZona, auxIdZonaAsig);

						pArrayCensista[posCensista].idZona = pArrayZona[auxZonaPos].id;
						pArrayZona[auxZonaPos].idCensista = pArrayCensista[posCensista].id;
						ret=0;
						printf("\n\tEl censista fue asignado a la zona correctamente!\n");

					}
					else
					{
						ret=-1;
						printf("\n\tLa zona seleccionada no existe!\n");
					}

				}
		}
		else
		{
			ret=-1;
			printf("\n\tEl censista seleccionado ya tiene una zona asignada!\n");
		}
	}

	return ret;
}

int tieneZonaCencista(Censista* pArrayCensista, int lenCencista, int posCensista)
{
	int ret=-1;
	if(pArrayCensista!=NULL && lenCencista>0 && posCensista>0)
	{
		if(pArrayCensista[posCensista].idZona==0)
		{
			// el censista no tiene zona asignada
			ret=0;
		}
	}
	return ret;
}
