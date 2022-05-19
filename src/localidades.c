/*
 * localidades.c
 *
 *  Created on: 18 may 2022
 *      Author: juanm
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include "localidades.h"

// static functions

static int newIdGenerator(void);

//******************************************

static int newIdGenerator(void)
{
	static int cont=1;
	return cont++;
}

int initArrayLocalidad(Localidad* pArray, int len)
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

int findEmptyLocalidadPos(Localidad* pArray, int len)
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

void forceLoadLocalidad(Localidad* pArray, int len, char nombre[])
{
	int indexFree;
	indexFree = findEmptyLocalidadPos(pArray, len);
	pArray[indexFree].id=newIdGenerator();
	strcpy(pArray[indexFree].nombre,nombre);
	pArray[indexFree].isEmpty=OCCUP;
}

int findLocalidadById(Localidad* pArray, int len, int id)
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

void printLocalidad(Localidad* pArray)
{

	printf("\n\tNombre: %s\n",pArray->nombre);


}

int printLocalidades(Localidad* pArray, int len)
{
	int ret=-1;
		int i;
		if(pArray!=NULL && len>0)
		{
			for(i=0; i<len;i++)
			{
				if(pArray[i].isEmpty == OCCUP)
				{
					printLocalidad(&pArray[i]);
				}
			}
			ret=0;
		}
		return ret;
}
