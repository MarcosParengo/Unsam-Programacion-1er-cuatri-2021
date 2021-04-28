/*Escribe una función recursiva que lea un par de enteros (analiza las
restricciones) y emita el resultado de elevar el primer número a la potencia
indicada por el segundo.*/
#include <stdio.h>

int Leer(int * x){
scanf("%d",x);
}

int potencia(int b, int e){
if(e==0) return 1;
else if(e==1) return b;
else return b*potencia(b,e-1);
}

int main(){
int base,expo;
    printf("Ingrese la base:\n");
    Leer(&base);
    printf("Ingrese el exponente:\n");
    Leer(&expo);
    printf("El resultado es: %d\n",potencia(base,expo));
getchar();
return 0;
}
