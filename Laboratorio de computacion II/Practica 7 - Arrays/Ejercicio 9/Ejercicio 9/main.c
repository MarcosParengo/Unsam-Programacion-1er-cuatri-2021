#include <stdio.h>
#include <stdlib.h>
void ingreso(int *vector,int longitud,char nvector[20]);
void imprime(int *vector,int m);
void concatenar(int *v1,int *v2,int *v3,int longitud);
int main()
{
    int longitud;
    printf("Que longitud desea que tengan sus vectores?\n");
    scanf("%d",&longitud);
    fflush(stdin);
    int v1[longitud],v2[longitud],v3[longitud*2];
    ingreso(v1,longitud,"primer");
    ingreso(v2,longitud,"segundo");
    concatenar(v1,v2,v3,longitud);
    imprimir(v3,longitud*2);
}
void ingreso(int *vector,int longitud,char nvector[20]){
    for(int i=0;i<longitud;i++){
        printf("Ingrese el %d%c numero del %s array\n",i+1,167,nvector);
        scanf("%d",vector+i);
        fflush(stdin);
    }
}
void concatenar(int *v1,int *v2,int *v3,int longitud){
    int vuelta=0;
    for(int j=0;j<longitud*2;j++){
        if(j<longitud){
            *(v3+j)=*(v1+vuelta);
            vuelta++;
        }if(j==longitud){
            vuelta=0;
            *(v3+j)=*(v2+vuelta);
            vuelta++;
        }if(j>longitud){
            *(v3+j)=*(v2+vuelta);
            vuelta++;
        }
    }
}
void imprimir(int *vector,int m){
    for(int i=0;i<m;i++){
        printf("%d%c numero del array: %d\n",i+1,167,*(vector+i));
    }
}
