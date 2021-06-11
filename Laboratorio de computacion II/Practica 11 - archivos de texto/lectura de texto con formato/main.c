#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE * pArchivo;
    int n;
    char nombre[30];
    float salario;
    pArchivo=fopen("prueba1.txt","a");//agrega cosas al archivo
    if(pArchivo!=NULL){
        //Grabar datos con tipo de datos, es como imprimir
        do{
            printf("Ingrese el numero de legajo, 0 para terminar\n");
            scanf("%d",&n);
            fflush(stdin);
            if(n>0){
                printf("Ingrese el nombre del empleado:\n");
                scanf("%s",&nombre);
                fflush(stdin);
                printf("Ingrese el salario del empleado:\n");
                scanf("%f",&salario);
                fflush(stdin);
                fprintf(pArchivo,"%d%15s%15f\n",n,nombre,salario);
            }
        }while(n>0);
        close(pArchivo);
        leerArch(pArchivo,"prueba1.txt");
    }
    return 0;
}
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

void leerArch(FILE * pA, char * nom){
int n;
char nombre[30];
float salario;
pA = fopen(nom,"r");

if(pA!=NULL){
  while(!feof(pA)){
    fscanf(pA,"%d%15s%15f\n", &n,nombre,&salario);
	printf("%d\t%s\t%.2lf\n",n,nombre,salario);
    }
    fclose(pA);
    }
else{ printf("Error en la apertura del archivo!");}
}

