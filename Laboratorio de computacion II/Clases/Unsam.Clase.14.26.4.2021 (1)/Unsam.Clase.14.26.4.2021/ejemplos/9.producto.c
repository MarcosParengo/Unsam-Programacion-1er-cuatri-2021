#include <stdio.h>
long int producto (int a,int b) {
    if ((a==0)||(b==0))
        return 0;
    else
        if (a==1)
           return b;
        else
           return b+producto(a-1,b);
}

int main()
{
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
        printf("El producto es: %d\n",producto(a,b));
        getchar();
        return 0;
}
