#include <stdio.h>
#define FILAS 6
#define COLUMNAS 5

void suma_por_fila(float[][COLUMNAS]);
void emitir(float matriz[][COLUMNAS]);

int main() {
   float matriz[][COLUMNAS] = {1.5, 2.2, 3.7, 0.5, 4.3,
                               6.1, 1.0, 9.8, 0.2, 4.4,
			                   0.5, 0.6, 4.2, 9.1, 6.0,
			                   3.0, 6.7, 3.3, 0.2, 2.1,
			                   8.9, 9.5, 3.1, 0.8, 7.0,
			                   0.5, 0.7, 0.2, 4.9, 0.7};
emitir(matriz);
printf("\n");
suma_por_fila(matriz);

getchar();
return(0);
}

void suma_por_fila(float matriz[][COLUMNAS]){
   int i,j;
   float suma_horizontal;

   for(i = 0; i < FILAS; i++) {
     suma_horizontal = 0; // inicializar acumulador
     {
       for(j = 0; j < COLUMNAS; j++)
       suma_horizontal = suma_horizontal + matriz[i][j];
     }
      printf("La suma de la fila %d es %.2f\n",  i, suma_horizontal);
 }
}

void emitir(float matriz[][COLUMNAS]){
   int i,j;

   for(i = 0; i < FILAS; i++)
     { printf("\n");
       for(j = 0; j < COLUMNAS; j++)
          printf("%.2f   ", matriz[i][j]);
     }
}

