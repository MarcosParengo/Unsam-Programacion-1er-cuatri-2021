#include <stdio.h>
#include <stdlib.h>

int main()
{
    char a,b,c,aux,aux2;
    int i=0;

    printf("Ingrese una letra\n");
    scanf("%c", &a);
    fflush(stdin);
    printf("Ingrese una letra\n");
    scanf("%c", &b);
    fflush(stdin);
    printf("Ingrese una letra\n");
    scanf("%c", &c);
    fflush(stdin);

    printf("a: %c\n",a);
    printf("b: %c\n",b);
    printf("c: %c\n",c);


    for(i=0;i<=2;i++){
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
    }

    printf("a: %c\n",a);
    printf("b: %c\n",b);
    printf("c: %c\n",c);
    
    printf("Ingrese un caracter para finalizar la ejecución\n");
    scanf("%c", &c);
}
