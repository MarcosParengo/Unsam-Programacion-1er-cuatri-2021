/*ejemplo 11*/
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


void emito_vuelo(struct vuelo v[], int d){
int i,j;
    for (i=0; i< d; i++){
    printf("Origen: %s, Destino: %s, Duracion: %d, Precio: %.2f, Fecha:%d/%d/%d\n",
        v[i].origen, v[i].destino, v[i].duracion, v[i].precio,
        v[i].date.dia,v[i].date.mes, v[i].date.anio);
        for ( j = 0; j < 3; j++){
           printf("Combustible de este trayecto gastado en el dia: %d, %.2f\n", j+1, v[i].combustible[j]);
        }
    }
}

void modif_varias(float * pre_o_comb){
printf("Ingrese el nuevo valor:\n");
scanf("%f",pre_o_comb);
fflush(stdin);
printf("Campo modificado...\n");
}

void carga_vuelo(struct vuelo v[], int d){
int i,j;
char op;
for (i = 0; i < d; i++){
    printf("Ingrese el vuelo origen\n");
    gets(v[i].origen);
    fflush(stdin);
    printf("Ingrese el vuelo destino\n");
    gets(v[i].destino);
    fflush(stdin);
    printf("Ingrese duración\n");
    scanf("%d",&v[i].duracion);
    fflush(stdin);
    printf("Ingrese el precio\n");
    scanf("%f",&v[i].precio);
    fflush(stdin);
    printf("Precio Ingresado %.2f\n", v[i].precio);
    printf("\nSe equivocó en el ingreso del precio?\nPulse cualquier teclar para seguir o '*' para modificar...\n");
    scanf("%c",&op);
    fflush(stdin);
    if (op == '*')  modif_varias(&v[i].precio);
    printf("Ingrese el dia\n");
    scanf("%d",&v[i].date.dia);
    fflush(stdin);
    printf("Ingrese el mes\n");
    scanf("%d",&v[i].date.mes);
    fflush(stdin);
    printf("Ingrese el año\n");
    scanf("%d",&v[i].date.anio);
    fflush(stdin);
    for ( j = 0; j < 3; j++){
        printf("Ingrese la cantidad de combustible del viaje %d\n", j + 1);
        scanf("%f",&v[i].combustible[j]);
        fflush(stdin);
        printf("\nSe equivocó en el ingreso de la cantidad de combustible?\nPulse cualquier teclar para seguir con el programa o '*' para modificar...\n");
        scanf("%c",&op);
        fflush(stdin);
        if (op == '*')  modif_varias(&v[i].combustible[j]);
    }
}
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

