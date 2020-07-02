/*
 * catering.c
 *
 *  Created on: 2 jul. 2020
 *      Author: Ezequiel
 */

#include "catering.h"

eCatering* Catering_nuevoCatering()
{
    eCatering* unCatering=(eCatering*)malloc(sizeof(eCatering));
    return unCatering;
}
int Catering_borrarCatering(eCatering* catering)
{
    int seLibero=0;
    if(catering!=NULL)
    {
        free(catering);
        seLibero=1;
    }
    return seLibero;
}
int Catering_setIdCatering(eCatering* catering,int idCatering)
{
    int retorno=0;
    if((catering!=NULL) && (idCatering > 0))
    {
        catering->idCatering=idCatering;
        retorno=1;
    }
    return retorno;
}
int Catering_setPrecio(eCatering* catering,int precio)
{
    int retorno=0;
    if((catering!=NULL) && (precio > 0))
    {
        catering->precio=precio;
        retorno=1;
    }
    return retorno;
}
int Catering_setIdRubro(eCatering* catering,int idRubro)
{
    int retorno=0;
    if((catering!=NULL) && (idRubro > 0))
    {
        catering->rubroId=idRubro;
        retorno=1;
    }
    return retorno;
}
int Catering_setServicio(eCatering* catering,char* Sservicio)
{
    int retorno=0;
    if((catering!=NULL) && (strlen(Sservicio) > 0))
    {
        strcpy(catering->servicio,Sservicio);
        retorno=1;
    }
    return retorno;
}
int Catering_setMedida(eCatering* catering,char* medida)
{
    int retorno=0;
    if((catering!=NULL) && (strlen(medida) > 0))
    {
        strcpy(catering->medida,medida);
        retorno=1;
    }
    return retorno;
}

int Catering_getIdCatering(eCatering* catering,int* idCatering)
{
    int retorno=0;
    if(catering!=NULL && idCatering!=NULL)
    {
        *idCatering=catering->idCatering;
        retorno=1;
    }
    return retorno;
}
int Catering_getPrecio(eCatering* catering,int* precio)
{
    int retorno=0;
    if(catering!=NULL && precio!=NULL)
    {
        *precio=catering->precio;
        retorno=1;
    }
    return retorno;
}
int Catering_getIdRubro(eCatering* catering,int* idRubro)
{
    int retorno=0;
    if(catering!=NULL && idRubro!=NULL)
    {
        *idRubro=catering->rubroId;
        retorno=1;
    }
    return retorno;
}
int Catering_getServicio(eCatering* catering,char* Sservicio)
{
    int retorno=0;
    if(catering!=NULL && Sservicio!=NULL)
    {
        strcpy(Sservicio,catering->servicio);
        retorno=1;
    }
    return retorno;
}
int Catering_getMedida(eCatering* catering,char* medida)
{
    int retorno=0;
    if(catering!=NULL && medida!=NULL)
    {
        strcpy(medida,catering->medida);
        retorno=1;
    }
    return retorno;
}
eCatering* Catering_nuevoCateringParametros(char* idCatering,char* catering,char* medida,char* precio,char* idRubro)
{
    eCatering* unCatering=NULL;
    if((idCatering!=NULL) && (catering!=NULL) && (precio!=NULL) && (medida!=NULL) && (idRubro!=NULL))
    {
        unCatering=Catering_nuevoCatering();
        if(unCatering!=NULL)
        {
            if(!Catering_setIdCatering(unCatering,atoi(idCatering))
            	|| !Catering_setServicio(unCatering,catering)
            	|| !Catering_setMedida(unCatering,medida)
				|| !Catering_setPrecio(unCatering,atoi(precio))
				|| !Catering_setIdRubro(unCatering,atoi(idRubro)))
            {
                Catering_borrarCatering(unCatering);
                unCatering=NULL;
            }
        }
    }
    return unCatering;
}
int Catering_cargarDatosModoTexto(FILE* archivo,LinkedList* listaCaterings)
{
    char nombreArchivo[256];
    char auxIdCatering[256];
    char auxCatering[256];
    char auxPrecio[256];
    char auxMedida[256];
    char auxIdRubro[256];
    eCatering* auxDatos;
    int sePudo=-1;
    if(!utn_getLetrasYNumeros(nombreArchivo,256,"\nIngrese el nombre del archivo a cargar: "))
    {
        archivo=fopen(nombreArchivo,"r");
        if(archivo!=NULL)
        {
            ll_clear(listaCaterings);
            fscanf(archivo,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",auxIdCatering,auxCatering,auxMedida,auxPrecio,auxIdRubro);
            while(!feof(archivo))
            {
                fscanf(archivo,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",auxIdCatering,auxCatering,auxMedida,auxPrecio,auxIdRubro);
                auxDatos=Catering_nuevoCateringParametros(auxIdCatering,auxCatering,auxMedida,auxPrecio,auxIdRubro);
                ll_add(listaCaterings,auxDatos);
                if(feof(archivo))
                {
                    break;
                }
            }
            fclose(archivo);
            printf("\nSe han cargado los datos\n");
            sePudo=1;
        }
    }
    return sePudo;
}
int Catering_funcionCriterio(void* itemUno, void* itemDos)
{
	 char bufferCateringA[100];
	 char bufferCateringB[100];
	 int result;
	 Catering_getServicio(itemUno,bufferCateringA);
	 Catering_getServicio(itemDos,bufferCateringB);
	    if(strcmp(bufferCateringA,bufferCateringB)<0)
	    {
	        result=-1;
	    }
	    	else if(strcmp(bufferCateringA,bufferCateringB)>0)
	    	{
	    		result=1;
	    	}
	    		else
	    		{
	    			result=0;
	    		}
	    return result;
}
void Catering_mostrarListaCatering(LinkedList* listaCaterings)
{
    eCatering* auxCatering;
    int i;
    int len=ll_len(listaCaterings);
    if(listaCaterings!=NULL)
    {
        if(listaCaterings!=NULL && ll_isEmpty(listaCaterings)==1)
        {
            printf("\nNo hay ningun elemento en la lista\n");
        }
        else
        {
            printf("\nIdCatering--Catering--Medida--Precio--RubroId--\n");
            for(i=0;i<len;i++)
            {
                auxCatering=(eCatering*)ll_get(listaCaterings,i);
                Catering_mostrarUnCatering(auxCatering);
            }
        }
    }
}
int Catering_mostrarUnCatering(eCatering* unCatering)
{
    int idCatering;
    char catering[256];
    int precio;
    char medida[256];
    int rubroId;

    Catering_getIdCatering(unCatering,&idCatering);
    Catering_getServicio(unCatering,catering);
    Catering_getMedida(unCatering,medida);
    Catering_getPrecio(unCatering,&precio);
    Catering_getIdRubro(unCatering,&rubroId);
    int seMostro=0;
    if(unCatering!=NULL)
    {
        printf("\n%d",idCatering);
        printf("%2s\t",catering);
        printf("%2s\t",medida);
        printf("%2d",precio);
        printf("%5d\n",rubroId);
        seMostro=1;
    }
    return seMostro;
}
int Catering_calcularPrecioPorConfiteria(eCatering* unCatering)
{
	int retorno=-1;
    int precio;
    int idRubro;
    if(unCatering!=NULL)
    {
        precio=unCatering->precio; //precio-(precio*0.2);
        idRubro= unCatering->rubroId;
        if(precio>=150 && idRubro==1)
        {
            unCatering->precio=precio-(precio*0.2);
            retorno=0;
        }
    }
    return retorno;
}

int Catering_calcularPrecioPorCuidadoRopaDos(void* unCatering)
{
	int mapeo=0;
    int precio;
    int idRubro;
 	int precioDescto;
    eCatering* catering=(eCatering*)unCatering;
    Catering_getPrecio(catering,&precio);
    Catering_getIdRubro(catering,&idRubro);
    precioDescto=precio-(precio*0.2);
    if(precioDescto>=120 && idRubro==1)
    {
        mapeo=1;
    }
    return mapeo;
}
int Catering_calcularPrecioPorLimpiezaDos(void* unCatering)
{
	int mapeo=0;
    int precio;
    int idRubro;
 	int precioDescto;
    eCatering* catering=(eCatering*)unCatering;
    Catering_getPrecio(catering,&precio);
    Catering_getIdRubro(catering,&idRubro);
    precioDescto=precio-(precio*0.1);
    if(precioDescto<=200 && idRubro==2)
    {
        mapeo=1;
    }
    return mapeo;
}
int Catering_calcularPrecioPorLunch(eCatering* unCatering)
{
	int retorno=-1;
    int precio;
    int idRubro;
    if(unCatering!=NULL)
    {
        precio=unCatering->precio; //precio-(precio*0.2);
        idRubro=unCatering->rubroId;
        	if(precio<=30 && idRubro==2)
        	{
        		unCatering->precio=precio-(precio*0.1);
        		retorno=0;
        	}
    }
    return retorno;
}
int Catering_guardarDatosMapeo(FILE* archivo,LinkedList* listaCaterings)
{
    char nombreArchivo[256];
    char auxIdCateringsStr[256];
    char auxServicioStr[256];
    char auxMedidaStr[256];
    char auxprecioStr[256];
    char auxRubroIdStr[256];
    int auxIdCaterings;
    int auxPrecio;
    int auxRubroId;
    int sePudo=-1;
    LinkedList* nuevaLista;
    eCatering* auxDatos;
    int i;
    int len;
    if(listaCaterings!=NULL && ll_isEmpty(listaCaterings)==1)
    {
        printf("\nNo hay ningun elemento en la lista\n");
    }
    else
    {
        if(getStrLetras("\nIngrese el nombre del nuevo archivo a crear: ",nombreArchivo,"\nSolo se permiten letras\n","\nRango valido entre 1 y 16\n",1,16,3))
        {
            archivo=fopen(nombreArchivo,"w");
            if(archivo!=NULL)
            {
            	nuevaLista=mapeo(listaCaterings,(void*)Catering_calcularPrecioPorConfiteria);
            	nuevaLista=mapeo(listaCaterings,(void*)Catering_calcularPrecioPorLunch);
            	/*nuevaLista=mapeo(listaCaterings,(void*)Catering_calcularPrecioPorCuidadoRopaDos);
            	nuevaLista=mapeo(listaCaterings,(void*)Catering_calcularPrecioPorLimpiezaDos);*/
            	if(nuevaLista!=NULL)
            	{
                    len=ll_len(nuevaLista);
                    fprintf(archivo,"\nIdCatering--Servicio--Medida--Precio--RubroId--\n");
                    for(i=0;i<len;i++)
                    {
                        auxDatos=(eCatering*)ll_get(nuevaLista,i);
                        Catering_getIdCatering(auxDatos,&auxIdCaterings);
                        itoa(auxIdCaterings,auxIdCateringsStr,10);
                        Catering_getServicio(auxDatos,auxServicioStr);
                        Catering_getMedida(auxDatos,auxMedidaStr);
                        Catering_getPrecio(auxDatos,&auxPrecio);
                        itoa(auxPrecio,auxprecioStr,10);
                        Catering_getIdRubro(auxDatos,&auxRubroId);
                        itoa(auxRubroId,auxRubroIdStr,10);
                        fprintf(archivo,"%s,%s,%s,%s,%s\n",auxIdCateringsStr,auxServicioStr,auxMedidaStr,auxprecioStr,auxRubroIdStr);
                    }
            	}
                fclose(archivo);
                printf("\nSe han guardado los datos\n");
                sePudo=1;
            }
        }
    }
    return sePudo;
}
int Catering_MontoMayora100(void* pElement)
{
    int retorno;
    int aux;
    if(pElement!=NULL){
        Catering_getPrecio(pElement,&aux);
        if(aux>100){
            retorno=1;
            Catering_mostrarUnCatering((eCatering*)pElement);
        }else
            retorno=0;
    }
    return retorno;
}
int Catering_CantidadRubroTres(void* pElement)
{
	int retorno;
	int auxRubro;
	if(pElement!=NULL)
	{
	    Catering_getIdRubro(pElement,&auxRubro);
	    if(auxRubro==3)
	    {
	    	retorno=1;
	        Catering_mostrarUnCatering((eCatering*)pElement);
	    }
	    else
	    {
	       retorno=0;
	    }
	}
	    return retorno;

}

