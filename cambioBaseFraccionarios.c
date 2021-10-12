
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "representacionNumeroEnBase.h"

//Dado la mantisa expresada como arreglo de caracteres, obtiene su representacion en base decimal a traves del
//metodo de la division para numeros fraccionarios.
int * deBaseOrigenADecimalFraccionario(float * resultado, char * numero, int * numeroSize, int * baseOrigen, int * usa_v ){

    //Declaración variables tipo puntero
    int *count;
    int *potencia;
    int *caracterEnDecimal;
    float *calculoDePotencia;


    //Inicialización memoria variables

    count = (int*) malloc(sizeof(int));
    potencia = (int*) malloc(sizeof(int));
    calculoDePotencia = (float*) malloc(sizeof(float));
    caracterEnDecimal = (int*) malloc(sizeof(int));

    //Inicialización de variables

    *count = 0;
    *potencia = -1;
    *calculoDePotencia = 0;
    *caracterEnDecimal = 0;

    if(*usa_v){
        printf("\n-.-.-.-.-.-.-.-Metodo de la division para numeros fraccionarios-.-.-.-.-.-.-.-\n");
        printf(" En el metodo de la division  para numeros fraccionarios, cada digito de el numero\n");
        printf(" en base origen, es dividido por la base origen elevada a la posicion del digito \n");
        printf(" en el numero, para luego sumar todos estos resultados parciales.\n");
        printf(" Se opera en la base destino\n");
        printf("-.-.-.-.-.-.-.--.-.-.-.-.-.-.--.-.-.-.-.-.-.--.-.-.-.-.-.-.--.-.-.-.-.-.-.-.-.-\n");
    }

    for(*count = 0; *count < *numeroSize; (*count)++){

        obtenerRepresentacionEnBaseDiez(caracterEnDecimal, numero);

        *calculoDePotencia = pow(*baseOrigen, *potencia);

        if(*usa_v){
            printf("\n-------------------------------------------------------------------------\n");
            printf(" Digito actual: %c\n", *numero);
            printf(" El digito actual en base 10 es: %i \n", *caracterEnDecimal);
            printf(" Potenciamos la base origen \"%i\" a la posicion del numero \"%i\".\n", *baseOrigen, *potencia);
            printf(" lo que resulta: %lf\n", *calculoDePotencia);
            printf(" Ahora, se divide el digito en base 10 %i por el resultado del calculo\n", *caracterEnDecimal);
            printf(" anterior, que da como resultado %lf\n", (*calculoDePotencia) * (*caracterEnDecimal));
            printf(" Y finalmente, sumamos este resultado parcial al resultado final");
            printf(" %lf + %lf = ", *resultado, (*calculoDePotencia) * (*caracterEnDecimal));
        }

        *resultado = *resultado + (*calculoDePotencia) * (*caracterEnDecimal);

        if(*usa_v){
            printf("%lf\n", *resultado);
        }

        (*potencia)--;

        numero++;

    }

    if(*usa_v){
        printf("\n-------------------------------------------------------------------------\n");

        printf("Resultado final: %lf", *resultado);

        printf("\n-.-.-.-.-.-.-.-Fin metodo de la division para numeros fraccionarios-.-.-.-.-.-.-.-\n\n\n");


    }

    free(count);
    free(potencia);
    free(calculoDePotencia);

    return 0;
}

//Dado la mantisa expresada como un numero flotante en base 10, obtiene su representacion en base destino a traves
//del metodo de la multiplicacion para numeros fraccionarios.
int * deBaseDecimalADestinoFraccionario(char * resultado, int * resultadoSize, float * numero, int * baseDestino, int * usa_v){

    //Declaración variables tipo puntero
    int *count;
    int *parteEnteraOperacionAux;
    double *parteEnteraOperacion;
    double *parteFraccionariaOperacion;
    double *resultadoMultiplicacion;

    //Inicialización memoria variables
    count = (int*) malloc(sizeof(int));
    parteEnteraOperacionAux = (int*) malloc(sizeof(int));
    parteEnteraOperacion = (double*) malloc(sizeof(double));
    parteFraccionariaOperacion = (double*) malloc(sizeof(double));
    resultadoMultiplicacion = (double*) malloc(sizeof(double));

    //Inicialización variables
    *parteEnteraOperacion = 0;
    *parteFraccionariaOperacion = *numero;
    *resultadoMultiplicacion = 0;
    *parteEnteraOperacionAux = 0;

     if(*usa_v){
        printf("\n-.-.-.-.-.-.-.-Metodo de la multiplicacion para numeros fraccionarios-.-.-.-.-.-.-.-\n");
        printf(" En el metodo de la multiplicacion para numeros fraccionarios, multiplicamos el numero por\n");
        printf(" la base destino, y luego separamos la parte entera de la fraccionaria. La parte entera del\n");
        printf(" resultado de esta operacion sera añadida a la derecha extrema del resultado total.\n");
        printf(" mientras que la parte fraccionaria se utilizara en la siguiente iteracion del algorimo\n");
        printf(" Se opera en la base origen.\n");
        printf("-.-.-.-.-.-.-.--.-.-.-.-.-.-.--.-.-.-.-.-.-.--.-.-.-.-.-.-.--.-.-.-.-.-.-.-.-.-\n");
    }


    for(*count = 0; *count < *resultadoSize; (*count)++ ){

         if(*usa_v){
            printf("\n-------------------------------------------------------------------------\n");
            printf(" numero a multiplicar: %lf\n", *parteFraccionariaOperacion);
         }

        *resultadoMultiplicacion = (*parteFraccionariaOperacion) * (*baseDestino);

        *parteFraccionariaOperacion = modf(*resultadoMultiplicacion, parteEnteraOperacion);

        *parteEnteraOperacionAux = *parteEnteraOperacion;

        obtenerRepresentacionEnBaseCorrespondiente(resultado, parteEnteraOperacionAux);

        if(*usa_v){
            printf(" base destino: %i\n", *baseDestino);
            printf(" Multiplicamos la base destino por el numero, resulta: %lf\n", *resultadoMultiplicacion);
            printf(" Separamos la parte entera de la fraccionaria, y concluye como:\n");
            printf(" Parte entera: %i \n", *parteEnteraOperacionAux);
            printf(" Parte fraccionaria: %lf\n", *parteFraccionariaOperacion);
            printf(" Pasamos la parte entera a la base destino: %c\n", *resultado);
            printf(" y la añadimos a la derecha extrema del resultado.");
        }

        resultado++;
    }


    if(*usa_v){
        printf("\n-------------------------------------------------------------------------\n");

        printf("Resultado final: %i", *resultado);

        printf("\n-.-.-.-.-.-.-.-Fin metodo de la multiplicacion para numeros fraccionarios-.-.-.-.-.-.-.-\n\n\n");
    }

    free(count);
    free(parteEnteraOperacionAux);
    free(parteEnteraOperacion);
    free(parteFraccionariaOperacion);
    free(resultadoMultiplicacion);



    return 0;
}

//Dado la mantisa expresada como arreglo de caracteres expresada en base origen, obtiene su representacion en
//base destino utilizando como paso intermedio la base 10.
int * cambioBaseFraccionarios(char* resultado,int* sizeResultado , char* numero, int* sizeNumero,int* baseOrigen, int* baseDestino, int * usa_v){

    //DECLARACIÓN PUNTEROS
    float *numeroEnBaseDecimal;
    int *i;

    //INICIALIZACIÓN DE MEMORIA Y VARIABLES CON MALLOC
    i = (int*) malloc(sizeof(int));

    numeroEnBaseDecimal = (float*) malloc(sizeof(float));

    //INICIALIZACIÓN DE VARIABLES

    *i = 0;

    *numeroEnBaseDecimal = 0;

    //OPERACIONES

    if(*usa_v){
        printf("\n/////////////////////////////////////////////////////////////////////////////////\n");
        printf("\n Para pasar la parte fraccionaria del numero lo que haremos primero es pasar los digitos\n");
        printf("\n del mismo a base 10 con el metodo de la division para numeros fraccionarios, \n");
        printf("\n luego pasar el numero representado en base 10 a la base destino utilizando el \n");
        printf("\n metodo de la multiplicacion para numeros fraccionarios.\n");
        printf("\n/////////////////////////////////////////////////////////////////////////////////\n");
    }

    deBaseOrigenADecimalFraccionario(numeroEnBaseDecimal, numero, sizeNumero, baseOrigen, usa_v);


    deBaseDecimalADestinoFraccionario(resultado, sizeResultado, numeroEnBaseDecimal, baseDestino, usa_v);


    //LIBERACIÓN DE MEMORIA
    free(numeroEnBaseDecimal);
    free(i);

    return 0;
}
