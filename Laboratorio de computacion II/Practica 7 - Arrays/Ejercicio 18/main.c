#include <stdio.h>
#include <stdlib.h>

int main()
{
    int array[] = {1,2,3,4,5,6};//Define un array de longitud 6
    int *puntero, x;//define dos variables int, una puntero y otra habitual
    puntero = array;//a la variable puntero le asigna la primer posicion del vector
    puntero++;//mueve el puntero a la siguiente posicion del array, array[1]
    *puntero = *puntero + 6;//modifica al valor al que apunta el puntero (array[1]=array[1]+6 --> array[1]=2+6)
    puntero = puntero + 3;//mueve el puntero tres posiciones, a la 5ta posicion del array, puntero ahora apunta a array[4]
    puntero = puntero-puntero[-1];//le resta a puntero lo que esta en puntero[-2] ({1,8,3,4,5,6}), 3, asi que hace que ahora puntero apunte a array[4-3],array[1]
    //                                                                                  \-2\-1\posicion 0
    x = puntero - array;//array apunta a array[0] y puntero a array[1], la diferencia entre las direcciones es 1
    printf("%d\n",x);
}
