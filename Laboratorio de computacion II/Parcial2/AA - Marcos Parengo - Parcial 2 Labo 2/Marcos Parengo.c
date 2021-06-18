#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include <time.h>


#define FIL 4
#define COL 6
//Una fabrica de zapatillas tiene N distribuidoras, todas ubicadas en distintas ciudades y
//necesita determinado datos respecto de sus ventas. Para ello, se define un vector de N
//struct con los siguientes datos:
struct distribuidora{
  int id_distribuidora;
  char ciudad[30];
  float ventas_del_mes[30];
  float total_ventas_del_mes;
  float importe_menor_venta;
};
//Datos 1. Adem�s se define un array con N datos de gerentes responsables:
struct gerentes{
    int id_gerentes;
    int id_distribuidora;
    char apellido[30];
};
//Prototipo funciones
void muestra(struct distribuidora a[],struct gerentes b[], int vauxiliar[],float ventasAnteriores[][COL]);
void carga_total_ventas(struct distribuidora a[]);
void carga_matriz(float ventasAnteriores[][COL]);
void carga_total_ventas(struct distribuidora a[]);
void menor_venta_pasada(struct distribuidora a[],float ventasAnteriores[][COL]);
int punto3(struct distribuidora a[],int vauxiliar[]);
void punto4(struct distribuidora a[],struct gerentes b[],int vauxiliar[],int cantidad);
void ordenaArrayDistribuidorasPorCiudad(struct distribuidora a[]);

int main()
{
    //lleno el vector de structs "distribuidora"
    struct distribuidora a[FIL]={{1,"Bernal",0,0,0},{2,"Quilmes",0,0,0},{3,"San Martin",0,0,0},{4,"Ezeiza",0,0,0}};
    //lleno el vector de structs "gerentes"
    struct gerentes b[FIL]={{23,1,"Gomez"},{12,2,"Martinez"},{1,3,"Tulio"},{44,4,"Hassid"}};

    //Datos 2. "se define un tercer array de enteros de dimension N que se inicializara con -1" Punto 3:
    int vauxiliar[FIL]={-1,-1,-1,-1};

    //Datos 3. Por otra parte, se almacenan en una array bidimensional de N filas por M columnas,
    //las ventas realizadas durante 6 meses anteriores a los cargados en el array de
    //sucursales:
    float ventasAnteriores[FIL][COL];

    srand(time(NULL));
    carga_ventas(a);
    carga_matriz(ventasAnteriores);
    muestra(a,b,vauxiliar,ventasAnteriores);

    //Requerimento 1
    printf("\n\n\n------------------------------------------------------Requerimento 1--------------------------------------\n\n\n");
    printf("\n\nPresione enter para ejecutar el Punto 1 (Funci%cn que reciba el vector de sucursales y cargue en el campo \"Total_de_ventas_del_mes\", el total del array \"ventas_del_mes\".)\n",162);
    getchar();
    printf("\n\n\n------------------------------------------------------Requerimento 1--------------------------------------\n\n\n");
    carga_total_ventas(a);
    muestra_ditribuidora(a);
    printf("Importante para esta funci%cn:\n\n",162);
    for(int i=0;i<FIL;i++){
            printf("Total de ventas del mes de la %d%c sucursal :%f\n",i+1,167,a[i].total_ventas_del_mes);
    }

    //Requerimento 2
    printf("\n\n\n------------------------------------------------------Requerimento 2-----------------------------------\n\n\n");
    printf("\nPresione enter para ejecutar el Punto 2 (Funci%cn que reciba el vector de sucursales, la matriz de ventas y cargue en el campo \"Importe_Menor_venta\" la menor de las ventas obtenida de la matriz.",162);
    getchar();
    printf("\n\n\n------------------------------------------------------Requerimento 2-----------------------------------\n\n\n");
    menor_venta_pasada(a,ventasAnteriores);
    muestra_ditribuidora(a);
    printf("Importante para esta funci%cn:\n\n",162);
    for(int i=0;i<FIL;i++){
            printf("Menor venta de meses pasados de la %d%c sucursal:%f\n",i+1,167,a[i].total_ventas_del_mes);
    }

    //Requerimento 3
    printf("\n\n\n------------------------------------------------------Requerimento 3------------------------------------\n\n\n");
    printf("\n\nPresione enter para ejecutar el Punto 3 (Funci%cn que reciba el array de sucursales, el vector de enteros y cargue",162);
    printf("en este vector, las posiciones de los registros del vector de sucursales cuyo");
    printf("\"Total_de_ventas_del_mes\" supere el \"Importe_Menor_venta\". Los datos de las");
    printf("posiciones deben almacenarse en forma contigua. Esta funci%cn debe retornar la",162);
    printf("cantidad de sucursales detectadas que cumplan con esa directiva.\n");
    getchar();
    printf("\n\n\n------------------------------------------------------Requerimento 3------------------------------------\n\n\n");
    int cantidad=punto3(a,vauxiliar);
    printf("Las sucursales cuyo total de ventas del mes superan a la menor venta de meses anteriores son %d \n",cantidad);
    printf("El Vector auxiliar quedo asi:\n\n");
    for (int i=0;i<FIL ;i++ ){
        printf("%d ; ",vauxiliar[i]);
    }
    printf("\n \n");


    //Requerimento 4
    printf("\n\n\n------------------------------------------------------Requerimento 4--------------------------------------\n\n\n");
    printf("\n\nPresione enter para ejecutar el Punto 4 (Funcion que reciba el vector de sucursales, vector de gerentes, vector de",162);
    printf("\n\n\n------------------------------------------------------Requerimento 4--------------------------------------\n\n\n");
    printf("posiciones y la cantidad retornada en la funci%cn anterior y emita el campo",162);
    printf("\"Ciudad\" de las sucursales que hayan cumplido la directiva y el campo \"Apellido\"");
    printf("del gerente que corresponde a esa ciudad.)\n");
    getchar();
    punto4(a,b,vauxiliar,cantidad);


    //Requerimento 5
    printf("\n\n\n------------------------------------------------------Requerimento 5---------------------------------------\n\n\n");
    printf("\n\nPresione enter para ejecutar el Punto 5(Funci%cn que ordena el array de distribuidoras alfabeticamente de forma creciente por ciudad)",162);
    printf("\n\n\n------------------------------------------------------Requerimento 5---------------------------------------\n\n\n");
    getchar();
    printf("\nVector de distribuidoras antes del ordenamiento:\n\n\n");
    muestra_ditribuidora(a);
    ordenaArrayDistribuidorasPorCiudad(a);
    printf("\nVector de distribuidoras despues del ordenamiento:\n\n\n");
    muestra_ditribuidora(a);
    printf("\nFin del Programa\n");
    printf("\nHecho por Marcos Parengo - 14/06/2021 - Parcial 2 Laboratorio de computaci%cn 2\n",162);
    getchar();
    return 0;
}

/*------------------------------------------------------------------Funcion para cargar el total de ventas del mes (Punto 1)---------------------------------------------------------------------*/

void carga_total_ventas(struct distribuidora a[]){
    int i,j;

    for (i=0;i<FIL;i++){
        float totalVentas=0;
        for (j=0;j<30;j++){
            totalVentas+=a[i].ventas_del_mes[j];
        }
        a[i].total_ventas_del_mes=totalVentas;
    }
}
/*------------------------------------------------------------------Funcion para cargar el promedio de descuentos meses anteriores (Punto 2)-----------------------------------------------------*/

void menor_venta_pasada(struct distribuidora a[],float ventasAnteriores[][COL]){
    int i,j;
    float menor;

    for (i=0;i<FIL;i++){
        menor=4000;
        for(j=0;j<COL;j++){
            if(menor>ventasAnteriores[i][j]){
                menor=ventasAnteriores[i][j];
            }
        }
        a[i].importe_menor_venta=menor;
    }
}
/*Funcion para contar y guardar las posiciones de las distribuidoras en las que el total de ventas del mes supere el importe de menor venta (Punto 3)*/

int punto3(struct distribuidora a[],int vauxiliar[]){
    int i,j=0;
    for (i=0;i<FIL;i++ ) {
        if (a[i].total_ventas_del_mes>a[i].importe_menor_venta) {
            vauxiliar[j]=i;
            j++;
        }
    }
    return j;
}
/*Imprime la ciudad y el apellido de las distribuidoras que cumplieron con la premisa del punto anterior (Punto 4)-*/

void punto4(struct distribuidora a[],struct gerentes b[],int vauxiliar[],int cantidad){
    int i,j=0;
    printf("Ciudad y nombre del gerente de cada una de las distribuidoras en las que el total de ventas del mes actual supera el importe de menor venta de meses anteriores:\n");
    for (i=0;i<cantidad;i++ ) {
        printf("\n_\n");
        printf("    Ciudad: %s\n",a[vauxiliar[i]].ciudad);
        printf("    Gerente: %s\n",b[vauxiliar[i]].apellido);

    }
}

/*Recibbe el array de distribuidoras y lo ordena por ciudad de forma ascendente(Punto 5)-*/

void ordenaArrayDistribuidorasPorCiudad(struct distribuidora a[]){
    int i,j,flag;
    struct distribuidora aux;

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

/*------------------------------------------------------------------Funcion para cargar aleatoriamente las ventas del mes---------------------------------------------------------------------*/

// carga en forma aleatoria los 30 ventas de cada sucursal
void carga_ventas(struct distribuidora a[]){
    int i,j;
    for (i=0;i<FIL ;i++ ){
        for (j=0;j<30;j++ )
        {
            a[i].ventas_del_mes[j]=rand()%50;
        }
    }
}
/*------------------------------------------------------------------Funcion para cargar aleatoriamente las ventas realizados con anterioridad---------------------------------------------------------------------*/

void carga_matriz(float ventasAnteriores[][COL]){
    int i,j;
    for (i=0;i<FIL;i++){
        for(j=0;j<COL;j++){
            ventasAnteriores[i][j]=rand()%4000;
          }
    }
}
/*------------------------------------------------------------------Funcion para mostrar---------------------------------------------------------------------*/
void muestra_ditribuidora(struct distribuidora a[]){
    printf("--------------------------------------Distribuidoras--------------------------------------:\n");
    for (int i=0;i<FIL ;i++ )
    {
        printf("\nID distribuidora: %d\n",a[i].id_distribuidora);
        printf("Ciudad: %s\n",a[i].ciudad);
        printf("\nVentas del ultimo mes:\n");

        for (int j=0;j<30;j++ ){
            printf ("%.2f - ",a[i].ventas_del_mes[j]);
        }
        printf("\n");
        printf("\nImporte menor de venta: %.2f\n",a[i].importe_menor_venta);
        printf("Total de ventas del mes: %.2f\n",a[i].total_ventas_del_mes);
        printf("\n-----------------------------------Fin sucursal %d%c----------------------------------\n",i+1,167);
    }
    printf("\n\n");
}
void muestra(struct distribuidora a[],struct gerentes b[], int vauxiliar[],float ventasAnteriores[][COL]){
    int i,j;
///emite struct distribuidoras
    printf("--------------------------------------Distribuidoras--------------------------------------:\n");
    for (i=0;i<FIL ;i++ )
    {
        printf("\nID distribuidora: %d\n",a[i].id_distribuidora);
        printf("Ciudad: %s\n",a[i].ciudad);
        printf("\nVentas del ultimo mes:\n");

        for (j=0;j<30;j++ ){
            printf ("%.2f - ",a[i].ventas_del_mes[j]);
        }
        printf("\n");
        printf("\nImporte menor de venta: %.2f\n",a[i].importe_menor_venta);
        printf("Total de ventas del mes: %.2f\n",a[i].total_ventas_del_mes);
        printf("\n-----------------------------------Fin %d%c sucursal----------------------------------\n",i+1,167);
    }

///emite struct gerentes
    printf("\n\n--------------------------------------Gerentes-------------------------------------------:\n\n");
    for (i=0;i<FIL ;i++ )
    {
        printf("\nID distribuidora: %d",b[i].id_distribuidora);
        printf("\nID gerente: %d\n",b[i].id_gerentes);
        printf ("Apellido del gerente: %s\n",b[i].apellido);
        printf("\n______________________________\n");
    }

///emite array auxiliar de -1
    printf("\n\n-----------------------------------Vector auxiliar----------------------------------------:\n\n");
    for (i=0;i<FIL ;i++ )
    {
        printf("%d ; ",vauxiliar[i]);
    }
        printf("\n \n");

///emite la matriz de ventas
    printf("\n\n----------------------------ventas realizadas con anterioridad--------------------------------:\n\n");
    for (i=0;i<FIL;i++){
        for(j=0;j<COL;j++){
            printf("%.2f - ",ventasAnteriores[i][j]);
        }
        printf("\n");
    }
}


