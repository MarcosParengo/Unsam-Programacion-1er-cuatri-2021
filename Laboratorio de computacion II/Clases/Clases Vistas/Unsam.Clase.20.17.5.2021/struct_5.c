/* struct.c: Illustrates structures */
#include <stdio.h>
#include <string.h>

struct vuelo {
    char origen[5];
    char destino[5];
    int duracion;
    float precio;

};

int main() {
   const int dim=2;
   struct vuelo un_vuelo[dim]; // creo un vector de tipo struct vuelo
   int i;
    for (i = 0; i < dim; i++){
    printf("Ingrese el vuelo origen\n");
    gets(un_vuelo[i].origen);
    fflush(stdin);
    printf("Ingrese el vuelo destino\n");
    gets(un_vuelo[i].destino);
    fflush(stdin);
    printf("Ingrese duración\n");
    scanf("%d",&un_vuelo[i].duracion);
    fflush(stdin);
    printf("Ingrese el precio\n");
    scanf("%f",&un_vuelo[i].precio);
    fflush(stdin);
    }
    for (i=0; i< dim; i++){
    printf("Origen: %s, Destino: %s, Duración: %d, Precio: %.2f\n",
           un_vuelo[i].origen, un_vuelo[i].destino, un_vuelo[i].duracion, un_vuelo[i].precio);
    }
getchar();
    return 0;
}

