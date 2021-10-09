
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "representacionNumeroEnBase.h"

//Dada una fracción expresada como un arreglo de enteros "numero" de tamaño "numeroSize" en base "baseOrigen"
//efectúa el cambio de base de la base "baseOrigen" a la base decimal y lo almacena en "resultado".
int * deBaseOrigenADecimalFraccionario(float * resultado, int * numero, int * numeroSize, int * baseOrigen ){

    //Declaración variables tipo puntero
    int *count;
    int *potencia;
    float *calculoDePotencia;

    //Inicialización memoria variables

    count = (int*) malloc(sizeof(int));
    potencia = (int*) malloc(sizeof(int));
    calculoDePotencia = (float*) malloc(sizeof(float));

    //Inicialización de variables

    *count = 0;
    *potencia = -1;
    *calculoDePotencia = 0;

    for(*count = 0; *count < *numeroSize; (*count)++){

        *calculoDePotencia = pow(*baseOrigen, *potencia);

        *resultado = *resultado + (*calculoDePotencia) * (*numero);

        (*potencia)--;

        numero++;

    }

    free(count);
    free(potencia);
    free(calculoDePotencia);

    return 0;
}

int * deBaseDecimalADestinoFraccionario(int * resultado, int * resultadoSize, float * numero, int * baseDestino){

    //Declaración variables tipo puntero
    int *count;
    double *parteEnteraOperacion;
    double *parteFraccionariaOperacion;
    double *resultadoMultiplicacion;

    //Inicialización memoria variables
    count = (int*) malloc(sizeof(int));
    parteEnteraOperacion = (double*) malloc(sizeof(double));
    parteFraccionariaOperacion = (double*) malloc(sizeof(double));
    resultadoMultiplicacion = (double*) malloc(sizeof(double));

    //Inicialización variables
    *parteEnteraOperacion = 0;
    *parteFraccionariaOperacion = *numero;
    *resultadoMultiplicacion = 0;

    #ifdef TEST_MODE
        printf("PARÁMETROS");
        printf("\n parametro resultado: %i  \n", *resultado);
        printf("\n parametro resultadoSize: %i  \n", *resultadoSize);
        printf("\n parametro numero: %lf\n", *numero);
        printf("\n parametro baseDestino: %i\n", *baseDestino);
        printf("////////////////////////");
    #endif // TEST_MODE


    for(*count = 0; *count < *resultadoSize; (*count)++ ){

        *resultadoMultiplicacion = (*parteFraccionariaOperacion) * (*baseDestino);

        *parteFraccionariaOperacion = modf(*resultadoMultiplicacion, parteEnteraOperacion);

        *resultado = *parteEnteraOperacion;

        #ifdef TEST_MODE
            printf("\nresultadoMultiplicacion: %lf  \n", *resultadoMultiplicacion);
            printf("\nparteFraccionariaOperacion: %lf  \n", *parteFraccionariaOperacion);
            printf("\nparteEnteraOperacion: %lf\n", *parteEnteraOperacion);
            printf("\nresultado: %i\n", *resultado);
            printf("////////////////////////");
        #endif // TEST_MODE

        resultado++;
    }

    free(count);
    free(parteEnteraOperacion);
    free(parteFraccionariaOperacion);
    free(resultadoMultiplicacion);

    return 0;
}

int * cambioBaseFraccionarios(char* resultado,int* sizeResultado , char* numero, int* sizeNumero,int* baseOrigen, int* baseDestino){

    //DECLARACIÓN PUNTEROS
    int *numeroRepresentadoEnArregloDeEnteros;
    float *numeroEnBaseDecimal;
    int *numeroEnBaseDestinoRepresentadoEnDecimal;
    int *i;

    //INICIALIZACIÓN DE MEMORIA Y VARIABLES CON MALLOC
    i = (int*) malloc(sizeof(int));

    numeroRepresentadoEnArregloDeEnteros = (int*) malloc(sizeof(int) * (*sizeResultado));

    numeroEnBaseDecimal = (float*) malloc(sizeof(float));

    numeroEnBaseDestinoRepresentadoEnDecimal = (int*) malloc(sizeof(int) * (*sizeResultado));

    //INICIALIZACIÓN DE VARIABLES
    for(*i = 0; *i<*sizeResultado; (*i)++){
        *(numeroRepresentadoEnArregloDeEnteros+*i) = 0;
    }

    *numeroEnBaseDecimal = 0;

    for(*i = 0; *i<*sizeResultado; (*i)++){
        *(numeroEnBaseDestinoRepresentadoEnDecimal+*i) = 0;
    }

    //OPERACIONES

    obtenerRepresentacionEnBaseDiez(numeroRepresentadoEnArregloDeEnteros, sizeNumero, numero, sizeNumero);

    deBaseOrigenADecimalFraccionario(numeroEnBaseDecimal, numeroRepresentadoEnArregloDeEnteros, sizeNumero, baseOrigen );

    deBaseDecimalADestinoFraccionario(numeroEnBaseDestinoRepresentadoEnDecimal, sizeResultado, numeroEnBaseDecimal, baseDestino);

    obtenerRepresentacionEnBaseCorrespondiente(resultado, sizeResultado, numeroEnBaseDestinoRepresentadoEnDecimal, sizeResultado);

    //LIBERACIÓN DE MEMORIA
    free(numeroRepresentadoEnArregloDeEnteros);
    free(numeroEnBaseDecimal);
    free(numeroEnBaseDestinoRepresentadoEnDecimal);
    free(i);

    return 0;
}
