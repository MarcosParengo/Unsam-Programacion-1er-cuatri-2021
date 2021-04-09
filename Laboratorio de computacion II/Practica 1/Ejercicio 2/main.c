#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a;
    float b;
    char c;

    scanf ("%c", &c);//Guarda como char lo ingresado(corresponde)
    printf("c char %c\n",c);

    scanf ("%d", &c);//Guarda como decimal lo ingresado(si se escribe un numero mayor a 255 da la vuelta)
    printf("c decimal %d\n",c);

    scanf ("%f", &c);//Guarda como float lo ingresado(No corresponde ya que a es int)
    printf("c float %f\n",c);

    scanf ("%d", &a);//Guarda como decimal lo ingresado(corresponde)
    printf("a decimal %d\n",a);

    scanf ("%f", &a);//Guarda como float lo ingresado(No corresponde ya que a es int)
    printf("a float %f",a);

    scanf ("%c", &a);//Guarda como char lo ingresado(No corresponde ya que a es int)
    printf("a char %c",a);

    scanf ("%d", &b);//Guarda como decimal lo ingresado(No corresponde ya que a es int)
    printf("b decimal %d\n",b);

    scanf ("%f", &b);//Guarda como float lo ingresado(corresponde)
    printf("b float %f\n",b);

    scanf ("%c", &b);//Guarda como char lo ingresado(No corresponde ya que a es gloat)
    printf("b char %c\n",b);

}
