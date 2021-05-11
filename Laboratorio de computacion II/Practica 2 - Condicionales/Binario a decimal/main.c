#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int lenght=255;
    int size;

    char texto[lenght];
    char auxiliar[lenght];
    char flag=0;
    double resultado=0;

    printf("Ingrese el numero binario que desea convertir en decimal\n");
    fflush(stdin);
    fgets(texto,lenght,stdin);
    size=strlen(texto);
    size=size-2;
    int i = 0;
    texto[size+1]=0;
    texto[size+2]=0;
	for(;i<size+1;i++){
        if(texto[i]!=48&&texto[i]!=49){flag=1;}
        double result=(double)(texto[i]-48);
        resultado=resultado+(result*pow(2,(double)(size-i)));
    }
    if(flag==1)
    {
        printf("El texto ingresado deberia estar compuesto unicamente por ceros y unos, el numero ingresado no es binario");
    }
    printf("el numero %s en decimal:%.0f",texto,resultado);
    return 0;
}
