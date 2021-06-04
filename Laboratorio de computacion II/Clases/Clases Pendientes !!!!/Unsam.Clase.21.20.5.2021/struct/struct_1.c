/* struct.c: Illustrates structures */
#include <stdio.h>
#include <string.h>
// declarar una estructura
struct vuelo {
    char origen[5]; // declaro las variables
    char destino[5];
    int duracion;
    float precio;
}; // definí un nuevo tipo de datos

int main() {
    struct vuelo un_vuelo = {"AEP", "CNQ", 95, 680.00}; // declaro la variable un_vuelo de tipo struct vuelo, inicializo los campos
    struct vuelo otro_vuelo;

    strcpy(otro_vuelo.origen,"EZE");
    strcpy(otro_vuelo.destino,"IRJ");
    otro_vuelo.duracion = 40;
    otro_vuelo.precio = 4780;

    printf("Origen: %s, Destino: %s, Duración: %d, Precio: %.2f\n",
           un_vuelo.origen, un_vuelo.destino, un_vuelo.duracion, un_vuelo.precio);
    printf("Origen: %s, Destino: %s, Duración: %d, Precio: %.2f\n",
           otro_vuelo.origen, otro_vuelo.destino, otro_vuelo.duracion, otro_vuelo.precio);
getchar();
    return 0;
}

