#include <stdio.h>
#include <stdlib.h>

int main()
{
    int ventas=4;
    int mes=6;
    int filaA23=4;
    int columnaA23=3;
    int arrayBD[mes][ventas];
    //int arrayBD2[filaA23][columnaA23] = {7,9,15,13,11,8,5,9,10,2.84};//llenar todo la matriz de una
    int arrayBD3[4][3] = {{7,9},{13,11,3},{5,9,10},{2,8,4}};//Llenar fila x fila
    int arrayBD4[][3] = {2,8,4,12,1,5,23,1,3,42,12,2,4,5};//Llenar fila x fila, calcula cuantas filas tendra, poco practico para el ingreso
    int contador=0;
    //Llenar
    for (int filas=0;filas<mes;filas++){
        for(int columnas=0;columnas<ventas;columnas++){
            arrayBD[filas][columnas]=contador;
            contador++;
        }
    }
    //Printar
    for (int filas=0;filas<mes;filas++){
        for(int columnas=0;columnas<ventas;columnas++){
            printf("%d ",arrayBD[filas][columnas]);
        }
        printf("\n");
    }

    printf("\n");

    for (int filas=0;filas<filaA23;filas++){
        for(int columnas=0;columnas<columnaA23;columnas++){
            printf("%d ",arrayBD3[filas][columnas]);
        }
        printf("\n");
    }


    return 0;
}
