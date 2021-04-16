#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int resultado[20];
    int resto;
    int aux;
    int flag=0;
    int i=0;
    int numero;
    printf("Ingrese un entero: ");
    scanf("%i", &numero);
    aux=numero;
	while(flag==0){
        resto=aux%2;
        resultado[i]=resto;
        aux=aux/2;
        if(aux==0){
                flag=1;
        }
        i=i+1;
	}
        i=i-1;
    printf("Resultado: ");
    for(;i>=0;i--){
        printf("%i",resultado[i]);
    }
    return 0;
}
