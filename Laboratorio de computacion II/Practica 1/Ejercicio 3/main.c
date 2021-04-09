#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a = 3,b = , c = 1,d,e;
    float m = 2.5, n = 5.4, r, s;

    d = m;//al m ser racional y d entero, redondea m para guardalo en d
    printf("%d\n",d);
    d = n;//al n ser racional y d entero, redondea m para guardalo en d
    printf("%d\n",d);
    e = 3.7;//al 3.7 ser racional y e entero, redondea 3.7 a 3 para guardalo en e
    printf("%d\n",e);
    d = a;//a tiene un valor de entero y d es una variable entera, por lo que no hay problema para guardar el valor de a en d
    printf("%d\n",d);
    d = a + b;//a y b tienen un valor de entero y d es una variable entera, por lo que no hay problema para guardar el valor de a+b en d
    printf("%d\n",d);
    d = a * b;//a y b tienen un valor de entero y d es una variable entera, por lo que no hay problema para guardar el valor de a*b en d
    printf("%d\n",d);
    d = a / b;//a/b da 1,5 pero d es entero, x lo que se guarda el valor redondeado(1)
    printf("%d\n",d);
    d = b / 4;//a/b da 0,5 pero d es entero, x lo que se guarda el valor redondeado(0)
    printf("%d\n",d);
    d = a % b;//resto de la division entera 3/2 (1)
    printf("%d\n",d);
    d = a % 2;
    e = b / c;
    e = c / b;
    r = a + b;
    r = a / b;
    r = a / 2;
    r = a /2.0;
    s = m + n;
    s = 3 + 4 - 1;
    s = 3.0 + 4.0 -1;
    a = m;
    a = m / 2;
    a = m / 2.0;
    a = 3.0 + 4.0 -1;
    r = a + 1;
    r = a + 1.0;
    a++;
    r++;
    b--;
    a+=5;
    s*=5;
}
