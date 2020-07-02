/*
 * rubro.c
 *
 *  Created on: 25 jun. 2020
 *      Author: Ezequiel
 */

#include "rubro.h"

int Rubro_setId(eRubro* rubro,int idRubro)
{
    int retorno=0;
    if((rubro!=NULL) && (idRubro > 0))
    {
        rubro->id=idRubro;
        retorno=1;
    }
    return retorno;
}
int Rubro_getId(eRubro* rubro,int* idRubro)
{
    int retorno=0;
    if(rubro!=NULL && idRubro!=NULL)
    {
        *idRubro=rubro->id;
        retorno=1;
    }
    return retorno;
}
int Rubro_setDescripcion(eRubro* rubro,char* DRubro)
{
    int retorno=0;
    if((rubro!=NULL) && (strlen(DRubro) > 0))
    {
        strcpy(rubro->descripcion,DRubro);
        retorno=1;
    }
    return retorno;
}
int Rubro_getDescripcion(eRubro* rubro,char* DRubro)
{
    int retorno=0;
    if(rubro!=NULL && DRubro!=NULL)
    {
        strcpy(DRubro,rubro->descripcion);
        retorno=1;
    }
    return retorno;
}
int Rubro_buscarPorId(LinkedList* listaRubro,int idABuscar)
{
    int auxId;
    int retorno=-1;
    eRubro* auxDatos;
    int i;
    int len=ll_len(listaRubro);
    if(listaRubro!=NULL)
    {
        for(i=0;i<len;i++)
        {
            auxDatos=ll_get(listaRubro,i);
            Rubro_getId(auxDatos,&auxId);
            if(auxId==idABuscar)
            {
                retorno=i;
                break;
            }
        }
    }
    return retorno;
}
