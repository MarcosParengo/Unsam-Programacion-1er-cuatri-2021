/* Inserta ordenadamente elementos en una tabla */
#include <stdio.h>
#define N 5

void emitir(int al[], int d){
int i;
printf("Contenido de la tabla:\n");
for (i=0;i<d;i++) printf(" Tabla[%d] = %d\n",i,al[i]);
printf("\n");
}

int BuscarD ( int tabla[], int tamano, int valor ){
 int izda,dcha,centro,encontrado;

 encontrado = 0;
 izda  = 0;
 dcha  = tamano-1;
 while ((izda <= dcha) && (!encontrado)){
  centro = ( izda + dcha ) / 2;
  if ( tabla[centro] == valor )
     {
     encontrado = 1;
     }
  else
     {
     if ( tabla[centro] > valor )
	 {
	 dcha = centro -1;
	 }
     else
	 {
         izda = centro +1;
	 }
    }
  }
 return encontrado;
}

void Insertar ( int tabla[], int tam, int valor ){
  int i,j, encontrado = 0;

  // Busco donde colocarlo
  i = 0;
  while ( i < tam & !encontrado)
	{
	if ( tabla[i] > valor )
	   {
	   encontrado = 1;
	   }
	else
	   {
	   i++;
	   }
	}

  // Desplazo si es necesario
   for (j=tam-1;j>=i;j--) tabla[j+1] = tabla[j];
   // Coloco el valor
   tabla[i] = valor;
   emitir(tabla,N );
}

int main(){
int Almacen[N],nelementos = 0,numero,i;
//carga
printf("Ingrese los números:\n");
for (i=0;i<N;i++) {
    printf("Valor %d:\n",i);
    scanf("%d",&numero);
    if ( !BuscarD( Almacen,nelementos,numero) )
	 {
	 printf("Insertando...\n");
	 Insertar(Almacen,nelementos,numero);
	 nelementos++;
	 }
    else
	 {
	 printf("Elemento repetido...\n");
	 }
    }

getchar();
return 0;
}









