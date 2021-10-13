/*
 ============================================================================
 Name        : labo.c
 Author      : francisco pucci romero
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "input.h"
#include "estadias.h"

#define TAMPERRO 3
#define TAMESTADIA 100

int main(void)
{
	setbuf(stdout, NULL);
	ePerro perros[TAMPERRO];
	eEstadia estadias[TAMESTADIA];
	//init  y estadia is empty = 0=basio
	int contEstadias=0;
	int eleccionMenu;
	int i;
	int acumEdad=0;
	int contPerros=0;
	float promedio;
	//harcodeo
	//inicializar en is empty todo
	//inicializarEstadia(estadias, TAMESTADIA);
	//inicializarPerro(perros, TAMPERRO);

	perros[0].idPerro=7000;
	strcpy (perros[0].nombrePerro, "Lobo");
	strcpy (perros[0].raza, "Sharpei");
	perros[0].edad=2;
	perros[0].isEmpty=1;

	perros[1].idPerro=7001;
	strcpy (perros[1].nombrePerro, "Sheila");
	strcpy (perros[1].raza, "Golden");
	perros[1].edad=12;
	perros[1].isEmpty=1;

	perros[2].idPerro=7002;
	strcpy (perros[2].nombrePerro, "Reina");
	strcpy (perros[2].raza, "Galgo");
	perros[2].edad=13;
	perros[2].isEmpty=1;







	do{
		pedirEntero(&eleccionMenu, "MENU\n "
					"Elija unaopcion:\n "
					"1:RESERVAR ESTADIA\n "
					"2:MODIFICAR ESTADIA\n "
					"3:CANCELAR ESTADIA \n "
					"4:MOSTAR LISTA DE ESTADIAS\n "
					"5:MOSTRAR LISTA PERROS\n "
					"6:MOSTRAR PROMEDIO EDADES \n "
					"7: salir",
					"OPCION INVALIDA\n"
					"ingrese una opcion\n"
					"Elija unaopcion:\n "
					"1:RESERVAR ESTADIA\n "
					"2:MODIFICAR ESTADIA\n "
					"3:CANCELAR ESTADIA \n "
					"4:MOSTAR LISTA DE ESTADIAS\n "
					"5:MOSTRAR LISTA PERROS\n "
					"6:MOSTRAR PROMEDIO EDADES \n"
					"7: salir"
					, 1, 7);
	switch(eleccionMenu)
	{
	case 1://reservar
		if(!estadia_agregarEstadia(estadias, TAMESTADIA, &contEstadias))
		{
			contEstadias++;
		}
		system("pause");
		break;
	case 2: //modificar estadia //sub menu
		if(contEstadias>0)
		{
		estadia_ModificarUno(estadias,TAMESTADIA);
		}
		else
		{
			printf("\nno existe ninguna estadia que modificar\n");
		}
		break;
	case 3://canselar estadia buscom id estadia y borro los datos

		if(contEstadias>0)
		{
		estadia_borrar( estadias, TAMESTADIA);
		}
		else
		{
			printf("\nno existe ninguna estadia que cancelar\n");
		}
	break;
	case 4://listas estadias//ordenamiento

		//print
		if(contEstadias>0)
		{
		estadia_ordenarPorFecha(estadias,TAMESTADIA);
		for(i=0;i<TAMESTADIA;i++)
		{
			if(estadias[i].isEmpty==OCUPADO)
			{
				estadia_printEstadia(estadias[i]);
			}
		}
		}
		else
		{
			printf("\nno existe ninguna estadia que mostrar\n");
		}
	break;
	case 5://lista perros//ordenamiento
		printf("\nPERROS:\n\n%-5s %-20s %-20s %-20s\n", "ID", "NOMBRE", "RAZA", "EDAD");
		for(i=0;i<TAMPERRO;i++)
		{
			if(perros[i].isEmpty==OCUPADO)
			{
			perro_printPerro(perros[i]);//menu perros aparte.
			}
		}

		break;
	case 6://promedio perros//recorre ve is empty y acumula edad
		for(i=0;i<TAMPERRO;i++)
		{
			acumEdad+=perros[i].edad;
			contPerros++;
		}
		promedio=acumEdad/contPerros;
	printf("promedio edad de perros=%f\n",promedio);
	break;
	case 7:
		//cortar
		break;
	}//fin switch
	}while(eleccionMenu!=7);
	printf("adios");
}

