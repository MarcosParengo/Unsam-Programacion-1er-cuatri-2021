/*Dibujo*/
#include <stdio.h>

int main(){
    int x, y, i, j;
    printf( "Ingrese 2 enteros entre 1 y 20:\n " );

    scanf( "%d%d", &x,&y);

        for ( i = 1; i <= y; i++ ) {
            for ( j = 1; j <= x; j++ ) {printf( "@" );
        }
    printf( "\n" ); }
    getchar();
return 0;}
