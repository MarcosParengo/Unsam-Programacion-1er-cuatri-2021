/*Números*/
#include <stdio.h>

int main(){
int n, i;

 printf("Cu%cl es la diferencia en los dos ciclos?\n\n", 160);
    for( n = 1; n <= 3; n++)
        for( i = 5;i <= 7; i++)
        printf("%d %d\n", n,i);

 printf("\n\n");

    for( n = 1;n <=3; n++){
        for( i = 5; i <= 7; i++)
        printf("%d %d", n,i);
        printf("\n");
    }

getchar();
return 0;
}
