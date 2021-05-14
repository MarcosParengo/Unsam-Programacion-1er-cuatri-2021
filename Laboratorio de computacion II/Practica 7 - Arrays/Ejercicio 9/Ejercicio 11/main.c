// Se ingresan los N y M elementos de los arreglos unidimensionales A y B, respectivamente. La computadora emite la
//unión de ambos, su diferencia y su intersección.
#include <stdio.h>
#include <stdlib.h>
void ingreso(int *vector,int longitud,char nvector[20]);
void imprime(int *vector,int m);
void unir(int *v1,int *v2,int *v3,int longitud);
void intersecar(int *v1,int *v2,int *v3,int longitud);
int main()
{
    int longitud;
    printf("Que longitud desea que tengan sus vectores?\n");
    scanf("%d",&longitud);
    fflush(stdin);
    int v1[longitud],v2[longitud],v3[longitud*2],interseccion[longitud];
    ingreso(v1,longitud,"primer");
    ingreso(v2,longitud,"segundo");
    unir(v1,v2,v3,longitud);
    intersecar(v1,v2,interseccion,longitud);
    printf("Union:\n");
    imprimir(v3,longitud*2);
    printf("Interseccion:\n");
    imprimir(interseccion,longitud);
}
void ingreso(int *vector,int longitud,char nvector[20]){
    for(int i=0;i<longitud;i++){
        printf("Ingrese el %d%c numero del %s array\n",i+1,167,nvector);
        scanf("%d",vector+i);
        fflush(stdin);
    }
}
void imprimir(int *vector,int m){
     printf("[\t");
    for(int i=0;i<m;i++){
        printf("%d\t",*(vector+i));
    }
    printf("]\n");
}
void unir(int *v1,int *v2,int *v3,int longitud){
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
void intersecar(int *v1,int *v2,int *v3,int longitud){
    int j=0;
    int posicionV1=0;
    while(posicionV1<longitud){
        *(v3+j)=0;
        for(int k=0;k<longitud;k++){
            if(*(v2+k)==*(v1+j)){
                *(v3+j)=*(v1+j);
                j++;
            }
            posicionV1++;
        }
    }
}
