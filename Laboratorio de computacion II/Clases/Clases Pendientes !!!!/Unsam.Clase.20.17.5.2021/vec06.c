#include<stdio.h>
#include<stdlib.h>

struct competidor{
char nom[30];
char ape[30];
int pais;
float intento[3];
};

void Leer_val(int * d){
do{
printf("Ingrese la cantidad de competidores\n");
scanf("%d", d);
}while ((*d<=0) || (*d>10));
}

void Carga (struct competidor v[], int d){
int i,j;

for(i=0;i<d;i++){
    printf("Ingresar competidor %d\n",i+1);
    printf("Nombre:\n");
    scanf("%s",v[i].nom);
    fflush(stdin);
    printf("Apellido:\n");
    scanf("%s",v[i].ape);
    fflush(stdin);
    printf("Pa%cs -> (1 a 5):\n",161);
    scanf("%d", &v[i].pais);
    fflush(stdin);
    for (j=0;j<3;j++){
        printf("Salto [%d]:\n",j+1);
        scanf("%f", &v[i].intento[j]);
        fflush(stdin);
    }
}
}

void Emitedatos (struct competidor v[], int d){
int i,j;
printf("\n");
printf("Nombre\t Apellido\t Pa%cs\t Marcas\t\n", 161);
for(i=0;i<d;i++){
    printf("%s\t",v[i].nom);
    printf("%s\t",v[i].ape);
    printf("%d\t",v[i].pais);
    for (j=0;j<3;j++)
        printf("%.2f\t", v[i].intento[j]);
        printf("\n");
}
}

void Mejores3 (struct competidor v[], int pos[], int d, int m){
int i, j, k;
float tope=999.99, max;

for(i=0;i<m;i++){
    max=0.0;
    for(j=0;j<d;j++){
        for(k=0;k<3;k++)
if ((v[j].intento[k] > max) && (v[j].intento[k] < tope)){
     max= v[j].intento[k];
     pos[i]=j;
     }
    }
tope=max;
}
}

void Emitir (struct competidor v[], int pos[], int d){
int i,j;
printf("\nRanking:\n");
printf("Nombre\t Apellido\t Pa%cs\t Marcas\t\n", 161);
for(i=0;i<d;i++){
    printf("%s\t",v[pos[i]].nom);
    printf("%s\t",v[pos[i]].ape);
    printf("%d\t",v[pos[i]].pais);
    for (j=0;j<3;j++)
        printf("%.2f\t", v[pos[i]].intento[j]);
        printf("\n");
}
}

int main(){
struct competidor vcomp[5];
int N, vposgan[3];

printf("Procesamiento de torneo sudamericano\n");
printf("--------Pa%cses--------\n",161);
printf("1. Argentina\n");
printf("2. Uruguay\n");
printf("3. Paraguay\n");
printf("4. Brasil\n");
printf("5. Chile\n");
Leer_val(&N);    //leer y validar N >0  y <=10;
Carga(vcomp, N);   //carga de datos
Emitedatos(vcomp, N);
Mejores3(vcomp, vposgan, N, 3);   //selecciona los 3 mejores competidoresy sus posiciones quedan almacenadas en vposgan, se elige según el mejor salto
Emitir(vcomp, vposgan, 3);   //se emiten todos los datos de los 3 mejores competidores
getchar();
return 0;
}
