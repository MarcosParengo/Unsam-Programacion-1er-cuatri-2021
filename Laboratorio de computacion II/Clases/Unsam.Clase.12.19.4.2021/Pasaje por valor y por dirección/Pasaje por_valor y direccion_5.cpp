#include <stdio.h>

void leer (int*,int*);
int operaciones (int*,int*);
void resultado(int*,int*,int );

int main(){
    int a,b,c;
    leer (&a,&b);
    resultado(&a,&b,c);
    getchar();
    return 0;
}

void leer (int*a,int*b){
    printf ("Ingrese 2 valores\n");
    scanf("%d",a);
    scanf("%d",b);
}

void resultado(int*a,int*b,int c){
int t;
t=operaciones(a,b);
printf("el resultado es %d\n",t);
   //o printf("el resultado es %d\n",operaciones(a,b));
printf("los valores de las variables a y b dentro de la función resultado son: %d y %d\n",*a,*b);
printf("El valor de c dentro de la función resultado es: %d\n", c);
}

int operaciones (int *a,int *b){
int c;
c=*a%*b+1;
*a=0;
*b=0;
printf("Los valores de a y b dentro de la función operaciones son:%d y %d\n", *a,*b);
return c;
}

