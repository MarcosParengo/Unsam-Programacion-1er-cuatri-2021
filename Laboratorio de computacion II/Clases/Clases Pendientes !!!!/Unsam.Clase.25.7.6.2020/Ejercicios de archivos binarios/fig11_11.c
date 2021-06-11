/* Figura 11.11: fig11_11.c - Creación secuencial de un archivo de acceso aleatorio*/
/*
1. Ejecuta el programa.
2. Abre el archivo creado y observa el contenido.
3. Modifica el archivo fuente usando funciones.
*/
#include <stdio.h>

/* definición de la estructura datosCliente */
struct datosCliente { 
   int numCta;          /* número de cuenta */
   char apellido[ 15 ]; /* apellido de la cuenta */
   char nombre[ 10 ];   /* nombre de la cuenta */
   double saldo;        /* saldo de la cuenta */
}; /* fin de la estructura datosCliente */

main()
{ 
   int i; /* contador utilizado para contar de 1 a 10 */

   /* crea una variable de tipo datosCliente con información predeterminada */
   struct datosCliente clienteEnBlanco = { 0, "", "", 0.0 }; 
   
   FILE *ptrCf; /* apuntador al archivo credito.dat */

   /* fopen abre el archivo; si no se puede abrir, sale del archivo */
   if ( ( ptrCf = fopen( "c:\\credito.dat", "wb" ) ) == NULL ) printf( "No pudo abrirse el archivo.\n" );

   else { 
      /* escribe 10 registros en blanco en el archivo */
      for ( i = 1; i <= 10; i++ ) {
         fwrite( &clienteEnBlanco, sizeof( struct datosCliente ), 1, ptrCf );
      } /* fin de for */

      fclose ( ptrCf ); /* fclose cierra el archivo */
   } /* fin de else */

   return 0; /* indica terminación exitosa */

} /* fin de main */
