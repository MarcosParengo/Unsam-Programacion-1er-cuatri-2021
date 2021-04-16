/* Figura 5.8: fig05_08.c
   Tiro de un dado de seis lados 6000 veces */
#include <stdio.h>
#include <stdlib.h>

/* la función main comienza la ejecución del programa */
int main()
{
   int frecuencia1 = 0; /* contador del tiro 1 */
   int frecuencia2 = 0; /* contador del tiro 2 */
   int frecuencia3 = 0; /* contador del tiro 3 */
   int frecuencia4 = 0; /* contador del tiro 4 */
   int frecuencia5 = 0; /* contador del tiro 5 */
   int frecuencia6 = 0; /* contador del tiro 6 */

   int tiro; /* contador de tiros, valores de 1 a 6000 */
   int cara; /* representa un tiro del dado, valores de 1 a 6 */

   /* repite 6000 veces y resume los resultados */
   for ( tiro = 1; tiro <= 6000; tiro++ ) {
      cara = 1 + rand() % 6; /* número aleatorio de 1 a 6 */

      /* determina el valor de la cara e incrementa el contador apropiado */
      switch ( cara ) {

         case 1: /* tiro 1 */
            ++frecuencia1;
            break;

         case 2: /* tiro 2 */
            ++frecuencia2;
            break;
       
         case 3: /* tiro 3 */
            ++frecuencia3;
            break;
         
         case 4: /* tiro 4 */
            ++frecuencia4;
            break;
         
         case 5: /* tiro 5 */
            ++frecuencia5;
            break;
         
         case 6: /* tiro 6 */
            ++frecuencia6;
            break; /* opcional */
      } /* fin de switch */

   } /* fin de for */
   
   /* despliega los resultados en forma tabular */
   printf( "%s%13s\n", "Cara", "Frecuencia" );
   printf( "   1%13d\n", frecuencia1 );
   printf( "   2%13d\n", frecuencia2 );
   printf( "   3%13d\n", frecuencia3 );
   printf( "   4%13d\n", frecuencia4 );
   printf( "   5%13d\n", frecuencia5 );
   printf( "   6%13d\n", frecuencia6 );
   
   return 0; /* indica terminación exitosa */

} /* fin de main */



/**************************************************************************
 * (C) Copyright 1992-2004 by Deitel & Associates, Inc. and               *
 * Pearson Education, Inc. All Rights Reserved.                           *
 *                                                                        *
 * DISCLAIMER: The authors and publisher of this book have used their     *
 * best efforts in preparing the book. These efforts include the          *
 * development, research, and testing of the theories and programs        *
 * to determine their effectiveness. The authors and publisher make       *
 * no warranty of any kind, expressed or implied, with regard to these    *
 * programs or to the documentation contained in these books. The authors *
 * and publisher shall not be liable in any event for incidental or       *
 * consequential damages in connection with, or arising out of, the       *
 * furnishing, performance, or use of these programs.                     *
 *************************************************************************/
