#include<stdio.h>
/*Completar el ejercicio*/

/*Carga del vector*/
void carga_vector(int v[], int d){
int i;
for(i = 0; i < d ; i++){
    printf("Ingrese v[%d]\n", i) ;
    scanf("%d", &v[i]);
 }
}
/*emisión del contenido del vector*/
void emite_vector(int v[], int d){
int i;
for(i = 0; i < d ; i++)
     printf("v[%d]=%d\n", i, v[i]);
}
/*Suma de los elementos del vector*/
int suma_vector(int v[], int d){
int i,suma=0;

for(i = 0; i < d ; i++)
     suma = suma + v[i];

  return suma;
}

/*emisión de los elementos en las posiciones pares*/
void elem_pos_par(int v[], int d){
int i;
printf("\nLos elementos en las posiciones pares son:\n");
for(i = 0; i < d ; i++){
    if (i%2 == 0)
         printf("v[%d]=%d\n", i, v[i]);
}
}

int main(){
  const int dim = 5;
  int v[dim];
  int suma;

/*a.	Cargar un vector de m elementos por teclado.
Debes considerar que no podrá superar el máximo de elementos de vector (m=dimensión).*/
carga_vector(v,dim);
/*emitimos el contenido del vector para testear*/
emite_vector(v,dim);

/*b.	Calcular y emitir la suma de sus elementos. */
suma = suma_vector(v,dim);
printf("\nLa suma de los elementos del vector es %d\n", suma);

/*j.	Emitir aquellos que estén ubicados en posición par. */
elem_pos_par(v,dim);


getchar();
return 0;
}
