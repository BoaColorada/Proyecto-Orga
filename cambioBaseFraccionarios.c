#include <stdio.h>
#include <stdlib.h>
#include <math.h>


#define MAX_DECIMAL_SIZE 15
#define TEST_MODE 1

/*
int * cambioBaseFraccionarios(char* resultado,int* sizeResultado , char* numero, int* sizeNumero,int* baseOrigen, int* baseDestino){


return 0;
}*/


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

    return 0;
}

int * deBaseDecimalADestinoFraccionario(int * resultado, int * resultadoSize, float * numero, int * baseDestino){

    //Declaración variables tipo puntero
    int *count;
    int *parteEnteraOperacion;
    double *parteFraccionariaOperacion;
    double *resultadoMultiplicacion;

    //Inicialización memoria variables
    count = (int*) malloc(sizeof(int));
    parteEnteraOperacion = (int*) malloc(sizeof(int));
    parteFraccionariaOperacion = (double*) malloc(sizeof(double));
    resultadoMultiplicacion = (double*) malloc(sizeof(double));

    //Inicialización variables
    *parteEnteraOperacion = 0;
    *parteFraccionariaOperacion = *numero;
    *resultadoMultiplicacion = 0;

    #ifdef TEST_MODE
        printf("\n parametro resultado: %lf  \n", resultadoMultiplicacion);
        printf("\n parametro resultadoSize: %lf  \n", parteFraccionariaOperacion);
        printf("\n parametro numero: %i\n", parteEnteraOperacion);
        printf("\n parametro baseDestino: %i\n", resultado);
    #endif // TEST_MODE


    for(*count = 0; *count < *resultadoSize; (*count)++ ){

        *resultadoMultiplicacion = (*parteFraccionariaOperacion) * (*baseDestino);

        *parteFraccionariaOperacion = modf(*resultadoMultiplicacion, parteEnteraOperacion);

        *resultado = *parteEnteraOperacion;

        #ifdef TEST_MODE
            printf("\nresultadoMultiplicacion: %lf  \n", resultadoMultiplicacion);
            printf("\nparteFraccionariaOperacion: %lf  \n", parteFraccionariaOperacion);
            printf("\nparteEnteraOperacion: %i\n", parteEnteraOperacion);
            printf("\nresultado: %i\n", resultado);
        #endif // TEST_MODE

        resultado++;

    }

    return 0;
}



