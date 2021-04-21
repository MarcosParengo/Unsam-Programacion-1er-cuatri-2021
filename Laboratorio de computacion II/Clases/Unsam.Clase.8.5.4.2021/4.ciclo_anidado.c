/*números primos*/
#include <stdio.h>
#include <math.h>

int main(){

    int d, t, n, esPrimo, contadorPrimos=0;

    printf("\nIngrese un n%cmero y le indicar%c si es primo. "
              "Para salir de programa ingrese un valor negativo o 0(cero)\n", 163, 130);
    scanf("%d", &n);

    while(n > 0){

        esPrimo=1;
        d=2;



        t = (int)sqrt(n);

        while((esPrimo == 1) && (d <= t)){
            if(n%d == 0){
                esPrimo = 0;
            }else{
                d++;
            }
        }

        if(esPrimo == 1){
            printf("\nEl n%cmero %d es primo\n", 163, n);
            contadorPrimos++;
        }else {
            printf("\nNo es primo\n");
        }
      printf("\nIngrese un n%cmero y le indicar%c si es primo. "
               "Para salir de programa ingrese un valor negativo o 0(cero)\n", 163, 130);
      scanf("%d", &n);

    }

    printf("\nEl total de n%cmeros primos ingresados es: %d\n", 163, contadorPrimos);
    printf("\n");

getchar();
return 0;
}
