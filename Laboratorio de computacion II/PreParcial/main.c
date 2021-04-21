#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int anios=7;
    float promedioMasAlto;
    char cursoPromedioMasAlto;
    int anioPromedioMasAlto;
    float promedios[14];
    int totalNota[14];
    int totalAlumno[14];
    int legajo=0;

    int nota;
    char input=1;
    int alumno=0;

    for(int anio=0;anio<anios;anio++){
        totalNota[anio]=0;//la del a
        totalNota[anio+7]=0;//la del b
        totalAlumno[anio]=0;//la del a
        totalAlumno[anio+7]=0;//la del b
        promedios[anio]=0;//la del a
        promedios[anio+7]=0;//la del b
        while(input!='0'){
            legajo++;
            alumno++;
            do{
                printf("Ingrese el grado del %i alumno de %i%c a%co (a o b, 0 para pasar al siguiente a%co)\n",alumno,anio+1,248,164,164);
                scanf("%c",&input);
                fflush(stdin);
            }while(input!='a' && input!='b' && input!='0');
            switch(input){
            case 'a':
                totalAlumno[anio]=totalAlumno[anio]+1;
                do{
                    printf("Ingrese la nota del %i alumno de %i%c a\n",totalAlumno[anio],anio+1,248);
                    scanf("%i",&nota);
                    fflush(stdin);
                }while(nota>10 || nota<0);
                totalNota[anio]=totalNota[anio]+nota;
            break;
            case 'b':
                totalAlumno[anio+7]=totalAlumno[anio+7]+1;
                do{
                    printf("Ingrese la nota del %i alumno de %i%c b\n",totalAlumno[anio+7],anio+1,248);
                    scanf("%i",&nota);
                    fflush(stdin);
                }while(nota>10 || nota<0);
                totalNota[anio+7]=totalNota[anio+7]+nota;
            break;
            }
        }
        if(totalAlumno[anio]!=0){promedios[anio]=(float)totalNota[anio]/(float)totalAlumno[anio];}
        if(totalAlumno[anio+7]!=0){promedios[anio+7]=(float)totalNota[anio+7]/(float)totalAlumno[anio+7];}
        if(promedios[anio]>promedioMasAlto){
            promedioMasAlto=promedios[anio];
            anioPromedioMasAlto=anio+1;
            cursoPromedioMasAlto='a';
        }
        if(promedios[anio+7]>promedioMasAlto){
            promedioMasAlto=promedios[anio+8];
            anioPromedioMasAlto=anio+1;
            cursoPromedioMasAlto='b';
        }
        printf("A: promedio:%f; nota total:%i;alumnos:%i\n",promedios[anio],totalNota[anio],totalAlumno[anio]);
        printf("B: promedio:%f; nota total:%i;alumnos:%i\n",promedios[anio+7],totalNota[anio+7],totalAlumno[anio+7]);
        input=NULL;
        alumno=0;
    }
    printf("\nRESULTADOS\n");
    //impresion
    for(int impresion=0;impresion<anios;impresion++){
        printf("...\n(*) Grado %i %c promedio general:\n",impresion+1,45);
        printf("A =%f\n",promedios[impresion]);
        printf("B =%f\n",promedios[impresion+7]);
    }
    printf("Se procesaron %i legajos en total\n",legajo);
    printf("El curso %i%c con un promedio de %f fue el curso con mejor desempe%co\n",anioPromedioMasAlto,cursoPromedioMasAlto,promedioMasAlto,164);
    return 0;
}
