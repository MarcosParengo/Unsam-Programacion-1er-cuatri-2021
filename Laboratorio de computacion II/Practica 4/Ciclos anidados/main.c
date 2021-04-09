#include <stdio.h>
#include <stdlib.h>

int main()
{
    int caracterVuelta=0;//De aqui se determina cuantos caracteres se imprimen en cada linea
    int lineasDeseadas=9;//determino de cuantas lineas deseo que sea la piramide
    int mitad=lineasDeseadas/2+lineasDeseadas%2;//determino la mitad, en donde deberia ser el pico de la piramide(mitad redondeada para arriba, xej "mitad de 7"=4)
    for(int vueltas=1;vueltas<=lineasDeseadas;vueltas++){
            if(vueltas<=mitad){//parte creciente
                caracterVuelta=caracterVuelta+1;
            }else{
                if(lineasDeseadas%2==0 && vueltas==mitad+1){//se mantiene en el pico en el caso de que se soliciten vueltas pares, donde el pico de la piramida debe ser doble, por lo quer lugo de la mitad tiene que mantenerse una vuelta mas sin bajar
                }else{
                    caracterVuelta=caracterVuelta-1;//parte decreciente
                }
            }
            int contadorImpresion=0;

            for(contadorImpresion;contadorImpresion<caracterVuelta;contadorImpresion++){//imprime la seguidilla de numeros determinada por caracter vueltas, por ejemplo si caracter vuelta es 4, el loop imprimira 1 2 3 4
                printf("%i ",contadorImpresion+1);
            }
            printf("\n");//corta la linea y cierra el ciclo y resetea la variable de la que depende el ciclo de impresion
            contadorImpresion=0;
    }
}
