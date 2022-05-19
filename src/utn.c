/*
 * input.c
 *
 *  Created on: 7 abr 2022
 *      Author: juanm
 */

#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <strings.h>
#include "utn.h"


// static func. firma

/**
* \brief valida una cadena de caracteres como un numero entero, mediante funcion isNumeric
* \param pResultado Se carga en la dir de memoria, una vez validado
* \return exito = [0] - error = [-1]
*/
static int getInt(int* pResultado);

/**
* \brief valida una cadena de caracteres como un numero flotante, mediante funcion isFloat
* \param pResultado Se carga en la dir de memoria, una vez validado
* \return exito = [0] - error = [-1]
*/
static int getFloat(float* pResultado);

/**
* \brief evalua los caracteres de una cadena para que sean numeros, positivos o negativos
* \param pResultado Se carga en la dir de memoria, una vez validado
* \return exito = [0] - error = [-1]
*/
static int isNumeric(char* pResultado);

/**
* \brief evalua los caracteres de una cadena para que sean numeros, positivos o negativos, teniendo en cuenta el punto
* \param pResultado Se carga en la dir de memoria, una vez validado
* \return exito = [0] - error = [-1]
*/
static int isFloat(char* pResultado);

/**
* \brief Es la encargada de tomar el dato ingresado por el usuario,
* \param pResultado Se carga en la dir de memoria, una vez validado
* \return exito = [0] - error = [-1]
*/
static int myGets(char* cadena, int longitud);

// stactic func. desarrollo

static int getInt(int* pResultado)
{
	int ret=-1;
	char buffer[4096];

	if(myGets(buffer,sizeof(buffer))==0 && isNumeric(buffer))
	{
		ret=0;
		*pResultado = atoi(buffer);
	}
	return ret;
}

static int getFloat(float* pResultado)
{
	int ret=-1;
	char buffer[4096];

	if(myGets(buffer,sizeof(buffer))==0 && isFloat(buffer))
	{
		ret=0;
		*pResultado = atof(buffer);
	}
	return ret;
}

static int myGets(char* pResultado, int longitud)
{
	fflush(stdin);

	if(fgets(pResultado,longitud,stdin)!=NULL)
	{
		pResultado[strlen(pResultado)-1]='\0'; // arregla el enter que se agrega al final, para que fgets cargue correctamente la cadena
	}

	return 0;
}

static int isNumeric(char* pResultado)
{
	int ret=-1;
	int i=0; // me tomo esta licencia aca

	if(pResultado[0] == '-') // negativos
	{
		i = 1;
	}
	for( ; pResultado[i] !='\0'; i++)
	{
		if(pResultado[i] > '9' || pResultado[i] < '0')
		{
			ret = 0;
			break;
		}
	}

	return ret;
}

static int isFloat(char* pResultado)
{
	int ret=-1;
	int i=0; // me tomo esta licencia aca

	if(pResultado[0] == '-') // negativos
	{
		i = 1;
	}
	for( ; pResultado[i] !='\0'; i++)
	{
		if((pResultado[i] > '9' || pResultado[i] < '0') && pResultado[i]!='.')
		{
			ret = 0;
			break;
		}
	}

	return ret;
}

static int isLetter(char* pResultado, int len)
{
	int ret=-1;
	int i;
	for(i=0; i<len;i++)
	{
		if(pResultado[i]!='\0')
		{
			if((pResultado[i] < 'A' || pResultado[i] > 'Z') && (pResultado[i] < 'a' || pResultado[i] > 'z'))
				{
					ret = 0;
				}
		}
	}
	return ret;
}

static int isDni(char* pResultado, int len)
{
	int ret=-1;
	int i;
	int dotCount=0;

	for(i=0; i<len;i++)
		{
		//printf("Esta llegando aca\n");
			if(pResultado[i]!= '\0')
			{
				//printf("Esta llegando aca 2\n");
				if(pResultado[i] == '.')
				{
					ret = 0;
				}
				printf("Esta llegando aca 3\n");
				if(pResultado[i] < '1' || pResultado[i] > '9')
					{
						ret = 0;
					}
				if(pResultado[i] == '.')
					{
						//printf("Hay un punto\n");
						dotCount++;
					}
				if(dotCount !=2)
				{
					ret = -1;
				}
			}
		}
	// por ahora existen estas variantes para gente de 80/90 anios (dnis 0.000.000) y los centennials has 99 millones (dnis 00.000.000)
	if(pResultado[1] =='.' && pResultado[5] =='.')
	{
		if(pResultado[9] != '\0')
		{
			ret = -1;
		}
		else
		{
			ret = 0;
		}

	}
	else
	{
		if(pResultado[2] =='.' && pResultado[6] =='.')
		{
			ret = 0;
		}
		else
		{
			// no fue un dni valido
			ret = -1;
		}
	}


	return ret;
}

int utn_getNumber(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
{
	int aux;
	int i;
	int ret=-1;

		if(pResultado!=NULL && mensaje!=NULL && mensajeError!=NULL && minimo<=maximo && reintentos>=0)
		{
			for(i=0;i<reintentos;i++)
			{
				printf("%s",mensaje);
				if(getInt(&aux) == 0 && aux >= minimo && aux <= maximo)
				{
					*pResultado = aux;
					ret=0; // salio bien
					break;
				}
				else
				{
					printf("%s",mensajeError);
					ret=-1;
				}
			}
		}
		else
		{
			printf("%s",mensaje);
			ret=-1; // salio mal
		}

	return ret;
}

int utn_getFloat(float* pResultado, char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos)
{
	float aux;
	int i;
	int ret=-1;

		if(pResultado!=NULL && mensaje!=NULL && mensajeError!=NULL && minimo<=maximo && reintentos>=0)
		{
			for(i=0;i<reintentos;i++)
			{
				printf("%s",mensaje);
				if(getFloat(&aux) == 0 && aux >= minimo && aux <= maximo)
				{
					*pResultado = aux;
					ret=0; // salio bien
					break;
				}
				else
				{
					printf("%s",mensajeError);
					ret=-1;
				}
			}
		}
		else
		{
			printf("%s",mensaje);
			ret=-1; // salio mal
		}

	return ret;
}

int utn_getChar(char* pResultado, char* mensaje, char* mensajeError, char minimo, char maximo, int reintentos)
{
	char aux[2];
	int ret=-1;
	int i;

		if(pResultado!=NULL && mensaje!=NULL && mensajeError!=NULL && minimo<=maximo && reintentos>=0)
		{
			for(i=0;i<reintentos;i++)
			{
				if(isdigit(*pResultado)==0)
				{
					printf("%s",mensaje);
					fgets(aux,sizeof(aux),stdin);
					strcpy(pResultado, aux);
					ret=0;
					break;
				}
				else
				{
					printf("%s",mensajeError);
					ret=-1; // salio mal
				}
			}
		}
		else
		{
			printf("%s",mensajeError);
			ret=-1; // salio mal
		}

	return ret;
}

int utn_getText(char* pResultado, int len, char* mensaje, char* mensajeError, int reintentos)
{
	char aux[124];
	int i;
	int ret=-1;

		if(pResultado!=NULL && len>0 && mensaje!=NULL && mensajeError!=NULL && reintentos>=0)
		{
			for(i=0;i<reintentos;i++)
			{
				printf("%s",mensaje);
				/*
				fflush(stdin);
				fgets(aux,sizeof(aux),stdin);
				aux[strlen(aux)-1]='\0';
				 * */
				if(myGets(aux, len)==0) // que solo sean letras y no numeros
				{
					if(isLetter(aux, len)==0)
					{
						if(isdigit(*aux)==0)
						{
							strcpy(pResultado,aux);
							ret=0;
							break;
						}
						else
						{
							printf("%s",mensajeError);
							ret=1; // salio mal
						}
					}
					else
					{
						printf("%s",mensajeError);
						ret=1; // salio mal
					}
				}
				else
				{
					printf("%s",mensajeError);
					ret=1; // salio mal
				}
			}
		}
		else
		{
			printf("%s",mensajeError);
			ret=1; // salio mal
		}

	return ret;
}

int utn_getDni(char* pResultado, int len, char* mensaje, char* mensajeError, int reintentos)
{
	char aux[12];
	int i;
	int ret=-1;

		if(pResultado!=NULL && len>0 && len<=12 && mensaje!=NULL && mensajeError!=NULL && reintentos>=0)
		{
			for(i=0;i<reintentos;i++)
			{
				printf("%s",mensaje);
				fflush(stdin);
				fgets(aux,len,stdin);
				aux[strlen(aux)-1]='\0';
				if(isDni(aux, len)==0 && strlen(aux)<=10)
				{
					strcpy(pResultado, aux);
					ret=0;
					break;
				}
			}
		}
		else
		{
			printf("%s",mensaje);
			ret=1; // salio mal
		}

	return ret;
}


