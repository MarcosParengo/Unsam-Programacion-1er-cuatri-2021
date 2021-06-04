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
    const int dim=2;
    autoMovil autos[dim];
    carga(autos,dim);
    impresion(autos,dim);

    return 0;
}

void emite_reg(autoMovil reg,int i){
    printf("\n");
    printf("Auto %d: Marca %s Modelo %s Ruedas %d techo %s puerta %s interior %s",i+1,reg.Marca,reg.Modelo,reg.Ruedas,reg.color.Techo,reg.color.Puerta,reg.color.Interior);
    for(int j=0;j<3;j++){
       printf(",el resultado del test n%c%d del auto n%c%d fue %d",167,j+1,167,i+1,reg.test[j]);
    }
}
void impresion(autoMovil autos[],int dim){
   for(int i=0;i<dim;i++){
        emite_reg(autos[i],i);
    }
}
void modif(int * pre_o_comb){
    printf("Ingrese el nuevo valor:\n");
    scanf("%d",pre_o_comb);
    fflush(stdin);
    printf("El nuevo valor es: %d\n",*pre_o_comb);
}
autoMovil carga_reg(int i){
    autoMovil reg;
    int opcion;
    printf("Ingrese la marca del auto n%c%d\n",167,i+1);
    gets(reg.Marca);
    fflush(stdin);
    printf("Ingrese el Modelo del auto n%c%d\n",167,i+1);
    gets(reg.Modelo);
    fflush(stdin);
    printf("Ingrese la cantidad de ruedas del auto n%c%d\n",167,i+1);
    scanf("%d",&reg.Ruedas);
    fflush(stdin);
    printf("Se equivoco en la cantidad de ruedas y quiere reingresar el valor del mismo? (0 para si, cualquier otra tecla para no)\n");
    scanf("%d",&opcion);
    fflush(stdin);
    if(opcion==0){
        modif(&reg.Ruedas);
    }
    printf("Ingrese el color del interior del auto n%c%d\n",167,i+1);
    gets(reg.color.Interior);
    fflush(stdin);
    printf("Ingrese el color del techo del auto n%c%d\n",167,i+1);
    gets(reg.color.Techo);
    fflush(stdin);
    printf("Ingrese el color de la puerta del auto n%c%d\n",167,i+1);
    fflush(stdin);
    gets(reg.color.Puerta);
    fflush(stdin);
    for(int j=0;j<3;j++){
       printf("Ingrese el resultado del test n%c%d del auto n%c%d\n",167,j+1,167,i+1);
        scanf("%d",&reg.test[j]);
        fflush(stdin);
    }
    return reg;
}
void carga(autoMovil autos[],int dim){
    for(int i=0;i<dim;i++){
        autos[i]=carga_reg(i);
    }
}
