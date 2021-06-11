#include <stdio.h>
#include <stdlib.h>
#define FILAS 4
#define COLUMNAS 6
int main()
{
    char* cadena[3] ={"No mes","Enero","Febrero","Marzo"};
    int arrayBD[FILAS][COLUMNAS];
    int contador=0;
    llenar(arrayBD);
    imprimir(arrayBD);


    return 0;
}

//imprimir(arrayBD);
void imprimir (int arrayBD[][COLUMNAS],int mes){
    int **array=arrayBD;
    for (int filas=0;filas<FILAS;filas++){
        for(int columnas=0;columnas<COLUMNAS;columnas++){
            printf("%d ",*(*(arrayBD+filas)+columnas));
        }
        printf("\n");
    }
}
//llenar(arrayBD);
void llenar (int arrayBD[][COLUMNAS],int mes){
    int contador=1;
    for (int filas=0;filas<FILAS;filas++){
        for(int columnas=0;columnas<COLUMNAS;columnas++){
            *(*(arrayBD+filas)+columnas)=contador;
            contador++;
        }
    }
}


