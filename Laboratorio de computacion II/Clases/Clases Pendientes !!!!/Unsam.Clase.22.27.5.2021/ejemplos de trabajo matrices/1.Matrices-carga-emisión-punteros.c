#include<stdio.h>

//Ejemplo1. Este programa ilustra la relacion entre las matrizrices y los punteros
int main(){
//declaramos un array bidimensional (matriz)  de 4 filas y 3 columnas
//Las filas se numeran de 0 a 1 y las columnas de 0 a 2
int matriz[2][3];
//Se carga la matriz, usamos las variables i y j como índices para recorrerla y cargarla
int i, j;
for (i=0;i<2;i++)
     for (j=0;j<3;j++){
            printf("Ingrese el valor de matriz[%d][%d]: ", i,j);
            scanf("%d",&matriz[i][j]);
            printf("\n");
            }

//ahora se emite la matriz
printf("\nContenido de la matriz\n");
for (i=0;i<2;i++){
     printf("\n");
     for (j=0;j<3;j++)
            printf("matriz[%d][%d]: %d  |  ", i,j,matriz[i][j]);
}

//vamos a ver cuales son las direcciones de los elementos de la matriz

printf("\n\nDirecciones de los elementos de la matriz\n");
for (i=0;i<2;i++){
     printf("\n");
     for (j=0;j<3;j++)
            printf("Posicion[%d][%d], Elemento: %d, Direccion: %x  | ",i,j, matriz[i][j],&matriz[i][j]);
}
//Ahora, emitiremos mat[0], matriz[1]
//como se vera, el nombre de la matriz con un solo subindice
//corresponde a la direccion de comienzo de la fila indicada por el subindice
printf("\n");
for(i=0;i<2;i++)
  printf("\nLa dirección por fila de matriz[%d] es %x \n", i, matriz[i]);

//ahora emitiremos el valor de matriz, debe ser igual que matriz[0]
  printf("\nLa dirección del nombre 'matriz' es: %x\n", matriz);
//Se observa que una matriz se maneja como un array de arrays
//matriz es la direccion de comienzo del array de direcciones de filas
//la direccion de cada fila es matriz[i] , con un solo subindice
//cada elemento es matriz[i][j]
//y la direccioo de un elemento se puede obtenerm como siempre con &matriz[i][j]
// o bien...
//si matriz[2] es la direccion de la fila 3,
//entonces, usando el operador de desreferencia *,
//se puede trabajar con matriz[2][0] o con * matriz[2]
//se puede trabajar con matriz[2][1] o con * (matriz[2]+1)
//se puede trabajar con matriz[2][2] o con * (matriz[2]+2)
//....etc
//como se ve en este ciclo de ejemplo
 printf("\n\nContenido de la matriz con notación de punteros:*(matriz[i]+j)\n");
for(i=0;i<2;i++){
 printf("\n");
 for (j=0;j<3;j++)
      printf("matriz[%d][%d]: %d  |  ", i,j,*(matriz[i]+j));
}
//Siguiendo el mismo razonamiento, si matriz es la direccion de comienzo
//del array de direcciones de filas, para la fila 3
//se puede trabajar con matriz[2][0]  o con *(* matriz+2)
//se puede trabajar con matriz[2][1]  o con *((* matriz+2)+1)
//se puede trabajar con matriz[2][2]  o con *((* matriz+2)+2)
//.....etc
//como se ve en este otro ciclo de ejemplo
printf("\n\nContenido de la matriz con notación de punteros:*(*(matriz+i)+j)\n");
for(i=0;i<2;i++){
  printf("\n");
 for (j=0;j<3;j++)
      printf("matriz[%d][%d]: %d  |  ",i,j,*(*(matriz+i)+j));
}
getchar();
return 0;
}




