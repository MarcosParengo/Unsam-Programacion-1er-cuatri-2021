#include <stdio.h>

/* la función main comienza la ejecución del programa */
int main()
{
   int x; /* contador */

   /* repite el ciclo 10 veces */
   for ( x = 1; x <= 10; x++ )

      printf( "%d ", x ); /* despliega el valor de x */
    /* fin de for */

   getchar();
   return 0; /* indica la terminación exitosa del programa */

} /* fin de la función main */

