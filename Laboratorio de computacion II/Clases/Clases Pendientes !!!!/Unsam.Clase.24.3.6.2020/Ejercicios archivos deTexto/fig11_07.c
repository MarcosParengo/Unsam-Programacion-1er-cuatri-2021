/* Figura 11.7: fig11_07.c - Lectura e impresión de un archivo de texto */
/*
1. Ejecuta el programa.
2. Abre el archivo clientes.dat y compara con lo que se emitió en la ejecución por pantalla.
3. Qué modo se utilizó para la apertura del archivo?. Coméntalo en el archivo fuente.
4. Qué función se utilizó para leer del archivo?. Coméntalo en el archivo fuente.
5. Investiga cómo funciona: !feof(ptrCf).
6. Qué cambios deberías hacer y en dónde para agregar datos al archivo sin perder el contenido anterior?.
7. Elimina el archivo clientes.dat, crea en el bloc de notas un archivo con el mismo nombre y
agrega datos de 2 clientes. Ejecuta este programa. Qué sucedió?
8. Modifica el programa usando funciones.
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
   int cuenta;        /* número de cuenta */
   char nombre[ 30 ]; /* nombre de cuenta */
   double saldo;      /* saldo de la cuenta */

   FILE *ptrCf;     /* ptrCf = apuntador al archivo clientes.dat */

   /* fopen abre el archivo; si no se puede abrir el archivo, abandona el programa */
   if ( ( ptrCf = fopen( "clientes.dat", "r" ) ) == NULL ) {
      printf( "El archivo no pudo abrirse\n" );
   } /* fin de if */
   else {
      printf( "%-10s%-13s%s\n", "Cuenta", "Nombre", "Saldo" );
      fscanf( ptrCf, "%d%s%lf", &cuenta, nombre, &saldo );

      while ( !feof( ptrCf ) ) {
         printf( "%-10d%-13s%7.2f\n", cuenta, nombre, saldo );
         fscanf( ptrCf, "%d%s%lf", &cuenta, nombre, &saldo );
      } /* fin de while */

      fclose( ptrCf ); /* fclose cierra el archivo */
   } /* fin de else */

   system("pause");
   return 0; /* indica terminación exitosa */

} /* fin de main */

