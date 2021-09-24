#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "cambioBaseEnteros.h"

#define MAX_DECIMAL_SIZE 15
#define TEST_MODE 0

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

    //INICIALIZACIÓN DE MEMORIA Y VARIABLES CON MALLOC

    numeroRepresentadoEnArregloDeEnteros = (int*) malloc(sizeof(int) * (*sizeResultado));

    for(int i = 0; i<*sizeResultado; i++){
        *(numeroRepresentadoEnArregloDeEnteros+i) = 0;
    }

    numeroEnBaseDecimal = (int*) malloc(sizeof(int));

    *numeroEnBaseDecimal = 0;

    numeroEnBaseDestinoRepresentadoEnDecimal = (int*) malloc(sizeof(int) * (*sizeResultado));

    for(int i = 0; i<*sizeResultado; i++){
        *(numeroEnBaseDestinoRepresentadoEnDecimal+i) = 0;
    }

    //OPERACIONES
    obtenerRepresentacionEnBaseDiez(numeroRepresentadoEnArregloDeEnteros, sizeResultado, numero, sizeResultado);

    #ifdef TEST_MODE
        printf("\n -_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_ \n");
        printf("\n RESULTADO obtenerRepresentacionEnBaseDiez: \n");
        for(int i=0; i<*sizeResultado; i++){
            printf("%i ... ", *(numeroRepresentadoEnArregloDeEnteros+i));
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
        for(int i=0; i<*sizeResultado; i++){
            printf("%i ... ", *(numeroEnBaseDestinoRepresentadoEnDecimal+i));
        }
        printf("\n -_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_ \n");
        printf("\n");
    #endif // TEST_MODE

    obtenerRepresentacionEnBaseCorrespondiente(resultado, sizeResultado, numeroEnBaseDestinoRepresentadoEnDecimal, sizeResultado);

    #ifdef TEST_MODE
        printf("\n -_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_ \n");
        printf("\n RESULTADO obtenerRepresentacionEnBaseCorrespondiente: \n");
        for(int i=0; i<*sizeResultado; i++){
            printf("%c ... ", *(resultado+i));
        }
        printf("\n -_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_ \n");
        printf("\n");
    #endif // TEST_MODE



    //LIBERACIÓN DE MEMORIA
    free(numeroRepresentadoEnArregloDeEnteros);
    free(numeroEnBaseDecimal);
    free(numeroEnBaseDestinoRepresentadoEnDecimal);

    return 0;
}

int * deBaseOrigenADecimalEntero(int* resultado, int* numero, int* numeroSize,int* baseOrigen){

    //Declaración variables de tipo elemental
    int i;
    int numeroDePotencia;
    int calcPotencia;
    int digitoAct;

    //Declaración variables de tipo puntero
    int *count;
    int *potencia;
    int *calculoDePotencia;
    int *digitoActual;

    //Inicialización variables de tipo puntero
    count = &i;
    potencia = &numeroDePotencia;
    calculoDePotencia = &calcPotencia;
    digitoActual = &digitoAct;

    //Inicialización variables de tipo elemental
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


    return 0;
}


int * deBaseDecimalADestinoEntero(int* resultado, int* resultadoSize , int* baseDestino, int *numero){
    //Declaración variables de tipo elemental
    int coci;
    int res;
    int count;

    //Declaración variables de tipo puntero
    int *cociente;
    int *resto;
    int *counter;

    //Inicialización variables de tipo puntero
    cociente = &coci;
    resto = &res;
    counter = &count;

    //Inicialización variables de tipo elemental
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

        *(resultado + count) = *resto;

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

    return 0;

}

//Dado un arreglo de enteros cambia a su correspondencia alfabética dependiendo del valor de los mismos
//Para obtener la correcta representación en la base que se requiera
int * obtenerRepresentacionEnBaseCorrespondiente(char *resultado, int *resultadoSize, int *numero, int *numeroSize){

    //Declaración variables de tipo elemental
    int count;
    //Declaración variables de tipo puntero
    int *counter;

    //Inicialización variables de tipo puntero
    counter = &count;

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


    return 0;
}

//Dado un arreglo de enteros cambia a su correspondencia alfabética dependiendo del valor de los mismos
//Para obtener la correcta representación en la base que se requiera
int * obtenerRepresentacionEnBaseDiez(int *resultado, int *resultadoSize, char * stringAConvertir, int *stringAConvertirSize){

    //Declaración variables de tipo elemental
    int count;

    //Declaración variables de tipo puntero
    int *counter;

    //Inicialización variables de tipo puntero
    counter = &count;

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


    return 0;
}
