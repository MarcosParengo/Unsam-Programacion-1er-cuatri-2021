#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include <time.h>


#define FIL 4
#define COL 6
// Una fábrica de cocinas, heladeras y lavarropas, tiene N sucursales propias, cada una
//ubicada en la cabecera de partido de la provincia de Buenos Aires. Para ello, se define un array
//de N struct con los siguientes datos:
struct sucursales{
  int id_sucursal;
  char ciudad[30];
  float descuentos_del_mes[30];
  float promedio_descuentos;
  float total_descuentos_del_mes;
};
//Además se define un array con N datos de gerentes responsables:
struct gerentes{
    int id_sucursal;
    char nombre_gerente[30];
};

// carga en forma aleatoria los 30 descuentos de cada sucursal
void carga_total_descuentos(struct sucursales a[]);
void carga_descuentos(struct sucursales a[]);
int cargaTotalDescuentosMayores(struct sucursales a[],int vauxiliar[]);
void ciudadYnombreGerenteSucursalesDescuentosMayores(struct sucursales a[],struct gerentes b[],int vauxiliar[],int cantidad);
int main()
{
    //lleno el vector de structs "sucursales"
    struct sucursales a[FIL]={{1,"Bernal",0,0,0},{2,"Quilmes",0,0,0},{3,"San Martin",0,0,0},{4,"Ciudad 4",0,0,0}};
    //lleno el vector de structs "gerentes"
    struct gerentes b[FIL]={{1,"Juan"},{2,"Pablo"},{3,"Mariel"},{4,"Ines"}};
    //"se define un tercer array de enteros de dimensión N que se inicializara con -1" Punto 3:
    int vauxiliar[FIL]={-1,-1,-1,-1};
    //Por otra parte, se almacenan en una array bidimensional de N filas por M columnas, los descuentos realizados con anterioridad por sucursal:
    float descuentosAnteriores[FIL][COL];
    srand(time(NULL));
    carga_descuentos(a);
    carga_matriz(descuentosAnteriores);
    muestra(a,b,vauxiliar,descuentosAnteriores);
    printf("\n\nPresione enter para ejecutar el Punto 1 (Funci%cn que reciba el array de sucursales y cargue en el campo \"Total_de_descuentos_del_mes\", el total del array \"Descuentos_del_mes\".)\n",162);
    getchar();
    carga_total_descuentos(a);
    muestra(a,b,vauxiliar,descuentosAnteriores);
    printf("n\nPresione enter para ejecutar el Punto 2 (Funci%cn que reciba el array de sucursales, la matriz de descuentos y cargue en el campo \"Promedio_ Descuentos\" el promedio de los descuentos en los meses procesados.\n",162);
    getchar();
    promedio_descuentos_pasados(a,descuentosAnteriores);
    muestra(a,b,vauxiliar,descuentosAnteriores);
    printf("\n\nPresione enter para ejecutar el Punto 3 (Funci%cn que reciba el array de sucursales, el array de enteros y cargue en este array, las posiciones de los registros del array de sucursales cuyo ‘Total_de_descuentos_del mes supere al  ‘Promedio_ Descuentos’. Los datos deben almacenarse en forma contigua. Esta función debe retornar la cantidad de sucursales detectada.\n",162);
    getchar();
    int cantidad=cargaTotalDescuentosMayores(a,vauxiliar);
    printf("Las sucursales cuyo total de descuentos del mes superan al promedio de descuentos de meses anteriores son %d \n",cantidad);

    printf("\n\nPresione enter para ejecutar el Punto 4");
    getchar();
    ciudadYnombreGerenteSucursalesDescuentosMayores(a,b,vauxiliar,cantidad);
    printf("\n\nPresione enter para ejecutar el Punto 5");
    getchar();
    ordenaArraySucursalesPorCiudad(a);
    muestra(a,b,vauxiliar,descuentosAnteriores);
    return 0;
}
/*------------------------------------------------------------------Funcion para cargar el total de descuentos del mes (Punto 1)---------------------------------------------------------------------*/

void carga_total_descuentos(struct sucursales a[]){
    int i,j;

    for (i=0;i<FIL;i++){
        float totalDescuentos=0;
        for (j=0;j<30;j++){
            totalDescuentos+=a[i].descuentos_del_mes[j];
        }
        a[i].total_descuentos_del_mes=totalDescuentos;
    }
}
/*------------------------------------------------------------------Funcion para cargar el promedio de descuentos meses anteriores (Punto 2)---------------------------------------------------------------------*/

void promedio_descuentos_pasados(struct sucursales a[],float descuentosAnteriores[][COL]){
    int i,j;
    float promedio;

    for (i=0;i<FIL;i++){
        promedio=0;
        for(j=0;j<COL;j++){
            promedio=promedio+descuentosAnteriores[i][j];
        }
        promedio=promedio/COL;
        a[i].promedio_descuentos=promedio;
    }
}
/*Funcion para contar y guardar las posiciones de las sucursales en las que el promedio de descuentos de meses anteriores sea mayor a el total de descuentos del mes actual(Punto 3)*/

int cargaTotalDescuentosMayores(struct sucursales a[],int vauxiliar[]){
    int i,j=0;
    for (i=0;i<FIL;i++ ) {
        if (a[i].promedio_descuentos<a[i].total_descuentos_del_mes) {
            vauxiliar[j]=i;
            j++;
        }
    }
    return j;
}
/*Recibe array sucursales, array de gerentes y array de posiciones y la cantidad función anterior y emita el campo ‘Ciudad’ de las sucursales obtenidas y el campo ‘Nombre_de_gerente’. (Punto 4)-*/

void ciudadYnombreGerenteSucursalesDescuentosMayores(struct sucursales a[],struct gerentes b[],int vauxiliar[],int cantidad){
    int i,j=0;
    printf("Ciudad y nombre del gerente de cada una de las sucursales en las que el promedio de descuentos de meses anteriores es mayor al total de descuentos del mes actual :\n");
    for (i=0;i<cantidad;i++ ) {
        printf("\n_\n");
        printf("    Ciudad: %s\n",a[vauxiliar[i]].ciudad);
        printf("    Gerente: %s\n",b[vauxiliar[i]].nombre_gerente);

    }
}

/*Recibbe el array de sucursales y lo ordena por ciudad de forma ascendente(Punto 5)-*/

void ordenaArraySucursalesPorCiudad(struct sucursales a[]){
    int i,j,flag;
    struct sucursales aux;

    for (i=0;i<FIL-1;i++) {
        flag = 0;
        for (j = 0; j < FIL-(i+1); j++)    {
            if (strcmp(a[j].ciudad,a[j+1].ciudad)>0) {
                aux = a[j];
                a[j] = a[j+1];
                a[j+1] = aux;
                flag = 1;
            }
        }
    }
}

/*------------------------------------------------------------------Funcion para cargar aleatoriamente los descuentos del mes---------------------------------------------------------------------*/

// carga en forma aleatoria los 30 descuentos de cada sucursal
void carga_descuentos(struct sucursales a[]){
    int i,j;
    for (i=0;i<FIL ;i++ ){
        for (j=0;j<30;j++ )
        {
            a[i].descuentos_del_mes[j]=rand()%180;
        }
    }
}
/*------------------------------------------------------------------Funcion para cargar aleatoriamente los descuentos realizados con anterioridad---------------------------------------------------------------------*/

void carga_matriz(float descuentosAnteriores[][COL]){
    int i,j;
    for (i=0;i<FIL;i++){
        for(j=0;j<COL;j++){
            descuentosAnteriores[i][j]=rand()%4000;
          }
    }
}
/*------------------------------------------------------------------Funcion para mostrar---------------------------------------------------------------------*/

void muestra(struct sucursales a[],struct gerentes b[], int vauxiliar[],float descuentosAnteriores[][COL]){
    int i,j;
///emite struct Sucursales
    printf("Sucursales:\n");
    printf("-------------\n");
    for (i=0;i<FIL ;i++ )
    {
        printf("\nID sucursal: %d\n",a[i].id_sucursal);
        printf("Ciudad: %s\n",a[i].ciudad);
        printf("\nDescuentos:\n");

        for (j=0;j<30;j++ ){
            printf ("%.2f - ",a[i].descuentos_del_mes[j]);
        }
        printf("\n");
        printf("\nPromedio de descuentos realizados con anterioridad: %.2f\n",a[i].promedio_descuentos);
        printf("Total de descuentos: %.2f\n",a[i].total_descuentos_del_mes);
        printf("\n---------------------------------------------------------------------------------------------\n");
    }

///emite struct gerentes
    printf("\n\n--------------------------------------Gerentes-------------------------------------------:\n");
    for (i=0;i<FIL ;i++ )
    {
        printf("\nID sucursal: %d\n",b[i].id_sucursal);
        printf ("Nombre del gerente: %s\n",b[i].nombre_gerente);
        printf("\n______________________________\n");
    }

///emite array auxiliar de -1
    printf("Vector auxiliar:\n");
    printf("-----------------\n");
    for (i=0;i<FIL ;i++ )
    {
        printf("%d ; ",vauxiliar[i]);
    }
        printf("\n \n");

///emite la matriz de promedios
    printf("Descuentos realizados con anterioridad:\n");
    printf("\n____________________\n");
    for (i=0;i<FIL;i++){
        for(j=0;j<COL;j++){
            printf("%.2f - ",descuentosAnteriores[i][j]);
        }
        printf("\n");
    }
        printf("\n______________________________\n");
}


