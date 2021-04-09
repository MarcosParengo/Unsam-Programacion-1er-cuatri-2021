#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int lenght=255;
    int size;

    char texto[lenght];
    char auxiliar[lenght];
    char bx;
    char contador=0;
    char ultLetra=0;
    fflush(stdin);



    do{
        printf("Ingrese un texto de menos de 255 caracteres y que termine con %c\n",36);
        fgets(texto,lenght,stdin);
        size=strlen(texto);
        size=size-2;
        printf("size %d\n",size);
        ultLetra=texto[size];
    }while(ultLetra!=36);

    int i = 0;

	for(;i<size+1;i++){
        printf("lugar %d, caracter %c,i %d\n",size-i,texto[size-i],i);
        bx=ultLetra=texto[size-i];
        auxiliar[i]=bx;
    }
    printf("Texto al revez: %s\n",auxiliar);
    return 0;
}
