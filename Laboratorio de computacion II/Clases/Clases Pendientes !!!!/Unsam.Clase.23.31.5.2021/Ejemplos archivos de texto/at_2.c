#include <stdio.h>

int main(){
char palabra[30];
FILE * pArchivo;

pArchivo = fopen("un_archivo.txt","w");

if(pArchivo != NULL){
		printf("Ingrese una palabra: \n");
		//scanf("%s",palabra);
		gets(palabra);
		fflush(stdin);
		fputs(palabra, pArchivo);
        fclose(pArchivo);
        }
else  printf("Error en la apertura del archivo!");

getchar();
return 0;
}


