#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "funciones.h"
#define MAXIMO 20

int main()
{
    EPersona listado[MAXIMO];
    EPersona auxiliar;
    char seguir='s';
    int opcion;
    char auxiliarNombre[20];
    char auxiliarEdad[10];
    char auxiliarDni[20];
    int i,j, indiceLibre, dniBuscado;
    int menor18 =0;
    int mayor18menor35=0;
    int mayor35=0;

    for(i=0; i<MAXIMO; i++)
    {
        listado[i].estado=0;
    }

    while(seguir=='s')
    {
        printf("\n1- Agregar persona\n");
        printf("2- Borrar persona\n");
        printf("3- Imprimir lista ordenada por  nombre\n");
        printf("4- Imprimir grafico de edades\n\n");
        printf("5- Salir\n");

        scanf("%d",&opcion);
        system("cls");

        switch(opcion)
        {
        case 1:
            indiceLibre=obtenerEspacioLibre(listado, MAXIMO, 0);
            if(indiceLibre==-1)
            {
                printf("No hay espacio libre\n");
                break;
            }
            printf("INGRESAR PERSONAL AL SISTEMA\n");
            if(!getStringLetras("ingrese nombre: ", auxiliarNombre))
            {
                printf("el nombre debe contener solo letras\n");
                break;
            }

            if(!getStringNumeros("Edad: ", auxiliarEdad))
            {
                printf("Ingrese solo valores numericos\n");
                break;
            }

            if(!getStringNumeros("DNI: ", auxiliarDni))
            {
                printf("Ingrese solo valores numericos\n");
                break;
            }
            strcpy(listado[indiceLibre].nombre, auxiliarNombre);
            strcpy(listado[indiceLibre].edad, auxiliarEdad);
            strcpy(listado[indiceLibre].dni, auxiliarDni);
            listado[indiceLibre].estado=1;

            break;
        case 2:
            printf("DAR DE BAJA\n");
            if(!getStringNumeros("DNI: ", auxiliarDni))
            {
                printf("Ingrese solo valores numericos\n");
                listado[dniBuscado].estado=0;
                break;
            }
            dniBuscado=buscarPorDni(listado, auxiliarDni, MAXIMO);

            if(dniBuscado == listado[dniBuscado].dni)
            {
                printf("Dni inexistente\n");
                break;
            }
            listado[dniBuscado].estado=0;
            printf("Personal dado de baja\n");
            break;

        case 3:
            printf("PERSONAL ORDENADO POR NOMBRE\n\n");
            printf("NOMBRE\t EDAD\t DNI\n");
            printf("_______________________\n");
            for(i=0 ; i<MAXIMO-1; i++)
            {
                for(j=i+1; j>0 ; j--)
                {
                    if((stricmp(listado[j].nombre,listado[j-1].nombre))<0)
                    {
                        auxiliar = listado[j];
                        listado[j] = listado[j-1];
                        listado[j-1] = auxiliar;
                    }
                }
            }
            for(i=0; i<MAXIMO; i++)
            {
                if(listado[i].estado==1)
                    printf("%s\t %s\t %s\n", listado[i].nombre, listado[i].edad, listado[i].dni);
            }
            break;

        case 4:
            printf("GRAFICO DE BARRAS\n");
            for(i=0; i<MAXIMO ; i++)
            {
                if(listado[i].estado==0)
                {
                    continue;
                }
                if(atoi(listado[i].edad)<18)
                {
                    menor18++;
                }
                else if(atoi(listado[i].edad)>35)
                {
                    mayor35++;
                }
                else
                {
                    mayor18menor35++;
                }
                printf("\n");

            }
            printf("\t%d\t\t %d\t\t %d\n", menor18, mayor18menor35, mayor35);
            printf("\t<18\t\t 18-35\t\t >35");
            break;

        case 5:
            seguir = 'n';
            break;
        }
    }

    return 0;
}


