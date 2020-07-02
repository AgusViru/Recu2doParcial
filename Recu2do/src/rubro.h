/*
 * rubro.h
 *
 *  Created on: 25 jun. 2020
 *      Author: Ezequiel
 */

#ifndef RUBRO_H_
#define RUBRO_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Validaciones.h"
#include "utn.h"
#include "LinkedList.h"
typedef struct
{
	int id;
	char descripcion[50];
}eRubro;

int Rubro_setId(eRubro* rubro,int idRubro);
int Rubro_getId(eRubro* rubro,int* idRubro);
int Rubro_setDescripcion(eRubro* rubro,char* DRubro);
int Rubro_getDescripcion(eRubro* rubro,char* DRubro);
int Rubro_buscarPorId(LinkedList* listaRubro,int idABuscar);
#endif /* RUBRO_H_ */
