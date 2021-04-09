#include <stdio.h>
#include <stdlib.h>

int main()
{
    int caracterVuelta=0;//De aqui se determina cuantos caracteres se imprimen en cada linea
    int A[4]={20,20,20,20};
    int B[4]={1,2,3,1};
    int contador;
    int contadorImpresion=0;
    int lineasImpresion=0;
    int tipoImpresion=0;

    int nimpresion=0;
    for(;nimpresion<4;nimpresion++){
        caracterVuelta=0;
        contadorImpresion=0;
        lineasImpresion=A[nimpresion];
        tipoImpresion=B[nimpresion];
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
                contador=0;
                caracterVuelta=lineasImpresion;
                for(int vueltas=1;vueltas<=lineasImpresion;vueltas++){
                    for(contadorImpresion;contadorImpresion<caracterVuelta;contadorImpresion++){
                        if(contadorImpresion<contador){
                            printf(" ");
                        }else{
                            printf("*");
                        }
                    }
                    printf("\n");
                    contador=contador+1;
                    contadorImpresion=0;
                }
                break;
            case 4:
                printf("D:\n");
                contador=9;
                caracterVuelta=lineasImpresion;
                for(int vueltas=1;vueltas<=lineasImpresion;vueltas++){
                    for(contadorImpresion;contadorImpresion<caracterVuelta;contadorImpresion++){
                        if(contadorImpresion<contador){
                            printf(" ");
                        }else{
                            printf("*");
                        }
                    }
                    printf("\n");
                    contador=contador-1;
                    contadorImpresion=0;
                }
                break;
        }
    }
}
