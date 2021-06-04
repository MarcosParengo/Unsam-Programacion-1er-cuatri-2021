#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
int main()
{
    int vector[30]={10,20,1,1,1,3,2,5,6,84,52,12,35,48,8,11,21,3,1,9,25,29,202};
    int posicion=0;
    _Bool encontrado=false;
    int vector2[30]={10,20,3,2,5,6,84,52,12,35,48,8,11,21,3,1,9,25,29};
    int posicion2=0;
    _Bool encontrado2=false;
    int size= sizeof(vector) / sizeof(int);

    ordenamientoSecuencial(vector,size,84,&encontrado,&posicion);
    busquedaBinaria(vector2,size,10,&encontrado2,&posicion2);

    if(encontrado==true){
        printf("Encontrado con busqueda secuencial en la posicion %d\n",posicion);
    }else{
        printf("Su numero no fue encontrado\n");
    }
    printf("Vector con quick sort:\n");
    for(int i=0;i<size;i++){
        printf("%d:%d\n",i+1,vector2[i]);
    }
    if(encontrado2==true){
        printf("el numero fue Encontrado con busqueda binaria en la posicion %d\n",posicion2);
    }else{
        printf("Su numero no fue encontrado\n");
    }
    return 0;
}

void ordenamientoSecuencial(int *vector,int size,int buscado,int *encontrado,int *posicion){
    for(int i=0;i<size;i++){
        if (vector[i]==buscado){
            *encontrado=true;
            *posicion=i+1;
            break;
        }
    }
}
void quick_sort (int *vector, int tamano) {
    int pared, actual, pivote, tmp;
    if (tamano < 2) return;
    // el elemento de pivote es la más a la derecha
    pivote = vector[tamano - 1];
    pared  = actual = 0;
    while (actual<tamano) {
        if (vector[actual] <= pivote) {
            if (pared != actual) {
                tmp=vector[actual];
                vector[actual]=vector[pared];
                vector[pared]=tmp;
            }
            pared ++;
        }
        actual ++;
    }
    quick_sort(vector, pared - 1);
    quick_sort(vector + pared - 1, tamano - pared + 1);
}

void busquedaBinaria(int *vector,int size,int buscado,int *encontrado,int *posicion){
    quick_sort(vector,size);
    int primero=0;
    int ultimo=size;
    int medio=(primero+ultimo)/2;
    while (primero<=ultimo){
        if (vector[medio]< buscado){
            primero=medio+1;
        }else if (vector[medio]== buscado){
            *encontrado=true;
            *posicion=medio+1;
            break;
        }else{
            ultimo = medio - 1;
        }
        medio = (primero+ultimo)/2;
    }
}
