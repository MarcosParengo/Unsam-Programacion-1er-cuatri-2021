#include <stdio.h>
#include <stdlib.h>
/*
2. Dado un vector de dimensión N. Se debe pedir un valor x (float) y la posición i al usuario para almacenar x en la
posición i de un vector. Los valores no se ingresan ordenados por posición. Se debe completar el tamaño del vector.
Si la posición está ocupada se vuelve a pedir el ingreso. Al finalizar, emitir el contenido del vector indicando también
la posición ocupada por cada número. Utiliza el ciclo while y funciones
*/
int main()
{
    int longitud=0,valor=0,posicion=0;
    do{
        printf("Que longitud desea que tenga el array?(mayor a 0,hasta 225)\n");
        scanf("%d",&longitud);
        fflush(stdin);
    }while(longitud<=0 || longitud>255);
    int vector1[longitud];
    do{
    printf("Que valor desea agregar al array?(Para parar de ingresar valores,\ningrese un numero mayor a 255)\n");
    scanf("%d",&valor);
    fflush(stdin);
    if (valor<=255){
        printf("En que posicion lo desea agregar al array?(Para parar de ingresar valores,\ningrese una posicion mayor a %d)\n",longitud);
        scanf("%d",&posicion);
        fflush(stdin);
        if(posicion<=longitud){
            addToVect(posicion,valor,vector1);
        }
    }
    }while(valor<255 && posicion<=longitud);
    printVect(vector1,longitud);
}
void addToVect(int posicion,int valor,int *vector){
     *(vector+posicion-1)=valor;
}
void printVect(int *vector,int m){
    for(int i=0;i<m;i++){
        printf("%d%c numero del array: %d\n",i+1,167,*(vector+i));
    }
}
