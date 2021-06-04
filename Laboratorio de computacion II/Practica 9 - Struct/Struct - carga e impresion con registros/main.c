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

    return 0;
}

void impresion(autoMovil autos[],int dim){
   for(int i=0;i<dim;i++){
        emite_reg(autos[i],i);
    }
}
void emite_reg(autoMovil reg,int i){
    printf("\n");
    printf("Auto %d: Marca %s Modelo %s Ruedas %d techo %s puerta %s interior %s",i+1,reg.Marca,reg.Modelo,reg.Ruedas,reg.color.Techo,reg.color.Puerta,reg.color.Interior);
    for(int j=0;j<3;j++){
       printf(",el resultado del test n%c%d del auto n%c%d fue %d",167,j+1,167,i+1,reg.test[j]);
    }
}
void carga(autoMovil autos[],int dim){
    for(int i=0;i<dim;i++){
        carga_reg(&autos[i],i);
    }
}
void carga_reg(autoMovil* ptr_reg,int i){
    printf("Ingrese la marca del auto n%c%d\n",167,i+1);
    gets(ptr_reg->Marca);
    fflush(stdin);
    printf("Ingrese el Modelo del auto n%c%d\n",167,i+1);
    gets(ptr_reg->Modelo);
    fflush(stdin);
    printf("Ingrese la cantidad de ruedas del auto n%c%d\n",167,i+1);
    scanf("%d",&ptr_reg->Ruedas);
    fflush(stdin);
    printf("Ingrese el color del interior del auto n%c%d\n",167,i+1);
    gets(ptr_reg->color.Interior);
    fflush(stdin);
    printf("Ingrese el color del techo del auto n%c%d\n",167,i+1);
    gets(ptr_reg->color.Techo);
    fflush(stdin);
    printf("Ingrese el color de la puerta del auto n%c%d\n",167,i+1);
    fflush(stdin);
    gets(ptr_reg->color.Puerta);
    fflush(stdin);
    for(int j=0;j<3;j++){
       printf("Ingrese el resultado del test n%c%d del auto n%c%d\n",167,j+1,167,i+1);
        scanf("%d",&ptr_reg->test[j]);
        fflush(stdin);
    }
}
