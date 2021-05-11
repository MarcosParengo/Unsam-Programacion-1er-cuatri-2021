#include <stdio.h>

void imprimirHistograma(int dia){
 int i;
 for (i=0; i<dia; i++)
    printf("*");
 printf("\n");
 }

void emitirFacturacionSemanal( int dia1, int dia2, int dia3, int dia4, int dia5, int dia6, int dia7)
{  printf("\n\n\n******HISTOGRAMA*******\n");
   printf("dia 1->");
    imprimirHistograma(dia1);
   printf("dia 2->");
    imprimirHistograma(dia2);
   printf("dia 3->");
    imprimirHistograma(dia3);
   printf("dia 4->");
    imprimirHistograma(dia4);
   printf("dia 5->");
    imprimirHistograma(dia5);
   printf("dia 6->");
    imprimirHistograma(dia6);
   printf("dia 7->");
   imprimirHistograma(dia7);
   }

void ingresarDiaria( int *dia1, int *dia2, int *dia3, int *dia4, int *dia5, int *dia6, int *dia7){
   printf("Ingrese el total facturado en el dia 1: ");
    scanf("%d", dia1);
   printf("Ingrese el total facturado en el dia 2: ");
    scanf("%d", dia2);
   printf("Ingrese el total facturado en el dia 3: ");
    scanf("%d", dia3);
   printf("Ingrese el total facturado en el dia 4: ");
    scanf("%d", dia4);
   printf("Ingrese el total facturado en el dia 5: ");
    scanf("%d", dia5);
   printf("Ingrese el total facturado en el dia 6: ");
    scanf("%d", dia6);
   printf("Ingrese el total facturado en el dia 7: ");
   scanf("%d", dia7);
   }


int main(){
int dia1=0, dia2=0, dia3=0, dia4=0, dia5=0, dia6=0, dia7=0;

ingresarDiaria(&dia1, &dia2, &dia3, &dia4, &dia5, &dia6, &dia7);

emitirFacturacionSemanal(dia1, dia2, dia3, dia4, dia5, dia6, dia7);

printf("\n\n\n ");
getchar();

return 0;
}



