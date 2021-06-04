#include <stdio.h>

void imprimirHistograma(int d[], int n){
int i;
 for (i=0; i<d[n]; i++)
    printf("*");
 }

void emitirFacturacionSemanal(int d[], int t) {
 int i;
   printf("\n\n\n******HISTOGRAMA*******");
   for (i=0; i<t; i++){
        printf("\ndia %d  ->", (i+1));
        imprimirHistograma(d, i);
   }
}

void ingresarDiaria( int d[], int t) {
 int i;
   for (i=0; i<t; i++)
   {
   printf("Ingrese el total facturado en el dia %d: ", i+1);
   scanf("%d", &d[i]);
   }
}

int main(){
int const tam=7;
int mi_array[tam];
ingresarDiaria(mi_array, tam);
emitirFacturacionSemanal(mi_array, tam);
printf("\n\n\n ");
getchar();
return 0; }
