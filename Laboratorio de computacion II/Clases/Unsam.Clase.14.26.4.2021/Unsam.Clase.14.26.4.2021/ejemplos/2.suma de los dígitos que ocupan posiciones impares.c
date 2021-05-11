/*Escribe el planteo recursivo e implemente en C una funci�n recursiva que
calcule la suma de los d�gitos que ocupan posiciones impares para un n�mero
natural. Se considera que la posici�n 1 es la posici�n del d�gito menos
significativo (lugar de la unidad), la posici�n 2 es la posici�n de la
decena, etc. Por ejemplo, si se considera el natural 587, el 7 est� en la
posici�n 1, el 8 en la posici�n 2 y el 5 en la posici�n 3. En el ejemplo, la
funci�n deber�a retornar 12 (7+5)..*/
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
