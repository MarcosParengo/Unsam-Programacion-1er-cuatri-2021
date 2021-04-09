#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

 /*Convierte el teclado de tu computadora en un pianito usando switch-case, teniendo en cuenta que para usar
la función Beep, tienes que incluir la librería windows.h. La función Beep() tiene dos parámetros, 1) la
frecuencia del sonido a reproducir, en hertzios, y 2) la duración del sonido, en milisegundos.
Entonces: Beep(unsigned int hz, unsigned int ms), declaramos las variables como unsigned ya que estos valores
no pueden ser negativos. A continuación dejamos como ejemplo frecuencia y duración de algunas notas
musicales (puedes investigar en internet), recuerda que cada nota debe ser un carácter de tu teclado, por
ejemplo la nota Re podría ser r ó R.
Notas musicales Notas altas
Do alto: Beep(1045,500)
Re: Beep(580,400) Re alto: Beep(1160,500)
Mi: Beep(650,400) Mi alto: Beep(1300,500);
Fa alto: Beep(1370,400)
Sol: Beep(780,500) Sol alto: Beep(1560,600)
La: Beep(870,500);
Si: Beep(995,700)
Nota: si te animas intenta armar con sentencias simples una melodía, por ejemplo el feliz cumpleaños u otra
de tu agrado
*/
int main()
{
    double don=532;
    double re=587;
    double mi=659;
    double fa=698;
    double sol=783;
    double la=880;
    double si=987;

    char letra;
    do{
        printf("uwu\n");
        scanf("%c",&letra);
        fflush(stdin);

        Beep(don,400);
        Beep(don,400);
        Beep(sol,400);
        Beep(sol,400);
        Beep(la,400);
        Beep(la,400);
        Beep(sol,700);
        Beep(fa,400);
        Beep(fa,400);
        Beep(mi,400);
        Beep(mi,400);
        Beep(re,400);
        Beep(re,400);
        Beep(don,400);

    }while(letra!=102);

    return 0;
}
