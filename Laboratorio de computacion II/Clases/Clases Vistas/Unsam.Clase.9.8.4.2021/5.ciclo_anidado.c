#include <stdio.h>

int main(){
int ancho, alto, c, r;
    /*Leer dimensiones*/
    printf("Ingrese ancho del rect%cngulo: ", 160);
    scanf("%d",&ancho);
    printf("Ingrese alto del rect%cngulo: ", 160);
    scanf("%d",&alto);
    /*Inicia ciclo externo*/
    r = 0;
    /*Repetir alto veces*/
    while(r<alto){
    /*Inicia ciclo interno*/
        c = 0;
                /*Repetir ancho veces*/
                while(c <ancho){
                printf("*");
                c++;
                /*Fin del ciclo interno*/
                }
    /*Cambiar de línea e incrementa el contador de
    renglones*/
        printf("\n");
        r++;
        }
    /*Fin del ciclo exterior*/

printf("\n");
getchar();
return 0;
}
