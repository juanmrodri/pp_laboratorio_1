/*
 ============================================================================
 Name        : pruebas_parcial.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================

ej de reporte, 1) el cencista que senso mas zonas?


 */

#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "strings.h"
#include "utn.h"
#include "arrayCensista.h"
#include "arrayZona.h"
#include "asignarZona.h"
#include "localidades.h"
#include "cargarDatos.h"
#define CEN_LEN 2000
#define ZON_LEN 5000
#define LOC_LEN 15
int main(void) {
	setbuf(stdout, NULL);

	int auxResponse;
	int auxPos;
	int auxId;


	Censista arrayCensistas[CEN_LEN];

	Zona arrayZonas[ZON_LEN];

	Localidad arrayLocalidades[LOC_LEN];

	initArrayCensista(arrayCensistas, CEN_LEN);

	initArrayZona(arrayZonas, ZON_LEN);

	initArrayLocalidad(arrayLocalidades, LOC_LEN);

	// localidades



	//char localidades[LOC_LEN][15];

	/*
	strcpy(localidades[0],"Almagro");
	strcpy(localidades[1],"Boedo");
	strcpy(localidades[2],"Devoto");
	strcpy(localidades[3],"Villa Crespo");
	strcpy(localidades[4],"Liniers");
	strcpy(localidades[5],"Mataderos");
	strcpy(localidades[6],"Palermo");
	strcpy(localidades[7],"Paternal");
	strcpy(localidades[8],"Hurlingham");
	strcpy(localidades[9],"El Palomar");
	*/


	// menu, pasar a biblioteca aparte

	forceLoadCensista(arrayCensistas, CEN_LEN, "Ricardo", "Mollo", 17, 8, 1955, "Bulnes", 635, 1, 0);
	forceLoadCensista(arrayCensistas, CEN_LEN, "Anibal", "Troilo", 2, 8, 1952, "Rivadavia", 7541, 1, 1);
	forceLoadCensista(arrayCensistas, CEN_LEN, "Jose", "Perez", 30, 3, 2000, "Av Cordoba", 2002, 1, 2);
	forceLoadCensista(arrayCensistas, CEN_LEN, "Alan", "Ramirez", 2, 5, 1995, "Av Scalabrini Ortiz", 850, 1, 0);
	forceLoadCensista(arrayCensistas, CEN_LEN, "Carlos", "Gonzalez", 24, 3, 1985, "Av Corrientes", 1500, 1, 7);

	ForceLoadZona(arrayZonas, ZON_LEN, "Lavalle", "Bulnes", "Billinghurst", "Sarmiento", 1, 0, 1);
	ForceLoadZona(arrayZonas, ZON_LEN, "Armenia", "Palestina", "Honduras", "Rivadavia", 1, 0, 4);
	ForceLoadZona(arrayZonas, ZON_LEN, "Mendoza", "Ayacucho", "Mitre", "Posadas", 1, 0, 2);

	forceLoadLocalidad(arrayLocalidades, LOC_LEN, "Almagro");
	forceLoadLocalidad(arrayLocalidades, LOC_LEN, "Boedo");
	forceLoadLocalidad(arrayLocalidades, LOC_LEN, "Devoto");
	forceLoadLocalidad(arrayLocalidades, LOC_LEN, "Liniers");
	forceLoadLocalidad(arrayLocalidades, LOC_LEN, "Palermo");
	forceLoadLocalidad(arrayLocalidades, LOC_LEN, "Paternal");
	forceLoadLocalidad(arrayLocalidades, LOC_LEN, "Hurlingham");
	forceLoadLocalidad(arrayLocalidades, LOC_LEN, "Moron");
	forceLoadLocalidad(arrayLocalidades, LOC_LEN, "Ciudadela");
	forceLoadLocalidad(arrayLocalidades, LOC_LEN, "Wilde");
	forceLoadLocalidad(arrayLocalidades, LOC_LEN, "Moreno");
	forceLoadLocalidad(arrayLocalidades, LOC_LEN, "Gerli");
	forceLoadLocalidad(arrayLocalidades, LOC_LEN, "Alsina");
	forceLoadLocalidad(arrayLocalidades, LOC_LEN, "Martinez");
	forceLoadLocalidad(arrayLocalidades, LOC_LEN, "Quilmes");

	do
	{
		printf("\n\n\t\t+++ Bienvenido al sistema de censo 2022 +++\n\n");
		if(utn_getNumber(&auxResponse, "\n\tElija una opcion?\n\n"
				"\t\t1) Cargar censista\n"
				"\t\t|\n"
				"\t\t2) Modificar censista\n"
				"\t\t|\n"
				"\t\t3) Dar de baja censista\n"
				"\t\t|\n"
				"\t\t4) Cargar Zona\n"
				"\t\t|\n"
				"\t\t5) Asignar zona a censar\n"
				"\t\t|\n"
				"\t\t6) cargar datos\n"
				"\t\t|\n"
				"\t\t7) Mostrar censistas\n"
				"\t\t|\n"
				"\t\t8) Mostrar zonas\n\n\t------------> ", "\n\tError en la seleccion\n\n", 1, 8, 2)==0)
		{
			switch(auxResponse)
			{
			case 1:
				if(findEmptyCensistaPos(arrayCensistas, CEN_LEN)>-1)
				{
					// cargar cencista
					loadCensista(arrayCensistas, CEN_LEN);
				}
				else
				{
					printf("\n\tPor el momento, no se pueden cargar mas censistas\n\n");
				}

				break;
			case 2:
				// mod censita
				if(isCensistaAdded(arrayCensistas, CEN_LEN)==0)
				{
					printCensistas(arrayCensistas, CEN_LEN);
					if(utn_getNumber(&auxId, "\n\tIngrese el Id del censista que quiere modificar: ", "\n\tError al ingresar opcion\n", 1, 2000, 2)==0)
					{
						auxPos = findCensistaById(arrayCensistas, CEN_LEN, auxId);
						if(auxPos!=-1)
						{
							printf("\n\tSe eligio: \n");
							printCensista(&arrayCensistas[auxPos]);
							if(utn_getNumber(&auxResponse, "\n\tQue desea modificar?\n\n"
															"\n\t1) Nombre\n\n"
															"\n\t2) Apellido\n\n"
															"\n\t3) Fecha de nacimiento\n\n"
															"\n\t1) Direccion\n\n\t------------> ", "Error al seleccionar", 1, 4, 2)==0)
							{
								modCensista(arrayCensistas, CEN_LEN, auxPos, auxId, auxResponse);
							}
							else
							{
								printf("\n\tError al seleccionar que quiere modificar\n\n");
							}
						}
						else
						{
							printf("\n\tEse posible que el id ingresado no exista, vuelva a intentar\n\n");
						}
					}
					else
					{
						printf("\n\tError al ingresar el id\n\n");
					}

				}
				else
				{
					printf("\n\tNo existen censitas ingresados, no se puede realizar la modificacion\n\n");
				}

				break;
			case 3:
				// dar de baja un censita
				if(isCensistaAdded(arrayCensistas, CEN_LEN)==0)
				{
					printCensistas(arrayCensistas, CEN_LEN);
					if(utn_getNumber(&auxId, "\n\tIngrese el Id del censista que quiere dar de baja: ", "\n\tError al ingresar opcion\n", 1, 9999, 2)==0)
					{
						if(findCensistaNullId(arrayCensistas, CEN_LEN, auxId)==0)
						{
							printf("\n\tEl id seleccionado no existe o fue dado de baja\n\n");
						}
						else
						{
							auxPos = findCensistaById(arrayCensistas, CEN_LEN, auxId);
							if(auxPos!=-1)
							{
								removeCensista(arrayCensistas, CEN_LEN, auxId);
							}
							else
							{
								printf("\n\tNo existe el id seleccionado\n\n");
							}
						}

					}
					else
					{
						printf("\n\tError al ingresar el dato\n\n");
					}
				}
				else
				{
					printf("\n\tNo existen censitas ingresados, no se puede realizar la baja\n\n");
				}
				break;
			case 4:
				// cargar zona
				if(findEmptyZonaPos(arrayZonas, ZON_LEN)>-1)
				{
					loadZona(arrayZonas, ZON_LEN);
				}
				else
				{
					printf("\n\tPor el momento, no se pueden cargar mas zonas\n\n");
				}
				break;
			case 5:
				// asignar
				if(isCensistaAdded(arrayCensistas, CEN_LEN)==0 && isZonaAdded(arrayZonas, ZON_LEN)==0)
				{
					printCensistas(arrayCensistas, CEN_LEN);
					// los 2 datos necesarios existen
					if(utn_getNumber(&auxId, "\n\tIngrese el Id del censista al que le quiere asignar una zona: ", "\n\tError al ingresar opcion\n", 1, 9999, 2)==0)
					{
						if(findCensistaNullId(arrayCensistas, CEN_LEN, auxId)==0)
						{
							printf("\n\tEl id seleccionado no existe o fue dado de baja\n\n");
						}
						else
						{
							auxPos = findCensistaById(arrayCensistas, CEN_LEN, auxId);
							if(auxPos!=-1)
							{
								asignarCensista(arrayCensistas, CEN_LEN, auxPos, arrayZonas, ZON_LEN);
							}
							else
							{
								printf("\n\tNo existe el id seleccionado\n\n");
							}
						}
					}

				}

				else
				{
					printf("\n\tPor favor para asignar una zona deben existir ambos datos\n\n");
				}
				break;
			case 6:
				// cargar datos
				break;
			case 7:
				if(isCensistaAdded(arrayCensistas, CEN_LEN)==0)
				{
					printCensistas(arrayCensistas, CEN_LEN);
				}
				else
				{
					printf("\n\tPor favor para imprimir ingrese algun censita!\n\n");
				}
				break;
			case 8:
				if(isZonaAdded(arrayZonas, ZON_LEN)==0)
				{
					printZonas(arrayZonas, ZON_LEN, arrayLocalidades, LOC_LEN);
				}
				else
				{
					printf("\n\tPor favor para imprimir ingrese alguna zona!\n\n");
				}
				break;
			}
		}
		else
		{
			printf("\n\n\t\t+++ Error al seleccionar, vuelva a intentar por favor +++\n\n");
		}
	}while(auxResponse!=0);



}
