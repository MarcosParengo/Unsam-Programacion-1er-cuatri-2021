#include <stdio.h>
#include <stdlib.h>

int main()
{
    char caracterDeInicio,caracterDeFin;
    char caracter1 = 90;//Z
    char caracter2 =100;//A

    if (caracter1>caracter2){//funcion que hace que el caracter de inicio sea siempre mayor al caracter de fin
        caracterDeInicio=caracter1;
        caracterDeFin=caracter2;
    }else{//funcion que hace que el caracter de inicio sea siempre mayor al caracter de fin
        caracterDeInicio=caracter2;
        caracterDeFin=caracter1;
    }
    //Caracter de inicio debe ser mayor a caracter de fin
    int vueltasDeseadas=caracterDeInicio-caracterDeFin;
    int vuelta=vueltasDeseadas;

    for(;vuelta>=0;vuelta=vuelta-1){
        int vueltaImpresion=vuelta;
        for(;vueltaImpresion>=0;vueltaImpresion--){
            printf("%c",caracterDeFin+vueltaImpresion);
        }
        printf("\n");
    }
}
