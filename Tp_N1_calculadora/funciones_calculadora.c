#include <stdio.h>
#include <stdlib.h>

float suma(float dato1, float dato2) //toma 2 valores ingresados por el usuario (dato1 y dato2)
{                                    // y los suma, devuelve un resultado float, c/decimal si es necesario.
    float resultado;                 // lo mismo con todas las operaciones
    resultado=dato1 + dato2;
    return resultado;
}


float resta(float dato1, float dato2)

{
    float resultado;
    resultado=dato1 - dato2;
    return resultado;
}


float dividir(float dato1, float dato2)

{
    float resultado;
    resultado=dato1 / dato2;
    return resultado;
}


float multiplicar(float dato1, float dato2)

{
    float resultado;
    resultado=dato1*dato2;
    return resultado;
}


int factorial(int dato)

{
    int i, resultado=1;                 //se unicia resultado en 1 para que cuando lo multipliquemos * i no nos de 0

        for (i=1; i <= dato; i++)       // se inicia i en 1, el for corre siempre y cuando i sea <= al dato ungresado
        {
         resultado= resultado * i;      // resultado va cambiando a medida que incrementa i
        }
        return resultado;
}
