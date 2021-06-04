/*Ejemplo 3*/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define LIN 100 /* máximo número de lineas de texto */
#define LONG 255 /* máximo número de caracteres por linea de texto */

/* prototipos */
char menu();
int readText( char s[][LONG + 1] );
long printText( const char s[][LONG + 1], const int t );


/* la función main() comienza la ejecución del programa */
int main() {
char texto[LIN][LONG + 1] = { "" }; /* iniciar todas las cadenas a nulo */
int t;
char opcion;

/* ciclo de control del programa */
   while ( (opcion = menu()) != 'S' ) {
        switch ( opcion ) {
        case 'N':   t = readText( texto ); break;
        case 'M':  printText( texto, t ); break;
        default:  printf( "\n Opción no válida\n\n" ); break; }
printf( "\n\n\t PULSE UNA TECLA PARA IR AL MENU PRINCIPAL... " );
getchar(); /* pausa */
}
return 0; /* indicar terminación exitosa */
} /* fin de main() */



/*--------- IMPLEMENTACIÓN DE FUNCIONES------------ */
/* LEER: devuelve la opción elegida por el usuario */
char menu() {
char c;
    system( "cls" ); //limpia la pantalla
    printf( "\n (N) Nuevo texto" );
    printf( "\n (M) Mostrar texto" );
    printf( "\n (S) Salir\n" );
    printf( "\n ?: " );
    c = (char) toupper( getchar() );
    system( "cls" );
return c;}



/* LEER: lee el texto y devuelve el número de lineas ingresadas */
int readText( char s[][LONG + 1] ){
int t;
printf( "\n Ingrese su texto (una linea en blanco para terminar):\n\n" );
s[0][0] = '\0'; /* iniciar la primera cadena a nulo */
    for ( t = 0; t < LIN; ++t ) {
        printf( "%2d: ", t );
        gets( &s[t][0] );
        /* salir en caso de linea en blanco */
        if ( !s[t][0] ) break;}
return t;}


/* LEER: imprime el texto caracter a caracter, devuelve el número de caracteres impresos */
long printText( const char s[][LONG + 1], const int t ){
int i, j;
/* si el primer caracter del texto es nulo */
    if ( !s[0][0] ) {
    printf( "\n\t No hay texto que mostrar\n" );
    return 0;}
printf( "\n\t Su texto es:\n\t ===========\n\n" );
    for ( i = 0; i < t; ++i ) {
    printf( "%2d: ", i );
        for ( j = 0; s[i][j]; ++j )
        printf( "%c", s[i][j] );
        printf( "\n" );}
return i * j;
}
