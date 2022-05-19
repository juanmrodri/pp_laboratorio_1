/*
 * cargarDatos.c
 *
 *  Created on: 18 may 2022
 *      Author: juanm
 */

#include <stdio.h>
#include <stdlib.h>
#include "arrayZona.h"
#include "arrayCensista.h"
#include "localidades.h"
#include "utn.h"


int cargarDatos(Censista* pArrayCensista, int lenCencista, Zona* pArrayZona, int lenZona)
{
	int ret=-1;
	int auxId;
	int cantidadCensadosLugar;
	int cantidadCensadosVirtual;
	int cantidadAusentes;
	if(pArrayCensista!=NULL && lenCencista>0 && pArrayZona!=NULL && lenZona>0)
	{
		if(utn_getNumber(&auxId, "\n\tPor favor indique el id de la zona finalizada: ", "\n\tError al ingresar el id\n", 1, 9999, 2)==0)
		{
			if(findZonaById(pArrayZona, lenZona, auxId)>-1)
			{
				if(utn_getNumber(&cantidadCensadosLugar, "\n\tIndique la cantidad de censados en el lugar: ", "\n\tError al ingresar el dato\n", 1, 9999, 2)==0)
				{
					if(utn_getNumber(&cantidadCensadosVirtual, "\n\tIndique la cantidad de personas que realizo el censo de manera virtual: ", "\n\tError al ingresar el dato\n", 1, 9999, 2)==0)
					{
						if(utn_getNumber(&cantidadAusentes, "\n\tIndique la cantidad de personas ausentes: ", "\n\tError al ingresar el dato\n", 1, 9999, 2)==0)
						{

							ret=0;
							printf("\n\tSe realizo la carga correctamente!!!\n");
						}
						else
						{
							ret=-1;
							printf("\n\tError al seleccionar!\n");
						}
					}
					else
					{
						ret=-1;
						printf("\n\tError al seleccionar!\n");
					}
				}
				else
				{
					ret=-1;
					printf("\n\tError al seleccionar!\n");
				}
			}
			else
			{
				ret=-1;
				printf("\n\tEl id seleccionado no existe!\n");
			}

		}
		else
		{
			ret=-1;
			printf("\n\tSe produjo un error al seleccionar!\n");
		}

	}

	return ret;
}

