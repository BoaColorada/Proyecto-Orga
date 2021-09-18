#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_DECIMAL_SIZE 15
#define TEST_MODE 1

/*
int* cambioBaseEnteros(char* resultado,int* sizeResultado , int* numero,int* sizeNumero,int* baseOrigen, int* baseDestino){

    int* numEnBaseDecimal;

    numEnBaseDecimal = (int*) malloc(sizeof(int) * MAX_DECIMAL_SIZE);


    BaseOrigenADecimal(numEnBaseDecimal,numero,sizeNumero,baseOrigen);

    deBaseDecimalADestino(baseDestino);


    free(numEnBaseDecimal);


    return 0;
}*/

int * deBaseOrigenADecimal(int* resultado, int* numero, int* numeroSize,int* baseOrigen){

    //Declaraci�n variables de tipo elemental
    int i;
    int numeroDePotencia;
    int calcPotencia;
    int digitoAct;

    //Declaraci�n variables de tipo puntero
    int *count;
    int *potencia;
    int *calculoDePotencia;
    int *digitoActual;

    //Inicializaci�n variables de tipo elemental
    i = (*numeroSize)-1;
    numeroDePotencia = 0;
    calcPotencia = 0;
    digitoAct = 0;

    //Inicializaci�n variables de tipo puntero
    count = &i;
    potencia = &numeroDePotencia;
    calculoDePotencia = &calcPotencia;
    digitoActual = &digitoAct;

    //Realiza el c�lculo de cambio de base destino a decimal partiendo desde su d�gito menos
    //significativo
    for( *count; (*count) >= 0 ; (*count)--){

        #ifdef TEST_MODE
            printf( "Count: %i \n" , *count);
        #endif

        //Representa el d�gito actual recuperado del arreglo numero con el que realizar el calculo
        //del m�todo de la multiplicaci�n
        digitoActual = numero+(*count);

        #ifdef TEST_MODE
            printf( "digitoActual: %i \n" , *digitoActual);
        #endif

        #ifdef TEST_MODE
            printf( "potencia: %i \n" , *potencia);
        #endif

        //Realiza el c�lculo de la potencia por la que se multiplicar� el digitoActual
        *calculoDePotencia = pow(*baseOrigen, *potencia);

        #ifdef TEST_MODE
            printf( "calculoDePotencia: %i \n" , *calculoDePotencia);
        #endif

        //Suma el valor del d�gitoActual en base 10 al resultado
        *resultado += (*digitoActual) * (*calculoDePotencia);

        #ifdef TEST_MODE
            printf( "resultado: %i \n" , *resultado);
            printf( "////////////////////// \n");
        #endif

        //Por cada d�gito procesado, aumenta en 1 la potencia
        (*potencia)++;

    }

    return 0;
}
/*
int* deBaseDecimalADestino(int* resultado ,int* baseDestino){

    return 0;
}*/
