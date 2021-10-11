
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "representacionNumeroEnBase.h"
#define TEST_MODE

//Dada una fracción expresada como un arreglo de enteros "numero" de tamaño "numeroSize" en base "baseOrigen"
//efectúa el cambio de base de la base "baseOrigen" a la base decimal y lo almacena en "resultado".
int * deBaseOrigenADecimalFraccionario(float * resultado, char * numero, int * numeroSize, int * baseOrigen, int * usa_v ){

    //Declaración variables tipo puntero
    int *count;
    int *potencia;
    int *caracterEnDecimal;
    float *calculoDePotencia;


    //Inicialización memoria variables

    count = (int*) malloc(sizeof(int));
    potencia = (int*) malloc(sizeof(int));
    calculoDePotencia = (float*) malloc(sizeof(float));
    caracterEnDecimal = (int*) malloc(sizeof(int));

    //Inicialización de variables

    *count = 0;
    *potencia = -1;
    *calculoDePotencia = 0;
    *caracterEnDecimal = 0;

    for(*count = 0; *count < *numeroSize; (*count)++){

        obtenerRepresentacionEnBaseDiez(caracterEnDecimal, numero);

        *calculoDePotencia = pow(*baseOrigen, *potencia);

        *resultado = *resultado + (*calculoDePotencia) * (*caracterEnDecimal);

        (*potencia)--;

        numero++;

    }

    free(count);
    free(potencia);
    free(calculoDePotencia);

    return 0;
}

int * deBaseDecimalADestinoFraccionario(char * resultado, int * resultadoSize, float * numero, int * baseDestino, int * usa_v){

    //Declaración variables tipo puntero
    int *count;
    int *parteEnteraOperacionAux;
    double *parteEnteraOperacion;
    double *parteFraccionariaOperacion;
    double *resultadoMultiplicacion;

    //Inicialización memoria variables
    count = (int*) malloc(sizeof(int));
    parteEnteraOperacionAux = (int*) malloc(sizeof(int));
    parteEnteraOperacion = (double*) malloc(sizeof(double));
    parteFraccionariaOperacion = (double*) malloc(sizeof(double));
    resultadoMultiplicacion = (double*) malloc(sizeof(double));

    //Inicialización variables
    *parteEnteraOperacion = 0;
    *parteFraccionariaOperacion = *numero;
    *resultadoMultiplicacion = 0;
    *parteEnteraOperacionAux = 0;
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

        *parteEnteraOperacionAux = *parteEnteraOperacion;

        obtenerRepresentacionEnBaseCorrespondiente(resultado, parteEnteraOperacionAux);

        #ifdef TEST_MODE
            printf("\nresultadoMultiplicacion: %lf  \n", *resultadoMultiplicacion);
            printf("\nparteFraccionariaOperacion: %lf  \n", *parteFraccionariaOperacion);
            printf("\nparteEnteraOperacion: %lf\n", *parteEnteraOperacion);
            printf("\nparteEnteraOperacionAux: %i\n", *parteEnteraOperacionAux);
            printf("\nresultado: %i\n", *resultado);
            printf("////////////////////////");
        #endif // TEST_MODE

        resultado++;
    }


    free(count);
    free(parteEnteraOperacionAux);
    free(parteEnteraOperacion);
    free(parteFraccionariaOperacion);
    free(resultadoMultiplicacion);


    return 0;
}

int * cambioBaseFraccionarios(char* resultado,int* sizeResultado , char* numero, int* sizeNumero,int* baseOrigen, int* baseDestino, int * usa_v){

    //DECLARACIÓN PUNTEROS
    float *numeroEnBaseDecimal;
    int *i;

    //INICIALIZACIÓN DE MEMORIA Y VARIABLES CON MALLOC
    i = (int*) malloc(sizeof(int));

    numeroEnBaseDecimal = (float*) malloc(sizeof(float));

    //INICIALIZACIÓN DE VARIABLES

    *i = 0;

    *numeroEnBaseDecimal = 0;

    //OPERACIONES



    deBaseOrigenADecimalFraccionario(numeroEnBaseDecimal, numero, sizeNumero, baseOrigen, usa_v);

    #ifdef TEST_MODE
        printf("\n -_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_ \n");
        printf("\n RESULTADO deBaseOrigenADecimal: \n");
        printf("%lf ... ", *(numeroEnBaseDecimal));
        printf("\n -_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_ \n");
        printf("\n");
    #endif // TEST_MODE

    deBaseDecimalADestinoFraccionario(resultado, sizeResultado, numeroEnBaseDecimal, baseDestino, usa_v);

     #ifdef TEST_MODE
        printf("\n -_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_ \n");
        printf("\n RESULTADO deBaseDecimalADestino: \n");
        for(*i=0; *i<*sizeResultado; (*i)++){
            printf("%c ... ", *(resultado+*i));
        }
        printf("\n -_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_ \n");
        printf("\n");
    #endif // TEST_MODE

    //LIBERACIÓN DE MEMORIA
    free(numeroEnBaseDecimal);
    free(i);

    return 0;
}
