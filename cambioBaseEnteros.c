#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_DECIMAL_SIZE 15;

int* cambioBaseEnteros(char* resultado,int* sizeResultado ,char* numero,int* sizeNumero,int* baseOrigen, int* baseDestino){

    int* numEnBaseDecimal;

    numEnBaseDecimal = (int*) malloc(sizeof(int) * MAX_DECIMAL_SIZE);

    BaseOrigenADecimal(numEnBaseDecimal,numero,sizeNumero,baseOrigen);


    deBaseDecimalADestino(baseDestino);

    return 0;
}

int* deBaseOrigenADecimal(int* resultado,char* numero,int* baseOrigen){
    int* retonro;

    return 0;
}

int* deBaseDecimalADestino(int* resultado ,int* baseDestino){

    return 0;
}
