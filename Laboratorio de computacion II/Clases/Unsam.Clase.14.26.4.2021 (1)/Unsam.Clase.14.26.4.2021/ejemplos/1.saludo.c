#include <stdio.h>


void saludo(int n);

int main()
 {
   saludo(10);
   getchar();
   return 0;
 }

void saludo(int n)  {
   if(n>0)
     {
       printf("%d-->Buenas tardes...\n", n);
       saludo(n-1); //llamada a s� misma: RECURSIVIDAD
     }
 }
//Hay que obervar que, para evitar caer en un bucle infinito, el argumento con que
//es llamada la funci�n, cambia y finaliza la ejecuci�n cuando deja de cumplirse
//el condicional if()

