#include <stdio.h>
#include <stdlib.h>

int main()
{
    char x = 2,y = 6,z = 9,r = 100,s = 10,a = 15,b = 3;
    x+= 10;//x=2 inicialmente, se le suma 10 => x=12
    printf("1.%d\n", x );
    s*= b;//s=10 inicialmente, se multiplica x 3 => s=30
    printf("2.%d\n",s);
    y+= x + 10;//y=6 inicialmente, se le suma 12 y 10 => y=28
    printf("4.%d\n",y);
    z -= a*b;//se le resta a*b a z=>9 - 45
    printf("5.%d\n",z);
    r /= 0;//se intenta dividir x 0, da error
    printf("3.%d\n",r);
}
