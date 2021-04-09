#include <stdio.h>
#include <stdlib.h>

int main()
{
    char x = 2,y = 6,z = 9,r = 100;
    z = 3 * x + 6;//No es posible minificar
    printf("%d",z);
    x += 10-y;//x = 10 + x - y;
    printf("%d",x);
    r *= 100;//r = 100*r;
    printf("%d",r);
    y/=10+x;//y = y/(10+x);
    printf("%d",y);
}
