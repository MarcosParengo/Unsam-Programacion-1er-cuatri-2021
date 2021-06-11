/* Figura 11.3: fig11_03.c- Ejemplo de creación de un archivo de texto */
/*
1. Ejecuta el programa.
2. Busca el archivo creado, observa el contenido.
3. Vuelve a ejecutar el programa.
4. Nuevamente observa el contenido, qué sucedió?
5. Qué modo se utilizó para la apertura del archivo?. Coméntalo en el archivo fuente.
6. Qué función se utilizó para escribir en el archivo?. Coméntalo en el archivo fuente.
7. Investiga cómo funciona: !feof(stdin). (Deitel, Cap. 11).
8. Modifica el programa usando funciones.
*/

#include <stdio.h>

int main()
{
   int cuenta;        /* número de cuenta */
   char nombre[30]; /* nombre de cuenta */
   double saldo;      /* saldo de la cuenta */

   FILE *ptrCf;     /* ptrCf = apuntador al archivo clientes.dat */

   if ( ( ptrCf = fopen( "clientes.dat", "a" ) ) == NULL ) {
      printf( "El archivo no pudo abrirse\n" );
   } /* fin de if */
   else {
      printf( "Introduzca la cuenta, el nombre, y el saldo.\n" );
      printf( "Introduzca Ctrl + Z para finalizar la entrada.\n" );
      scanf( "%d%s%lf", &cuenta, nombre, &saldo );

      while ( !feof(stdin)) {
         fprintf( ptrCf, "%d %s %.2f\n", cuenta, nombre, saldo );
         scanf( "%d%s%lf", &cuenta, nombre, &saldo );
      } /* fin de while */

      fclose( ptrCf ); /* fclose cierra el archivo */
   } /* fin de else */

   return 0; /* indica terminación exitosa */

} /* fin de main */
