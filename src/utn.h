/*
 * input.h
 *
 *  Created on: 7 abr 2022
 *      Author: juanm
 */

#ifndef INPUT_H_
#define INPUT_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/**
* \brief Solicita un numero entero a un usuario, se utiliza la funcion getInt para validar
* \param pResultado Se carga en la dir de memoria, una vez validado
* \param mensaje Mensaje que solicita que se debe hacer
* \param mensajeError Es el mensaje a ser mostrado en caso de error
* \param minimo Limite inferior a validar
* \param maximo Limite superior a validar
* \param reintentos cantidad de intentos en caso de error
* \return exito = [0] - error = [1]
*/
int utn_getNumber(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);

/**
* \brief Solicita un numero flotante a un usuario, se utiliza la funcion getFloat para validar
* \param pResultado Se carga en la dir de memoria, una vez validado
* \param mensaje Mensaje que solicita que se debe hacer
* \param mensajeError Es el mensaje a ser mostrado en caso de error
* \param minimo Limite inferior a validar
* \param maximo Limite superior a validar
* \param reintentos cantidad de intentos en caso de error
* \return exito = [0] - error = [1]
*/
int utn_getFloat(float* pResultado, char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos);

/**
* \brief Solicita un carater al usuario
* \param pResultado Se carga en la dir de memoria, una vez validado
* \param mensaje Mensaje que solicita que se debe hacer
* \param mensajeError Es el mensaje a ser mostrado en caso de error
* \param minimo Limite inferior a validar
* \param maximo Limite superior a validar
* \param reintentos cantidad de intentos en caso de error
* \return exito = [0] - error = [1]
*/
int utn_getChar(char* pResultado, char* mensaje, char* mensajeError, char minimo, char maximo, int reintentos);

/**
* \brief Solicita una cadenad de caracteres al usuario, y, en este caso, llama a la funcion isLetter, para validar solo letras entre A/Z & a/z incluyendo " "
* \param pResultado Se carga en la dir de memoria, una vez validado
* \param mensaje Mensaje que solicita que se debe hacer
* \param mensajeError Es el mensaje a ser mostrado en caso de error
* \param minimo Limite inferior a validar
* \param maximo Limite superior a validar
* \param reintentos cantidad de intentos en caso de error
* \return exito = [0] - error = [1]
*/
int utn_getText(char* pResultado, int len, char* mensaje, char* mensajeError, int reintentos);

/**
* \brief Solicita una cadenad de caracteres que representa el dni (maximo 10 posiciones), se utiliza la funcion isDni para validar
* \param pResultado Se carga en la dir de memoria, una vez validado
* \param mensaje Mensaje que solicita que se debe hacer
* \param mensajeError Es el mensaje a ser mostrado en caso de error
* \param minimo Limite inferior a validar
* \param maximo Limite superior a validar
* \param reintentos cantidad de intentos en caso de error
* \return exito = [0] - error = [1]
*/
int utn_getDni(char* pResultado, int len, char* mensaje, char* mensajeError, int reintentos);


#endif /* INPUT_H_ */
