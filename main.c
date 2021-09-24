#include <stdio.h>
#include <stdlib.h>
#include "cambioBaseEnteros.h"


int main()
{
    int * resultadoSize = (int*) malloc(sizeof(int));
    *resultadoSize = 5;

    int * baseDestino = (int*) malloc(sizeof(int));
    *baseDestino = 2;

    float * numero = (float*) malloc(sizeof(float));
    *numero = 0;

    int * resultado = (int*) malloc(sizeof(int) * (*resultadoSize));

    for(int i = 0; i<*resultadoSize; i++){
        *(resultado+i) = 0;
    }

    /*
    *(numero+0) = 5;
    *(numero+1) = 11;
    *(numero+2) = 8;
    *(numero+3) = 12;
    *(numero+4) = 7;
    */

    *numero = 0.5;

    deBaseDecimalADestinoFraccionario(resultado, resultadoSize, numero, baseDestino);

    printf("Resultado Final:\n");
    for(int i = 0; i<*resultadoSize; i++){
        printf("%i", *resultado);
    }




    return 0;
}


    /*
    int * resultadoSize = (int*) malloc(sizeof(int));
    *resultadoSize = 10;

    int * baseOrigen = (int*) malloc(sizeof(int));
    *baseOrigen = 16;

    int * baseDestino = (int*) malloc(sizeof(int));
    *baseDestino = 3;

    char * resultado = (char*) malloc(sizeof(char) * (*resultadoSize));

    for(int i = 0; i<*resultadoSize; i++){
        *(resultado+i) = '-';
    }

    char * numero = (char*) malloc(sizeof(char) * (*resultadoSize));

    for(int i = 0; i<*resultadoSize; i++){
        *(numero+i) = '-';
    }

    *(numero+5) = 'A';
    *(numero+6) = '9';
    *(numero+7) = 'B';
    *(numero+8) = '5';
    *(numero+9) = '1';


    printf("Numero Inicial: \n");
    for(int i=0; i<*resultadoSize; i++){
        printf("%c ... ", *(numero+i));
    }
    printf("\n");

    cambioBaseEnteros(resultado,resultadoSize, numero, resultadoSize, baseOrigen, baseDestino);

    printf("\n");
    printf("Resultado Final: \n");
    for(int i=0; i<*resultadoSize; i++){
        printf("%c ... \n", *(resultado+i));
    }
    */


    /*
    if(0){
        #define PRUEBA 1
    }

    printf("%i", PRUEBA);

    int * resultadoSize = (int*) malloc(sizeof(int));
    *resultadoSize = 10;

    int * resultado = (int*) malloc(sizeof(int) * (*resultadoSize));

    for(int i = 0; i<*resultadoSize; i++){
        *(resultado+i) = 0;
    }

    int * numero = (int*) malloc(sizeof(int));
    *numero = 1002;

    int * baseDestino = (int*) malloc(sizeof(int));
    *baseDestino = 13;


    char * stringPostProcesado = (char*) malloc((sizeof(char) * (*resultadoSize) + 1));

    for(int i = 0; i<(*resultadoSize)+1; i++){
        *(stringPostProcesado+i) = 'a';
    }

    *(stringPostProcesado + *resultadoSize) = '\0';

    deBaseDecimalADestino(resultado, resultadoSize , baseDestino, numero);

    obtenerRepresentacionEnBase(stringPostProcesado, resultadoSize, resultado, resultadoSize);



    printf("\n");
    for(int i = 0; i<(*resultadoSize)+1; i++){
            printf("%c,", *(stringPostProcesado+i));
    }
    printf("\n");
    printf("%i", *(stringPostProcesado+10));

    printf("%s", *stringPostProcesado);

    free(stringPostProcesado);
    free(resultadoSize);
    free(resultado);
    free(baseDestino);
    free(numero);
    */

    /*
    int * resultado = (int*) malloc(sizeof(int));
    *resultado = 0;
    int * numeroSize = (int*) malloc(sizeof(int));
    *numeroSize = 4;
    int * baseOrigen = (int*) malloc(sizeof(int));
    *baseOrigen = 7;

  //  int numero[4] = {15, 15, 14, 2};
                    //FFE2
    int * numero = (int*) malloc(sizeof(int) * 4);

    *numero = 0;
    *(numero+1) = 0;
    *(numero+2) = 1;
    *(numero+3) = 0;

    deBaseOrigenADecimal(resultado, numero, numeroSize, baseOrigen);

    printf("%i", *resultado);

    free(resultado);
    free(numeroSize);
    free(baseOrigen);

    return 0;*/
