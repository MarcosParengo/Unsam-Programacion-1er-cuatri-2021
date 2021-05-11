#include <stdio.h>
#include <stdlib.h>

int main (){
    void * generico;
    int* pint,x=3 ;
    char *pchar="Punteros a caracteres" ;//forma de definir una cadena de caracteres constante
    //*pchar='c'//mal ya que pretendo cambiar el valor de una cadena de caracteres constante

    //char pchar[20]="Punteros a caracteres"
    //*pchar='p'//cambio el valor de la posicion de pchar (el primer valor de la cadena)
    //printf("&s",pchar);//retorna "punteros a caracteres", efectivamente cambie la primer letra de mi cadena
    pint=&x;
    printf("El valor apuntado por pint es %d (valor de x)",*pint) ;
    generico=pchar;
    printf("\n\npchar (tipo char) apuntado por p %s",pchar);
    //*pchar apunta a una cadena de caracteres
    printf("\n\ngenerico (tipo void) apunta a objeto char:%s" ,(char*)generico);
    //generico apunta a una cadena de caracteres, debo castearlo void a char
    printf("\n\nImprimo ahora generico como char: ");
    puts((char*)generico);
    //generico apunta a una cadena de caracteres, debo castearlo void a char
    return 0 ;
}
