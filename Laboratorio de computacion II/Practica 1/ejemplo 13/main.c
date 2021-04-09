#include <stdio.h>
#include <stdlib.h>

int main()
{
    float numero1,numero2;
    printf("ingrese el primer numero\n");
    scanf ("%f", &numero1);
    printf("ingrese el segundo numero\n");
    scanf ("%f", &numero2);
    printf("n1+n2=%f\n",numero1+numero2);
    printf("n1-n2=%f\n",numero1-numero2);
    printf("n1*n2=%f\n",numero1*numero2);
    printf("n1/n2=%f\n",numero1/numero2);
    printf("(n1+n2)/2=%f\n",((numero1+numero2)/2));
    printf("(n1*(-n2/2))*2=%f\n",(numero1*(-numero2/2))*2);

    return 0;
}
