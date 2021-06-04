/* Ordenamiento de un vector de números enteros*/
/* Método: burbuja mejorado con centinela */
/* Ejemplo de paso de vectores como parámetros */
/* Entrada: teclado */
/* Salida: pantalla  */
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

void cargaelem(int v[], int d){
int i;
srand(time(NULL));
for (i = 0; i < d; i++) v[i] = 1 + rand() % 50;
}

void emiteelem(int v[], int d){
int i;
for (i = 0; i < d; i++) printf ("%d - ", v[i]);
printf("\n");
}

void ordenaelem(int v[], int d){
int i,j, aux, cambio;
/* Ordenamiento*/
for (i = 0; i < d-1; i++)
    {cambio = 0;
	   for (j = 0; j < d-(i+1); j++)
       {if (v[j] > v[j+1]){
            aux = v[j];
			v[j] = v[j+1];
			v[j+1] = aux;
			cambio = 1;
		}
    }
    }
/* Fin ordenamiento*/
}

int main(){
const int dim=10;
int vec[dim];
cargaelem(vec,dim);
printf ("\nElementos ingresados: \n");
emiteelem(vec,dim);
ordenaelem(vec,dim);
printf ("\nResultado después de ordenar: \n");
emiteelem(vec,dim);
getchar();
return 0;
}
