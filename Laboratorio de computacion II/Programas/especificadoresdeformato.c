/*especificadores de formato*/
#include<stdio.h>

int main(){
int a= -150;
long b=1234567890;
float c= 23.123456789;
double z=12345678934.7654386935;
int e= 532;
unsigned char f= 'a';
int op= 30;
char cad[10]="palabra";
int * p=&a;

printf("%c de %crbol\n",160,160); //á
printf ("%d es el valor de a %%d \n", a);//%d	un entero con signo en notaci�n de base decimal
printf ("%i es el valor de a %%i \n", a);//%i	un entero con signo
printf ("%x es el valor de a %%x \n", a);//%x	Hexadecimal sin signo con min�sculas
printf ("%X es el valor de a %%X \n", a);//%X	Hexadecimal sin signo con may�sculas
printf ("%ld es el valor de b %%ld \n", b);//%ld  N�mero entero largo
printf ("%f es el valor de c%%f \n", c);//%f	formato de punto flotante
printf ("%g es el valor de c %%g \n", c);//%g	la opci�n m�s corta entre "%e" y "%f"
printf ("%lf es el valor de z %%lf \n", z);//%lf	double
printf ("%e es el valor de e %%e \n", e);//%e	en notaci�n cient�fica indicando el exponente con "e"
printf ("%c es el valor de f %%c  \n", f);//%c: Caracter
printf ("%d es el valor de f %%d \n", f);//%c: Caracter como entero
printf ("%o es el valor de op %%o \n", op);//%o: n�mero entero como octal
printf ("%s es el valor de cad %%s \n", cad);//%o: cadena
printf ("%p es la direcci�n cad %%p \n", cad);//%n: puntero direccion de memoria
getchar();
return 0;
}
