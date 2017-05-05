#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <strings.h>
#include "validaciones.h"
#include "estructuras.h"
#include "cargaYEdicion.h"

int getInt(char mensaje[])
{
    int entero;
    printf("%s",mensaje);
    scanf("%d",&entero);
    return entero;
}

float getFloat(char mensaje[])
{
    float flotante;
    printf("%s",mensaje);
    scanf("%f",&flotante);
    return flotante;
}
char getChar(char mensaje[])
{
    char caracter;
    printf("%s",mensaje);
    fflush(stdin); // Win
    // fpurge(stdin); //Linux y OSx
    scanf("%c",&caracter);
    return caracter;
}

int getNumeroAleatorio(int desde, int hasta, int iniciar)/////////////////////////////
{
    /***chequear**/
    if(iniciar)
        srand (time(NULL));
    return desde + (rand() % (hasta + 1 - desde)) ;
}

void getString(char mensaje[],char arrayChar[])
{
    printf("%s",mensaje);
    scanf("%s",arrayChar);
}

int getNumerosChar (char array[],char mensaje[])
{
    getString(mensaje,array);
    if(esNumeroChar(array))
        {
            return 1;
        }
        return 0;
}
                        /**
 * \brief Solicita un texto al  y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return 1 si el texto contiene solo letras
 */
int getStringLetras(char mensaje[],char input[])
{
    getString(mensaje,input);
    if(esSoloLetras(input))
    {
        return 1;
    }
    return 0;
}

/**
 * Obtiene el primer indice libre del array.
 * @param lista el array se pasa como parametro.
 * @return el primer indice disponible
 */
int obtenerEspacioLibre(EPersona lista[], int cantidad_elementos, int estado)
{
    int i;
    for(i=0; i < cantidad_elementos; i++)
    {
        if(lista[i].estado==estado)
        {
            return i;
        }
    }
    return -1;
}
void inicializarListaDeUsuario(EPersona lista[],int cantidad,int estado)
{
    int i;
    for(i=0; i<cantidad; i++)
    {
        lista[i].estado=estado;
    }
}

/*int buscarPorDni(EPersona lista[], int cantidad,char dni[])
{
    int i;
    for(i=0; i<cantidad; i++)
    {
        if(strcmp(lista[i].dni,dni)==0)
            return i;
    }
    return -1;
}*/

int buscarPorusuario(EPersona lista[], int cantidad,char usuario[])
{
    int retorno=-1;
    int i;
    for(i=0; i<cantidad; i++)
    {
        if((strcmp(lista[i].usuario,usuario)==0) && lista[i].estado==1)
        {
            retorno=i;
            break;
        }

    }

    return retorno;
}

int obtenerEspacioLibrePublicacion(EPublicaciones lista[], int cantidad_elementos, int estado)
{
    int i;
    for(i=0; i < cantidad_elementos; i++)
    {
        if(lista[i].estado==estado)
        {
            return i;
        }
    }
    return -1;
}

void inicializarListaDePublicacion(EPublicaciones lista[],int cantidad,int estado)
{
    int i;
    for(i=0; i<cantidad; i++)
    {
        lista[i].estado=estado;
    }
}

int buscarPorId(EPersona lista[], int cantidad,int valor)
{
    int retorno=-1;
    int i;
    for(i=0; i<cantidad; i++)
    {
        if((lista[i].id== valor) && lista[i].estado==1)
        {
            retorno=i;
            break;
        }

    }

    return retorno;
}

int buscarPorIdPublicacion(EPublicaciones lista[], int cantidad,int valor)
{
    int retorno=-1;
    int i;
    for(i=0; i<cantidad; i++)
    {
        if((lista[i].idPublicaion== valor) && lista[i].estado==1)
        {
            retorno=i;
            break;
        }

    }

    return retorno;
}

/*int sortEmployeeByNameAndLastname(EPersona listaUsuarios[], int length, int order)
{
    // order==1 es descendente y order==0 es ascendente
    int i;
    int retorno = -1;
    int flagSwap;
    EPersona auxiliar;

    if(listaUsuarios != NULL && length > 0)
    {
        retorno = 0;
        do
        {
            flagSwap = 0;
            for(i=0; i<length-1; i++)
            {
                if(strcmp(listaUsuarios[i].nombre,listaUsuarios[i+1].nombre)==0 && order == 1)
                {
                    //flagSwap= 0;
                    if(strcmp(listaUsuarios[i].apellido,listaUsuarios[i+1].apellido)> 0 && order == 1 )
                    {
                        auxiliar = listaUsuarios[i];
                        listaUsuarios[i] = listaUsuarios[i+1];
                        listaUsuarios[i+1] = auxiliar;
                        //flagSwap = 1;
                    }
                }
                else
                {
                    if(strcmp(listaUsuarios[i].nombre,listaUsuarios[i+1].nombre)==0 && order == 0)
                    {
                        flagSwap= 0;
                        if(strcmp(listaUsuarios[i].apellido,listaUsuarios[i+1].apellido)< 0 && order == 0 )
                        {
                            auxiliar = listaUsuarios[i];
                            listaUsuarios[i] = listaUsuarios[i+1];
                            listaUsuarios[i+1] = auxiliar;
                            flagSwap = 1;
                        }
                    }
                }
            }

        } while(flagSwap);
    }return retorno;
}
*/
