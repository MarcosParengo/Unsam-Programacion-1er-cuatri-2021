#include <stdio.h>

int vglobal = 1000;

int main(){
int vlocal=20;
printf("\nLa variable vglobal en main vale = %d\n", vglobal);
printf("\nLa variable vlocal en main vale = %d\n", vlocal);
vlocal++;
vglobal++;
printf("\nLa variable vglobal despues de incrementar vale = %d\n", vglobal);
printf("\nLa variable vlocal despues de incrementar vale = %d\n", vlocal);
return 0;
}

