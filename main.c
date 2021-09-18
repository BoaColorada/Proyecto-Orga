#include <stdio.h>
#include <stdlib.h>
#include "cambioBaseEnteros.h"

int main()
{

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

    return 0;
}
