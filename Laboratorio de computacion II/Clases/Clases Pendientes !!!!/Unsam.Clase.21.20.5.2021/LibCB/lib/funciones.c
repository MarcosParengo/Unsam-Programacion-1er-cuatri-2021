#include <stdio.h>
#include <stdlib.h>
#include "misfunciones.h"

int main()
{int numero, resultado, total;
float n1, n2, n3, res;

printf("Introduzca un número:\n");
scanf("%i",&numero);
resultado=par(numero);

if (resultado==1)
   printf("Es par.\n");
else
    printf("Es impar.\n");

printf("Introduzca un número real:\n");
scanf("%f",&n1);
printf("Introduzca otro número real:\n");
scanf("%f",&n2);
res=media2(n1,n2);
printf("La media es: %.2f.\n",res);


printf("Introduzca un número real:\n");
scanf("%f",&n1);
printf("Introduzca otro número real:\n");
scanf("%f",&n2);
printf("Introduzca otro número real:\n");
scanf("%f",&n3);

media3(n1,n2,n3);

numero=pedir();
total =triple(numero);
printf("El triple de %i es: %i\n",numero, total);

getchar();
return 0;
 }
