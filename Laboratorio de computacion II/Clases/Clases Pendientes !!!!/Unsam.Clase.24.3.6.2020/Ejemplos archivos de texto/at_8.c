#include <stdio.h>

void leerArch(FILE * pA, char * nom){
char linea[200];
pA=fopen(nom,"r");
if(pA != NULL){
    fgets(linea,20,pA); //carga una l�nea
    while(!feof(pA)){
     printf("%s", linea); // tambi�n se usa puts(texto)
     fgets(linea,20,pA);
    }
    fclose(pA);
    }
else { printf("Error en la apertura del archivo!");}
}

int main(){
FILE * pArchivo;
char nombreArch[30] = "un_texto.xyz";
leerArch(pArchivo, nombreArch);
getchar();
return 0;
}
