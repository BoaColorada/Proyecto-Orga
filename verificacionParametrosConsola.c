#include <ctype.h>
#include <stdlib.h>
#include <error.h>

#include <stdio.h>

#define MAX_BASE_SIZE 16
#define MIN_BASE_SIZE 2
#define MAX_ARG_SIZE 16
#define DEFAULT_BASE 10

int * verificarBase(char * base, int * baseEntero){

    int * baseTransformada;
    int * cantDigitosBase;

    baseTransformada = (int*) malloc(sizeof(int));

    cantDigitosBase = (int*) malloc(sizeof(int));


    *baseTransformada = 0;
    *cantDigitosBase = 0;


    if( (*(base+1)) == '\0'){
        *cantDigitosBase = 1;
    } else if ( (*(base+2)) == '\0') {
        *cantDigitosBase = 2;
    } else {
        printf("Base fuera de limites");
    }

    if(*base>=48 && *base<=57){
        *baseTransformada = (*baseTransformada) + ((*base) - 48);
        base++;
    } else {
        printf("Base fuera de limites");
        exit(EXIT_FAILURE);
    }

    if(*cantDigitosBase == 2 ){
        if(*base >= 48 && *base <=54){
            *baseTransformada = (*baseTransformada) * 10 + ((*base) - 48);
        } else {
            printf("Base fuera de limites");
            exit(EXIT_FAILURE);
        }
    }


    if(( (MIN_BASE_SIZE) <= *baseTransformada) && (*baseTransformada <= (MAX_BASE_SIZE))){
        *baseEntero = *baseTransformada;
    } else {
        printf("Base fuera de límites");
        exit(EXIT_FAILURE);
    }


    free(baseTransformada);

    return 0;
}

//Verifica que el numero esté expresado correctamente en la base pasada por parámetros.
int * verificarNumero(char * numero, int * base){

    //DECLARACION PUNTEROS
    int * puntoEncontrado;
    int * asciiNumericoMaximo;
    int * asciiLetraMinimo;
    int * asciiLetraMaximo;

    //INICIALIZACIÓN DE MEMORIA Y VARIABLES CON MALLOC
    puntoEncontrado = (int*) malloc(sizeof(int));
    asciiNumericoMaximo = (int*) malloc(sizeof(int));
    asciiLetraMinimo = (int*) malloc(sizeof(int));
    asciiLetraMaximo = (int*) malloc(sizeof(int));

    //INICIALIZACIÓN DE VARIABLES
    *puntoEncontrado = 0;

    *asciiNumericoMaximo = (*base)+47;
    if(*asciiNumericoMaximo > 57){
        *asciiNumericoMaximo = 57;
    }

    if(*base <= 10){
        *asciiLetraMinimo = -1;
        *asciiLetraMaximo = -1;
    } else {
        *asciiLetraMinimo = 65;
        *asciiLetraMaximo = *base + 54;
    }


    while(*numero != '\0'){


        if(*numero >= 97 && *numero <= 102){
            *numero = toupper(*numero);
        }

        if(*puntoEncontrado && *numero == 46){
            printf("Error: Argumento -n contiene más de un punto");
            exit(EXIT_FAILURE);
        }
        if(*numero == 46){
            *puntoEncontrado = 1;
        }

        if((*asciiLetraMaximo != -1) && (*asciiLetraMinimo != -1)){
            if( (*numero < 48 || *numero > *asciiNumericoMaximo) && (*numero < *asciiLetraMinimo || *numero > *asciiLetraMaximo) && *numero != 46)   {
                printf("Error: Argumento -n contiene caracteres que no son propios de la base origen.");
                exit(EXIT_FAILURE);
            }
        } else if ( (*numero < 48 || *numero > *asciiNumericoMaximo) && *numero != 46 ){
            printf("Error: Argumento -n contiene caracteres que no son propios de la base origen.");
            exit(EXIT_FAILURE);
        }
        numero++;
    }

    free(puntoEncontrado);
    free(asciiNumericoMaximo);
    free(asciiLetraMinimo);
    free(asciiLetraMaximo);


    return 0;
}

//Separa un numero "numero" representado como arreglo de caracteres en dos arreglos:
//"parteEntera" de tamaño "parteEnteraSize", y "parteFraccionaria" de "parteFraccionariaSize"
void separarNumero(char * numero ,char * parteEntera, int * parteEnteraSize , char * parteFraccionaria, int * parteFraccionariaSize){

    //DECLARACION PUNTEROS
    int * i;
    int * posicionPunto;
    int * numeroSizeEntero;
    int * numeroSizeFraccionario;
    char * recorridoNumero;


    //INICIALIZACIÓN DE MEMORIA Y VARIABLES CON MALLOC
    posicionPunto = (int*) malloc(sizeof(int));
    numeroSizeEntero = (int*) malloc(sizeof(int));
    numeroSizeFraccionario = (int*) malloc(sizeof(int));
    i = (int*) malloc(sizeof(int));

    *numeroSizeEntero = 0;
    *numeroSizeFraccionario = 0;
    *posicionPunto = 0;
    recorridoNumero = numero;
    *i = 0;

    while(*recorridoNumero != '\0'){
        if(*recorridoNumero == 46){
            *posicionPunto = *numeroSizeEntero;
        } else if(*posicionPunto == 0){
            (*numeroSizeEntero)++;
        }else if(*posicionPunto != 0){
            (*numeroSizeFraccionario)++;
        }


        recorridoNumero++;
    }


    if(*parteEnteraSize < *numeroSizeEntero || *parteFraccionariaSize < *numeroSizeFraccionario){
        printf("Error: el tamaño de los arreglos de salida no es suficiente para el parámetro nu    mero indicado");
        exit(EXIT_FAILURE);
    }


    for(*i = (*numeroSizeEntero) - 1; *i>=0; (*i)--){

        *(parteEntera + *parteEnteraSize - *i - 1 ) = *numero++;

    }

    numero++;

    for(*i = 0; *i<*numeroSizeFraccionario; (*i)++){

        *(parteFraccionaria) = *(numero);

        parteFraccionaria++;
        numero++;
    }


    free(i);
    free(posicionPunto);
    free(numeroSizeEntero);
    free(numeroSizeFraccionario);
}

//Verifica los "argc" argumentos contenidos en "argv" y según corresponda, devuelve el numero, su tamaño,
//la base origen, la base destino, y si utiliza -v y/o -h
int verificarParametrosConsola(int * argc, char **argv, char * parteEntera,int * parteEnteraSize, char * parteFraccionaria,int * parteFraccionariaSize, int * baseOrigen, int * baseDestino, int * usa_v, int * usa_h){

    //DECLARACIÓN PUNTEROS
    int * i;
    int * cantArgumentos;
    char * posicionNumero;
    char * caracterActual;

    //INICIALIZACIÓN DE MEMORIA Y VARIABLES CON MALLOC
    i = (int*) malloc(sizeof(int));

    cantArgumentos = (int*) malloc(sizeof(int));

    posicionNumero = (char*) malloc(sizeof(char));

    //INICIALIZACIÓN VARIABLES
    *i = 0;

    *cantArgumentos = *argc;

    *posicionNumero = 'Z';

    *baseDestino = DEFAULT_BASE;
    *baseOrigen = DEFAULT_BASE;
    *usa_h = 0;
    *usa_v = 0;

    //OPERACIONES

    if((*argc < 3) || (*argc > 9)){
        printf("Cantidad de argumentos no correcta");
        exit(EXIT_FAILURE);
    } else {

        for(*i = 1; *i < *cantArgumentos; (*i)++){

            caracterActual = *(argv + *i);

            while(*caracterActual != '\0'){

                if(*caracterActual == '-'){

                    caracterActual++;

                    switch (*caracterActual){
                    case 'n':
                        caracterActual++;

                        //Si -n está seguido de algún otro caracter, error
                        if(*caracterActual != '\0'){
                            printf("Parámetros incorrectos");
                            exit(EXIT_FAILURE);
                        }

                        //Salteamos el numero en argv
                        (*i)++;

                        posicionNumero = *(argv + *i);


                    break;
                    case 's':

                        caracterActual++;

                        //Si -s está seguido de algún otro caracter, error
                        if(*caracterActual != '\0'){
                            printf("Parámetros incorrectos");
                            exit(EXIT_FAILURE);
                        }

                        //Salteamos el valor de la base
                        (*i)++;

                        verificarBase(*(argv + *i), baseOrigen);

                    break;
                    case 'd':

                        caracterActual++;

                        //Si -n está seguido de algún otro caracter, error
                        if(*caracterActual != '\0'){
                            printf("Parámetros incorrectos");
                            exit(EXIT_FAILURE);
                        }

                        //Salteamos el valor de la base
                        (*i)++;

                        verificarBase(*(argv + *i), baseDestino);

                    break;
                    case 'v':
                        caracterActual++;

                        //Si -v está seguido de algún otro caracter, error
                        if(*caracterActual != '\0'){
                            printf("Parámetros incorrectos");
                            exit(EXIT_FAILURE);
                        }

                        *usa_v = 1;

                    break;
                    case 'h':
                        caracterActual++;

                        //Si -h está seguido de algún otro caracter, error
                        if(*caracterActual != '\0'){
                            printf("Parámetros incorrectos");
                            exit(EXIT_FAILURE);
                        }

                        *usa_h = 1;
                    break;
                    }


                } else {
                    printf("Error: argumentos incorrectos");
                    exit(EXIT_FAILURE);
                }

            }

        }

        verificarNumero(posicionNumero, baseOrigen);
        separarNumero(posicionNumero , parteEntera, parteEnteraSize , parteFraccionaria,parteFraccionariaSize);
    }

    free(i);
    free(cantArgumentos);
    free(posicionNumero);


    return 0;
}


