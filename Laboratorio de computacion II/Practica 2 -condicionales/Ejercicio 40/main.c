#include <stdio.h>
#include <stdlib.h>

int main()
{
    char unaletra,enter;

    printf("Ingrese la primer letra del dia y pulse intro, por favor: ");
    scanf("%c", &unaletra);
    fflush(stdin);
    if (unaletra==109 || unaletra==77){
        unaletra=0;
        printf("La letra fue M Ingrese la segunda letra del dia y pulse intro, por favor: ");
        scanf("%c", &unaletra);
        fflush(stdin);
        if (unaletra==73 || unaletra==105){
            printf("Miercoles");
        }else if(unaletra==97 || unaletra==65){
            printf("Martes");
        }
    }else if(unaletra==108 || unaletra==76){
        printf("Lunes");
    }else if(unaletra==106 || unaletra==74){
        printf("Jueves");
    }else if(unaletra==118 || unaletra==86){
        printf("Viernes");
    }
    else if(unaletra==83 || unaletra==115){
        printf("Sabado");
    }
    else if(unaletra==68 || unaletra==100){
        printf("Domingo");
    }
}
