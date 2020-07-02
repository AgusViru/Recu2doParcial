#ifndef VALIDACIONES_H_INCLUDED
#define VALIDACIONES_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/** \brief Pide un numero entero y lo retorna
 *
 * \param mensaje char* El mensaje pidiendo un numero
 * \return int Un numero entero
 *
 */
int getInt(char* mensaje);

/** \brief Pide un numero flotante
 *
 * \param mensaje char* El mensaje pidiendo un numero con coma
 * \return float Un numero flotante
 *
 */
float getFloat(char* mensaje);

/** \brief Pide un caracter y lo retorna
 *
 * \param mensaje char* El mensaje pidiendo una letra
 * \return char Un caracter
 *
 */
char getChar(char* mensaje);

/** \brief Pide una cadena de caracteres y la guarda por referencia
 *
 * \param mensaje char* El mensaje pidiendo una palabra
 * \param unArray char* El array en donde guardar la cadena de caracteres
 * \return void No retorna nada
 *
 */
void getString(char* mensaje,char* unArray);

/** \brief Recibe una cadena de caracteres y valida que contenga solo numeros
 *
 * \param unArray char* La cadena de caracteres a validar
 * \return int Si contiene solo numeros [1] si no [0]
 *
 */
int validarSoloNumeros(char* unArray);

/** \brief Recibe una cadena de caracteres y valida que contenga solo numeros y un punto
 *
 * \param unArray char* La cadena de caracteres a validar
 * \return int Si contiene solo numeros y un punto [1] si no [0]
 *
 */
int validarSoloNumerosFlotantes(char* unArray);

/** \brief Recibe una cadena de caracteres y valida que contenga solo letras y espacios
 *
 * \param unArray char* La cadena de caracteres a validar
 * \return int Si contiene solo letras o espacios [1] si no [0]
 *
 */
int validarSoloLetras(char* unArray);

/** \brief Pide una cadena de caracteres y valida que solo contenga numeros
 *
 * \param mensaje char* El El mensaje pidiendo un numero
 * \param unArray char* El array en donde guardar la cadena de caracteres
 * \param mensajeErrorNumeros char* El mensaje de error informando que solo se permiten numeros
 * \param mensajeErrorRango char* El mensaje de error informando el rango del numero permitido
 * \param min int El rango minimo valido
 * \param max int El rango maximo valido
 * \param intentos int La cantidad de intentos
 * \return int Si se agotaron los intentos [0] si se ingreso el dato correctamente [1]
 *
 */
int getStrNumeros(char* mensaje,char* unArray,char* mensajeErrorNumeros,char* mensajeErrorRango,int min,int max,int intentos);

/** \brief Pide una cadena de caracteres y valida que solo contenga numeros y un punto
 *
 * \param mensaje char* El mensaje pidiendo un numero
 * \param unArray char* El array en donde guardar la cadena de caracteres
 * \param mensajeErrorNumeros char* El mensaje de error informando que solo se permiten numeros y un punto
 * \param mensajeErrorRango char* El mensaje de error informando el rango del numero permitido
 * \param min float El rango minimo valido
 * \param max float El rango maximo valido
 * \param intentos int La cantidad de intentos
 * \return int Si se agotaron los intentos [0] si se ingreso el dato correctamente [1]
 *
 */
int getStrNumerosFlotantes(char* mensaje,char* unArray,char* mensajeErrorNumeros,char* mensajeErrorRango,float min,float max,int intentos);

/** \brief Pide una cadena de caracteres y valida que solo contenga numeros sin importar el rango
 *
 * \param mensaje char* El mensaje pidiendo un numero
 * \param unArray char* El array en donde guardar la cadena de caracteres
 * \param mensajeErrorNumeros char* El mensaje de error informando que solo se permiten numeros
 * \param intentos int La cantidad de intentos
 * \return int Si se agotaron los intentos [0] si se ingreso el dato correctamente [1]
 *
 */
int getStrNumerosSinRango(char* mensaje,char* unArray,char* mensajeErrorNumeros,int intentos);

/** \brief Pide una cadena de caracteres y valida que solo contenga letras o espacios
 *
 * \param mensaje char* El mensaje pidiendo una palabra
 * \param unArray char* El array en donde guardar la cadena de caracteres
 * \param mensajeErrorLetras char* El mensaje de error informando que solo se permiten letras
 * \param mensajeErrorRango char* El mensaje de error informando el rango valido de la palabra
 * \param min int El rango minimo valido
 * \param max int El rango maximo valido
 * \param intentos int La cantidad de intentos
 * \return int Si se agotaron los intentos [0] si se ingreso el dato correctamente [1]
 *
 */
int getStrLetras(char* mensaje,char* unArray,char* mensajeErrorLetras,char* mensajeErrorRango,int min,int max,int intentos);

/** \brief Pregunta si se desea confirmar una accion con "s" o "n"
 *
 * \param mensajeInicial char* El mensaje informando que confirme una accion con 's' o 'n'
 * \param mensajeAclaracion char* El mensaje aclarando que solamente se confirma con 's' o con 'n'
 * \return int Si se ingreso 's' [1] si se ingreso 'n' [0] en caso de error [-1]
 *
 */
int confirmarCambios(char* mensajeInicial,char* mensajeAclaracion);

/** \brief Pregunta el genero de una entidad
 *
 * \param mensajeInicial char* El mensaje pidiendo que se elija el genero de la persona con ('m' o 'f')
 * \param mensajeAclaracion char* El mensaje aclarando que solamente se debe elejir la letra 'm' o 'f'
 * \return int Si se ingreso 'm' [1] si se ingreso 'f' [0] en caso de error [-1]
 *
 */
int validarGenero(char* mensajeInicial,char* mensajeAclaracion);
#endif // VALIDACIONES_H_INCLUDED
