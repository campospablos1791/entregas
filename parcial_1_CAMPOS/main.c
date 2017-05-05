#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#define CANT 100
#define CANTPRODUCTOS 1000
#include "validaciones.h"
#include "cargaYEdicion.h"
#include "estructuras.h"



int main()
{

    EPersona listaUsuarios[CANT];
    EPublicaciones publicaciones[CANTPRODUCTOS];

    inicializarListaDeUsuario(listaUsuarios, CANT, 0); //O INDICA QUE ESTA VACIO
    inicializarListaDePublicacion(publicaciones, CANTPRODUCTOS, 0);

    char seguir='s';
    int opcion='0';
    int i;
    int IndiceLibreUsuario;
    char auxNombre[50];
    char auxUsuario[50];
    char auxClave[50];
    int contID=0;
    int idUsuario;
    int idPublic;
    int idEncontrado;
    int IndiceLibrePublicacion;
    char nuevaPublic[255];
    int auxPrecio;
    int auxStock;
    int contVentas=0;

    /*int lugarLibrePersonaas;
    char auxNonbre[30];
    char auxNick[30];
    char auxClave[30];
    char auxEmail[30];
    int contID=0;
    int nickEncontrado;
    int posNick;
    int lugarLibreCom;
    char nuevoCom[255];
    int contCom=0;*/

    do
    {

        printf("ALTA Y BAJA DE DATOS PERSONALES.\n\n");
        printf("1- ALTA DE USUARIO\n");
        printf("2- MODIFICAR DATOS DE USUARIO\n");
        printf("3- BAJA DE USUARIO\n");
        printf("4- PUBLICAR PRODUCTO\n");
        printf("5- MODIFICAR PUBLICACION\n");
        printf("6- CANCELAR PUBLICACION\n");
        printf("7- COMPRAR PRODUCTO\n");
        printf("8- LISTAR PUBLICACION DE USUARIO\n");
        printf("9- LISTAR PUBLICACIONES\n");
        printf("10- LISTAR USUARIOS\n");
        printf("11- SALIR\n");


        scanf("%d",&opcion);
        //opcion=getchar();
        switch(opcion)
        {
        case 1:
            IndiceLibreUsuario=obtenerEspacioLibre(listaUsuarios, CANT, 0);
            if(IndiceLibreUsuario!=-1)
            {
                if(!getStringLetras("ingrese nombre: ",auxNombre))
                {
                    printf("solo puede ingresar letras\n");
                }
                if(!getStringLetras("ingrese usuario: ",auxUsuario))
                {
                    printf("solo puede ingresar letras\n");
                }
                if(!getStringLetras("ingrese clave: ",auxClave))
                {
                    printf("solo puede ingresar letras\n");
                }
            }
                strcpy(listaUsuarios[IndiceLibreUsuario].nombre, auxNombre);
                strcpy(listaUsuarios[IndiceLibreUsuario].usuario, auxUsuario);
                strcpy(listaUsuarios[IndiceLibreUsuario].clave, auxClave);
                listaUsuarios[IndiceLibreUsuario].estado=1;
                listaUsuarios[IndiceLibreUsuario].id=contID;
                contID++;
            break;

        case 2:
                idUsuario=getInt("ingrese ID\n");
                idEncontrado=buscarPorId(listaUsuarios,CANT, idUsuario);
                opcion=getChar("Ingrese la opcion a modificar, \n\n 1-Nombre.\n 2-Usuario. \n 3-Clave.\n");
                    switch(opcion)
                    {
                        case '1':
                            getStringLetras("Ingrese el nombre nuevo: ",auxNombre);
                            strcpy(listaUsuarios[idEncontrado].nombre, auxNombre);
                        break;

                        case '2':
                            getStringLetras("Ingrese nuevo usuario: ", auxUsuario);
                            strcpy(listaUsuarios[idEncontrado].usuario, auxUsuario);
                        break;

                        case '3':
                            getStringLetras("Ingrese la nueva clave: ", auxClave);
                            strcpy(listaUsuarios[idEncontrado].clave, auxClave);
                        break;

                        default : printf("Error. Opcion incorrecta.");
                        break;
                    }
            break;

        case 3:
            idUsuario=getInt("ingrese ID\n");
            idEncontrado=buscarPorId(listaUsuarios,CANT, idUsuario);
            listaUsuarios[idEncontrado].estado=0;
            break;

        case 4:
            IndiceLibrePublicacion=obtenerEspacioLibrePublicacion(publicaciones, CANTPRODUCTOS, 0);
            if(IndiceLibrePublicacion!=-1)
            {
                idUsuario=getInt("ingrese ID\n");
            }
            idEncontrado=buscarPorId(listaUsuarios, CANT, idUsuario);
            if(listaUsuarios[idEncontrado].id==idUsuario)
            {
                publicaciones[IndiceLibrePublicacion].idPublicaion=listaUsuarios[idEncontrado].id;
                getString("NOMBRE PUBLICACION: ", nuevaPublic);
                auxPrecio=getInt("ingrese precio\n");
                auxStock=getInt("ingrese stock\n");
            }

            strcpy(publicaciones[IndiceLibrePublicacion].nombrePublicacion, nuevaPublic);
            publicaciones[IndiceLibrePublicacion].precio=auxPrecio;
            publicaciones[IndiceLibrePublicacion].stock=auxStock;
            publicaciones[IndiceLibrePublicacion].estado=1;

            printf("NOMBRE\tPRECIO\tSTOCK\n");
            for(i=0; i<CANT; i++)
            {
                if(publicaciones[i].estado==1)
                {
                    printf("%s\t%d\t%d\n", publicaciones[i].nombrePublicacion, publicaciones[i].precio, publicaciones[i].stock);
                }
            }
            break;

        case 5:
            idUsuario=getInt("ingrese ID\n");
                idEncontrado=buscarPorId(listaUsuarios,CANT, idUsuario);
                printf("ID\tNOMBRE\tPRECIO\tVENDIDOS\tSTOCK\n");
            for(i=0; i<CANT; i++)
            {
                if(publicaciones[i].estado==1)
                {
                    printf("%d\t%s\t%d\t%d\n", publicaciones[i].idPublicaion, publicaciones[i].nombrePublicacion, contVentas, publicaciones[i].stock);
                    idPublic=getInt("ingrese ID de la publicacion\n");
                    idEncontrado=buscarPorIdPublicacion(publicaciones,CANT, idPublic);
                    opcion=getChar("Ingrese la opcion a modificar, \n\n 1-PRECIO.\n 2-STOCK. \n");
                    switch(opcion)
                    {
                        case '1':
                            auxPrecio=getInt("Ingrese el precio: ");
                            publicaciones[idEncontrado].precio= auxPrecio;
                        break;

                        case '2':
                            auxStock=getInt("Ingrese el stock: ");
                            publicaciones[idEncontrado].stock= auxStock;
                        break;
                        default : printf("Error. Opcion incorrecta.");
                        break;
                    }
                }
            }
            break;

        case 6:
            idPublic=getInt("ingrese ID publicacion\n");
            idEncontrado=buscarPorIdPublicacion(publicaciones,CANTPRODUCTOS, idPublic);
            if(idEncontrado!=-1 )
                {
                    printf("%s", publicaciones[idEncontrado].nombrePublicacion);
                }
            publicaciones[idEncontrado].estado=0;
            break;

        case 7:
            idPublic=getInt("ingrese ID de la publicacion\n");
            idEncontrado=buscarPorIdPublicacion(publicaciones,CANTPRODUCTOS, idPublic);
            if(idEncontrado==1 && publicaciones[idEncontrado].stock>0)
            {
                contVentas++;
            }
            break;

        case 8:
            printf("ID\tNOMBRE\tPRECIO\tVENDIDOS\tSTOCK\n");
            idPublic=getInt("ingrese ID de la publicacion\n");
            idEncontrado=buscarPorIdPublicacion(publicaciones,CANTPRODUCTOS, idPublic);
            if(idEncontrado!=-1)
            {
                for(i=0;i<CANT;i++)
                {
                    if(idEncontrado==idPublic)
                    {
                      printf("%d\t%s\t%d\t%d\t%d\t%s\n", publicaciones[i].idPublicaion, publicaciones[i].nombrePublicacion, publicaciones[i].precio, publicaciones[i].stock);
                    }

                }
            }

            break;
        case 9:
            printf("ID\tNOMBRE\tPRECIO\tVENDIDOS\tSTOCK\tNOMBRE USUARIO\n");
            for(i=0;i<CANTPRODUCTOS; i++)
            {
                if(publicaciones[i].idPublicaion==1)

                {
                    printf("%d\t%s\t%d\t%d\t%d\n", publicaciones[i].idPublicaion, publicaciones[i].nombrePublicacion, publicaciones[i].precio, publicaciones[i].stock, listaUsuarios[i].nombre);
                }

            }
            break;
        case 10:
            printf("nombre\tusuario\tclave\tID\n");
            for(i=0; i<CANT; i++)
            {
                if(listaUsuarios[i].estado==1)
                {
                   printf("%s\t%s\t%s\t%d\n",listaUsuarios[i].nombre, listaUsuarios[i].usuario, listaUsuarios[i].clave, listaUsuarios[i].id);
                }
            }
            break;
        case 11:
            seguir = 'n';
            break;

        default :
            printf("Opcion incorrecta.\n");
            break;
        }

        //system("cls");
    }
    while(seguir=='s');
    return 0;
}
