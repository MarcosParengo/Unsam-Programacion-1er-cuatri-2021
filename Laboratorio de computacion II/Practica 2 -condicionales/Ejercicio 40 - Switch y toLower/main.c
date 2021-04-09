#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
    char unaletra,enter;

    printf("Ingrese la primer letra del dia y pulse intro, por favor: ");
    scanf("%c", &unaletra);
    fflush(stdin);
    unaletra=tolower(unaletra);
    switch(unaletra){
    case 109:
        unaletra=0;
        printf("La letra fue M Ingrese la segunda letra del dia y pulse intro, por favor: ");
        scanf("%c", &unaletra);
        fflush(stdin);
        unaletra=tolower(unaletra);
        if (unaletra==105){
            printf("Miercoles");
        }else if(unaletra==97){
            printf("Martes");
        }
        break;
    case 108:
        printf("Lunes");
        break;
    case 106:
        printf("Jueves");
        break;
    case 118:
        printf("Viernes");
        break;
    case 83:
        printf("Sabado");
        break;
    case 68:
        printf("Domingo");
        break;
    default:
        printf("default");
        break;
    }
}
