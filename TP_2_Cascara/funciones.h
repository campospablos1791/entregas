#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct {

    char nombre[50];
    char edad[10];
    int estado;
    char dni[20];

}EPersona;

/**
 * Obtiene el primer indice libre del array.
 * @param lista el array se pasa como parametro.
 * @return el primer indice disponible
 */
int obtenerEspacioLibre(EPersona lista[], int cantidad, int valor);

/**
 * Obtiene el indice que coincide con el dni pasado por parametro.
 * @param lista el array se pasa como parametro.
 * @param dni el dni a ser buscado en el array.
 * @return el indice en donde se encuentra el elemento que coincide con el parametro dni
 */
int buscarPorDni(EPersona lista[], char valor[], int cantidad);

void getString(char mensaje[],char input[]);
int getStringLetras(char mensaje[],char input[]);
int esSoloLetras(char str[]);
int esNumerico(char str[]);
int getStringNumeros(char mensaje[],char input[]);
int ordenar(EPersona lista[], int cantidad);
/*int ordenar(EPersona lista[], int cantidad, char buffer);*/

#endif // FUNCIONES_H_INCLUDED


/*void inicializar(Epersona lista[], int valor, int cantidad);*/  //error.. e

