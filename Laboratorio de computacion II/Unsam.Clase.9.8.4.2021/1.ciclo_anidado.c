/*Tabla de multiplicar*/
#include <stdio.h>

int main(){

short i, j;
printf("La tabla de multiplicar del 1 al 10 es:\n");

    for (i = 1;i <= 10; i++){
        for ( j = 1; j <= 10; j++ )
        printf("%d por %d vale %d\n",i,j,i*j);
    }
getchar();
return 0;}
