/*
 * arrayCencista.c
 *
 *  Created on: 15 may 2022
 *      Author: jmrodri
 */

#include <stdio.h>
#include <stdlib.h>
#include "arrayCensista.h"
#include "arrayZona.h"
#include "utn.h"
#define EMPTY 1
#define OCCUP 0

// static functions

static int newIdGenerator(void);

static int calculaEdad(int anio);

//******************************************

static int newIdGenerator(void)
{
	static int cont=1;
	return cont++;
}

static int calculaEdad(int anio)
{
	int edad;

	edad=2022-anio;

	return edad;
}

//******************************************


void forceLoadCensista(Censista* pArray, int len, char nombre[], char apellido[], int dia, int mes, int anio, char calle[], int altura, int estado, int idZona)
{
	int indexFree;
	int auxEdad;

	auxEdad = calculaEdad(anio);
	indexFree = findEmptyCensistaPos(pArray, len);
	pArray[indexFree].id=newIdGenerator();
	strcpy(pArray[indexFree].nombre,nombre);
	strcpy(pArray[indexFree].apellido,apellido);
	pArray[indexFree].fecha.dia=dia;
	pArray[indexFree].fecha.mes=mes;
	pArray[indexFree].fecha.anio=anio;
	pArray[indexFree].edad=auxEdad;
	strcpy(pArray[indexFree].dir.calle,calle);
	pArray[indexFree].dir.altura=altura;
	pArray[indexFree].estado=estado;
	pArray[indexFree].idZona=idZona;
	pArray[indexFree].isEmpty=OCCUP;

}

int initArrayCensista(Censista* pArray, int len)
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

int findEmptyCensistaPos(Censista* pArray, int len)
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

int findCensistaById(Censista* pArray, int len, int id)
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

int findCensistaNullId(Censista* pArray, int len, int id)
{
	int ret=-1;
	int i;

	if(pArray!=NULL && len>0)
	{
		for(i=0;i<len;i++)
		{
			if(pArray[i].id==id && pArray[i].isEmpty==EMPTY)
			{
				ret=0;
				break;
			}
		}
	}

	return ret;
}

int isCensistaAdded(Censista* pArray, int len)
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

int loadCensista(Censista* pArray, int len)
{
	char auxNombre[51];
	char auxApellido[51];
	int auxDia; // fechaNacimiento
	int auxMes; // fechaNacimiento
	int auxAnio; // fechaNacimiento
	int auxEdad;
	char auxCalle[31]; // direccion
	int auxAltura; // direccion
	int indexFree;
	int ret=-1;

	if(pArray!=NULL && len>0)
	{
		indexFree = findEmptyCensistaPos(pArray ,len);

		if(indexFree>-1 && pArray[indexFree].isEmpty==EMPTY)
		{
			printf("\n\n\t----------------------------------------------\n\n");
			if(utn_getText(auxNombre, 51,"\n\tIngrese el nombre del censista: ", "\n\tError al ingresar el nombre\n", 2)==0)
			{
				if(utn_getText(auxApellido, 51, "\n\tIngrese el apellido del censista: ", "\n\tError al ingresar el apellido\n", 2)==0)
				{
					if(utn_getNumber(&auxDia, "\n\tFecha de nacimiento(dia): ", "\n\tError al ingresar el dia\n", 1, 31, 2)==0)
					{
						if(utn_getNumber(&auxMes, "\n\tFecha de nacimiento(mes): ", "\n\tError al ingresar el mes\n", 1, 12, 2)==0)
						{
							if(utn_getNumber(&auxAnio, "\n\tFecha de nacimiento(anio): ", "\n\tError al ingresar el anio\n", 1950, 2004, 2)==0)
							{
								if(utn_getText(auxCalle, 51, "\n\tDireccion(calle): ", "\n\tError al ingresar la calle\n", 2)==0)
								{
									if(utn_getNumber(&auxAltura, "\n\tDireccion(altura): ", "\n\tError al ingresar la altura\n", 1, 17000, 2)==0)
									{
										auxEdad = calculaEdad(auxAnio); // calculamos la edad
										addCensista(pArray, len, newIdGenerator(), auxNombre, auxApellido, auxDia, auxMes, auxAnio, auxEdad, auxCalle, auxAltura, 1); // el estado lo pasamos "activo" porque lo estamos dando de alta
										ret=0;
									}
									else
									{
										ret=-1;
										printf("\n\tSe produjo un error al ingresar la altura!\n");
									}
								}
								else
								{
									ret=-1;
									printf("\n\tSe produjo un error al ingresar la calle!\n");
								}
							}
							else
							{
								ret=-1;
								printf("\n\tSe produjo un error al ingresar el anio!\n");
							}
						}
						else
						{
							ret=-1;
							printf("\n\tSe produjo un error al ingresar el dia!\n");
						}
					}
					else
					{
						ret=-1;
						printf("\n\tSe produjo un error al ingresar el dia!\n");
					}
				}
				else
				{
					ret=-1;
					printf("\n\tSe produjo un error al ingresar el apellido!\n");
				}
			}
			else
			{
				ret=-1;
				printf("\n\tSe produjo un error al ingresar el nombre!\n");
			}

		}

	}
	else
	{
		// directamente no se puede ingresar ningun dato
		ret=-1;
		printf("\n\tError al realizar la carga!\n");
	}

	return ret;
}

int addCensista(Censista* pArray, int len, int id, char nombre[], char apellido[], int dia, int mes, int anio, int edad, char calle[], int altura, int estado)
{
	int ret=-1;
	int indexFree;

	if(pArray!=NULL && len>0 && nombre!=NULL && apellido!=NULL && id!=0 && dia>0 && dia<32 && mes>0 && mes<13 && anio>1949 && anio<2005)
	{

		indexFree = findEmptyCensistaPos(pArray ,len);
		pArray[indexFree].id = id;
		strcpy(pArray[indexFree].nombre,nombre);
		strcpy(pArray[indexFree].apellido,apellido);
		pArray[indexFree].fecha.dia=dia;
		pArray[indexFree].fecha.mes=mes;
		pArray[indexFree].fecha.anio=anio;
		pArray[indexFree].edad=edad;
		strcpy(pArray[indexFree].dir.calle,calle);
		pArray[indexFree].dir.altura=altura;
		pArray[indexFree].estado=estado;
		pArray[indexFree].isEmpty=OCCUP; // no esta mas empty
		pArray[indexFree].idZona=0; // valor ilogico, no tiene zona asignada aun

	}

	return ret;
}

int modCensista(Censista* pArray, int len, int pos, int id, int opcion)
{

	int auxResponse;
	char auxNombre[51];
	char auxApellido[51];
	int auxDia;
	int auxMes;
	int auxAnio;
	char auxCalle[31];
	int auxAltura;
	int ret=-1;
	if(pArray!=NULL && len>0 && pos>=0 && id>0 && opcion>0 && pArray[pos].id == id)
	{
		switch(opcion)
		{
			//nombre
			case 1:
				if(utn_getNumber(&auxResponse, "\n\tEsta por modificar el nombre, desea continuar? (0 si- 1 no): ", "\n\tPor favor elija una opcion correcta", 0, 1, 2)==0)
				 {
					 if(auxResponse==0)
					 {
						 if(utn_getText(auxNombre, 51, "\n\tIngrese el nombre del censista: ", "\n\tError al ingresar el nombre\n", 2)==0)
						 {
							 ret=0;
							 strcpy(pArray[pos].nombre,auxNombre);
							 printf("\n\tModificacion realizada con exito\n\n");
						 }
						 else
						 {
							 // no se modifica
							 ret=-1;
						 }
					 }
					 else
					 {
						 // no se modifica
						printf("\n\tNo se modificara el nombre\n\n");
						ret=-1;
					 }
				 }
				else
				 {
					 // no se modifica
					printf("\n\tError al seleccionar\n\n");
					ret=-1;
				 }
				break;
			//apellido
			case 2:
				if(utn_getNumber(&auxResponse, "\n\tEsta por modificar el apellido, desea continuar? (0 si- 1 no): ", "\n\tPor favor elija una opcion correcta", 0, 1, 2)==0)
				 {
					 if(auxResponse==0)
					 {
						 if(utn_getText(auxApellido, 51, "\n\tIngrese el apellido del censista: ", "\n\tError al ingresar el apellido\n", 2)==0)
						 {
							 ret=0;
							 strcpy(pArray[pos].apellido,auxApellido);
							 printf("\n\tModificacion realizada con exito\n\n");
						 }
						 else
						 {
							 // no se modifica
							 ret=-1;
						 }
					 }
					 else
					 {
						 // no se modifica
						printf("\n\tNo se modificara el apellido\n\n");
						ret=-1;
					 }
				 }
				else
				 {
					 // no se modifica
					printf("\n\tError al seleccionar\n\n");
					ret=-1;
				 }
				break;
			//fecha de nacimiento
			case 3:
				if(utn_getNumber(&auxResponse, "\n\tEsta por modificar la fecha de nacimiento, desea continuar? (0 si- 1 no): ", "\n\tPor favor elija una opcion correcta", 0, 1, 2)==0)
				 {
					 if(auxResponse==0)
					 {
						 if(utn_getNumber(&auxResponse, "\n\tQue campo desea modificar? 1-Dia 2-Mes 3-Anio: ", "\n\tPor favor elija una opcion correcta", 1, 3, 2)==0)
						 {
								 switch(auxResponse)
								 {
								 // dia
								 case 1:
									 if(utn_getNumber(&auxDia, "\n\tIngrese el nuevo dia: ", "\n\tError al ingresar el dia\n", 1, 31, 2)==0)
									 {
										 ret=0;
										 pArray[pos].fecha.dia=auxDia;
										 printf("\n\tModificacion realizada con exito\n\n");
									 }
									 else
									 {
										 // no se modifica
										 ret=-1;
									 }
									 break;
								 // mes
								 case 2:
									 if(utn_getNumber(&auxMes, "\n\tIngrese el nuevo mes: ", "\n\tError al ingresar el mes\n", 1, 12, 2)==0)
									 {
										 ret=0;
										 pArray[pos].fecha.mes=auxMes;
										 printf("\n\tModificacion realizada con exito\n\n");
									 }
									 else
									 {
										 // no se modifica
										 ret=-1;
									 }
									 break;
								 // anio
								 case 3:
									 if(utn_getNumber(&auxAnio, "\n\tIngrese el nuevo anio: ", "\n\tError al ingresar el anio\n", 1950, 2004, 2)==0)
									 {
										 ret=0;
										 pArray[pos].fecha.anio=auxAnio;
										 printf("\n\tModificacion realizada con exito\n\n");
									 }
									 else
									 {
										 // no se modifica
										 ret=-1;
									 }
									 break;
								 }
						 }
						 else
						 {
							 // no se modifica
							printf("\n\tError al seleccionar\n\n");
							ret=-1;
						 }
					 }
					 else
					 {
						 // no se modifica
						printf("\n\tNo se modificara la fecha de nacimiento\n\n");
						 ret=-1;
					 }
				 }
				else
				 {
					 // no se modifica
					printf("\n\tError al seleccionar\n\n");
					ret=-1;
				 }
				break;
			//Direccion
			case 4:
				if(utn_getNumber(&auxResponse, "\n\tEsta por modificar la direccion, desea continuar? (0 si- 1 no): ", "\n\tPor favor elija una opcion correcta", 0, 1, 2)==0)
				{
					if(auxResponse==0)
					{
						if(utn_getNumber(&auxResponse, "\n\tQue campo desea modificar? 1-Calle 2-Altura: ", "\n\tPor favor elija una opcion correcta", 1, 2, 2)==0)
						{
							switch(auxResponse)
							{
							// calle
							case 1:
								if(utn_getText(auxCalle, 31, "\n\tIngrese la nueva calle: ", "\n\tError al ingresar la calle\n", 2)==0)
								 {
									 ret=0;
									 strcpy(pArray[pos].dir.calle,auxCalle);
									 printf("\n\tModificacion realizada con exito\n\n");
								 }
								 else
								 {
									 // no se modifica
									 ret=-1;
								 }
								break;
							// altura
							case 2:
								if(utn_getNumber(&auxAltura, "\n\tIngrese la nueva altura: ", "\n\tError al ingresar la altura\n", 1, 17000, 2)==0)
								 {
									 ret=0;
									 pArray[pos].dir.altura=auxAltura;
									 printf("\n\tModificacion realizada con exito\n\n");
								 }
								 else
								 {
									 // no se modifica
									 ret=-1;
								 }
								break;
							}
						}
					}
				}
				else
				 {
					 // no se modifica
					printf("\n\tError al seleccionar\n\n");
					ret=-1;
				 }
				break;
		}
	}

	return ret;
}

int removeCensista(Censista* pArray, int len, int id)
{
	int ret=-1;
	int i;
	int auxResponse;
	if(pArray!=NULL && len>0 && id>0)
	{
		for(i=0;i<len;i++)
		{
			if(pArray[i].idZona==1)
			{
				ret=-1;
				printf("\n\tEl censista todavia tiene una Zona asignada!\n\n");
				break;
			}
			else
			{
				if(pArray[i].id == id && pArray[i].isEmpty == OCCUP && pArray[i].idZona==0)
				{
					printf("\n\tEsta por dar de baja:\n\n");
					printCensista(&pArray[i]);
					if(utn_getNumber(&auxResponse, "\n\tdesea continuar? (0 si- 1 no): ", "\n\tPor favor elija una opcion correcta", 0, 1, 2)==0)
					{
						if(auxResponse==0)
						{
							ret=0;
							pArray[i].isEmpty=EMPTY;
							pArray[i].estado=3; // estado inactivo
							printf("\n\tBaja realizada con exito!\n\n");
						}
						else
						{
							ret=-1;
							printf("\n\tNo se realizara la baja\n\n");
						}
					}
				}
			}
		}
	}

	return ret;
}

int printCensista(Censista* pArray)
{
	char auxEstado[10]; //1 activo / 2 liberado / 3 inactivo
	char auxLocalidad[20]; // si es que tiene asignada alguna
	int ret=-1;
	if(pArray->estado==1)
	{
		// esta activo
		strcpy(auxEstado,"Activo");
	}
	else
	{
		if(pArray->estado==2)
		{
			// esta inactivo
			strcpy(auxEstado,"Liberado");
		}
		else
		{
			if(pArray->estado==3)
			{
				// esta inactivo
				strcpy(auxEstado,"Inactivo");
			}
		}
	}
	if(pArray->idZona==0)
	{
		strcpy(auxLocalidad,"Sin Zona asignada");
	}
	else
	{
		strcpy(auxLocalidad,"Tiene asignada");
	}

	if(pArray->isEmpty == OCCUP)
	{
		printf("\n\tId: %d\n"
			   "\n\tNombre: %s\n"
			   "\n\tApellido: %s\n"
			   "\n\tFecha de nacimiento: %d/%d/%d\n"
			   "\n\tEdad: %d\n"
			   "\n\tDireccion: %s %d\n"
			   "\n\tEstado: %s\n"
			   "\n\tZona asignada (localidad): %s\n"
			   "\n\tId de la zona asignada: %d\n\n",
			   pArray->id, pArray->nombre, pArray->apellido,pArray->fecha.dia,pArray->fecha.mes,pArray->fecha.anio,pArray->edad, pArray->dir.calle,pArray->dir.altura,auxEstado,auxLocalidad,pArray->idZona);
		ret=0;
	}

	return ret;
}

int printCensistas(Censista* pArray, int len)
{
	int ret=-1;
	int i;
	if(pArray!=NULL && len>0)
	{
		for(i=0; i<len;i++)
		{
			if(pArray[i].isEmpty == OCCUP)
			{
				printCensista(&pArray[i]);
			}
		}
		ret=0;
	}
	return ret;
}


