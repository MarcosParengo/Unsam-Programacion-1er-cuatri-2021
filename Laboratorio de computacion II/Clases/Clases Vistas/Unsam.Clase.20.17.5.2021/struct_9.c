/*ejemplo 9*/
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
    float combustible[3];
};

void emite_reg(struct vuelo reg){
int j;
printf("Origen: %s, Destino: %s, Duracion: %d, Precio: %.2f, Fecha:%d/%d/%d\n",
        reg.origen, reg.destino, reg.duracion, reg.precio,
        reg.date.dia, reg.date.mes, reg.date.anio);
        for ( j = 0; j < 3; j++){
           printf("Combustible de este trayecto gastado en el dia: %d, %.2f\n", j+1, reg.combustible[j]);
        }
}

void emito_vuelo(struct vuelo v[], int d){
int i,j;
    for (i=0; i< d; i++){
    emite_reg(v[i]);
    }
}

void carga_reg(struct vuelo * ptr_reg){
 int j;
    printf("Ingrese el vuelo origen\n");
    gets(ptr_reg->origen);
    fflush(stdin);
    printf("Ingrese el vuelo destino\n");
    gets(ptr_reg->destino);
    fflush(stdin);
    printf("Ingrese duración\n");
    scanf("%d",&ptr_reg->duracion);
    fflush(stdin);
    printf("Ingrese el precio\n");
    scanf("%f",&ptr_reg->precio);
    fflush(stdin);
    printf("Ingrese el dia\n");
    scanf("%d",&ptr_reg->date.dia);
    fflush(stdin);
    printf("Ingrese el mes\n");
    scanf("%d",&ptr_reg->date.mes);
    fflush(stdin);
    printf("Ingrese el año\n");
    scanf("%d",&ptr_reg->date.anio);
    fflush(stdin);
    for ( j = 0; j < 3; j++){
        printf("Ingrese la cantidad de combustible del viaje %d\n", j + 1);
        scanf("%f",&ptr_reg->combustible[j]);
        fflush(stdin);
    }
}

void carga_vuelo(struct vuelo v[], int d){
int i,j;
char op;
for (i = 0; i < d; i++)
    carga_reg(&v[i]);
}

int main() {
const int dim=2;
struct vuelo un_vuelo[dim];
    printf("Comienzo de programa...\n");
    carga_vuelo(un_vuelo, dim);
    printf("Emisión de los datos cargados...\n");
    emito_vuelo(un_vuelo, dim);
    printf("Fin de programa...\n");
getchar();
return 0;
}

