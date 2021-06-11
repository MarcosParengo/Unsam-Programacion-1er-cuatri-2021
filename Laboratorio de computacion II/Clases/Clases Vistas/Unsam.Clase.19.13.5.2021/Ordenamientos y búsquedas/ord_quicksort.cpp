/* ordenamiento de un vector de números enteros */
/* método: quicksort */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void quicksort(int a[], int primero, int ultimo){
int contint=0, pivote, i, j, central, tmp,c;
central = (primero + ultimo)/2;
pivote = a[central];
i = primero;
j = ultimo;
do {
 while (a[i] < pivote) i++;
 while (a[j] > pivote) j--;
            if (i<=j){
            tmp = a[i];
            a[i] = a[j];
            a[j] = tmp;
            i++;
            j--;
            }
    }while (i <= j);
if (primero < j)  quicksort(a, primero, j);
if (i < ultimo)  quicksort(a, i, ultimo);
}

void cargaelem(int v[], int d){
int i;
srand(time(NULL));
for (i = 0; i < d; i++) v[i] = 1 + rand() % 50;
}

void emitirelem(int v[], int d){
int i;
for(i=0;i<d;i++)
printf("%5d",v[i]);
printf("\n");
}

int main(){
const int dim=10;
int vec[dim];

long int i=0;

cargaelem(vec,dim);
printf("\nValores ingresados: \n");
emitirelem(vec,dim);
quicksort(vec,0,dim-1);
printf("\nValores ordenados: \n");
emitirelem(vec,dim);

/*
https://davidcapello.com/blog/cpp/medir-el-tiempo-de-una-rutina/
clock_t comienzo;
comienzo=clock();
printf( "Número de segundos transcurridos desde el comienzo del programa: %.2f s\n", (clock()-comienzo)/1000.0);
*/
getchar();
return 0;
}
