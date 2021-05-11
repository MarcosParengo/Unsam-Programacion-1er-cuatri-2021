#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
    float y,z;
    float x=12;
    ( ( 0 < x) ? (y=23):(z=-5));//If (x>8) y = 23;else z = -5;
    x=12;
    ( ( x>=8 && x!=12 ) ? (z= sqrt(6*x)):( ( x>0) ? (z = sin(3*x)):(z = sin(5*x))));
    /*
        if ((x>=8)&&(x!=12))
            z = sqrt(6*x);
        else if (x>0)
            z = sin(3*x);
        else
            z = sin(5*x);*/
    printf("%f",z);
}
