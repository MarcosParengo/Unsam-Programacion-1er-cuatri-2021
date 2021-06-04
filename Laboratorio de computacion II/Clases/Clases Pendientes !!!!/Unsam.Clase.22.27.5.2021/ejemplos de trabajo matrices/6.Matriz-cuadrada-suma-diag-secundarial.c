#include <stdio.h>
#define DIM 5

float suma_diag_sec(float[][DIM]);
void emitir(float matriz[][DIM]);
void emitirdiagonal(float matriz[][DIM]);

int main() {
   float matriz[][DIM] = {1.5, 2.2, 3.7, 0.5, 4.3,
                          6.1, 1.0, 9.8, 0.2, 4.4,
			              0.5, 0.6, 4.2, 9.1, 6.0,
			              3.0, 6.7, 3.3, 0.2, 2.1,
                          8.9, 9.5, 3.1, 0.8, 7.0};
emitir(matriz);
printf("\n\n");
emitirdiagonal(matriz);
printf("\n\n");
printf("La suma de la diagonal secundaria es %.2f\n", suma_diag_sec(matriz));

getchar();
return(0);
}

float suma_diag_sec(float matriz[][DIM]){
   int i,j;
   float suma=0;

   for(i = 0; i < DIM; i++) {
       for(j = 0; j < DIM; j++)
        if ( i + j == DIM - 1) suma = suma + matriz[i][j];
     }
return suma;
}

void emitir(float matriz[][DIM]){
   int i,j;

   for(i = 0; i < DIM; i++)
     { printf("\n");
       for(j = 0; j < DIM; j++)
          printf("%.2f   ", matriz[i][j]);
     }
}

void emitirdiagonal(float matriz[][DIM]){
   int i,j;

   for(i = 0; i < DIM; i++)
       for(j = 0; j < DIM; j++)
          if ( i + j == DIM - 1) printf("%.2f   ", matriz[i][j]);

}

