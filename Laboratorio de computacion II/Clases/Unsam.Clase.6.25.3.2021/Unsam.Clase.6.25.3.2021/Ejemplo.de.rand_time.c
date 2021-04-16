#include <stdio.h>
#include <time.h> /* contiene el prototipo de la función time */

/* la función main comienza la ejecución del programa */
int main()
{

    /* randomiza el generador de números aleatorios mediante el uso de la función time */
   srand( time( NULL ) );

   int i; /* contador */

   //printf("\nEl numero %d fue dado por rand\n", rand());

   /* repite 10 veces */
   for ( i = 0; i < 10; i++ )

      /* obtiene un número aleatorio entre 1 y 6 y lo despliega */
      printf( "%d\n", 1 + ( rand() % 6 ) );


getchar();
   return 0; /* indica terminación exitosa */


} /* fin de main */


/*
Para resolver debemos buscar la forma de obtener un número que sea distinto en
la ejecución de cada programa. Se utiliza habitualmente
para ello la fecha/hora del sistema. Este valor cambia si ejecutamos el programa
en distinto instante de tiempo. Tendríamos que arrancar el programa dos veces en
el mismo segundo para obtener la misma secuencia de números aleatorios.
srand (time(NULL));
*/
