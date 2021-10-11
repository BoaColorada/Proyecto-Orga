#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define TEST_MODE 0

//Dado un arreglo de enteros cambia a su correspondencia alfabética dependiendo del valor de los mismos
//Para obtener la correcta representación en la base que se requiera
int * obtenerRepresentacionEnBaseCorrespondiente(char *resultado, int *resultadoSize, int *numero, int *numeroSize){


    //DECLARACIÓN PUNTEROS
    int *counter;

    //INICIALIZACIÓN DE MEMORIA Y VARIABLES CON MALLOC
    counter = (int*) malloc(sizeof(int));

    //INICIALIZACIÓN VARIABLES
    *counter = 0;

    #ifdef TEST_MODE
        printf("\n ------------- INICIO METODO obtenerRepresentacionEnBaseCorrespondiente ------------- \n");

        printf("\nParametro resultado Inicial: \n");
        for(int i=0; i<*resultadoSize; i++){
            printf("%c ... ", *(resultado+i));
        }

        printf("\nParametro resultadoSize Inicial: \n");
        printf("%i \n", *resultadoSize);
        printf("\n");

        printf("\nParametro numero Inicial: \n");
        for(int i=0; i<*numeroSize; i++){
            printf("%i ... ", *(numero+i));
        }

        printf("\nParametro numeroSize Inicial: \n");
        printf("%i \n", *numeroSize);
        printf("\n");

    #endif


    for(*counter = 0; *counter<(*resultadoSize); (*counter)++ ){

        if(*numero>9 && *numero<16){
            *resultado = (*numero + 55);
        } else if (*numero>=0 && *numero<=9){
            *resultado = (*numero + 48);
        }

        #ifdef TEST_MODE
            printf( "numero: %i \n" , *numero);
            printf( "resultado: %c \n" , *resultado);
            printf( "/////////////// \n");
        #endif

        numero++;
        resultado++;


    }

    #ifdef TEST_MODE
        printf("\n ------------- FINAL METODO obtenerRepresentacionEnBaseCorrespondiente ------------- \n");
    #endif // TEST_MODE

    free(counter);

    return 0;
}

//Dado un arreglo de enteros cambia a su correspondencia alfabética dependiendo del valor de los mismos
//Para obtener la correcta representación en la base que se requiera
int * obtenerRepresentacionEnBaseDiez(int *resultado, int *resultadoSize, char * stringAConvertir, int *stringAConvertirSize){

    //DECLARACIÓN PUNTEROS
    int *counter;

    //INICIALIZACIÓN DE MEMORIA Y VARIABLES CON MALLOC
    counter = (int*) malloc(sizeof(int));

    //INICIALIZACIÓN VARIABLES
    *counter = 0;

    #ifdef TEST_MODE
        printf("\n ------------- INICIO METODO obtenerRepresentacionEnBaseDiez ------------- \n");

        printf("\nParametro resultado Inicial: \n");
        for(int i=0; i<*resultadoSize; i++){
            printf("%i ... ", *(resultado+i));
        }
        printf("\n");

        printf("\nParametro resultadoSize Inicial: \n");
        printf("%i \n", *resultadoSize);
        printf("\n");

        printf("\nParametro stringAConvertir Inicial: \n");
        for(int i=0; i<*resultadoSize; i++){
            printf("%c ... ", *(stringAConvertir+i));
        }
        printf("\n");

        printf("\nParametro stringAConvertirSize Inicial: \n");
        printf("%i \n", *stringAConvertirSize);
        printf("\n");


    #endif


    for(*counter = 0; *counter<*stringAConvertirSize; (*counter)++){

        if(*stringAConvertir>=65 && *stringAConvertir<=70){
            *resultado = ((*stringAConvertir) - 55);
        } else if (*stringAConvertir>=48 && *stringAConvertir<=57){
            *resultado = ((*stringAConvertir) - 48);
        } else {
            printf("Error: el parametro -n tiene caracteres que no pertenecen a la base.");
            exit(0);
        }

        #ifdef TEST_MODE
            printf("count:  %i \n", *counter);
            printf("stringAConvertir: %c \n", *(stringAConvertir));
            printf("Resultado: %i \n", *(resultado));
            printf("////////////////////////////// \n");
        #endif

    resultado++;
    stringAConvertir++;

    }

    #ifdef TEST_MODE
        printf("\n ------------- FINAL METODO obtenerRepresentacionEnBaseDiez ------------- \n");
    #endif


    free(counter);

    return 0;
}
