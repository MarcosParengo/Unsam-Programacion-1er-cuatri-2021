/* Figura 11.12: fig11_12.c - Escritura en un archivo de acceso aleatorio */
/*
1. Ejecuta el archivo fuente.
2. En qu� modo fue abierto el archivo?. Com�ntalo en el programa.
3. Qu� funci�n se utiliza para la lectura de datos y para la escritura en el archivo?.
4. Qu� realiza la siguiente instrucci�n:
"fseek( ptrCf, ( cliente.numCta - 1 ) * sizeof( struct datosCliente ), SEEK_SET );"
5. Modifica el programa usando funciones.
*/

#include <stdio.h>
/* definici�n de la estructura datosCliente */
struct datosCliente { 
   int numCta;          /* n�mero de cuenta */
   char apellido[ 15 ]; /* apellido de la cuenta */
   char nombre[ 10 ];   /* nombre de la cuenta */
   double saldo;        /* saldo de la cuenta */
}; /* fin de la estructura datosCliente  */
 
int main() 
{ 
   FILE *ptrCf; /* apuntador al archivo credito.dat */

   struct datosCliente cliente = { 0, "", "", 0.0 };

   if ( ( ptrCf = fopen( "c:\\credito.dat", "rb+" ) ) == NULL ) 
      printf( "El archivo no pudo abrirse.\n" );
   else { 

      /* se requiere que el usuario especifique el n�mero de cuenta */
      printf( "Introduzca el numero de cuenta"
         " ( 1 a 100, 0 para terminar la entrada )\n? " );
      scanf( "%d", &cliente.numCta );

      /* el usuario introduce la informaci�n, la cual se copia dentro del archivo */
      while ( cliente.numCta != 0 ) { 

         /* el usuario introduce el apellido, el nombre y el saldo */
         printf( "Introduzca el apellido, el nombre, el saldo\n? " );
        
         /* establece los valores para apellido, nombre, y saldo del registro */
         fscanf( stdin, "%s%s%lf", cliente.apellido, 
            cliente.nombre, &cliente.saldo );

         /* localiza la posici�n de un registro espec�fico en el archivo */
         fseek( ptrCf, ( cliente.numCta - 1 ) * 
            sizeof( struct datosCliente ), SEEK_SET );

         /* escribe en el archivo la informaci�n especificada por el usuario */
         fwrite( &cliente, sizeof( struct datosCliente ), 1, ptrCf );

         /* permite al usuario introducir otro n�mero de cuenta */
         printf( "Introduce el numero de cuenta\n? " );
         scanf( "%d", &cliente.numCta );
      } /* fin de while */

      fclose( ptrCf ); /* fclose cierra el archivo */
   } /* fin de else */

   return 0; /* indica terminaci�n exitosa */

} /* fin de main */
