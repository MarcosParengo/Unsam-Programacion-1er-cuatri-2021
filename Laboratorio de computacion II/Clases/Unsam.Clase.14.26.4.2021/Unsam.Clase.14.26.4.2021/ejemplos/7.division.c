#include <stdio.h>
#include <stdlib.h>

long int division (int a,int b) {
    int i;
    if (a<b)
        return 0;
    else
        if (a==b)
           return 1;
        else
           return 1+division(a-b,b);
}

int main() {
        int a, b;


        printf("ingrese a: \n");
        scanf("%d",&a);
        while (a<0)
        {
              printf("Ingrese un a no negativo \n");
              scanf ("%d",&a);
        }
        printf("ingrese b: \n");
        scanf("%d",&b);
        while (b<=0)
        {
              printf("Ingrese un b positivo distinto de 0 \n");
              scanf ("%d",&b);
        }
        printf("El cociente es: %d\n",division(a,b));
        system("pause");
        return 0;
}
