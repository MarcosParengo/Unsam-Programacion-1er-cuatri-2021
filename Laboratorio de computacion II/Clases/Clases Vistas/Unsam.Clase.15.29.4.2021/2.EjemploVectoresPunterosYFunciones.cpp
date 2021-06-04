#include<stdio.h>
/*
Con este programa mostraremos algunas caracteristicas muy importantes de los vectores
en C, y su relación con los punteros
*/
void carga_vector(int v[], int d){
int i;
for(i = 0; i < d ; i++){
    printf("Ingrese v[%d]\n", i) ;
    scanf("%d", &v[i]);
 }
}

void emite_vector(int v[], int d){
int i;
for(i = 0; i < d ; i++)
     printf("v[%d]=%d\n", i, v[i]);
}

void direccion_elementos(int v[], int d){
int i;
for(i = 0; i < d ; i++)
    printf("El elemento v[%d] tiene direccion %p \n", i, &v[i]) ;
}

void emito_v(int v[]){
printf("\nEsto se emite como printf de v: %p\n", v);
}

void emito_con_NotPunt(int * v, int d){
int i;
for(i = 0; i < d ; i++)
    printf("v[%d]=%d \n", i, *(v+i)) ;
}

/* La siguiente función tiene el mismo efecto que la anterior
sólo cambia, en el encabezado, la escritura del parámetro que recibe
la dirección del vector, en el ciclo for
se expresa con notación de punteros*/

//void emito_con_NotPunt(int v[], int d){
//int i;
//for(i = 0; i < d ; i++)
//    printf("v[%d]=%d \n", i, *(v+i)) ;
//}

/* La siguiente función también tiene, se recibe la dirección del
vector en un puntero, pero el ciclo for
se expresa con notación de subíndices*/

//void emito_con_NotPunt(int * v, int d){
//int i;
//for(i = 0; i < d ; i++)
//    printf("v[%d]=%d \n", i, v[i]) ;
//}



int main(){
 /* primero vamos a cargar el vector
 por motivos didacticos, iremos declarando y definiendo las variables
 a medida que las necesitemos en el programa
 Recordar que , por normas de buena programacion, lo mas correcto es definir y declarar
 las variables al comienzo del programa */
  const int dim = 5;
  int v[dim];

 /*carga del vector*/
printf("Carga del vector utilizando subíndices\n");
carga_vector(v,dim);

 /*emitimos el contenido del vector*/
printf("\nEmision del vector utilizando subíndices\n") ;
emite_vector(v,dim);

/*Ahora vamos a mostrar las direcciones  correspondientes a los elementos del vector
recordar que los valores que se van a emitir   varian de una computadora a otra*/
direccion_elementos(v,dim);


/*y ahora , el punto central de este programa
vamos a ver que se emite  cuando hagamos un printf de v (el nombre del vector)*/
emito_v(v);

//Se mostro lo mismo que con &v[0]
//eso significa que el nombre de v tiene un valor asociado, y ese valor es la direccion
//del primer elemento del mismo
//En C, el nombre de un vector es un puntero al comienzo del vector
//El nombre de un vector ES la direccion de comienzo del mismo
//v es un PUNTERO CONSTANTE (es decir, no podemos hacer que v 'comience en otra parte'

//entonces, v es &v[o]
//          v+1 es &v[1]
//          v+2 es &v[2]
// y asi sucesivamente...
//lo cual implica, por la notación de punteros que ya conocemos
//que v[0] es *v
//    v[1] es *(v+1)
//    v[2] es *(v+2)
//etc...
//vamos a emitir el contenido de v usando la notacion de punteros
printf("\nEmision del contenido del vector usando\nnotacion de punteros y el nombre del vector\n") ;
emito_con_NotPunt(v,dim);

getchar();
return 0;
}
