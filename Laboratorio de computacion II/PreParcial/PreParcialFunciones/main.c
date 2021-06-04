#include <stdio.h>
#include <stdlib.h>

int legajo=0;
int input=NULL;

int funcion1();
void funcion2(char grado,int nota,int *cantAlumnosA,int *cantAlumnosB,int *acumuladorA,int *acumuladorB);

int main()
{
    funcion1();
    return 0;
}
int funcion1(){
    char charGrado=NULL;
    int nota=0,cantAlumnosA=0,cantAlumnosB=0,acumuladorA=0,acumuladorB=0;
    float promedioA=0,promedioB=0;
    for(int anio=1;anio<=7;anio++){
        printf("Ingrese el numero de legajo del alumno de %d%c a%co, para terminar pulse 0\n",anio,167,164);
        scanf("%d",&legajo);
        fflush(stdin);
        while(legajo>0){
            printf("Ingrese el grado del alumno de %d%c a%co al que corresponde el legajo n%c %i\n",anio,167,164,167,legajo);
            scanf("%c",&charGrado);
            fflush(stdin);
            printf("Ingrese la nota del alumno de %d%c a%co al que corresponde el legajo n%c %i\n",anio,167,164,167,legajo);
            scanf("%i",&nota);
            fflush(stdin);
            funcion2(charGrado,nota,&cantAlumnosA,&cantAlumnosB,&acumuladorA,&acumuladorB);
            printf("Ingrese el numero de legajo del alumno de %d%c a%co, para terminar pulse 0\n",anio,167,164);
            scanf("%d",&legajo);
            fflush(stdin);
        }
        if (cantAlumnosA!=0){
            promedioA=(float)acumuladorA/(float)cantAlumnosA;
            printf("Promedio %i%c A %f\n",anio,167,promedioA);
        }else{
            printf("No se ingresaron legajos de %d%c a%co %f\n",anio,167,164);
        }
        if (cantAlumnosB!=0){
            promedioB=(float)acumuladorB/(float)cantAlumnosB;
            printf("Promedio %i%c B %f\n",anio,167,promedioB);
        }else{
            printf("No se ingresaron legajos de %d%c a%co B\n",anio,167,164);
        }
        cantAlumnosA=0;
        cantAlumnosB=0;
        acumuladorA=0;
        acumuladorB=0;
    }
}
void funcion2(char grado,int nota,int *cantAlumnosA,int *cantAlumnosB,int *acumuladorA,int *acumuladorB){
    switch(grado){
            case 'a':
                *acumuladorA = *acumuladorA + nota;
                (*cantAlumnosA)++;
            break;
            case 'b':
                *acumuladorB = *acumuladorB + nota;
                (*cantAlumnosB)++;
            break;
    }
}

