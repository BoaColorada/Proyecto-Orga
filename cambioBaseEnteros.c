#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "representacionNumeroEnBase.h"
#define TEST_MODE 1


int * deBaseOrigenADecimalEntero(int* resultado, int* numero, int* numeroSize,int* baseOrigen){

    //DECLARACIÓN PUNTEROS
    int *count;
    int *potencia;
    int *calculoDePotencia;
    int *digitoActual;

    //ASIGNACIÓN DE MEMORIA DINÁMICA CON MALLOC
    count = (int *) malloc(sizeof(int));
    potencia = (int *) malloc(sizeof(int));
    calculoDePotencia = (int *) malloc(sizeof(int));
    digitoActual = (int *) malloc(sizeof(int));

    //INICIALIZACIÓN VARIABLES
    *count = (*numeroSize)-1;
    *potencia = 0;
    *calculoDePotencia = 0;
    *digitoActual = 0;

    #ifdef TEST_MODE

        printf("\n ------------- INICIO METODO deBaseOrigenADecimal ------------- \n");

        printf("\nParametro resultado Inicial: \n");
        printf("%i \n", *resultado);
        printf("\n");

        printf("\nParametro numero Inicial: \n");
        for(int i=0; i<*numeroSize; i++){
            printf("%i ... ", *(numero+i));
        }
        printf("\n");

        printf("\nParametro numeroSize Inicial: \n");
        printf("%i \n", *numeroSize);
        printf("\n");

        printf("\nParametro baseOrigen Inicial: \n");
        printf("%i \n", *baseOrigen);
        printf("\n");

    #endif // TEST_MODE

    //Realiza el cálculo de cambio de base destino a decimal partiendo desde su dígito menos
    //significativo
    for( *count = (*numeroSize)-1 ; (*count) >= 0 ; (*count)--){

        #ifdef TEST_MODE
            printf( "Count: %i \n" , *count);
        #endif

        //Representa el dígito actual recuperado del arreglo numero con el que realizar el calculo
        //del método de la multiplicación
        digitoActual = numero+(*count);

        #ifdef TEST_MODE
            printf( "digitoActual: %i \n" , *digitoActual);
        #endif

        #ifdef TEST_MODE
            printf( "potencia: %i \n" , *potencia);
        #endif

        //Realiza el cálculo de la potencia por la que se multiplicará el digitoActual
        *calculoDePotencia = pow(*baseOrigen, *potencia);

        #ifdef TEST_MODE
            printf( "calculoDePotencia: %i \n" , *calculoDePotencia);
        #endif

        //Suma el valor del dígitoActual en base 10 al resultado
        *resultado = *resultado +( (*digitoActual) * (*calculoDePotencia) );

        #ifdef TEST_MODE
            printf( "resultado: %i \n" , *resultado);
            printf( "////////////////////// \n");
        #endif

        //Por cada dígito procesado, aumenta en 1 la potencia
        (*potencia)++;

    }

    #ifdef TEST_MODE
        printf("\n ------------- FINAL METODO deBaseOrigenADecimal ------------- \n");
    #endif

    free(count);
    free(potencia);
    free(calculoDePotencia);
    free(digitoActual);

    return 0;
}


int * deBaseDecimalADestinoEntero(int* resultado, int* resultadoSize , int* baseDestino, int *numero){

    //DECLARACIÓN PUNTEROS
    int *cociente;
    int *resto;
    int *counter;

    //ASIGNACIÓN DE MEMORIA DINÁMICA CON MALLOC
    cociente = (int *) malloc(sizeof(int));
    resto = (int *) malloc(sizeof(int));
    counter = (int *) malloc(sizeof(int));

    //INICIALIZACIÓN VARIABLES
    *cociente = *numero;
    *resto = 0;
    *counter = (*resultadoSize) - 1;


    #ifdef TEST_MODE

        printf("\n ------------- INICIO METODO deBaseDecimalADestino ------------- \n");

        printf("\nParametro resultado Inicial: \n");
        for(int i=0; i<*resultadoSize; i++){
            printf("%i ... ", *(resultado+i));
        }

        printf("\nParametro resultadoSize Inicial: \n");
        printf("%i \n", *resultadoSize);
        printf("\n");

        printf("\nParametro baseDestino Inicial: \n");
        printf("%i \n", *baseDestino);
        printf("\n");

        printf("\nParametro numero Inicial: \n");
        printf("%i \n", *numero);
        printf("\n");

    #endif // TEST_MODE


    while( *cociente != 0 ){

        *resto = (*cociente) % (*baseDestino);

        #ifdef TEST_MODE
            printf( "Resto: %i \n" , *resto);
        #endif

        *(resultado + *counter) = *resto;

        #ifdef TEST_MODE
            printf( "Resultado en posicion %i: %i \n" , *counter, *(resultado + *counter));
        #endif

        *cociente = (*cociente) / (*baseDestino);

        #ifdef TEST_MODE
            printf( "Cociente: %i \n" , *cociente);
        #endif

        (*counter)--;

        #ifdef TEST_MODE
            printf( "Counter: %i \n" , *counter);
        #endif

        #ifdef TEST_MODE
            printf( "////////////////////// \n");
        #endif
    }

    #ifdef TEST_MODE
        printf("\n ------------- FINAL METODO deBaseDecimalADestino ------------- \n");
    #endif

    free(cociente);
    free(resto);
    free(counter);

    return 0;
}


int * cambioBaseEnteros(char* resultado,int* sizeResultado , char* numero, int* sizeNumero,int* baseOrigen, int* baseDestino){

    #ifdef TEST_MODE
        printf("\n Parametro resultado Inicial: \n");
        for(int i=0; i<*sizeResultado; i++){
            printf("%c ... ", *(resultado+i));
        }
        printf("\n");

        printf("\n Parametro sizeResultado Inicial: \n");
        printf("%i \n", *sizeResultado);

        printf("\n Parametro numero Inicial: \n");
        for(int i=0; i<*sizeNumero; i++){
            printf("%c ... ", *(numero+i));
        }
        printf("\n");

        printf("\n Parametro sizeNumero Inicial: \n");
        printf("%i \n", *sizeResultado);

        printf("\n Parametro baseOrigen Inicial: \n");
        printf("%i \n", *baseOrigen);

        printf("\n Parametro baseDestino Inicial: \n");
        printf("%i \n", *baseDestino);
    #endif

    //DECLARACIÓN PUNTEROS
    int *numeroRepresentadoEnArregloDeEnteros;
    int *numeroEnBaseDecimal;
    int *numeroEnBaseDestinoRepresentadoEnDecimal;
    int *i;

    //INICIALIZACIÓN DE MEMORIA Y VARIABLES CON MALLOC

    numeroRepresentadoEnArregloDeEnteros = (int*) malloc(sizeof(int) * (*sizeResultado));

    numeroEnBaseDecimal = (int*) malloc(sizeof(int));

    numeroEnBaseDestinoRepresentadoEnDecimal = (int*) malloc(sizeof(int) * (*sizeResultado));

    i = (int*) malloc(sizeof(int));

    //INICIALIZACIÓN DE VARIABLES

    *i = 0;

    for(*i = 0; *i<*sizeResultado; (*i)++){
        *(numeroRepresentadoEnArregloDeEnteros+*i) = 0;
    }

    *numeroEnBaseDecimal = 0;

    for(*i = 0; *i<*sizeResultado; (*i)++){
        *(numeroEnBaseDestinoRepresentadoEnDecimal+*i) = 0;
    }


    //OPERACIONES
    obtenerRepresentacionEnBaseDiez(numeroRepresentadoEnArregloDeEnteros, sizeResultado, numero, sizeResultado);

    #ifdef TEST_MODE
        printf("\n -_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_ \n");
        printf("\n RESULTADO obtenerRepresentacionEnBaseDiez: \n");
        for(*i=0; *i<*sizeResultado; (*i)++){
            printf("%i ... ", *(numeroRepresentadoEnArregloDeEnteros+*i));
        }
        printf("\n -_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_ \n");
        printf("\n");
    #endif // TEST_MODE



    deBaseOrigenADecimalEntero(numeroEnBaseDecimal, numeroRepresentadoEnArregloDeEnteros, sizeResultado, baseOrigen);

    #ifdef TEST_MODE
        printf("\n -_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_ \n");
        printf("\n RESULTADO deBaseOrigenADecimal: \n");
        printf("%i ... ", *(numeroEnBaseDecimal));
        printf("\n -_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_ \n");
        printf("\n");
    #endif // TEST_MODE

    deBaseDecimalADestinoEntero(numeroEnBaseDestinoRepresentadoEnDecimal, sizeResultado, baseDestino, numeroEnBaseDecimal);

    #ifdef TEST_MODE
        printf("\n -_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_ \n");
        printf("\n RESULTADO deBaseDecimalADestino: \n");
        for(*i=0; *i<*sizeResultado; (*i)++){
            printf("%i ... ", *(numeroEnBaseDestinoRepresentadoEnDecimal+*i));
        }
        printf("\n -_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_ \n");
        printf("\n");
    #endif // TEST_MODE

    obtenerRepresentacionEnBaseCorrespondiente(resultado, sizeResultado, numeroEnBaseDestinoRepresentadoEnDecimal, sizeResultado);

    #ifdef TEST_MODE
        printf("\n -_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_ \n");
        printf("\n RESULTADO obtenerRepresentacionEnBaseCorrespondiente: \n");
        for(*i=0; *i<*sizeResultado; (*i)++){
            printf("%c ... ", *(resultado+*i));
        }
        printf("\n -_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_ \n");
        printf("\n");
    #endif // TEST_MODE



    //LIBERACIÓN DE MEMORIA
    free(i);
    free(numeroRepresentadoEnArregloDeEnteros);
    free(numeroEnBaseDecimal);
    free(numeroEnBaseDestinoRepresentadoEnDecimal);

    return 0;
}

