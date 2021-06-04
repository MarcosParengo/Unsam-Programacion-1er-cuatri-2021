/*
 Ejemplos de FUNCIONES sobre tablas:
   - Cargar
   - Mostrar
   - Ordenar
   - Busqueda secuencial
   - Busqueda dicotómica o binaria
   TODAS las funciones reciben como parámetro Nelementos, donde
   se guarda el tamaño de la tabla
*/
#include <stdio.h>
#include <time.h>
#define N 10

// Ordenamiento por el método de la Burbuja ( Intercambio directo) con indicador
void Ordenar (int v[], int Nelementos){
int aux,i=0,j,cambio = 1;

while (cambio){
    cambio = 0;
    for (j=0; j<Nelementos-i-1 ;j++){
      	if (v[j]> v[j+1]){
            aux=v[j];
            v[j]= v[j+1];
            v[j+1]= aux;
	    cambio = 1;
            }
         }
    i++;
   }
}

// carga el vector con N elementos en forma aleatoria
void Rellenar (int v[], int Nelementos){
int i;
srand(time(NULL));
for (i=0;i<Nelementos ;i++) v[i]=10+rand()%99;

}

//emite
void Mostrar (int v[], int Nelementos){
int i;
for (i=0;i< Nelementos;i++) printf("%2d = %3d \n",i+1, v[i]);
}

/* Busqueda secuencial devuelve :
   -1 sin no lo encuentra, o la posición 0 - (N-1) */
int BuscarSecuencial  ( int v[], int valor, int Nelementos ){
 int i,resu=-1;

 for (i=0;i<Nelementos;i++ ){
      if ( valor == v[i] ){
         resu = i;
         break;
         }
      }
 return resu;
}

/* Busqueda dicotomica devuelve :
   -1 sin no lo encuentra, o la posición 0 - (N-1) */
int BuscarBinaria ( int v[], int dato, int Nelementos ){
  int encontrado=0,izq=0,der=Nelementos-1,resu=-1,medio;

  while ((encontrado==0)&&(izq<=der)){
      medio=(izq+der)/2;
      if (v[medio]==dato){
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

  if ( encontrado )
      {
      resu = medio; /* Guarda la posición */
      }

 return resu;
}

void main(){
    int datos[N];
    int pos, valor;

    Rellenar(datos,N);
    Ordenar(datos,N);
    Mostrar(datos,N);
    printf("Ingrese un valor a buscar:\n");
    scanf("%d",& valor );
    puts("BÚSQUEDA SECUENCIAL");
    pos = BuscarSecuencial(datos,valor,N);
    if ( pos == -1)
        {
        printf(" El valor no se ha encontrado \n");
        }
    else
        {
        printf(" El valor se encuentra en la posición %d \n", pos+1 );
        }

    puts("BÚSQUEDA BINARIA");
    pos = BuscarBinaria(datos,valor,N);
    if ( pos == -1)
        {
        printf(" El valor no se ha encontrado \n");
        }
    else
        {
        printf(" El valor se encuentra en la posición %d \n", pos +1 );
        }

  getchar();
  getchar();
}

