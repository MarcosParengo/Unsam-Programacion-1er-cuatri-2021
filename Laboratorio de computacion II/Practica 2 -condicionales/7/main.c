#include <stdio.h>
#include <stdlib.h>

int main()
{
    int caracterVuelta=0;//De aqui se determina cuantos caracteres se imprimen en cada linea
    int A[4]={10,10,10,10};
    int B[4]={1,2,3,4};
    //int A[2]={7,0};
    int nimpresion=0;
    for(;nimpresion<4;nimpresion++){
        int contadorImpresion=0;
        int lineasImpresion=A[nimpresion];
        int tipoImpresion=B[nimpresion];
        switch (tipoImpresion) {
            case 1:
                printf("A:\n");
                for(int vueltas=1;vueltas<=lineasImpresion;vueltas++){
                    caracterVuelta=caracterVuelta+1;
                    for(contadorImpresion;contadorImpresion<caracterVuelta;contadorImpresion++){
                    printf("*");
                    }
                    printf("\n");
                    contadorImpresion=0;
                }
                break;
            case 2:
                printf("B:\n");
                caracterVuelta=lineasImpresion+1;
                for(int vueltas=1;vueltas<=lineasImpresion;vueltas++){
                    caracterVuelta=caracterVuelta-1;
                    for(contadorImpresion;contadorImpresion<caracterVuelta;contadorImpresion++){
                    printf("*");
                    }
                    printf("\n");
                    contadorImpresion=0;
                }
                break;
            case 3:
                printf("C:\n");
                int contador=10;
                caracterVuelta=lineasImpresion+1;
                for(int vueltas=1;vueltas<=lineasImpresion;vueltas++){
                    for(contadorImpresion;contadorImpresion<caracterVuelta;contadorImpresion++){
                    if(contadorImpresion<contador-1){
                        printf(" ");
                    }else{
                        printf("");
                    }
                    }
                    printf("\n");
                    contador=contador-1;
                    contadorImpresion=0;
                }
                break;
            case 4:
                printf("caso4");
                break;
        }
    }
}
