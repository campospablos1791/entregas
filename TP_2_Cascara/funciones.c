#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"


/**
 * \brief Solicita un texto al usuario y lo devuelve
 * \param mensaje: Es el mensaje que se quiere mostrar.
 * \param input Array donde se cargará el texto ingresado (auxiliar)
 * \return nada (void)
 */
void getString(char mensaje[],char input[])
{
    printf("%s",mensaje);
    scanf ("%s", input);
}

/**
 * \brief Verifica si el valor recibido contiene solo letras
 * \param str Array con la cadena a ser analizada (analiza la cadena de caracteres)
 * \return 1 si contiene solo ' ' y letras y 0 si contine algun otro simbolo/numero,etc
 *
 */
int esSoloLetras(char str[])
{
    int i=0;
    while(str[i] != '\0')
    {
        if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
            return 0;
        i++;
    }
    return 1;
}

/**
 * \brief Solicita un texto al usuario y lo devuelve
 * \param mensaje Es el mensaje que se quiere mostrar.
 * \param input Array donde se cargará el texto ingresado (auxiliar)
 * \return 1 si el texto contiene solo letras
 */
int getStringLetras(char mensaje[],char input[])
{
    char aux[256];
    getString(mensaje,aux);  /*llama a la funcion getstring para mostrar mensaje*/
    if(esSoloLetras(aux))    /*llama a la funcion esSoloLetras para validar*/
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}

int obtenerEspacioLibre(EPersona lista[], int cantidad, int valor)
{
    int i;
    for(i=0 ; i<cantidad ; i++)
    {
        if(lista[i].estado==valor)
            return i;
    }
    return -1;
}

/**
 * \brief Verifica si el valor ingresado es un numero
 * \param str Array con la cadena a ser analizada
 * \return 1 si es número y 0 si no es numero
 *
 */

int esNumerico(char str[])
{
    int i=0;
    while(str[i]!= '\0')
    {
        if(str[i] < '0' || str[i] > '9')
        {
            return 0;
        }

        i++;
    }
    return 1;
}

/**
 * \brief Solicita un texto numérico al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return 1 si el texto contiene solo números
 */
int getStringNumeros(char mensaje[],char input[])
{
    char aux[256];
    getString(mensaje,aux);
    if(esNumerico(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}

int buscarPorDni(EPersona lista[], char valor[], int cantidad)
{
    int i;
    for(i=0 ; i<cantidad ; i++)
    {
       if((strcmp(lista[i].dni,valor)==0))
       {
            return i;
       }
    }
    return -1;
}


/*int ordenar(EPersona lista[], int cantidad, char buffer)
{

    int i, j;
    for(i=0; i<cantidad-1 ; i++)
    {
        if(EPersona[i].nombre == -1)
        {
            continue;
        }
        for(j=i+1; j<cantidad; j++)
        {
            if(lista[j].nombre == -1)
            {
                continue;
            }
            if(strcmp(lista[i].nombre, lista[j].nombre) > 0)
            {
                buffer = lista[j];
                lista[j] = lista[i];
                lista[i] = buffer;
            }
        }
    }
    break;
}*/




/*void inicializar(Epersona lista[], int valor, int cantidad)
        {
            int i;
            for(i=0; i<cantidad; i++)
            {
                lista[i].estado=valor;
            }
        }*/


