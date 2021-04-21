#include <stdio.h>
#include <stdlib.h>

int main()
{
    //a. Declara a, b y c variables enteras, y p, q y r variables puntero a entero.
    int a,b,c, *p,*q,*r;
    //b. Declara m, n variables de tipo float y s y t variables puntero a float.
    float m,n,*s,*t;
    //c. Asigna a p la dirección de a y a q la dirección de b.
    p=&a;
    q=&b;
    //d. Asigna a b el valor 40 usando el puntero q. Mostrar el valor de b, la dirección de b , el valor de q, la dirección de q y el
    //valor contenido en la dirección almacenada en q.
    *q=40;
    printf("b: %i\n",b);
    printf("direcci%cn de b: %i\n",162,&b);
    printf("valor de q: %i\n",q);
    printf("direcci%cn de q: %i\n",162,&q);
    printf("valor contenido en la direcci%cn almacenada en q: %i\n",162,*q);
    //e. Ingresar desde teclado el valor de a usando su dirección almacenada. Mostrar el valor de a, la dirección de a, el valor de p,
    //la dirección de p y el valor contenido en la dirección almacenada en p.
    printf("ingrese el valor que desea asignarle a \"a\"\n",a);
    scanf("%i",p);
    printf("a: %i\n",a);
    printf("direcci%cn de a: %i\n",162,&a);
    printf("valor de p: %i\n",p);
    printf("direcci%cn de p: %i\n",162,&p);
    printf("valor contenido en la direcci%cn almacenada en p: %i\n",162,*p);
    //f. Asigna a r la dirección de a.
    r=&a;
    //g. Asigna a la posición de memoria contenida en el puntero r el valor 200. Mostrar el valor de a, la dirección de a , el valor de
    //p, la dirección de p y el valor contenido en la dirección almacenada en p, y el valor de r, la dirección de r y el valor
    //contenido en la dirección almacenada en r.
    *r=200;
    printf("a: %i\n",a);
    printf("direcci%cn de a: %i\n",162,&a);
    printf("valor de p: %i\n",p);
    printf("direcci%cn de p: %i\n",162,&p);
    printf("valor contenido en la direcci%cn almacenada en p: %i\n",162,*p);
    printf("valor de r: %i\n",r);
    printf("direcci%cn de r: %i\n",162,&r);
    printf("valor contenido en la direcci%cn almacenada en r: %i\n",162,*r);
    //h. Emite un mensaje indicando si el valor del puntero p es igual al valor del puntero q
    printf("el valor del puntero p");
    (p==q ? printf(" es igual") : printf(" no es igual"));
    printf(" al valor del puntero q\n");

    //i. Ídem h indicando si el valor del puntero p es igual al valor del puntero r.
    printf("el valor del puntero p");
    (p==r ? printf(" es igual") : printf(" no es igual"));
    printf(" al valor del puntero r\n");
    //j. Emite un mensaje indicando si el contenido de la posición de memoria apuntada por p es igual al contenido de la
    //posición de memoria apuntada por q.
    printf("el contenido de la posici%cn de memoria apuntada por p",162);
    (*p==*r ? printf(" es igual") : printf(" no es igual"));
    printf(" al contenido de la posici%cn de memoria apuntada por q\n",162);
    //k. Declara una variable de tipo puntero a entero y una variable entera. Asígnale un valor a la variable entera. Guarda la
    //dirección. Luego lee el contenido de la variable puntero y muéstralo en hexadecimal.
    int *variablePaE,variable;
    variable=10;
    variablePaE=&variable;
    printf("el contenido de la posici%cn de memoria apuntada por el puntero variablePaE en hexadecimal es %x\n",162,*variablePaE);
    return 0;

}
