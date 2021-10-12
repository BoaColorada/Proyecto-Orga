#include <stdio.h>

//Muestra la sintaxis y semantica del programa en pantalla.
void help(){

    printf("\n----------------------------AYUDA DE CONVERT----------------------------\n");

    printf("SINTAXIS:\n");
    printf("convert -n <number> [-s <source_base>] [-d <dest_base>] [-v] [-h]\n");
    printf("\n\n");



    printf("Descripci�n de cada par�metro:\n\n");

    printf("convert:\n");
    printf("    El nombre del programa, es obligatorio y siempre se debe encontrar al inicio.\n\n");

    printf("-n <number>:\n");
    printf("    <number> Indica el n�mero que se quiere cambiar de base, este debe ser limitado\n");
    printf("    a 10 d�gitos para su parte entera, y 5 digitos para su parte fraccionaria,\n");
    printf("    con ambas partes separadas por un punto.\n");
    printf("-s <source_base>:\n");


    printf("    Parametro opcional que indica la base de origen del numero ingresado, \n");
    printf("    en caso de que no se especifique, se asume que el n�mero est� en base 10.\n");
    printf("    La m�nima base origen posible es 2, y la m�xima es 16.\n");

    printf("-d <dest_base>:\n");
    printf("    Parametro opcional que indica la base destino para convertir el numero ingresado,\n");
    printf("    en caso de que no se especifique, se asume que el n�mero se convertir� a\n");
    printf("    base 10. La m�nima base destino posible es 2, y la m�xima es 16.\n");

    printf("-v:\n");
    printf("    Parametro opcional. En caso de que se llame al programa con este par�metro,\n");
    printf("    se mostrar� por pantalla los pasos intermedios que se utilizan para\n");
    printf("    efectuar el cambio de base\n");

    printf("\n Autores: \n");
    printf("-Nombre: Agustin Cuello, LU 130678\n");
    printf("-Nombre: Guillermo Rodriguez, LU 120921");

    printf("\n------------------------------------------------------------------------\n");

    perror("ERROR");
}
