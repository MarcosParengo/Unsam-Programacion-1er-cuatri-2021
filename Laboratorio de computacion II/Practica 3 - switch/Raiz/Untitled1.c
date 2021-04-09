#include <math.h>
#include <stdio.h>
#include <stdlib.h>


int main()
{
    double base = 9;
    double power = (1/3);
    double result;
    double dRaizCubica;
    result=power/base;
    dRaizCubica = pow(base, (double)1/3);
    printf("resultado: %f\n",result);
    result=pow(base, power);
    printf("resultado: %f\n",dRaizCubica);
}
