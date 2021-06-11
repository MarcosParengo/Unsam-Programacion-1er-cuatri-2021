#include <stdio.h>

int main(){
char caracter;
FILE * pArchivo;

pArchivo = fopen("un_archivo.txt","w");

if(pArchivo != NULL){
		do{
		printf("Ingrese un caracter: ");
		scanf("%c",&caracter);
		fflush(stdin);
		fputc(caracter, pArchivo);
		}while(caracter != '*');
     fclose(pArchivo);}
else  printf("Error en la apertura del archivo!");

getchar();
return 0;
}


