/* Figura 11.8: fig11_08.c - Programa de investigación crediticia */
/*
1. Ejecuta el programa.
2. Qué modo utiliza?
3. Agrega en el archivo clientes.dat más datos.
4. Vuelve a ejecutar el programa.
5. Qué hace la función rewind?
6. Modifica el programa usando funciones.
*/

#include <stdio.h>

int main()
{
   int consulta;      /* número de solicitud */
   int cuenta;        /* número de cuenta */
   double saldo;      /* saldo de la cuenta */
   char nombre[ 30 ]; /* nombre de la cuenta */
   FILE *ptrCf;       /* apuntador al archivo clientes.dat */

   /* fopen abre el archivo; si no se puede abrir el archivo, sale del programa */
   if ( ( ptrCf = fopen( "clientes.dat", "r" ) ) == NULL ) {
      printf( "El archivo no pudo abrirse\n" );
   } /* fin de if */
   else {

      /* despliega las opciones de consulta */
      printf( "Introduzca la consulta\n"
         " 1 - Lista las cuentas con saldo cero\n"
         " 2 - Lista las cuentas con saldo a favor\n"
         " 3 - Lista las cuentas con saldo en contra\n"
         " 4 - Fin del programa\n? " );
      scanf( "%d", &consulta );

      /* procesa la consulta del usuario */
      while ( consulta != 4 ) {

         /* lee la cuenta, el nombre y el saldo del archivo */
         fscanf( ptrCf, "%d%s%lf", &cuenta, nombre, &saldo );

         switch ( consulta ) {

            case 1:
               printf( "\nCuentas con saldo cero:\n" );
               /* lee el contenido del archivo (hasta eof) */
               while ( !feof( ptrCf ) ) {
                  if ( saldo == 0 ) printf( "%-10d%-13s%7.2f\n", cuenta, nombre, saldo );
                  /* lee la cuenta, el nombre y el saldo del archivo */
                  fscanf( ptrCf, "%d%s%lf", &cuenta, nombre, &saldo );
               } /* fin de while */

               break;

            case 2:
               printf( "\nCuentas con saldos a favor :\n" );

               /* lee el contenido del archivo (hasta eof) */
               while ( !feof( ptrCf ) ) {
                  if ( saldo < 0 ) printf( "%-10d%-13s%7.2f\n", cuenta, nombre, saldo );
                    /* lee la cuenta, el nombre y el saldo del archivo */
                  fscanf( ptrCf, "%d%s%lf", &cuenta, nombre, &saldo );
               } /* fin de while */

               break;

            case 3:
               printf( "\nCuentas con saldo en contra:\n" );

               /* lee el contenido del archivo (hasta eof) */
               while ( !feof( ptrCf ) ) {
                  if ( saldo > 0 ) printf( "%-10d%-13s%7.2f\n", cuenta, nombre, saldo );
                  /* lee la cuenta, el nombre y el saldo del archivo */
                  fscanf( ptrCf, "%d%s%lf", &cuenta, nombre, &saldo );
               } /* fin while */

               break;

         } /* fin de switch */

         rewind( ptrCf );

         printf( "\n? " );
         scanf( "%d", &consulta );
      } /* fin de while */

      printf( "Fin de la ejecucion.\n" );
      fclose( ptrCf ); /* fclose cierra el archivo */
   } /* fin de else */

   return 0; /* indica terminación exitosa */

} /* fin de main */

