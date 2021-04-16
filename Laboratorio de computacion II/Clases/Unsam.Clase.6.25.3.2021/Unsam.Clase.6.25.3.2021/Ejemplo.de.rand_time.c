#include <stdio.h>
#include <time.h> /* contiene el prototipo de la funci�n time */

/* la funci�n main comienza la ejecuci�n del programa */
int main()
{

    /* randomiza el generador de n�meros aleatorios mediante el uso de la funci�n time */
   srand( time( NULL ) );

   int i; /* contador */

   //printf("\nEl numero %d fue dado por rand\n", rand());

   /* repite 10 veces */
   for ( i = 0; i < 10; i++ )

      /* obtiene un n�mero aleatorio entre 1 y 6 y lo despliega */
      printf( "%d\n", 1 + ( rand() % 6 ) );


getchar();
   return 0; /* indica terminaci�n exitosa */


} /* fin de main */


/*
Para resolver debemos buscar la forma de obtener un n�mero que sea distinto en
la ejecuci�n de cada programa. Se utiliza habitualmente
para ello la fecha/hora del sistema. Este valor cambia si ejecutamos el programa
en distinto instante de tiempo. Tendr�amos que arrancar el programa dos veces en
el mismo segundo para obtener la misma secuencia de n�meros aleatorios.
srand (time(NULL));
*/
