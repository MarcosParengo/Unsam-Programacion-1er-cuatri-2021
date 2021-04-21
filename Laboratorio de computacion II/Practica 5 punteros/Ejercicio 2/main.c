#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a , b ;
    int * pa ;
    a = 5 ;//le asigno 5 a la variable a
    pa = &a;//le asignola posicion de memoria de a a pa
    b= *pa ;//le asigno el valor de la posicion guardadada en pa
    printf("a: %i\n",a);
    printf("pa: %i\n",pa);
    printf("b: %i\n",b);

    int i,j,*p ;
    p=&i;//le asigno a p la posicion de i
    printf("p: %i (antes de la reasignacion)\n",p);
    *p = 21;//le asigno a la variable a la que refiere p (i) 21 (igual a i=21)
    p =&j;//le asigno a p la posicion de j
    *p=1;21;//le asigno a la variable a la que refiere p (j) 21 (igual a i=21)
    printf("i: %i\n",i);
    printf("j: %i\n",j);
    printf("p: %i\n",p);

    return 0;
}
