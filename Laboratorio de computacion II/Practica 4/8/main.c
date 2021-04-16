#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int cantidadDeNotas;

    printf("ingrese la cantidad de notas por alumno deseada alumno\n");
    scanf("%i",&cantidadDeNotas);
    fflush(stdin);

    int contadorNota=0;
    int notaAlumno1[cantidadDeNotas];
    int notaAlumno2[cantidadDeNotas];
    int notaAlumno3[cantidadDeNotas];
    int acumulador=0;
    char nombreAlumno1[20];
    char nombreAlumno2[20];
    char nombreAlumno3[20];
    //Carga
    printf("Ingrese el nombre del 1%c alumno\n",248);
    gets(nombreAlumno1);
    printf("Ingrese el nombre del 2%c alumno\n",248);
    gets(nombreAlumno2);
    printf("Ingrese el nombre del 3%c alumno\n",248);
    gets(nombreAlumno3);

    for(contadorNota=0;contadorNota<cantidadDeNotas;contadorNota++){
        do{
            printf("Ingrese la %i%c nota del 1%c alumno\n",contadorNota+1,248,248);
            scanf("%i",&notaAlumno1[contadorNota]);
            fflush(stdin);
        }while(notaAlumno1[contadorNota]>10 || notaAlumno1[contadorNota]<0);
    }
    for(contadorNota=0;contadorNota<cantidadDeNotas;contadorNota++){
        do{
            printf("Ingrese la %i%c nota del 2%c alumno\n",contadorNota+1,248,248);
            scanf("%i",&notaAlumno2[contadorNota]);
            fflush(stdin);
        }while(notaAlumno2[contadorNota]>10 || notaAlumno2[contadorNota]<0);
    }
    for(contadorNota=0;contadorNota<cantidadDeNotas;contadorNota++){
        do{
            printf("Ingrese la %i%c nota del 3%c alumno\n",contadorNota+1,248,248);
            scanf("%i",&notaAlumno3[contadorNota]);
            fflush(stdin);
        }while(notaAlumno3[contadorNota]>10 || notaAlumno3[contadorNota]<0);
    }
    //Impresión
    acumulador=0;
    printf("informaci%cn de %s:\n",162,nombreAlumno1);
    for(contadorNota=0;contadorNota<cantidadDeNotas;contadorNota++){
        printf("%i%c nota:%i\n",contadorNota+1,248,notaAlumno1[contadorNota]);
        acumulador=acumulador+notaAlumno1[contadorNota];
    }
    printf("El promedio es %i\n",acumulador/cantidadDeNotas);

    acumulador=0;
    printf("informaci%cn de %s:\n",162,nombreAlumno2);
    for(contadorNota=0;contadorNota<cantidadDeNotas;contadorNota++){
        printf("%i%c nota:%i\n",contadorNota+1,248,notaAlumno2[contadorNota]);
        acumulador=acumulador+notaAlumno2[contadorNota];
    }
    printf("El promedio es %i\n",acumulador/cantidadDeNotas);

    acumulador=0;
    printf("informaci%cn de %s:\n",162,nombreAlumno3);
    for(contadorNota=0;contadorNota<cantidadDeNotas;contadorNota++){
        printf("%i%c nota:%i\n",contadorNota+1,248,notaAlumno3[contadorNota]);
        acumulador=acumulador+notaAlumno3[contadorNota];
    }
    printf("El promedio es %i\n",acumulador/cantidadDeNotas);

    return 0;
}
