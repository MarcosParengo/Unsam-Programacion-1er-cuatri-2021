#include <stdio.h>
#include <stdlib.h>

int funcion1();
void funcion2(char categoria,double importe,double *acumuladorB,double *acumuladorM,double *acumuladorG,int *ccB,int *cCM,int *cCG);
int main()
{
    int totalClientes=0;
    double totalFacturacion=0;
    double totalFacturacionB=0;
    double totalFacturacionM=0;
    double totalFacturacionG=0;
    char catMenos=NULL;
    double importeCatMenos;
    funcion1(&totalClientes,&totalFacturacion,&catMenos,&importeCatMenos,&totalFacturacionB,&totalFacturacionM,&totalFacturacionG);
    printf("....................................................................................\n");
    printf("Termin%c el ingreso de datos\n",162);
    printf("....................................................................................\n");
    printf("La facturaci%cn total fue de %d\n",162,totalFacturacion);
    printf("Se ingresaron datos de %i clientes\n",totalClientes);
    printf("La categor%ca que facturo menos fue la \"%c\", con un importe de %d\n",162,catMenos,importeCatMenos);
    return 0;
}
int funcion1(int *totalClientes,double *totalFacturacion,char *catMenos,double *importeCatMenos,double *totalFacturacionB,double *totalFacturacionM,double *totalFacturacionG){
    char categoria=NULL;
    int Ncliente=0,sucursal=1;
    int cCB=0,cCM=0,cCG=0;
    double acumuladorB=0,acumuladorM=0,acumuladorG=0,importe=0;
    for(sucursal=1;sucursal<=14;sucursal++){
        printf("Ingrese el numero de cliente de la  %i%c sucursal del que quiere registrar una compra, si desea pasar a la siguente sucursal, ingrese 0\n",sucursal,167);
        scanf("%d",&Ncliente);
        fflush(stdin);
        while(Ncliente>0){
            printf("Seleccione la clase de producto que adquiri%c el cliente n%c%i de la sucursal  n%c%i\n",162,167,Ncliente,167,sucursal);
            scanf("%c",&categoria);
            fflush(stdin);
            printf("Ingrese el importe de la compra \n");
            scanf("%i",&importe);
            fflush(stdin);
            funcion2(categoria,importe,&acumuladorB,&acumuladorM,&acumuladorG,&cCB,&cCM,&cCG);
            (*totalClientes)++;
            printf("Ingrese el numero de cliente de la  %i%c sucursal del que quiere registrar una compra, si desea pasar a la siguente sucursal, ingrese 0\n",sucursal,167);
            scanf("%d",&Ncliente);
            fflush(stdin);
        }
        printf("Sucursal n%c%i facturaci%cn:\n",167,sucursal,162);
        printf("B: %d,",acumuladorB);
        printf("%d clientes\n",cCB);
        printf("M: %d,",acumuladorM);
        printf("%d clientes\n",cCM);
        printf("G: %d,",acumuladorG);
        printf("%d clientes\n",cCG);
        *totalFacturacion = *totalFacturacion+acumuladorM+acumuladorB+acumuladorG;
        *totalFacturacionB=*totalFacturacionB+acumuladorB;
        *totalFacturacionM=*totalFacturacionM+acumuladorM;
        *totalFacturacionG=*totalFacturacionG+acumuladorG;
        if (*totalFacturacionB<=*importeCatMenos){
            *importeCatMenos=*totalFacturacionB;
            *catMenos='B';
        }
        if (*totalFacturacionM<=*importeCatMenos && cCM!=0){
            *importeCatMenos=*totalFacturacionM;
            *catMenos='M';
        }
        if (*totalFacturacionG<=*importeCatMenos && cCG!=0){
            *importeCatMenos=*totalFacturacionG;
            *catMenos='G';
        }
        cCB=0;
        cCM=0;
        cCG=0;
        acumuladorB=0;
        acumuladorM=0;
        acumuladorG=0;
    }
}
void funcion2(char categoria,double importe,double *acumuladorB,double *acumuladorM,double *acumuladorG,int *cCB,int *cCM,int *cCG){
    switch(categoria){
            case 'B':
                *acumuladorB = *acumuladorB + importe;
                (*cCB)++;
            break;
            case 'M':
                *acumuladorM = *acumuladorM + importe;
                (*cCM)++;
            break;
            case 'G':
                *acumuladorG = *acumuladorG + importe;
                (*cCG)++;
            break;
    }
}
