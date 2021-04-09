#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a, b, c, d = 0;
    int e = 1;
    int x = 2, y = 3;
    a = 5 > 3;//Se guarda un 1 en a ya que la condicion es verdadera
    b = ((4<5) && (2>2));//Se guarda un 0 en a ya una de las dos condiciones no es verdadera &&->and(las dos condiciones deben ser verdaderas para q devuelva true)
    a = !e;//devuelve el opuesto de e, 0
    b = (((x%2)==0) || -1<10);//devuelve un 1 ya que por lo menos una condicion es verdadera
    printf("%d",b);
    c = ( d && e );//devuelve un 0 ya que una de las condiciones es falsa
    c = ( d || e );//devuelve un 0 ya que por lo menos una de las condiciones es verdadera
    c = ! ( d && e );//devuelve un 1 ya que es el opuesto de un and que tiene una de las condiciones falsa
    c = ( ! d ) && ( ! e );//devuelve un 0 ya que es el opuesto de una de las condiciones da falso
    c = ( a && ( ! a ) );//devuelve un 0 ya que  de una de las condiciones da falso
    c = ( ( ( x <= ( y * 3.2 ) ) && ( y % 2 != 0 ) ) || ( 1 ) );//devuelve un 1 ya que por lo menos una condicion es verdadera
    return 0;
}
