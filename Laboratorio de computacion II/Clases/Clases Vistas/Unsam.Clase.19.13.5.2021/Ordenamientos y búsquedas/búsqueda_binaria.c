/*    Búsqueda binaria dentro de un arreglo*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void cargaelem(int v[], int d);
int busquedaBinaria( const int b[], int claveDeBusqueda, int bajo, int alto, int d );
void emitelem(int v[], int d);
int main()
{  const int dim=10;
   int vec[ dim ]; /* crea el arreglo a */
   int llave; /* valor a localizar en el arreglo a */
   int resultado; /* variable para almacenar la ubicación de la llave o -1 */

   cargaelem(vec, dim);
   emitelem(vec, dim);
   printf( "Introduzca un número a buscar:\n" );
   scanf( "%d", &llave );
   resultado = busquedaBinaria( vec, llave, 0, dim - 1, dim );

   if ( resultado != -1 ) {
      printf( "\n%d se encuentra en la posicion %d del arreglo\n", llave, resultado );
   }
   else {
      printf( "\n%d no se encuentra\n", llave );
   }
   getchar();
   return 0;

} /* fin de main */

void cargaelem(int v[], int d){
int i;
srand(time(NULL));
for(i=0;i<d;i++){
v[i] = 1 + rand() % 50;
}
}

void emitelem(int v[], int d){
int i;

for(i=0;i<d;i++) printf("%d - ",v[i]);

printf("\n");

}

int busquedaBinaria( const int b[], int claveDeBusqueda, int bajo, int alto, int d ){
   int central;
   while ( bajo <= alto ) {
     central = ( bajo + alto ) / 2;
     if ( claveDeBusqueda == b[ central ] ) {
         return central;
      }
      else if ( claveDeBusqueda < b[ central ] ) {
         alto = central - 1;
      }
      else {
         bajo = central + 1;
      }
   }
   return -1;
}
