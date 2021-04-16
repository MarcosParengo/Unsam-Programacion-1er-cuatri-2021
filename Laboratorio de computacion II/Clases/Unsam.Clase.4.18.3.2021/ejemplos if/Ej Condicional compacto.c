#include <stdio.h>
#include <stdlib.h>


int main(){
int a, b;
printf( "Introduce un n%cmero: \n",163);
scanf( "%i", &a );
    if ( a<10 )
            {b = 1;}
    else
            {b = 4;}
printf ( "La variable 'b' toma el valor: %i\n", b );

printf ( "Condicional compacto:\n");
printf( "Introduce un n%cmero: ",163 );
scanf( "%i", &a );
b = ( a<10 ) ? 1 : 4 ;
printf ( "La variable 'b' toma el valor: %i\n", b );
getchar();
return 0;
}
