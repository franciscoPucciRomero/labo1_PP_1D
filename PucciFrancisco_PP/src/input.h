/*
 * inputs.h
 *
 *  Created on: 27 sept. 2021
 *      Author: santi
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>



#ifndef INPUT_H_
#define INPUT_H_


int pedirEntero(int* entero, char* mensaje, char* mensajeError, int min, int max);
int pedirFlotante(float* flotante, char* mensaje, char* mensajeError, float min, float max);
int pedirCadena(char* cadena, char* mensaje, char* mensajeError, int max);
int pedirCaracter(char* caracter, char* mensaje);


#endif /* INPUTS_H_ */
