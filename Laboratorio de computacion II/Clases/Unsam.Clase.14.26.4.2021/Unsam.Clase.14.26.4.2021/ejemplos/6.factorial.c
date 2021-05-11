#include <stdio.h>

long int factorial (long int x){
    if ((x==0)||(x==1))
        return 1;
    else
        return x*factorial(x-1);
}

int main(){
    int x;

        printf("ingrese número: \n");
        scanf("%d",&x);
        while (x<=0)
        {
              printf("Ingrese un número positivo \n");
              scanf ("%d",&x);
        }
        printf("El factorial es: %d\n",factorial(x));

    getchar();
    return 0;
}

