/*
 * catering.h
 *
 *  Created on: 2 jul. 2020
 *      Author: Ezequiel
 */

#ifndef CATERING_H_
#define CATERING_H_

#include "LinkedList.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Validaciones.h"
#include "utn.h"
#include "rubro.h"
typedef struct
{
	int idCatering;
	char servicio[50];
	int precio;
	char medida[50];
	int rubroId;
}eCatering;

eCatering* Articulo_nuevoCatering();
int Catering_borrarCatering(eCatering* catering);
int Catering_setIdArticulo(eCatering* catering,int idCatering);
int Catering_setPrecio(eCatering* catering,int precio);
int Catering_setIdRubro(eCatering* catering,int idRubro);
int Catering_setServicio(eCatering* catering,char* Sservicio);
int Catering_setMedida(eCatering* catering,char* medida);
int Catering_getIdArticulo(eCatering* catering,int* idArticulo);
int Catering_getPrecio(eCatering* catering,int* precio);
int Catering_getIdRubro(eCatering* catering,int* idRubro);
int Catering_getServicio(eCatering* catering,char* Sservicio);
int Catering_getMedida(eCatering* catering,char* medida);
eCatering* Catering_nuevoCateringParametros(char* idCatering,char* servicio,char* medida,char* precio,char* idRubro);
int Catering_cargarDatosModoTexto(FILE* archivo,LinkedList* listaCatering);
int Catering_funcionCriterio(void* itemUno, void* itemDos);
void Catering_mostrarListaCatering(LinkedList* listaCatering);
int Catering_mostrarUnCatering(eCatering* Catering);
int Catering_calcularPrecioPorConfiteria(eCatering* unCatering);
int Catering_calcularPrecioPorCuidadoRopaDos(void* unCatering);
int Catering_calcularPrecioPorLimpiezaDos(void* unCatering);
int Catering_calcularPrecioPorLunch(eCatering* unCatering);
int Catering_guardarDatosMapeo(FILE* archivo,LinkedList* listaCatering);
int Catering_MontoMayora100(void* pElement);
int Catering_CantidadRubroTres(void* pElement);

#endif /* CATERING_H_ */
