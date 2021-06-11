#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE * pArchivo;
    int n;
    char nombre[30];
    float salario;
    pArchivo=fopen("prueba1.txt","w");//Reescribe todo el archivo
    if(pArchivo!=NULL){
        //Caracter por caracter
        /*do{
         printf("ingrese un caracter:\n");
         scanf("%c",&caracter);
         fflush(stdin);
         fputc(caracter,pArchivo);
        }while(caracter!='n');
        close(pArchivo);
        */
        //Palabra por palabra
        /*
        for(int i=0;i<255;i++){
            printf("Ingrese la %d%c palabra(Corta para terminar el ingreso): \n",i+1,167);
            scanf("%s",palabra);
            if(strcmp(palabra, "corta")==1){
                close(pArchivo);
                break;
            }
            fputs(palabra,pArchivo);
            fputc(espacio,pArchivo);
        }
        */
        //Texto entero
        /*
        printf("Ingrese una oracion de hasta 255 caracteres:\n");
        gets(texto);
        fflush(stdin);
        fputs(texto,pArchivo);
        printf("El texto \"%s\" fue ingresado correctamente al archivo",texto);
        close(pArchivo);
        */
    }
    return 0;
}
