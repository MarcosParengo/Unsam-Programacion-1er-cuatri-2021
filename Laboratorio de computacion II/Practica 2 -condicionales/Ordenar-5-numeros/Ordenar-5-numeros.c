#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a,b,c,d,e,aux,aux2;
    int i=0;

    printf("Ingrese un numero\n");
    scanf("%d", &a);
    printf("Ingrese otro numero\n");
    scanf("%d", &b);
    printf("Ingrese otro letra\n");
    scanf("%d", &c);
    printf("Ingrese otro letra\n");
    scanf("%d", &d);
    printf("Ingrese otro letra\n");
    scanf("%d", &e);

    //Imprimo el orden original
    printf("Orden original:\n");
    printf("a: %d\n",a);
    printf("b: %d\n",b);
    printf("c: %d\n",c);
    printf("d: %d\n",d);
    printf("e: %d\n",e);
    //Los ordeno de menor a mayor
    for(i=0;i<=4;i++){
        if(a>b){
            aux=a;
            a=b;
            b=aux;
        }
        if(b>c){
            aux=c;
            c=b;
            b=aux;
        }
        if(c>d){
            aux=d;
            d=c;
            c=aux;
        }
        if(d>e){
            aux=e;
            e=d;
            d=aux;
        }
    }
    printf("Secuencia ordenada:\n");
    printf("a: %d\n",a);
    printf("b: %d\n",b);
    printf("c: %d\n",c);
    printf("d: %d\n",d);
    printf("e: %d\n",e);

    printf("Ingrese un caracter para finalizar la ejecuci%cn\n",162);
    scanf("%d", &c);
}
