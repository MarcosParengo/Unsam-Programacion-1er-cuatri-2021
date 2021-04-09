#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <ctype.h>
/* Notas musicales Notas altas
Do alto: Beep(1045,500)
Re alto: Beep(1160,500)            Re: Beep(580,400)
Mi alto: Beep(1300,500);            Mi: Beep(650,400)
Fa alto: Beep(1370,400)
Sol alto: Beep(1560,600)            Sol: Beep(780,500)
                                    La: Beep(870,500);
                                    Si: Beep(995,700)
*/
int main()
{
    int i = 0;
    char nota;

    printf("Ingresa notas musicales!\n");
    printf("\r\t1(RE)\tg(DO ALTO) \n\r\t2(MI) \th(RE ALTO)\n\r\t");
    printf("3(SOL) \tj(MI ALTO) \n\r\t4(LA) \tk(FA ALTO)\n\r\t");
    printf("5(SI) \tl(SOL ALTO)\n");

    do{
    fflush(stdin);
    scanf("%c",&nota);
    nota=tolower(nota);
    fflush(stdin);
    switch(nota){
        case '1':
            Beep(580,400);
            break;
        case '2':
            Beep(650,400);
            break;
        case '3':
            Beep(780,500);
            break;
        case '4':
            Beep(870,500);
            break;
        case '5':
            Beep(995,700);
            break;
        case 'g':
            Beep(1045,500);
            break;
        case 'h':
            Beep(1160,500);
            break;
        case 'j':
            Beep(1300,500);
            break;
        case 'k':
            Beep(1370,400);
            break;
        case 'l':
            Beep(1560,600);
            break;
        case 'z':
            i++;
            break;
        default:
            printf("Nota no disponible.\n");
            break;
    }
}while(nota != 0);
    return 0;
}
