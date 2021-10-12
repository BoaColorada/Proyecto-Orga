#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "representacionNumeroEnBase.h"

//
/**
*Dado el numero expresado como arreglo de caracteres, obtiene su representacion en base decimal a traves del
*metodo de la multiplicacion para numeros enteros.
*resultado : entero que almacena el resultado de la funcion.
*numero : arreglo de caracteres que almacena el numero entero.
*numeroSize : almacena la longitud del parametro "numero".
*baseOrigen : Base en la que el parametro "numero" esta representado.
*usa_V : indica si se debe mostra informacion adicional sobre los computos intermedios de proceso de conversion.
*/
//
void deBaseOrigenADecimalEntero(int* resultado, char * numero, int* numeroSize,int* baseOrigen, int * usa_v){

    //DECLARACIÓN PUNTEROS
    int *count;
    int *potencia;
    int *calculoDePotencia;
    char *digitoActual;
    int *digitoActualEnDecimal;

    //ASIGNACIÓN DE MEMORIA DINÁMICA CON MALLOC
    count = (int *) malloc(sizeof(int));
    potencia = (int *) malloc(sizeof(int));
    calculoDePotencia = (int *) malloc(sizeof(int));
    digitoActual = (char *) malloc(sizeof(char));
    digitoActualEnDecimal = (int *) malloc(sizeof(int));


    //INICIALIZACIÓN VARIABLES
    *count = (*numeroSize)-1;
    *potencia = 0;
    *calculoDePotencia = 0;
    *digitoActual = '0';
    *digitoActualEnDecimal = 0;


    if(*usa_v){
        printf("\n-.-.-.-.-.-.-.-Metodo de la multiplicacion para numeros enteros-.-.-.-.-.-.-.-\n");
        printf(" En el metodo de la multiplicacion para numeros enteros, cada digito de el numero\n");
        printf(" en base origen, es multiplicado por la base origen elevada a la posicion del digito \n");
        printf(" en el numero, para luego sumar todos estos resultados parciales.\n");
        printf(" Se opera en la base destino\n");
        printf("-.-.-.-.-.-.-.--.-.-.-.-.-.-.--.-.-.-.-.-.-.--.-.-.-.-.-.-.--.-.-.-.-.-.-.-.-.-\n");
    }


    //Realiza el cálculo de cambio de base destino a decimal partiendo desde su dígito menos
    //significativo
    for( *count = (*numeroSize)-1 ; (*count) >= 0 ; (*count)--){

        digitoActual = numero+(*count);


        obtenerRepresentacionEnBaseDiez(digitoActualEnDecimal, digitoActual);


        //Realiza el cálculo de la potencia por la que se multiplicará el digitoActualEnDecimal
        *calculoDePotencia = pow(*baseOrigen, *potencia);

        if(*usa_v){
            printf("\n-------------------------------------------------------------------------\n");
            printf(" Digito actual a operar: %c\n", *digitoActual);
            printf(" El digito actual en base 10 es: %i \n", *digitoActualEnDecimal);
            printf(" Potenciamos la base origen \"%i\" a la posicion del numero \"%i\".\n", *baseOrigen, *potencia);
            printf(" lo que resulta: %i\n", *calculoDePotencia);
            printf(" Ahora, se multiplica el digito en base 10 %i por el resultado del calculo\n", *digitoActualEnDecimal);
            printf(" anterior, que da como resultado %i\n", (*digitoActualEnDecimal) * (*calculoDePotencia));
            printf(" Y finalmente, sumamos este resultado parcial al resultado final");
            printf(" %i + %i = ", *resultado, (*digitoActualEnDecimal) * (*calculoDePotencia));
        }


        //Suma el valor del dígitoActual en base 10 al resultado
        *resultado = *resultado +( (*digitoActualEnDecimal) * (*calculoDePotencia) );

        if(*usa_v){
            printf("%i\n", *resultado);
        }

        //Por cada dígito procesado, aumenta en 1 la potencia
        (*potencia)++;

    }

    if(*usa_v){
        printf("\n-------------------------------------------------------------------------\n");

        printf("Resultado final: %i", *resultado);

        printf("\n-.-.-.-.-.-.-.-Fin metodo de la multiplicacion para numeros enteros-.-.-.-.-.-.-.-\n\n\n");


    }

    free(count);
    free(potencia);
    free(calculoDePotencia);
    free(digitoActual);
    free(digitoActualEnDecimal);

}


/**
*Dado el numero expresado como un entero, obtiene su representacion en base destino a traves del
*metodo de la division para numeros enteros.
*resultado : caracter que almacena el resultado de la funcion.
*retultadoSize : entero que almacena la longitud del parametro "resultado".
*baseDestino : base en la que el se representara el parametro "numero" luego de ser procesado.
*numero : arreglo de caracteres que almacena el numero entero.
*usa_V : indica si se debe mostra informacion adicional sobre los computos intermedios de proceso de conversion.
*/
void deBaseDecimalADestinoEntero(char * resultado, int* resultadoSize , int* baseDestino, int *numero, int * usa_v){

    //DECLARACIÓN PUNTEROS
    int *cociente;
    int *resto;
    int *counter;

    //ASIGNACIÓN DE MEMORIA DINÁMICA CON MALLOC
    cociente = (int *) malloc(sizeof(int));
    resto = (int *) malloc(sizeof(int));
    counter = (int *) malloc(sizeof(int));

    //INICIALIZACIÓN VARIABLES
    *cociente = *numero;
    *resto = 0;
    *counter = (*resultadoSize) - 1;


    if(*usa_v){
        printf("\n-.-.-.-.-.-.-.-Metodo de la division para numeros enteros-.-.-.-.-.-.-.-\n");
        printf(" En el metodo de la division para numeros enteros, dividimos el numero por \n");
        printf(" la base destino, y el resto de esta operacion sera añadido a la izquierda extrema\n");
        printf(" del resultado. Para las operaciones siguientes, se toma como el numero el cociente\n");
        printf(" de la ultima division realizada.\n");
        printf(" Este metodo termina cuando el cociente de la division resulta 0. Se opera en la base origen\n");
        printf("-.-.-.-.-.-.-.--.-.-.-.-.-.-.--.-.-.-.-.-.-.--.-.-.-.-.-.-.--.-.-.-.-.-.-.-.-.-\n");
    }


    while( *cociente != 0 ){

        if(*usa_v){
            printf("\n-------------------------------------------------------------------------\n");
            printf(" numero a dividir: %i\n", *cociente);
        }

        *resto = (*cociente) % (*baseDestino);

        obtenerRepresentacionEnBaseCorrespondiente( (resultado + *counter) , resto);

        *cociente = (*cociente) / (*baseDestino);

        if(*usa_v){
            printf(" divisor: %i\n", *baseDestino);
            printf(" cociente division: %i\n", *cociente);
            printf(" resto: %i\n", *resto);
            printf(" pasamos el resto a base destino para ubicarlo en el resultado, resulta: %c\n", *(resultado + *counter));
            printf(" añadimos el resto en base destino al resultado.\n");
        }

        (*counter)--;


    }


    if(*usa_v){
        printf("\n-------------------------------------------------------------------------\n");

        printf("Resultado final: ");

        for(*counter = 0; *counter < *resultadoSize; (*counter)++){
            printf("%c", *(resultado+*counter) );
        }

        printf("\n-.-.-.-.-.-.-.-Fin metodo de la division para numeros enteros-.-.-.-.-.-.-.-\n\n\n");


    }

    free(cociente);
    free(resto);
    free(counter);
}


/**
*Dado el numero expresado como arreglo de caracteres en base origen, obtiene su representacion en base destino
*utilizando la base 10 como paso intermediario.
*resultado : caracter que almacena el resultado de la funcion.
*sizeResultado : entero que almacena la longitud del parametro "resultado".
*numero : arreglo de caracteres que almacena el numero entero.
*sizeNumero : almacena la longitud del parametro "numero".
*baseOrigen : Base en la que el parametro "numero" esta representado
*baseDestino : base en la que el se representara el parametro "numero" luego de ser procesado.
*usa_V : indica si se debe mostra informacion adicional sobre los computos intermedios de proceso de conversion.
*/
void cambioBaseEnteros(char* resultado,int* sizeResultado , char* numero, int* sizeNumero,int* baseOrigen, int* baseDestino, int * usa_v){

    //DECLARACIÓN PUNTEROS
    int * numeroEnBaseDecimal;
    int * i;

    //INICIALIZACIÓN DE MEMORIA Y VARIABLES CON MALLOC

    numeroEnBaseDecimal = (int*) malloc(sizeof(int));


    i = (int*) malloc(sizeof(int));

    //INICIALIZACIÓN DE VARIABLES

    *i = 0;

    *numeroEnBaseDecimal = 0;


    //OPERACIONES


    if(*usa_v){
        printf("\n/////////////////////////////////////////////////////////////////////////////////\n");
        printf("\n Para pasar la parte entera del numero lo que haremos primero es pasar los digitos\n");
        printf("\n del mismo a base 10 con el metodo de la multiplicacion para numeros enteros, \n");
        printf("\n luego pasar el numero representado en base 10 a la base destino utilizando el \n");
        printf("\n metodo de la division para numeros enteros.\n");
        printf("\n/////////////////////////////////////////////////////////////////////////////////\n");
    }

    deBaseOrigenADecimalEntero(numeroEnBaseDecimal, numero, sizeNumero, baseOrigen, usa_v);

    deBaseDecimalADestinoEntero(resultado, sizeResultado, baseDestino, numeroEnBaseDecimal, usa_v);

    //LIBERACIÓN DE MEMORIA
    free(i);
    free(numeroEnBaseDecimal);
}

