#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int aux;
    int flag=0;
    int i=0;
    int numero;
    printf("Ingrese un entero: ");
    scanf("%i", &numero);
    aux=numero;
	do{
        i++;
        printf("%i resto",(aux%2));
        if(i==10){
            flag=1;
        }
	}while(flag==0);
    return 0;
}
