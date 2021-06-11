#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char texto[255];
    FILE * pArchivo=NULL;
    openFile(&pArchivo);
    readFile(pArchivo,texto);
    printf("%s",texto);
    return 0;
}





//Abre o en su defecto crea un archivo
//Se elije el modo de operacion( "a","w",etc)
void openFile(FILE * * pArchivo){
    char nombreArchivo[30];
    char modoDeOperacion[2];
    printf("Como se llama el archivo que desea crear o abrir?(no hace falta que especifique la extension)\n");
    scanf("%s",&nombreArchivo);
    fflush(stdin);
    char buffer[255];
    printf("En que modo de operacion desea abrir el archivo?\n");
    printf("(r/w/a/r+/w+/a+)\n");
    scanf("%s",&modoDeOperacion);
    if((strcmp(modoDeOperacion, "w")==0)||(strcmp(modoDeOperacion, "a")==0)||(strcmp(modoDeOperacion, "r")==0)
       ||(strcmp(modoDeOperacion, "r+")==0)||(strcmp(modoDeOperacion, "w+")==0)||(strcmp(modoDeOperacion, "a+")==0)){

    }else{
        printf("\n!!ERROR!!:No eligio ninguna forma de apertura valida");
        exit(1);
    }
    strcat(strcpy(buffer, nombreArchivo), ".txt");
    *pArchivo=fopen(buffer,modoDeOperacion);
}
//Agrega un texto a un archivo. El archivo ya debe estar abierto
//Recibe la direccion en la que esta el archivo abierto
void addToFile(FILE * pArchivo){
    char texto[255];
    if(pArchivo!=NULL){
        printf("Ingrese una oracion de hasta 255 caracteres:\n");
        gets(texto);
        fflush(stdin);
        fputs(texto,pArchivo);
    }else{
        printf("!!ERROR!!: Todavia no abrio ningun archivo");
    }
}
//Lee un texto de un archivo. El archivo ya debe estar abierto
//Recibe la direccion en la que esta el archivo abierto
//Devuelve en un vector de caracteres lo leido
void readFile(FILE * pArchivo,char *texto){
    char c;
    if(pArchivo!=NULL){
        //while(*texto !=){
        while(!feof(pArchivo)){
        *texto=fgetc(pArchivo);
        texto++;
        }
        close(pArchivo);
    }else{
        printf("!!ERROR!!: Todavia no abrio ningun archivo");
    }
}
