/*  EJEMPLO CON OPERACIONES BÁSICAS */
//  Rellenar
//  Mostrar
//  Ordenar (Burbuja con indicador)
//  Buscar (Secuencial y Dicotómica)
#include <stdio.h>
#include <time.h>
#define N 10


int main(){
 int v[N];
 int i,j, aux, der, izq, medio, encontrado, dato, intercambio;
clock_t comienzo;

 /* carga */
 for (i=0;i<N;i++)  v[i]=10+rand()%99;

/* emito */
printf("Contenido del vector:\n");
for (i=0;i<N;i++) printf(" %d |",v[i]);

printf("\n\n");


/* Ordenamiento por Burbuja con indicador*/

for (i=0;i<N-1;i++)	{
    intercambio = 0;
    for (j=0;j<N-1-i;j++)   {
        if (v[j]>v[j+1]) 	   {
           aux = v[j];
           v[j] = v[j+1];
           v[j+1]= aux;
           intercambio = 1;
           }
        }
     // Si no ha habido ningún intercambio la tabla ya está ordenada
     if ( ! intercambio )
         {
         break;
         }
   }
/* emito ordenado */

printf("Contenido del vector ordenado:\n");
for (i=0;i<N;i++) printf(" %d |",v[i]);

printf("\n\n");

printf("\nIntroduzca el valor a buscar:");
scanf("%d",&dato);

/* Busqueda Secuencial*/
printf(" BÚSQUEDA SECUENCIAL \n");
encontrado = 0;
for ( i=0;i<N; i++ )
     {
     if ( dato == v[i])
        {
        printf("El valor ha sido encontrado en la posición:%d \n",i);
        encontrado = 1;
        break;
        }
     }
if ( encontrado == 0 )
   {
   printf("El valor no se ha encontrado \n");
   }

printf("\n\n");


printf(" BúSQUEDA DICOTÓMICA O BINARIA \n");

encontrado=0;
izq = 0;
der = N;
while ((encontrado==0)&&(izq<=der))
	{
   medio=(izq+der)/2;
   if (v[medio]==dato)
   	{
      encontrado=1;
      }
   else
   	{
      if (v[medio]>dato)
      	{
         der=medio-1;
         }
      else
      	{
         izq=medio+1;
         }
      }
   }
if (encontrado==0)
	{
   printf("El valor no se ha encontrado");
   }

getchar();
return 0;
}
