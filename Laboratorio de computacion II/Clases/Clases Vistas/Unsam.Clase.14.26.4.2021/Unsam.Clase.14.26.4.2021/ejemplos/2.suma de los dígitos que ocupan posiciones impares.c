/*Escribe el planteo recursivo e implemente en C una función recursiva que
calcule la suma de los dígitos que ocupan posiciones impares para un número
natural. Se considera que la posición 1 es la posición del dígito menos
significativo (lugar de la unidad), la posición 2 es la posición de la
decena, etc. Por ejemplo, si se considera el natural 587, el 7 está en la
posición 1, el 8 en la posición 2 y el 5 en la posición 3. En el ejemplo, la
función debería retornar 12 (7+5)..*/
#include <stdio.h>

int Leer(int * x){
scanf("%d",x);
}

int sum_dig (int n){
	if (n==0)      //caso base
	    return n;
	else
	    return sum_dig (n / 100) + (n % 10);
    }

int main(){
int valor;
printf("Ingrese el valor:\n");
Leer(&valor);
printf("El resultado es: %d\n",sum_dig(valor));
getchar();
return 0;
}
