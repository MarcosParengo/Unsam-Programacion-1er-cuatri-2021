#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    float x, y, z, result1, result2;

    printf ("Ingrese el valor de x : ");
    scanf ("%f", &x);
    fflush (stdin);

    result1 = (x > 8)? (y = 23) : (z = -5);

    result2 = ((x >= 8)&&(x != 12))?(x>0)? (z=sqrt(6*x)) : (z=sin(3*x)) : (z=sin(5*x));

    printf ("Los valores de Y y Z son %.2f y %.2f", y, z);

    getchar();
    return 0;
}
