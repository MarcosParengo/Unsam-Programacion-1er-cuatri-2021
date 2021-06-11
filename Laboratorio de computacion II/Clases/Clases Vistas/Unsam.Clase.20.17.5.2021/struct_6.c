/* struct.c: Illustrates structures */
#include <stdio.h>
#include <string.h>

struct fecha{
int dia, mes, anio;
};

struct vuelo {
    char origen[5];
    char destino[5];
    int duracion;
    float precio;
    struct fecha date;
    };

int main() {
   const int dim=2;
   struct vuelo un_vuelo[dim];

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
    printf("Ingrese el dia\n");
    scanf("%d",&un_vuelo[i].date.dia);
    fflush(stdin);
    printf("Ingrese el mes\n");
    scanf("%d",&un_vuelo[i].date.mes);
    fflush(stdin);
    printf("Ingrese el año\n");
    scanf("%d",&un_vuelo[i].date.anio);
    fflush(stdin);
    }

    for (i=0; i< dim; i++){
    printf("Origen: %s, Destino: %s, Duración: %d, Precio: %.2f, Fecha:%d/%d/%d\n",
           un_vuelo[i].origen, un_vuelo[i].destino, un_vuelo[i].duracion, un_vuelo[i].precio,
           un_vuelo[i].date.dia,un_vuelo[i].date.mes, un_vuelo[i].date.anio);
    }

getchar();
    return 0;
}

