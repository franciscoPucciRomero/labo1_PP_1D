/*
 * estadias.c
 *
 *  Created on: 12 Oct 2021
 *      Author: Francisco
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "input.h"
#include "estadias.h"


eFecha pedirFecha(char mensaje[])
{
	eFecha fecha;

	printf("%s", mensaje);
	pedirEntero(&fecha.dia, "Ingrese dia (1-31): ", "Error. Reingrese dia (1-31): ", 1, 31);
	pedirEntero(&fecha.mes, "Ingrese mes (1-12): ", "Error. Reingrese mes (1-12): ", 1, 12);
	pedirEntero(&fecha.anio, "Ingrese año (2015-2022): ", "Error. Reingrese dia (2015-2022): ", 2015, 2022);

	return fecha;
}

int estadia_agregarEstadia(eEstadia estadias[], int tam, int* ultimoIdIngresado)
{
	int retorno = -1;
	int id;
	int index = estadia_buscarEspacioLibre(estadias, tam);

	id=*ultimoIdIngresado;

	if(index != -1) //Si hay lugar en el array
	{
		if(!estadia_cargarUna(estadias, index, id))
		{
			printf("\nSe cargo el producto!\n\n");
			id++;
			*ultimoIdIngresado=id;
		}
		else
		{
			printf("\nSe cancelo el alta del producto.\n\n");

		}
		retorno = 0;
	}
	else
	{
		printf("\nError. No hay espacio disponible.\n\n");
	}

	return retorno;
}
int estadia_buscarEspacioLibre(eEstadia estadias[], int tam)
{
	int i;
	int index = -1;

	for(i=0; i<tam; i++)
	{
		if(estadias[i].isEmpty == VACIO)
		{
			index = i;
			break;
		}
	}

	return index;
}
int estadia_cargarUna(eEstadia estadias[], int i, int id)
{
	eFecha auxfecha;
	int retorno =0;

	estadias[i].idEstadia=100000+id;
	estadias[i].isEmpty=OCUPADO;
	pedirCadena(estadias[i].nombreDuenio, "\ningrese su nombre", "error ingrese nombre", 21);//val
	//pedirCadena(estadias[i].nombreDuenio, "ingrese su apellido", "error ingrese apellido", 21);//val

	pedirEntero(estadias[i].telefonoContacto, "\ningrese telefono", "error ingrese telefono", 0, 100);//validar
	pedirEntero(estadias[i].idPerro, "\ningrrese id del perro", "error ingrrese id del perro", 7000, 7003);//validar
	auxfecha=pedirFecha("\ningrese fecha de estadia");
	estadias[i].fechaEstadia=auxfecha;
	return retorno;
}
//hasta aca case 1 cargar estadia

//modificar estadia
int estadia_ModificarUno(eEstadia estadias[], int tam)//modificar esta funcion y los mostrar_//
{
	int retorno = -1;
	int index;
	int idIngresado;


	pedirEntero(&idIngresado, "\nIngrese el ID de la estadia a modificar : ", "\nReingrese el ID ID de la estadia a modificar: ", 100000, 100100);
	index = estadia_buscarPorId(estadias, tam, idIngresado);

	if(index != -1) //Existe el producto?
	{
		pedirEntero(estadias[idIngresado].idPerro, "ingrese nuevo id de perro\n", "ingrese id valido\n", 7000, 7003);//validar id existente
		pedirEntero(estadias[idIngresado].telefonoContacto, "ingrese nuevo numero\n", "erro ingrese nuevo numero\n", 0, 1000);//

	}
	else
	{
		printf("\nError. Producto no encontrado...\n\n");
	}

	return retorno;
}
int estadia_buscarPorId(eEstadia estadias[], int tam, int id)
{
	int i;
	int index = -1;

	for(i=0; i<tam; i++)
	{
		if(estadias[i].isEmpty == OCUPADO && estadias[i].idEstadia == id)
		{
			index = i;
			break;
		}
	}

	return index;
}
//caso 3 borrar
int estadia_borrar(eEstadia estadias[], int tam)
{
	int retorno = -1;
	int index;
	int idIngresado;

	pedirEntero(&idIngresado, "Ingrese el ID de la estadia a modificar : ", "Reingrese el ID ID de la estadia a modificar: ", 100000, 100100);
	index = estadia_buscarPorId(estadias, tam, idIngresado);

	if(index != -1) //Existe el producto?
	{

			estadias[index].isEmpty = VACIO;
			printf("\nse elimino la estadia \n\n");
			retorno = 0;
			estadias[index].isEmpty = VACIO;

	}
	else
	{
		printf("\nError. estadia no ecncontrada \n");
	}

	return retorno;
}
void estadia_ordenarPorFecha(eEstadia estadias[], int tam)
{
	int i;
	int j;
	eEstadia auxEstadia;

	for(i=0; i<tam-1; i++)
	{
		for(j=i+1; j<tam; j++)
		{
			if(estadias[i].isEmpty == OCUPADO && estadias[j].isEmpty == OCUPADO && ((estadias[i].fechaEstadia.anio*10000)+(estadias[i].fechaEstadia.mes*100)+estadias[i].fechaEstadia.dia) > (estadias[j].fechaEstadia.anio*10000)+(estadias[j].fechaEstadia.mes*100)+(estadias[j].fechaEstadia.dia))
			{
				auxEstadia = estadias[i];
				estadias[i] = estadias[j];
				estadias[j] = auxEstadia;
			}
			if(estadias[i].isEmpty == OCUPADO && estadias[j].isEmpty == OCUPADO && ((estadias[i].fechaEstadia.anio*10000)+(estadias[i].fechaEstadia.mes*100)+estadias[i].fechaEstadia.dia) == (estadias[j].fechaEstadia.anio*10000)+(estadias[j].fechaEstadia.mes*100)+(estadias[j].fechaEstadia.dia))
			{
				if(strcmp(estadias[i].nombreDuenio , estadias[j].nombreDuenio) > 0)
				{
					auxEstadia = estadias[i];
					estadias[i] = estadias[j];
					estadias[j] = auxEstadia;
				}
			}
		}
	}
}
int estadia_printEstadia(eEstadia estadias)
{
	/*int idEstadia;
	char nombreDuenio[22];
	int telefonoContacto;
	int idPerro;
	eFecha fechaEstadia;
	int isEmpty;*/
	int ret=0;

	printf("\estadia:\n\n%-5s %-20s %-20s %-20s %-20s\n", "ID", "Duenio", "telefono", "perro", "fecha");
	printf("\nProducto a modificar:\n\n%-5d %-20s %-20d %-20d %-20d/%d/%d\n", estadias.idEstadia  , estadias.nombreDuenio, estadias.telefonoContacto, estadias.idPerro, estadias.fechaEstadia.anio,estadias.fechaEstadia.mes,estadias.fechaEstadia.dia);

	return ret;
}
void perro_printPerro(ePerro perros)
{


	printf("\n%-5d %-20s %-20s %-20d \n", perros.idPerro, perros.nombrePerro ,perros.raza ,perros.edad );

}
void inicializarEstadia(eEstadia* estadia,int TAM)
{
	int i;
	for(i=0;1<TAM;i++)
	{
		estadia[i].isEmpty=0;
	}
}
void inicializarPerro(ePerro* perro,int TAM)
{
	int i;
	for(i=0;1<TAM;i++)
	{
		perro[i].isEmpty=0;
	}
}




