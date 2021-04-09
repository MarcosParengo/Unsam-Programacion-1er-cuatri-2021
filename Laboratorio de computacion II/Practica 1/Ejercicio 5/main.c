#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a = 10;
    float b = 19.3;
    double d = 64.8;
    char c = 64;

    printf("%f\n",a+b);//float
    printf("%f\n",c+d);//float
    printf("%d\n",(int)d+a);//int
    printf("%f\n",(d+b));//double
    printf("%f\n",(float)c+d);//double
}
