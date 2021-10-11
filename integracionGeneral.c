#include <stdio.h>
#include <stdlib.h>
#include <error.h>

#include "cambioBaseEnteros.h"
#include "cambioBaseFraccionarios.h"
#include "verificacionParametrosConsola.h"
#include "help.h"

#define DEFAULT_BASE 10
#define DEC_SIZE 5
#define INT_SIZE 10
#define DEC_OUTPUT_SIZE 10
#define INT_OUTPUT_SIZE 20

void integracionGeneral(int * argc, char * *argv){

    //DECLARACIÓN DE VARIABLES
    int * i;
    int * baseOrigen;
    int * baseDestino;
    int * usa_v;
    int * usa_h;
    int * parteEnteraSize;
    int * parteFraccionariaSize;
    int * resultadoParteEnteraSize;
    int * resultadoParteFraccionariaSize;
    char * parteEntera;
    char * parteFraccionaria;
    char * resultadoParteEntera;
    char * resultadoParteFraccionaria;

    //ASIGNACIÓN DE MEMORIA CON MALLOC

    i = (int*) malloc(sizeof(int));

    baseOrigen = (int*) malloc(sizeof(int));

    baseDestino = (int*) malloc(sizeof(int));

    usa_v = (int*) malloc(sizeof(int));

    usa_h = (int*) malloc(sizeof(int));

    parteEnteraSize = (int*) malloc(sizeof(int));

    parteFraccionariaSize = (int*) malloc(sizeof(int));

    resultadoParteEnteraSize = (int*) malloc(sizeof(int));

    resultadoParteFraccionariaSize = (int*) malloc(sizeof(int));

    parteEntera = (char*) malloc(sizeof(char) * INT_SIZE);

    parteFraccionaria = (char*) malloc(sizeof(char) * DEC_SIZE);

    resultadoParteFraccionaria = (char*) malloc(sizeof(char) * DEC_OUTPUT_SIZE);

    resultadoParteEntera = (char*) malloc(sizeof(char) * INT_OUTPUT_SIZE);

    //INICIALIZACIÓN DE VARIABLES

    *i = 0;
    *baseOrigen = DEFAULT_BASE;
    *baseDestino = DEFAULT_BASE;
    *usa_h = 0;
    *usa_v = 0;
    *parteEnteraSize = INT_SIZE;
    *parteFraccionariaSize = DEC_SIZE;
    *resultadoParteEnteraSize = INT_OUTPUT_SIZE;
    *resultadoParteFraccionariaSize = DEC_OUTPUT_SIZE;


    for(*i = 0; (*i)<*parteEnteraSize; (*i)++){
        *(parteEntera+(*i)) = '0';
    }

    for(*i = 0; (*i)<*parteFraccionariaSize; (*i)++){
        *(parteFraccionaria+(*i)) = '0';
    }

    for(*i = 0; (*i)<*resultadoParteEnteraSize; (*i)++){
        *(resultadoParteEntera+(*i)) = '0';
    }

    for(*i = 0; (*i)<*resultadoParteFraccionariaSize; (*i)++){
        *(resultadoParteFraccionaria+(*i)) = '0';
    }

    //OPERACIONES

    #ifdef TEST_MODE
        printf("PREVIO A INICIO verificarParametrosConsola\n");
    #endif // TEST_MODE

    verificarParametrosConsola(argc, argv, parteEntera, parteEnteraSize, parteFraccionaria, parteFraccionariaSize, baseOrigen, baseDestino, usa_v, usa_h);

    #ifdef TEST_MODE

        printf("Base origen: %i \n", *baseOrigen);

        printf("Base destino: %i \n", *baseDestino);

        printf("usa -v: %i \n", *usa_v);

        printf("usa -h: %i \n", *usa_h);

        for(int i = 0; i<*parteEnteraSize; i++){
            printf("%c" ,*(parteEntera+i));
        }

        printf("\n");

        for(int i = 0; i<*parteFraccionariaSize; i++){
            printf("%c" ,*(parteFraccionaria+i));
        }

        printf("\n");
    #endif

    cambioBaseEnteros(resultadoParteEntera, resultadoParteEnteraSize, parteEntera, parteEnteraSize, baseOrigen, baseDestino, usa_v);

    cambioBaseFraccionarios(resultadoParteFraccionaria, resultadoParteFraccionariaSize, parteFraccionaria, parteFraccionariaSize, baseOrigen, baseDestino, usa_v);

    printf("RESULTADO: ");
    for(*i = 0; *i < *resultadoParteEnteraSize; (*i)++){
        printf("%c", *resultadoParteEntera);
        resultadoParteEntera++;
    }

    printf(".");

    for(*i = 0; *i < *resultadoParteFraccionariaSize; (*i)++){
        printf("%c", *resultadoParteFraccionaria);
        resultadoParteFraccionaria++;
    }



    free(i);
    free(usa_v);
    free(usa_h);
    free(baseOrigen);
    free(baseDestino);
    free(parteEntera);
    free(parteEnteraSize);
    free(parteFraccionaria);
    free(parteFraccionariaSize);
    free(resultadoParteEntera);
    free(resultadoParteEnteraSize);
    free(resultadoParteFraccionaria);
    free(resultadoParteFraccionariaSize);

    printf("\n\nFinalización correcta del proceso");
}
/*
int * mostrarResultado(char * parteEntera, int * parteEnteraSize, char * parteEnteraSize, int * parteFraccionariaSize){

    //DECLARACIÓN VARIABLES
    int * numeroDecEncontrado;
    int * numeroFracEncontrado;
    int * i;

    numeroFracEncontrado = (int*) malloc(sizeof(int));
    numeroDecEncontrado = (int*) malloc(sizeof(int));
    i = (int*) malloc(sizeof(int));


    *numeroDecEncontrado = 0;
    *numeroFracEncontrado = 0;
    *i = 0;

    for(*i = 0; *i<*parteEnteraSize; (*i)++){
        if(parteEntera != 0){
            *numeroDecEncontrado = 1;
        }
        parteEntera++;
    }

    if(*i == parteEnteraSize){
        printf("0");
    }

    for(*i = 0; *i<*parteEnteraSize; (*i)++){

    }


}*/
