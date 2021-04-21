/*pasaje 4*/
#include <stdio.h>

void por_valor2(int n);
void por_valor (int x);
void por_direccion(int * x);
void por_direccion2(int * n);

int main(){
    int a = 1, tope=5;
    int i;

    por_valor(a);
    printf("\nEl valor de la variable a en main es: %d\n", a);

    por_direccion(&a);
    printf("\nEl valor de la variable a en main es: %d\n", a);

    /*salida:
    El valor de la variable a en main es: 1
    El valor de la variable a en main es: 3
    */

 getchar();
 return 0;
}

void por_valor2(int n){
n++;
}

void por_direccion2(int * n){
(*n)++;
}

void por_valor(int n){
n++;
por_valor2(n);
//printf("\nEl valor de la variable despues de (por_valor2) a es: %d\n", n);
por_direccion2(&n);
//printf("\nEl valor de la variable despues de (por_direccion2) a es: %d\n", n);
}


/*
//¿cuál es el error en la siguiente función?
void por_direccion(int * n){
(*n)++;
por_valor2(n);
por_direccion2(&n);
}
*/

void por_direccion(int * n){
(*n)++;
por_valor2(*n);
//printf("\nEl valor de la variable (por_valor2) a es: %d\n", *n);
por_direccion2(n);
//printf("\nEl valor de la variable (por_direccion2) a es: %d\n", *n);
}
