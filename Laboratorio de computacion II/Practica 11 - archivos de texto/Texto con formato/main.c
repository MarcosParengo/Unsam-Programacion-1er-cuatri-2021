#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    }
    return 0;
}
