#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define VENDEDOR 4
#define MES 3

void cargaMatriz(float m[][MES]);
void emiteMatriz(float m[][MES], char vend[][10], char mes[][10]);

int main() {
float ventas[][MES]={0.0};
char vendedores[][10]= {"vend_1","vend_2","vend_3","vend_4"};
char meses[][10]= {"mes_1","mes_2","mes_3"};
int i;

/*control
for (i = 0; i < MES; i++ )printf("%20s", meses[i]);
printf("\n\n"); //línea nueva
for (i = 0; i < VENDEDOR; i++ )printf("%20s", vendedores[i]);
printf("\n\n"); //línea nueva
*/

cargaMatriz(ventas);
emiteMatriz(ventas, vendedores, meses);

return 0;
}

void cargaMatriz(float m[][MES]){
int i, j;
srand(time(NULL));
for (i=0; i < VENDEDOR; i++)
    for (j=0; j < MES; j++)
      m[i][j] = 10 + rand() % 89;
}

void emiteMatriz(float m[][MES], char vend[][10], char mes[][10]){
int i, j;
//títulos columnas
for (i = 0; i < MES; i++ )printf("%15s", mes[i]);

printf("\n\n"); //línea nueva

for (i=0; i < VENDEDOR; i++) {
    printf("%s:", vend[i]); {
      for (j=0; j < MES; j++)
       printf ("%10.2f |", m[i][j]);
}
  printf("\n ");
}
}

