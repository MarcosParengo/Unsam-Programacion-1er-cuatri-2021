/*suma los impares desde 1 hasta n*/
#include <stdio.h>
#include <stdlib.h>

int suma(int n){
    if(n<=1) return 1;
    return (2*n-1)+suma(n-1);
}

int main() {
int n;
    printf("Ingresa un n%cmero entero positivo:\n",163);
    scanf("%d",&n);
    printf("La suma de los %d primeros impares es %d\n", n, suma(n));
getchar();
return 0;
}


