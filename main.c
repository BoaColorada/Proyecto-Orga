#include <stdio.h>
#include <stdlib.h>
#include <error.h>
#include "cambioBaseEnteros.h"
#include "cambioBaseFraccionarios.h"
#include "verificacionParametrosConsola.h"
#include "help.h"

int main (int argc, char **argv)

{
    #ifdef TEST_MODE
        int i;

        printf ("Número de argumentos pasados: %d\n",argc);

        for (i= 0; i < argc; i++){
          printf ("El argumento %d vale: %s\n",i, *(argv+i));
        }
    #endif // TEST_MODE

    help();

    /*
    int * baseOrigen = (int*) malloc(sizeof(int));
    *baseOrigen = 0;

    int * baseDestino = (int*) malloc(sizeof(int));
    *baseDestino = 0;

    int * usa_v = (int*) malloc(sizeof(int));
    *usa_v = 0;

    int * usa_h = (int*) malloc(sizeof(int));
    *usa_h = 0;

    int * parteEnteraSize = (int*) malloc(sizeof(int));
    *parteEnteraSize = 10;

    int * parteFraccionariaSize = (int*) malloc(sizeof(int));
    *parteFraccionariaSize = 5;

    char * parteEntera = (char*) malloc(sizeof(char) * (*parteEnteraSize));
    for(int i = 0; i<*parteEnteraSize; (i)++){
        *(parteEntera+i) = '0';
    }

    char * parteFraccionaria = (char*) malloc(sizeof(char) * (*parteFraccionariaSize));
    for(int i = 0; i<*parteFraccionariaSize; (i)++){
        *(parteFraccionaria+i) = '0';
    }


    printf("PREVIO A INICIO verificarParametrosConsola\n");

    verificarParametrosConsola(&argc, argv, parteEntera, parteEnteraSize, parteFraccionaria, parteFraccionariaSize, baseOrigen, baseDestino, usa_v, usa_h);

    printf("a");

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


    free(baseOrigen);
    free(baseDestino);
    free(usa_v);
    free(usa_h);
    free(parteEntera);
    free(parteEnteraSize);
    free(parteFraccionaria);
    free(parteFraccionariaSize);


    printf("Finalización correcta del proceso");
    */
    exit(EXIT_SUCCESS);
    return EXIT_SUCCESS;
}

/*
    int i;

    printf ("Número de argumentos pasados: %d\n",argc);

    for (i= 0; i < argc; i++){
      printf ("El argumento %d vale: %s\n",i, argv[i]);
    }
*/


/*
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

    *numero = 0.5;

    deBaseDecimalADestinoFraccionario(resultado, resultadoSize, numero, baseDestino);

    printf("Resultado Final:\n");
    for(int i = 0; i<*resultadoSize; i++){
        printf("%i", *resultado);
    }

    */


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
