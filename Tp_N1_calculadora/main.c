/************************************************************************

*Programa: Calculadora
*
*Objetivo:
    Ingresar 2 numeros y calcular: - Suma
                                   - Resta
                                   - Multiplicacion
                                   - Division
                                   - Factorial

* Version: 0.1 del 7 de abril de 2017
* Autor: Campos Pablo Sebastian
*

*************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "funciones_calculadora.h"
#include <conio.h>

int main()
{
    char salir='n';
    int resFac, opcion=0;
    float num1, num2, resultado;

   while(salir=='n')
    {
        system("cls");
        printf("1- Ingresar 1er operando (A= %.2f)\n", num1);
        printf("2- Ingresar 2do operando (B= %.2f)\n", num2);
        printf("3- Calcular la suma (A+B)\n");
        printf("4- Calcular la resta (A-B)\n");
        printf("5- Calcular la division (A/B)\n");
        printf("6- Calcular la multiplicacion (A*B)\n");
        printf("7- Calcular el factorial (A!)\n");
        printf("8- Calcular todas las operaciones\n");
        printf("9- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                printf("ingrese numero A ");
                scanf("%f", &num1);
                break;
            case 2:
                printf("ingrese nummero B ");
                scanf("%f", &num2);
                break;
            case 3:
                printf("la suma es: %.2f\n", resultado=suma(num1, num2));
                break;
            case 4:
                printf("la resta es: %.2f\n", resultado=resta(num1, num2));
                break;
            case 5:
                while(num2 == 0)
                {
                    printf("imposible dividir por 0, ingrese otro numero ");
                    scanf("%f", &num2);
                }
                printf("la division es: %.2f", resultado=dividir(num1, num2));
                break;
            case 6:
                printf("la multiplicacion es: %.2f", resultado=multiplicar(num1, num2));
                break;
            case 7:
                printf("el factorial de A es: %d", resFac= factorial(num1));
                getch();
                break;
            case 8:
                printf("la suma es: %.2f\n", resultado=suma(num1, num2));
                printf("la resta es: %.2f\n", resultado=resta(num1, num2));
                while(num2 == 0)
                {
                    printf("imposible dividir por 0, ingrese otro numero ");
                    scanf("%f", &num2);
                }
                printf("la division es: %.2f\n", resultado=dividir(num1, num2));
                printf("la multiplicacion es: %.2f\n", resultado=multiplicar(num1, num2));
                printf("el factorial de A es: %d\n", resFac= factorial(num1));
                break;
            case 9:
                printf("SALIR?, s/n");
                fflush(stdin);
                scanf("%c", &salir);
                break;
            default:
                printf("opcion no valida, reingrese operacion");
                break;
        }
        getch(); //El getch() sirve para darle una pausa hasta que el usuario presiona una tecla. Para poder usarla incluir la libreria conio.h
    }
    return 0;
}


