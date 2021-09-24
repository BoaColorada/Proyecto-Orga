#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_DECIMAL_SIZE 15

int * cambioBaseEnteros(char* resultado,int* sizeResultado , char* numero, int* sizeNumero,int* baseOrigen, int* baseDestino);
int * deBaseOrigenADecimalEntero(int* resultado, int* numero, int* numeroSize,int* baseOrigen);
int * deBaseDecimalADestinoEntero(int* resultado, int* resultadoSize , int* baseDestino, int *numero);
int * obtenerRepresentacionEnBaseCorrespondiente(char *resultado, int *resultadoSize, int *numero, int *numeroSize);
int * obtenerRepresentacionEnBaseDiez(int *resultado, int *resultadoSize, char * stringAConvertir, int *stringAConvertirSize);
