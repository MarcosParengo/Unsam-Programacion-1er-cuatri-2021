/*Escribe un programa que lea un número entero correspondiente a la cantidad
de discos a usar y emita los movimientos correspondientes al juego de las
Torres de Hanoi. Ejemplo: Se dan tres barras verticales y n discos de
diferentes tamaños. Los discos pueden apilarse en las barras formando
“torres”. Los discos aparecen inicialmente en la primera barra en orden
decreciente y la tarea es mover los n discos de la primer barra a la tercera
de manera que queden ordenados de la misma forma inicial. Las reglas a
cumplir son:
 En cada paso se mueve exactamente un disco desde una barra a otra.
  En ningún momento pueden situarse un disco encima de otro más pequeño.*/
#include <stdio.h>

void Leer(int * x){
printf("Ingrese la cantidad de discos:\n")    ;
scanf("%d",x);
}

void hanoi(int cantidisco,char origen, char destino, char auxiliar){
if(cantidisco>0){
    hanoi(cantidisco-1,origen,auxiliar,destino);
    printf("Mover disco desde %c hasta %c\n",origen,destino);
    hanoi(cantidisco-1,auxiliar,destino,origen);
    }
}

int main(){
char origen='a', destino='b', auxiliar='c';
int cantdis;
    printf("Torres de Hanoi: \n");
    Leer(&cantdis);
    hanoi(cantdis, origen, destino, auxiliar);
getchar();
return 0;
}
