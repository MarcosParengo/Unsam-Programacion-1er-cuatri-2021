#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int n, opcion;

    char texto[255];
    char texto1[255];
    FILE * pArchivo1=NULL;

    do
    {
        printf("Elija la operacion a realizar:\n");
        printf("1. Abrir o crear archivo\n");
        printf("2. Agregar texto al archivo\n");
        printf("3. Mover el texto de un archivo a la varible texto\n");
        printf("4. Imprimir la variable texto\n");
        printf("0. Salir del programa\n");
        scanf( "%d", &opcion );
        fflush(stdin);
        switch ( opcion )
        {
            case 1:
                openFile(&pArchivo1);
                break;
            case 2:
                addToFile(pArchivo1,&pArchivo1);
                break;
            case 3:
                readFile(pArchivo1,texto1);
                break;
            case 4:
                printf("%s",texto1);
                break;
         }
    } while ( opcion != 0 );

    return 0;
}
//Abre o en su defecto crea un archivo
//Se elije el modo de operacion( "a","w",etc)
void openFile(FILE * * pArchivo){
    char nombreArchivo[30];
    char modoDeOperacion[2];
    printf("Como se llama el archivo que desea crear (o abrir si ya existe)? (no hace falta que especifique la extension)\n");
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
void addToFile(FILE * pArchivo,FILE * * pArchivo1){
    char texto[255];
    if(pArchivo!=NULL){
        printf("Ingrese una oracion de hasta 255 caracteres:\n");
        gets(texto);
        fflush(stdin);
        fputs(texto,pArchivo);
        fclose(pArchivo);
        *pArchivo1=NULL;
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
