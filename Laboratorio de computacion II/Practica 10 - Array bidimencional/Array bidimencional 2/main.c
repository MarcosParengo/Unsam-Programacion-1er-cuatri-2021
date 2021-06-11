#include <stdio.h>
#include <stdlib.h>
#define FILAS 4
#define COLUMNAS 6
int main()
{
    int mes=6;
    int arrayBD[FILAS][COLUMNAS];
    int contador=0;
    //Llenar

    llenar(arrayBD,mes);
    imprimir(arrayBD, mes);

    return 0;
}

void imprimir (int arrayBD[][COLUMNAS],int mes){
    int **array=arrayBD;
    for (int filas=0;filas<FILAS;filas++){
        for(int columnas=0;columnas<COLUMNAS;columnas++){
            printf("%d ",*(*(arrayBD+filas)+columnas));
        }
        printf("\n");
    }
}
void llenar (int arrayBD[][COLUMNAS],int mes){
    int contador=1;
    for (int filas=0;filas<FILAS;filas++){
        for(int columnas=0;columnas<COLUMNAS;columnas++){
            *(*(arrayBD+filas)+columnas)=contador;
            contador++;
        }
    }
}


