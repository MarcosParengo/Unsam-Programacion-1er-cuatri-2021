#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int lenght=255;
    int size;

    char texto[lenght];
    char contador=0;
    char ultLetra=0;
    char letraACambiar=0;

    printf("Ingrese la letra que desee cambiar por x\n");
    scanf("%c",&letraACambiar);
    fflush(stdin);
    printf("Ingrese un texto de menos de 255 caracteres y que termine con $%c\n",ultLetra);

    do{
        fgets(texto,lenght,stdin);
        size=strlen(texto);
        ultLetra=texto[size-2];
        printf("La ultima Letra es: %c\n",ultLetra);
        printf("Texto antes: %s\n",texto);
    }while(ultLetra!=36);

    int i = 0;

	for(;i<size;i++){
           if(texto[i]==letraACambiar){
            contador++;
            texto[i]=120;
           }
    }
    printf("Texto con \"a\" cambiadas por \"x\": %s\n",texto);
}
