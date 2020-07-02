#include "Validaciones.h"

int getInt(char* mensaje)
{
    int auxInt;
    printf("%s",mensaje);
    scanf("%d",&auxInt);
    fflush(stdin);
    return auxInt;
}
float getFloat(char* mensaje)
{
    float auxFloat;
    printf("%s",mensaje);
    scanf("%f",&auxFloat);
    fflush(stdin);
    return auxFloat;
}
char getChar(char* mensaje)
{
    char auxChar;
    printf("%s",mensaje);
    scanf("%c",&auxChar);
    fflush(stdin);
    return auxChar;
}
void getString(char* mensaje,char* unArray)
{
    printf("%s",mensaje);
    scanf("%[^\n]",unArray);
    fflush(stdin);
}
int validarSoloNumeros(char* unArray)
{
    int contadorSignos=0;
    int retorno=1;
    int i=0;
    while(unArray[i] != '\0')
    {
        if((unArray[0] != '+') && (unArray[0] != '-') && (unArray[i] < '0' || unArray[i] > '9'))
        {
            retorno=0;
            break;
        }
        if(unArray[i] == '+' || unArray [i] == '-')
        {
            contadorSignos++;
        }
        i++;
    }
    if((retorno==1) && (contadorSignos > 1))
    {
        retorno=0;
    }
    return retorno;
}
int validarSoloNumerosFlotantes(char* unArray)
{
    int contadorPuntos=0;
    int contadorSignos=0;
    int retorno=1;
    int i=0;
    while(unArray[i] != '\0')
    {
        if((unArray[0] != '+') && (unArray[0] != '-') && (unArray[i] != '.') && (unArray[i] < '0' || unArray[i] > '9'))
        {
            retorno=0;
            break;
        }
        if(unArray[i] == '+' || unArray [i] == '-')
        {
            contadorSignos++;
        }
        if(unArray[i] == '.')
        {
            contadorPuntos++;
        }
        i++;
    }
    if((retorno==1) && ((contadorSignos > 1) || (contadorPuntos > 1)))
    {
        retorno=0;
    }
    return retorno;
}
int validarSoloLetras(char* unArray)
{
    int retorno=1;
    int i=0;
    while(unArray[i] != '\0')
    {
        if((unArray[i] != ' ') && (unArray[i] != '.') && (unArray[i] < 'a' || unArray[i] > 'z') && (unArray[i] < 'A' || unArray[i] > 'Z'))
        {
            retorno=0;
            break;
        }
        i++;
    }
    return retorno;
}
int getStrNumeros(char* mensaje,char* unArray,char* mensajeErrorNumeros,char* mensajeErrorRango,int min,int max,int intentos)
{
    int contIntentos=0;
    int retorno=1;
    char auxString[256];
    getString(mensaje,auxString);
    if(((validarSoloNumeros(auxString)==0) || (atoi(auxString) < min || atoi(auxString) > max)) && (contIntentos != intentos))
    {
        contIntentos++;
    }
    while(((validarSoloNumeros(auxString)==0) || (atoi(auxString) < min || atoi(auxString) > max)) && (contIntentos != intentos))
    {
        if(validarSoloNumeros(auxString)==0)
        {
            printf("%s",mensajeErrorNumeros);
        }
        else if(atoi(auxString) < min || atoi(auxString) > max)
        {
            printf("%s",mensajeErrorRango);
        }
        getString(mensaje,auxString);
        if(((validarSoloNumeros(auxString)==0) || (atoi(auxString) < min || atoi(auxString) > max)) && (contIntentos != intentos))
        {
            contIntentos++;
        }
    }
    if((retorno==1) && (contIntentos==intentos))
    {
        printf("\nSe acabaron los intentos\n");
        retorno=0;
    }
    else
    {
        strcpy(unArray,auxString);
    }
    return retorno;
}
int getStrNumerosFlotantes(char* mensaje,char* unArray,char* mensajeErrorNumeros,char* mensajeErrorRango,float min,float max,int intentos)
{
    int contIntentos=0;
    int retorno=1;
    char auxString[256];
    getString(mensaje,auxString);
    if(((validarSoloNumerosFlotantes(auxString)==0) || (atof(auxString) < min || atof(auxString) > max)) && (contIntentos != intentos))
    {
        contIntentos++;
    }
    while(((validarSoloNumerosFlotantes(auxString)==0) || (atof(auxString) < min || atof(auxString) > max)) && (contIntentos != intentos))
    {
        if(validarSoloNumerosFlotantes(auxString)==0)
        {
            printf("%s",mensajeErrorNumeros);
        }
        else if(atof(auxString) < min || atof(auxString) > max)
        {
            printf("%s",mensajeErrorRango);
        }
        getString(mensaje,auxString);
        if(((validarSoloNumerosFlotantes(auxString)==0) || (atof(auxString) < min || atof(auxString) > max)) && (contIntentos != intentos))
        {
            contIntentos++;
        }
    }
    if((retorno==1) && (contIntentos==intentos))
    {
        printf("\nSe acabaron los intentos\n");
        retorno=0;
    }
    else
    {
        strcpy(unArray,auxString);
    }
    return retorno;
}
int getStrNumerosSinRango(char* mensaje,char* unArray,char* mensajeErrorNumeros,int intentos)
{
    int contIntentos=0;
    int retorno=1;
    char auxString[256];
    getString(mensaje,auxString);
    if((validarSoloNumeros(auxString)==0) && (contIntentos != intentos))
    {
        contIntentos++;
    }
    while((validarSoloNumeros(auxString)==0) && (contIntentos != intentos))
    {
        if(validarSoloNumeros(auxString)==0)
        {
            printf("%s",mensajeErrorNumeros);
        }
        getString(mensaje,auxString);
        if((validarSoloNumeros(auxString)==0) && (contIntentos != intentos))
        {
            contIntentos++;
        }
    }
    if((retorno==1) && (contIntentos==intentos))
    {
        printf("\nSe acabaron los intentos\n");
        retorno=0;
    }
    else
    {
        strcpy(unArray,auxString);
    }
    return retorno;
}
int getStrLetras(char* mensaje,char* unArray,char* mensajeErrorLetras,char* mensajeErrorRango,int min,int max,int intentos)
{
    int retorno=1;
    int contIntentos=0;
    char auxString[256];
    getString(mensaje,auxString);
    if(((validarSoloLetras(auxString) == 0) || (strlen(auxString) < min || strlen(auxString) > max)) && (contIntentos != intentos))
    {
        contIntentos++;
    }
    while(((validarSoloLetras(auxString) == 0) || (strlen(auxString) < min || strlen(auxString) > max)) && (contIntentos != intentos))
    {
        if(validarSoloLetras(auxString) == 0)
        {
            printf("%s",mensajeErrorLetras);
        }
        else if(strlen(auxString) < min || strlen(auxString) > max)
        {
            printf("%s",mensajeErrorRango);
        }
        getString(mensaje,auxString);
        if(((validarSoloLetras(auxString) == 0) || (strlen(auxString) < min || strlen(auxString) > max)) && (contIntentos != intentos))
        {
            contIntentos++;
        }
    }
    if((retorno==1) && (contIntentos == intentos))
    {
        printf("\nSe acabaron los intentos\n");
        retorno=0;
    }
    else
    {
        strcpy(unArray,auxString);
    }
    return retorno;
}
int confirmarCambios(char* mensajeInicial,char* mensajeAclaracion)
{
    int retorno=-1;
    char confirmacion;
    confirmacion=getChar(mensajeInicial);
    confirmacion=tolower(confirmacion);
    while(confirmacion != 's' && confirmacion != 'n')
    {
        confirmacion=getChar(mensajeAclaracion);
        confirmacion=tolower(confirmacion);
    }
    if(confirmacion == 's')
    {
        retorno=1;
    }
    else if(confirmacion == 'n')
    {
        retorno=0;
    }
    return retorno;
}
int validarGenero(char* mensajeInicial,char* mensajeAclaracion)
{
    int retorno=-1;
    char confirmacion;
    confirmacion=getChar(mensajeInicial);
    confirmacion=tolower(confirmacion);
    while(confirmacion != 'm' && confirmacion != 'f')
    {
        confirmacion=getChar(mensajeAclaracion);
        confirmacion=tolower(confirmacion);
    }
    if(confirmacion == 'm')
    {
        retorno=1;
    }
    else if(confirmacion == 'f')
    {
        retorno=0;
    }
    return retorno;
}
