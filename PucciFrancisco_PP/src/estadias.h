
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef ESTADIAS_H_
#define ESTADIAS_H_

#define VACIO 0
#define OCUPADO 1

#include "estadias.h"
#include "input.c"

typedef struct
{
	int dia;
	int mes;
	int anio;

}eFecha;

typedef struct
{
	int idEstadia;
	char nombreDuenio[22];
	int telefonoContacto;
	int idPerro;
	eFecha fechaEstadia;
	int isEmpty;

}eEstadia;

typedef struct
{
	int idPerro;
	char nombrePerro[22];
	char raza[22];
	int edad;
	int isEmpty;
}ePerro;


eFecha pedirFecha(char mensaje[]);
int estadia_agregarEstadia(eEstadia estadias[], int tam, int* ultimoIdIngresado);
int estadia_buscarEspacioLibre(eEstadia estadias[], int tam);
int estadia_cargarUna(eEstadia estadias[], int i, int id);
int estadia_ModificarUno(eEstadia estadias[], int tam);
int estadia_buscarPorId(eEstadia estadias[], int tam, int id);
int estadia_borrar(eEstadia estadias[], int tam);
void estadia_ordenarPorFecha(eEstadia estadias[], int tam);
int estadia_printEstadia(eEstadia estadias);
void perro_printPerro(ePerro perros);
void inicializarEstadia(eEstadia* estadia,int TAM);
void inicializarPerro(ePerro* perro,int TAM);

#endif
