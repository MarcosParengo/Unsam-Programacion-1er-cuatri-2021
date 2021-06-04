/*pasaje 2*/
#include <stdio.h>

void por_valor (int x);
void por_direccion(int * x);

int main(){
int a = 1;
int i;
for(i=0;i<10;i++){
    por_valor(a);
    printf("\nEl valor de la variable a es: %d\n", a);
}

printf("\n\n\n");

for(i=0;i<10;i++){
 por_direccion(&a);
 printf("\nEl valor de la variable a es: %d\n", a);
}

/*salida:
El valor de la variable a es: 1
El valor de la variable a es: 1
El valor de la variable a es: 1
El valor de la variable a es: 1
El valor de la variable a es: 1
El valor de la variable a es: 1
El valor de la variable a es: 1
El valor de la variable a es: 1
El valor de la variable a es: 1
El valor de la variable a es: 1

El valor de la variable a es: 2
El valor de la variable a es: 3
El valor de la variable a es: 4
El valor de la variable a es: 5
El valor de la variable a es: 6
El valor de la variable a es: 7
El valor de la variable a es: 8
El valor de la variable a es: 9
El valor de la variable a es: 10
El valor de la variable a es: 11
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

