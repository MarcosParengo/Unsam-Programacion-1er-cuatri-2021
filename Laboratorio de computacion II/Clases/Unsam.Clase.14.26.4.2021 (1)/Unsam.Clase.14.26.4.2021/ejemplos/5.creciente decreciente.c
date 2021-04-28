/*Escriba funciones recursivas para:
Mostrar los números del 1 al N en orden creciente.
Mostrar los números del 1 al N en orden decreciente.*/
#include <stdio.h>


void decreciente(int n){
if (n>0) {printf ("%d |",n);
          decreciente(n-1);
         }
}

void creciente(int n){
if (n==1) printf ("%d |",n);
else {creciente(n-1);
      printf ("%d |",n);
     }
}


int main(){
int x;
        printf("Ingrese un valor entero mayor a 0\n");
        scanf("%d",&x);
        decreciente(x);
        printf("\n\n\n");
        creciente(x);
getchar();
return 0;
}
