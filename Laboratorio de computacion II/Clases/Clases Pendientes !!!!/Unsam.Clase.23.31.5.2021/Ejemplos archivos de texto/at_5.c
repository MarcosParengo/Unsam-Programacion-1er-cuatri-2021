#include <stdio.h>
#include <stdlib.h>

void crearArch(FILE * pA, char * nom){
pA = fopen(nom,"w");
if(pA!=NULL){
     printf("Archivo creado exitosamente.\n");
     fclose(pA);
     }
else {
     printf("Error en la creación del archivo!");
     }
}

void escribirArch(FILE * pA, char * nom){
int n;
char nombre[30];
float salario;
pA = fopen(nom,"a");

if(pA!=NULL){
do{
 printf("Ingrese el n%cmero de legajo del empleado\nPara terminar ingrese 0 o n%cmero menor que 0:\n", 163,163);
 scanf("%d",&n);
 if(n>0){
   printf("Ingrese el nombre del empleado: ");
    scanf("%s",nombre);
    printf("Ingrese el salario del empleado: ");
    scanf("%f",&salario);
    fprintf(pA,"%d%15s%15f\n", n,nombre,salario);
    }
  } while(n>0);
 fclose(pA);
 }
else{ printf("Error en la apertura del archivo!");}
}

int main(){
FILE * pArchivo;
char nombreArch[30] = "empleados.txt";
int opcion;

printf("Elija la operaci%cn a realizar\n", 162);
printf("1 - Crear Archivo\n");
printf("2 - Agregar datos al Archivo\n");
printf("3 - Salir del programa\n");
scanf("%d",&opcion);
switch(opcion){
    case 1: crearArch(pArchivo, nombreArch);
            break;
    case 2: escribirArch(pArchivo, nombreArch);
            break;
    case 3: exit(1);
    default: printf("Ingreso un valor inv%clido, fin del programa...\n", 160);
}

getchar();
return 0;}


