#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define TEST_MODE 1

//Dado un entero cambia a su correspondencia alfabética dependiendo del valor del mismo
//Para obtener la correcta representación en la base que se requiera
int * obtenerRepresentacionEnBaseCorrespondiente(char *resultado, int *numero){

    #ifdef TEST_MODE
        printf("\n ------------- INICIO METODO obtenerRepresentacionEnBaseCorrespondiente ------------- \n");

        printf("\nParametro resultado Inicial: \n");
        printf("%c ... ", *(resultado));

        printf("\nParametro numero Inicial: \n");
        printf("%i ... ", *(numero));

    #endif

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

    #ifdef TEST_MODE
        printf("\n ------------- FINAL METODO obtenerRepresentacionEnBaseCorrespondiente ------------- \n");
    #endif // TEST_MODE

    return 0;
}

//Dado un arreglo de enteros cambia a su correspondencia alfabética dependiendo del valor de los mismos
//Para obtener la correcta representación en la base que se requiera
int * obtenerRepresentacionEnBaseDiez(int *resultado, char * caracterAConvertir){

    #ifdef TEST_MODE
        printf("\n ------------- INICIO METODO obtenerRepresentacionEnBaseDiez ------------- \n");

        printf("\nParametro resultado Inicial: \n");
        printf("%i ... ", *(resultado));
        printf("\n");

        printf("\nParametro caracterAConvertir Inicial: \n");
            printf("%c ... ", *(caracterAConvertir));
        printf("\n");

    #endif


        if(*caracterAConvertir>=65 && *caracterAConvertir<=70){
            *resultado = ((*caracterAConvertir) - 55);
        } else if (*caracterAConvertir>=48 && *caracterAConvertir<=57){
            *resultado = ((*caracterAConvertir) - 48);
        } else {
            printf("Error: el parametro -n tiene caracteres que no pertenecen a la base.");
            exit(0);
        }

        #ifdef TEST_MODE
            printf("caracterAConvertir: %c \n", *(caracterAConvertir));
            printf("Resultado: %i \n", *(resultado));
            printf("////////////////////////////// \n");
        #endif


    #ifdef TEST_MODE
        printf("\n ------------- FINAL METODO obtenerRepresentacionEnBaseDiez ------------- \n");
    #endif

    return 0;
}
