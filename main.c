#include <stdio.h>
#include <stdlib.h>
#include <error.h>

/**
*Metodo que inicializa el programa.
*arc : cantidad de parametros recibidos por consola.
*arv : arreglo de string que contiene los parametros recibidos por consola.
*retorna informacion sobre la terminacion anormal del programa.
*/
int main (int argc, char **argv)
{
    integracionGeneral(&argc, argv);

    exit(EXIT_SUCCESS);
    return EXIT_SUCCESS;
}

