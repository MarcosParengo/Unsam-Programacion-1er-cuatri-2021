#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct colores{
    char Techo[30];
    char Puerta[30];
    char Interior[30];
}colores;
typedef struct autoMovil{
    char Marca[30];
    char Modelo[30];
    int Ruedas;
    colores color;
    int test[3];
}autoMovil;
int main()
{
    /*autoMovil auto1={"Calio", "Toyota",4,{"rojo","rojo","rojo"}};
    autoMovil auto2={"ka", "Ford",3};
    autoMovil auto3;
    autoMovil auto4;
    strcpy(auto3.Modelo,"Cuto");
    auto3.Ruedas=4;
    strcpy(auto3.Marca,"Cuto");
    ^*/

    const int dim=2;
    autoMovil autos[dim];
    carga(autos,dim);

    impresion(autos,dim);

    /*
    for(int i=0;i<dim;i++){
        printf("Ingrese la marca del auto n%c%d\n",167,i+1);
        scanf("%s",autos[i].Marca);
        printf("Ingrese el Modelo del auto n%c%d\n",167,i+1);
        scanf("%s",autos[i].Modelo);
        printf("Ingrese la cantidad de ruedas del auto n%c%d\n",167,i+1);
        scanf("%d",&autos[i].Ruedas);
        fflush(stdin);
        printf("Ingrese el color del interior del auto n%c%d\n",167,i+1);
        scanf("%s",autos[i].color.Interior);
        printf("Ingrese el color del techo del auto n%c%d\n",167,i+1);
        scanf("%s",autos[i].color.Techo);
        printf("Ingrese el color de la puerta del auto n%c%d\n",167,i+1);
        scanf("%s",autos[i].color.Puerta);
        for(int j=0;j<3;j++){
           printf("Ingrese el resultado del test n%c%d del auto n%c%d\n",167,j+1,167,i+1);
            scanf("%d",&autos[i].test[j]);
        }
    }
    for(int i=0;i<dim;i++){
        printf("\n");
        printf("Auto %d: Marca %s Modelo %s Ruedas %d techo %s puerta %s interior %s",i+1,autos[i].Marca,autos[i].Modelo,autos[i].Ruedas,autos[i].color.Techo,autos[i].color.Puerta,autos[i].color.Interior);
        for(int j=0;j<3;j++){
           printf(",el resultado del test n%c%d del auto n%c%d fue %d",167,j+1,167,i+1,autos[i].test[j]);
        }
    }*/
    return 0;
}

void carga(autoMovil autos[],int dim){
   for(int i=0;i<dim;i++){
        printf("Ingrese la marca del auto n%c%d\n",167,i+1);
        scanf("%s",autos[i].Marca);
        printf("Ingrese el Modelo del auto n%c%d\n",167,i+1);
        scanf("%s",autos[i].Modelo);
        printf("Ingrese la cantidad de ruedas del auto n%c%d\n",167,i+1);
        scanf("%d",&autos[i].Ruedas);
        fflush(stdin);
        printf("Ingrese el color del interior del auto n%c%d\n",167,i+1);
        scanf("%s",autos[i].color.Interior);
        printf("Ingrese el color del techo del auto n%c%d\n",167,i+1);
        scanf("%s",autos[i].color.Techo);
        printf("Ingrese el color de la puerta del auto n%c%d\n",167,i+1);
        scanf("%s",autos[i].color.Puerta);
        for(int j=0;j<3;j++){
           printf("Ingrese el resultado del test n%c%d del auto n%c%d\n",167,j+1,167,i+1);
            scanf("%d",&autos[i].test[j]);
        }
    }
}
void impresion(autoMovil autos[],int dim){
   for(int i=0;i<dim;i++){
        printf("\n");
        printf("Auto %d: Marca %s Modelo %s Ruedas %d techo %s puerta %s interior %s",i+1,autos[i].Marca,autos[i].Modelo,autos[i].Ruedas,autos[i].color.Techo,autos[i].color.Puerta,autos[i].color.Interior);
        for(int j=0;j<3;j++){
           printf(",el resultado del test n%c%d del auto n%c%d fue %d",167,j+1,167,i+1,autos[i].test[j]);
        }
    }
}
