/*pasaje 1*/
#include <stdio.h>

void por_valor (int x);
void por_direccion(int * x);

int main(){
int a = 1;

 por_valor(a);
 printf("\nEl valor de la variable a es: %d\n", a);

 por_direccion(&a);
 printf("\nEl valor de la variable a es: %d\n", a);

 /* salida:
El valor de la variable a es: 1
El valor de la variable a es: 2
*/

 getchar();
 return 0;
}

void por_valor(int n){
n++;
}

void por_direccion(int * n){
(*n)++;
 }

