/*Programa de repetici�n controlada por contador */
#include <stdio.h>

/* la funci�n main inicia la ejecuci�n del programa */
int main()
{
   int contador;     /* n�mero de la calificaci�n siguiente */

   /* fase de inicializaci�n */
     contador = 1; /* inicializa el contador del ciclo */

   /* fase de proceso */
   while ( contador <= 10 ) {     /* repite 10 veces el ciclo */

      contador = contador + 1;      /* incrementa el contador */
      printf( "\n valor de contador es: %d ", contador);
     } /* fin de while */

   /* fase de terminaci�n */

   getchar();
   return 0; /* indica que el programa termin� con exito */
} /* fin de la funci�n main */
