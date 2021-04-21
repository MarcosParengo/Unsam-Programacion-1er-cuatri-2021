#include <stdio.h>

int vglobal = 1000;

void suma1(int x);
void suma2(int x);

int main(){
int vlocal=20;
//clrscr();
printf("\nLa variable vglobal en main vale = %d\n", vglobal);
printf("\nLa variable vlocal en main vale = %d\n", vlocal);
suma1(vlocal);
/* En salida no se ha modificado su valor pese a */
/* que en suma1 se hagan operaciones con vlocal (argumento) */
printf("\nLa variable vglobal despues de suma1 vale = %d\n", vglobal);
printf("\nLa variable vlocal despues de suma1 vale = %d\n", vlocal);
suma2(vlocal);
printf("\nLa variable vglobal despues de suma2 vale = %d\n", vglobal);
printf("\nLa variable vlocal despues de suma2 vale = %d\n", vlocal);
getchar();
return 0;
}

void suma1(int x){
++x;
++vglobal;
printf("\nLa variable vglobal dentro de suma1 vale = %d\n", vglobal);
printf("\nEl argumento (vlocal) dentro de suma1 vale = %d\n", x);
}

void suma2(int x){
int vglobal=7;
++x;
printf("\nLa variable vglobal dentro de suma2 vale = %d\n", vglobal);
printf("\nEl argumento (vlocal) dentro de suma2 vale = %d\n", x);
++vglobal;
}
