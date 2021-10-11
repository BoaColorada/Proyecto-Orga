#include <ctype.h>
#include <stdlib.h>
#include <error.h>

#include <stdio.h>

#define MAX_BASE_SIZE 16
#define MIN_BASE_SIZE 2
#define MAX_ARG_SIZE 16
#define DEFAULT_BASE 10
#define TEST_MODE 1

#define PARAM_CANT_ERROR -1

int * verificarBase(char * base, int * baseEntero){

    int * baseTransformada;
    int * cantDigitosBase;

    baseTransformada = (int*) malloc(sizeof(int));

    cantDigitosBase = (int*) malloc(sizeof(int));


    *baseTransformada = 0;
    *cantDigitosBase = 0;


    #ifdef TEST_MODE

        printf("\n ------------- INICIO METODO verificarBase ------------- \n");

        printf("\nParametro base Inicial: \n");
        printf("%c%c \n", *base, *(base+1));
        printf("\n");

        printf("\nParametro baseEntero Inicial: \n");
        printf("%i \n", *baseEntero);
        printf("\n");

        printf("\n baseTransformada Inicial: \n");
        printf("%i \n", *baseTransformada);
        printf("\n");

        printf("\n cantDigitosBase Inicial: \n");
        printf("%i \n", *cantDigitosBase);
        printf("\n");

    #endif // TEST_MODE

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
        exit(0);
    }

    if(*cantDigitosBase == 2 ){
        if(*base >= 48 && *base <=54){
            *baseTransformada = (*baseTransformada) * 10 + ((*base) - 48);
        } else {
            printf("Base fuera de limites");
            exit(0);
        }
    }

     #ifdef TEST_MODE

        printf("\n ------------- INTERMEDIO METODO verificarBase ------------- \n");

        printf("\n baseTransformada Intermedio: \n");
        printf("%i \n", *baseTransformada);
        printf("\n");

    #endif // TEST_MODE

    if(( (MIN_BASE_SIZE) <= *baseTransformada) && (*baseTransformada <= (MAX_BASE_SIZE))){
        *baseEntero = *baseTransformada;
    } else {
        printf("Base fuera de límites");
        exit(0);
    }

     #ifdef TEST_MODE

        printf("\n ------------- LUEGO DE OPERACIONES METODO verificarBase ------------- \n");

        printf("\nParametro base final: \n");
        printf("%c \n", *base);
        printf("\n");

        printf("\nParametro baseEntero final: \n");
        printf("%i \n", *baseEntero);
        printf("\n");

        printf("\n baseTransformada final: \n");
        printf("%i \n", *baseTransformada);
        printf("\n");

        printf("\n cantDigitosBase final: \n");
        printf("%i \n", *cantDigitosBase);
        printf("\n");

        printf("\n ------------- FINAL METODO verificarBase ------------- \n");

    #endif // TEST_MODE


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


     #ifdef TEST_MODE

        printf("\n ------------- INICIO METODO verificarNumero ------------- \n");

        printf("\nParametro numero Inicial: \n");
        printf("%c \n", *numero);
        printf("\n");

        printf("\nParametro base Inicial: \n");
        printf("%i \n", *base);
        printf("\n");

        printf("\n puntoEncontrado Inicial: \n");
        printf("%i \n", *puntoEncontrado);
        printf("\n");

        printf("\n asciiNumericoMaximo Inicial: \n");
        printf("%i \n", *asciiNumericoMaximo);
        printf("\n");

        printf("\n asciiLetraMinimo Inicial: \n");
        printf("%i \n", *asciiLetraMinimo);
        printf("\n");

        printf("\n asciiLetraMaximo Inicial: \n");
        printf("%i \n", *asciiLetraMaximo);
        printf("\n");

        printf("\n----OPERACIONES-----\n");
    #endif // TEST_MODE


    while(*numero != '\0'){

            #ifdef TEST_MODE

                printf("\n numero actual: \n");
                printf("Numero: %c \n", *numero);
                printf("ASCII: %i \n", *numero);
                printf("\n");

            #endif // TEST_MODE

        if(*numero >= 97 && *numero <= 102){
            *numero = toupper(*numero);
        }

        if(*puntoEncontrado && *numero == 46){
            printf("Error: Argumento -n contiene más de un punto");
            exit(0);
        }
        if(*numero == 46){
            *puntoEncontrado = 1;
        }

        if((*asciiLetraMaximo != -1) && (*asciiLetraMinimo != -1)){
            if( (*numero < 48 || *numero > *asciiNumericoMaximo) && (*numero < *asciiLetraMinimo || *numero > *asciiLetraMaximo) && *numero != 46)   {
                printf("Error: Argumento -n contiene caracteres que no son propios de la base origen.");
                exit(0);
            }
        } else if ( (*numero < 48 || *numero > *asciiNumericoMaximo) && *numero != 46 ){
            printf("Error: Argumento -n contiene caracteres que no son propios de la base origen.");
            exit(0);
        }
        numero++;
    }

    #ifdef TEST_MODE

        printf("\n ------------- LUEGO METODO verificarNumero ------------- \n");

        printf("\nParametro numero final: \n");
        printf("%c \n", *numero);
        printf("\n");

        printf("\nParametro base final: \n");
        printf("%i \n", *base);
        printf("\n");

        printf("\n puntoEncontrado final: \n");
        printf("%i \n", *puntoEncontrado);
        printf("\n");

        printf("\n asciiNumericoMaximo final: \n");
        printf("%i \n", *asciiNumericoMaximo);
        printf("\n");

        printf("\n asciiLetraMinimo final: \n");
        printf("%i \n", *asciiLetraMinimo);
        printf("\n");

        printf("\n asciiLetraMaximo final: \n");
        printf("%i \n", *asciiLetraMaximo);
        printf("\n");

    #endif // TEST_MODE

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

        #ifdef TEST_MODE
                printf("Recorrido numero: %c \n", *recorridoNumero);
                printf("Recorrido numeroSizeEntero: %i \n", *numeroSizeEntero);
                printf("Recorrido numeroSizeFraccionario: %i \n", *numeroSizeFraccionario);
                printf("////////////////////////////////////////////// \n");
        #endif // TEST_MODE

        recorridoNumero++;
    }


    if(*parteEnteraSize < *numeroSizeEntero || *parteFraccionariaSize < *numeroSizeFraccionario){
        printf("Error: el tamaño de los arreglos de salida no es suficiente para el parámetro nu    mero indicado");
        exit(0);
    }


    #ifdef TEST_MODE
            printf("numeroSizeEntero: %i\n", *numeroSizeEntero);
            printf("numeroSizeFraccionario: %i\n", *numeroSizeFraccionario);
    #endif

    for(*i = (*numeroSizeEntero) - 1; *i>=0; (*i)--){

        *(parteEntera + *parteEnteraSize - *i - 1 ) = *numero++;



        #ifdef TEST_MODE
                printf("Parte entera[%i]: %c \n", *i, *(parteEntera + *parteEnteraSize - *i - 1 ));
        #endif

    }

    numero++;

    for(*i = 0; *i<*numeroSizeFraccionario; (*i)++){

        *(parteFraccionaria) = *(numero);

        #ifdef TEST_MODE
                printf("Parte fraccionaria[%i]: %c \n", *i, *parteFraccionaria);
        #endif

        parteFraccionaria++;
        numero++;
    }


    /*
    free(numeroSizeEntero);
    free(numeroSizeFraccionario);
    free(posicionPunto);
    free(i);
    */
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

    caracterActual = (char*) malloc(sizeof(char));


    //INICIALIZACIÓN VARIABLES
    *i = 0;

    *cantArgumentos = *argc;

    *caracterActual = 'Z';

    *posicionNumero = 'Z';

    *baseDestino = DEFAULT_BASE;
    *baseOrigen = DEFAULT_BASE;
    *usa_h = 0;
    *usa_v = 0;


     #ifdef TEST_MODE

        printf("\n ------------- INICIO METODO verificarParametrosConsola ------------- \n");

        printf("\nParametro parteEntera Inicial: \n");
        printf("%c \n", *parteEntera);
        printf("\n");

        printf("\nParametro parteEnteraSize Inicial: \n");
        printf("%i \n", *parteEnteraSize);
        printf("\n");

        printf("\nParametro parteFraccionaria Inicial: \n");
        printf("%c \n", *parteFraccionaria);
        printf("\n");

        printf("\nParametro parteFraccionariaSize Inicial: \n");
        printf("%i \n", *parteFraccionariaSize);
        printf("\n");

        printf("\nParametro baseOrigen Inicial: \n");
        printf("%i \n", *baseOrigen);
        printf("\n");

        printf("\nParametro baseDestino Inicial: \n");
        printf("%i \n", *baseDestino);
        printf("\n");

        printf("\nParametro usa_h Inicial: \n");
        printf("%i \n", *usa_h);
        printf("\n");

        printf("\nParametro usa_v Inicial: \n");
        printf("%i \n", *usa_v);
        printf("\n");



        printf("\n i Inicial: \n");
        printf("%i \n", *i);
        printf("\n");

        printf("\n cantArgumentos Inicial: \n");
        printf("%i \n", *cantArgumentos);
        printf("\n");

        printf("\n posicionNumero Inicial: \n");
        printf("%c \n", *posicionNumero);
        printf("\n");

        printf("\n caracterActual Inicial: \n");
        printf("%c \n", *caracterActual);
        printf("\n");

    #endif // TEST_MODE



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
                            exit(0);
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
                            exit(0);
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
                            exit(0);
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
                            exit(0);
                        }

                        *usa_v = 1;

                    break;
                    case 'h':
                        caracterActual++;

                        //Si -h está seguido de algún otro caracter, error
                        if(*caracterActual != '\0'){
                            printf("Parámetros incorrectos");
                            exit(0);
                        }

                        *usa_h = 1;
                    break;
                    }


                } else {
                    printf("Error: argumentos incorrectos");
                    exit(0);
                }

            }

        }



        verificarNumero(posicionNumero, baseOrigen);
        separarNumero(posicionNumero , parteEntera, parteEnteraSize , parteFraccionaria,parteFraccionariaSize);
    }

    #ifdef TEST_MODE

        printf("\n ------------- FINAL METODO verificarParametrosConsola ------------- \n");

        printf("\nParametro parteEntera Final: \n");
        for(int i = 0; i<*parteEnteraSize; i++){
            printf("%c" ,*parteEntera);
            parteEntera++;
        }
        printf("\n");

        printf("\nParametro parteEnteraSize Final: \n");
        printf("%i \n", *parteEnteraSize);
        printf("\n");

        printf("\nParametro parteFraccionaria Final: \n");
        for(int i = 0; i<*parteFraccionariaSize; i++){
            printf("%c" ,*parteFraccionaria);
            parteFraccionaria++;
        }
        printf("\n");

        printf("\nParametro parteFraccionaria Final: \n");
        printf("%i \n", *parteFraccionaria);
        printf("\n");






        printf("\nParametro baseOrigen Final: \n");
        printf("%i \n", *baseOrigen);
        printf("\n");

        printf("\nParametro baseDestino Final: \n");
        printf("%i \n", *baseDestino);
        printf("\n");

        printf("\nParametro usa_h Final: \n");
        printf("%i \n", *usa_h);
        printf("\n");

        printf("\nParametro usa_v Final: \n");
        printf("%i \n", *usa_v);
        printf("\n");


        printf("\n i Final: \n");
        printf("%i \n", *i);
        printf("\n");

        printf("\n cantArgumentos Final: \n");
        printf("%i \n", *cantArgumentos);
        printf("\n");

        printf("\n posicionNumero Final: \n");
        printf("%c \n", *posicionNumero);
        printf("\n");

        printf("\n caracterActual Final: \n");
        printf("%c \n", *caracterActual);
        printf("\n");

        printf("METODO verificarParametrosConsola PASADO EXITOSAMENTE\n");

    #endif // TEST_MODE

    free(i);
    free(cantArgumentos);
    //free(caracterActual);
    //free(posicionNumero);


    return 0;
}


