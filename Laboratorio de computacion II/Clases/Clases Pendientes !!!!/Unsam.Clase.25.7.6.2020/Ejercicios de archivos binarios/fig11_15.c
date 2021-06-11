/* Figura 11.15: fig11_15.c - Lectura secuencial de un archivo de acceso aleatorio */
/*
1. Ejecuta el programa.
2. Qué modo se utiliza en la apertura del archivo?
3. Qué función permite la lectura de los datos?, cómo se emiten por pantalla?.
4. Modifica el programa usando funciones.
*/
#include <stdio.h>
#include <stdlib.h>

struct datosCliente { 
   int numCta;          /* número de cuenta */
   char apellido[ 15 ]; /* apellido */
   char nombre[ 10 ];   /* nombre */
   double saldo;        /* saldo  */
}; /* fin de la estructura datosCliente */

main()
{ 
   FILE *ptrCf; /* apuntador de archivo credito.dat */

   /* crea datosCliente con información predeterminada */
   struct datosCliente cliente = { 0, "", "", 0.0 };

   /* fopen abre el archivo; si no se puede abrir, sale del archivo */
   if ( ( ptrCf = fopen( "c:\\credito.dat", "rb" ) ) == NULL ) 
      printf( "No pudo abrirse el archivo.\n" );
   else { 
      printf( "%-6s%-16s%-11s%10s\n", "Cta", "Apellido", "Nombre", "Saldo" );
      
      /* lee todos los registro del archivo (hasta eof) */
      while ( !feof( ptrCf ) ) { 
         fread( &cliente, sizeof( struct datosCliente ), 1, ptrCf );

         /* despliega el registro */
         if ( cliente.numCta != 0 ) {
            printf( "%-6d%-16s%-11s%10.2f\n", 
               cliente.numCta, cliente.apellido, 
               cliente.nombre, cliente.saldo );
         } /* fin de if */

      } /* fin de while */
      fclose( ptrCf ); /* fclose cierra el archivo */
   } /* fin de else */
   system ("pause");
   return 0; /* indica terminación exitosa */
} /* fin de main */

