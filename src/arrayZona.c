/*
 * arrayZona.c
 *
 *  Created on: 15 may 2022
 *      Author: jmrodri
 */

#include <stdio.h>
#include <stdlib.h>
#include "arrayZona.h"
#include "arrayCensista.h"
#include "localidades.h"
#include "utn.h"
#define EMPTY 1
#define OCCUP 0

// static functions

static int newIdGenerator(void);

//******************************************

static int newIdGenerator(void)
{
	static int cont=1;
	return cont++;
}

void ForceLoadZona(Zona* pArray, int len, char calleUno[], char calleDos[], char calleTres[], char calleCuatro[], int estado, int idCensista, int localidad)
{
	int indexFree;

	indexFree = findEmptyZonaPos(pArray, len);
	pArray[indexFree].id=newIdGenerator();
	strcpy(pArray[indexFree].calleUno,calleUno);
	strcpy(pArray[indexFree].calleDos,calleDos);
	strcpy(pArray[indexFree].calleTres,calleTres);
	strcpy(pArray[indexFree].calleCuatro,calleCuatro);
	pArray[indexFree].estado=estado;
	pArray[indexFree].idCensista=idCensista;
	pArray[indexFree].localidad=localidad;
	pArray[indexFree].isEmpty=OCCUP;
}

int initArrayZona(Zona* pArray, int len)
{
	int ret=-1;
	int i;

	if(pArray!=NULL && len>0)
	{
		for(i=0;i<len;i++)
		{
			pArray[i].isEmpty = EMPTY; // esta empty
			ret=0;
		}
	}
	return ret;
}

int findEmptyZonaPos(Zona* pArray, int len)
{
	int ret=-1;
	int i;

	if(pArray!=NULL && len>0)
	{
		for(i=0;i<len;i++)
		{
			if(pArray[i].isEmpty==EMPTY)
			{
				ret=i;
				break;
			}
		}
	}

	return ret;
}

int findZonaById(Zona* pArray, int len, int id)
{
	int ret=-1;
	int i;

	if(pArray!=NULL && len>0)
	{
		for(i=0;i<len;i++)
		{
			if(pArray[i].id==id)
			{
				ret=i;
				break;
			}
		}
	}

	return ret;
}

int isZonaAdded(Zona* pArray, int len)
{
	int ret=-1;
	int i;

	if(pArray!=NULL && len>0)
	{
		for(i=0;i<len;i++)
		{
			if(pArray[i].isEmpty==OCCUP)
			{
				ret=0;
				break;
			}
		}
	}

	return ret;
}

int loadZona(Zona* pArray, int len)
{
	char calleUno[21];
	char calleDos[21];
	char calleTres[21];
	char calleCuatro[21];
	int auxLocalidad;
	int ret=-1;
	int indexFree;

	if(pArray!=NULL && len>0)
	{
		indexFree = findEmptyZonaPos(pArray, len);

		if(indexFree>-1 && pArray[indexFree].isEmpty==EMPTY)
		{
			printf("\n\n\t----------------------------------------------\n\n");
			if(utn_getText(calleUno, 51,"\n\tIngrese el nombre de la calle(1): ", "\n\tError al ingresar el nombre\n", 2)==0)
			{
				if(utn_getText(calleDos, 51,"\n\tIngrese el nombre de la calle(2): ", "\n\tError al ingresar el nombre\n", 2)==0)
				{
					if(utn_getText(calleTres, 51,"\n\tIngrese el nombre de la calle(3): ", "\n\tError al ingresar el nombre\n", 2)==0)
					{
						if(utn_getText(calleCuatro, 51,"\n\tIngrese el nombre de la calle(4): ", "\n\tError al ingresar el nombre\n", 2)==0)
						{
							if(utn_getNumber(&auxLocalidad, "\n\tIngrese la localidad: ", "\n\tError al ingresar la localidad\n", 1, 31, 2)==0)
							{
									addZona(pArray, len, newIdGenerator(), calleUno, calleDos, calleTres, calleCuatro, auxLocalidad);

							}
						}
						else
						{
							ret=-1;
							printf("\n\tSe produjo un error al ingresar la calle(4)!\n");
						}
					}
					else
					{
						ret=-1;
						printf("\n\tSe produjo un error al ingresar la calle(3)!\n");
					}
				}
				else
				{
					ret=-1;
					printf("\n\tSe produjo un error al ingresar la calle(2)!\n");
				}
			}
			else
			{
				ret=-1;
				printf("\n\tSe produjo un error al ingresar la calle(1)!\n");
			}
		}
	}

	return ret;
}

int addZona(Zona* pArray, int len, int id, char calleUno[], char calleDos[], char calleTres[], char calleCuatro[], int localidad)
{
	int ret=-1;
	int indexFree;
	if(pArray!=NULL && len>0 && calleUno!=NULL && calleDos!=NULL && calleTres!=NULL && calleCuatro!=NULL && localidad>0)
	{
		indexFree=findEmptyZonaPos(pArray, len);
		pArray[indexFree].id=id;
		strcpy(pArray[indexFree].calleUno,calleUno);
		strcpy(pArray[indexFree].calleDos,calleDos);
		strcpy(pArray[indexFree].calleTres,calleTres);
		strcpy(pArray[indexFree].calleCuatro,calleCuatro);
		pArray[indexFree].localidad=localidad;
		pArray[indexFree].estado=1; // zona pendiente, sin censar
		pArray[indexFree].isEmpty=OCCUP;
		pArray[indexFree].idCensista=0; // sin censista asignado
	}

	return ret;
}

int printZona(Zona* pArray, Localidad* pArrayLocalidades, int lenLocalidad)
{
	char auxLocalidad[21];
	int auxLocalidadId;

	auxLocalidadId = pArray->localidad;

	buscarNombreLocalidad(pArrayLocalidades, lenLocalidad, auxLocalidad, auxLocalidadId);

	int ret=-1;
	if(pArray->isEmpty == OCCUP)
	{
		printf("\n\tId: %d\n"
			   "\n\tCalle(1): %s\n"
			   "\n\tCalle(2): %s\n"
			   "\n\tCalle(3): %s\n"
			   "\n\tCalle(4): %s\n"
			   "\n\tId censista asignado: %d\n"
			   "\n\tLocalidad: %s\n",
			   pArray->id, pArray->calleUno, pArray->calleDos,pArray->calleTres,pArray->calleCuatro,pArray->idCensista, auxLocalidad);
		ret=0;
	}
	return ret;
}

int printZonas(Zona* pArray, int len, Localidad* pArrayLocalidades, int lenLocalidad)
{
	int ret=-1;
	int i;
	if(pArray!=NULL && len>0)
	{
		for(i=0; i<len;i++)
		{
			if(pArray[i].isEmpty == OCCUP)
			{
				printZona(&pArray[i], pArrayLocalidades, lenLocalidad);
			}
		}
		ret=0;
	}
	return ret;
}

int buscarNombreLocalidad(Localidad* pArrayLocalidades, int lenLocalidad, char nombre[], int auxlocalidad)
{
	int ret=-1;
	int i;

	if(pArrayLocalidades!=NULL && lenLocalidad>0)
	{
		for(i=0;i<lenLocalidad;i++)
		{
			if(pArrayLocalidades[i].id==auxlocalidad)
			{
				strcpy(nombre,pArrayLocalidades[i].nombre);
			}
		}
	}
	return ret;
}

