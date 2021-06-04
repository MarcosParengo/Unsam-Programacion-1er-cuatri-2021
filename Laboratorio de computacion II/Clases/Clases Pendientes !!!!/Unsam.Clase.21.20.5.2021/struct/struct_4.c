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
   struct vuelo un_vuelo = {"AEP", "CNQ", 95, 680.00, {11,4,2020}};
   struct vuelo otro_vuelo;
   struct vuelo tercer_vuelo;

    strcpy(otro_vuelo.origen,"EZE");
    strcpy(otro_vuelo.destino,"IRJ");
    otro_vuelo.duracion = 40;
    otro_vuelo.precio = 4780;
    otro_vuelo.date.dia = 12;
    otro_vuelo.date.mes = 4;
    otro_vuelo.date.anio =2020;

    printf("Ingrese el vuelo origen\n");
    gets(tercer_vuelo.origen);
    printf("Ingrese el vuelo destino\n");
    gets(tercer_vuelo.destino);
    printf("Ingrese duración\n");
    scanf("%d",&tercer_vuelo.duracion);
    printf("Ingrese el precio\n");
    scanf("%f",&tercer_vuelo.precio);
    printf("Ingrese el dia\n");
    scanf("%d",&tercer_vuelo.date.dia);
    printf("Ingrese el mes\n");
    scanf("%d",&tercer_vuelo.date.mes);
    printf("Ingrese el año\n");
    scanf("%d",&tercer_vuelo.date.anio);

    printf("Origen: %s, Destino: %s, Duración: %d, Precio: %.2f, Fecha:%d/%d/%d\n",
           un_vuelo.origen, un_vuelo.destino, un_vuelo.duracion, un_vuelo.precio,
           un_vuelo.date.dia,un_vuelo.date.mes, un_vuelo.date.anio);
    printf("Origen: %s, Destino: %s, Duración: %d, Precio: %.2f, Fecha:%d/%d/%d\n",
           otro_vuelo.origen, otro_vuelo.destino, otro_vuelo.duracion, otro_vuelo.precio,
           otro_vuelo.date.dia,otro_vuelo.date.mes, otro_vuelo.date.anio);
    printf("Origen: %s, Destino: %s, Duración: %d, Precio: %.2f, Fecha:%d/%d/%d\n",
           tercer_vuelo.origen, tercer_vuelo.destino, tercer_vuelo.duracion, tercer_vuelo.precio,
           tercer_vuelo.date.dia,tercer_vuelo.date.mes, tercer_vuelo.date.anio);

getchar();
    return 0;
}

