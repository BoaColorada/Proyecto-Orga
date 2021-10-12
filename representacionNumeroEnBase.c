#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <error.h>

//
//
/**
*Dado un entero cambia a su correspondencia alfabética dependiendo del valor del mismo
*para obtener la correcta representación en la base que se requiera.
*
*numero : entero que almacena la el "numero".
*/
void obtenerRepresentacionEnBaseCorrespondiente(char *resultado, int *numero){

        if(*numero>9 && *numero<16){
            *resultado = (*numero + 55);
        } else if (*numero>=0 && *numero<=9){
            *resultado = (*numero + 48);
        }
}

/**
*Dado un arreglo de enteros cambia a su correspondencia alfabética dependiendo del valor de los mismos
*Para obtener la correcta representación en la base que se requiera.
*resultado : arreglo de caracteres que almacena el resultado de la funcion.
*caracterAConvertir : recibe el caracter a convertir.
*/
void obtenerRepresentacionEnBaseDiez(int *resultado, char * caracterAConvertir){

        if(*caracterAConvertir>=65 && *caracterAConvertir<=70){
            *resultado = ((*caracterAConvertir) - 55);
        } else if (*caracterAConvertir>=48 && *caracterAConvertir<=57){
            *resultado = ((*caracterAConvertir) - 48);
        } else {
            printf("Error: el parametro -n tiene caracteres que no pertenecen a la base.");
            exit(EXIT_FAILURE);
        }
}
