#include<stdio.h>

int Proceso1(float * prom, int * anio, char * grado);
void Proceso2(char grado,float nota,float * aA,float * aB,int * cA,int * cB);

int main(){
    int tlp = 0, anio;
    float promedio;
    char grado;

    /*invoco la función Proceso1 que retornará la cantidad de legajos procesados*/
    tlp=Proceso1(&promedio,&anio,&grado); /*necesito pasar estas variables por dirección para se muestren en main*/

    printf("Cantidad de legajos procesados %d\n", tlp);
    printf("El mayor promedio de todos es %.2f, del grado %c a%co %d", promedio, grado,164,anio);
    getchar();
    return 0;
}

int Proceso1(float * prom, int * anio, char * grad){
    int i,leg,contA, contB, tlp=0;
    char grado;
    float nota, acumA,acumB, promA, promB, mayProm=0;

    for(i = 1; i <= 2; i++){
      /* Inicializo contadores y acumuladores porque deben estar en 0 cada vez que cambia
      el año procesado */
      acumA = 0;
      acumB=0;
      contA = 0;
      contB = 0;
      printf("Ingrese un n%cmero de legajo: \n",163);
      scanf("%d",&leg); /* variable de control del while, recordar que no sé cuántos legajos se procesarán*/
            fflush(stdin); /*como tengo variables char debo vaciar el buffer del teclado */
            while (leg > 0){
                printf("Ingrese la gradoisi%cn, A %c B: \n",162, 162);
                scanf("%c", &grado);
                fflush(stdin);
                printf("Ingrese la nota: ");
                scanf("%f", &nota);
                fflush(stdin);
                Proceso2(grado, nota, &acumA, &acumB, &contA,&contB);
                printf("Ingrese un n%cmero de legajo, para terminar pulse 0:\n ",163);
                scanf("%d",&leg);
                fflush(stdin);
            }
        tlp=tlp+contA+contB;
        /* para este ejemplo suponemos que siempre hay alumnos con notas en todas
        las gradoisiones */
        if (contA > 0) {promA=(float)acumA / contA;
          printf ("A%co:%d -> promedio A:%.2f\n",164,i, promA);
        }
        if (contB > 0) {promB=(float)acumB / contB;
        printf ("A%co:%d -> promedio B:%.2f\n",164,i, promB);
        }

        if(promA > *prom) {
            *prom = promA;
            *anio = i;
            *grad = 'A';
        }
        if(promB > *prom) {
            *prom = promB;
            *anio = i;
            *grad = 'B';
        }

    }
return tlp;
}

void Proceso2(char grado,float nota,float * aA,float * aB,int * cA,int * cB){
    switch(grado){
        case 'a':
        case 'A': *aA = *aA + nota;
                  (*cA)++;/*importante colocar los paréntesis*/
                  break;
        case 'b':
        case 'B': *aB = *aB + nota;
                  (*cB)++;
                  break;
       }
}
