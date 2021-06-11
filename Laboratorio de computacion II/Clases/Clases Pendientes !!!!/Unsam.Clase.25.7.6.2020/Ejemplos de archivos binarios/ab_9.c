#include <stdio.h>
struct persona{
    int leg;
    char ape[20];
    float suel;
};

int main(){
struct persona unapersona;
FILE *pArchivo;
pArchivo=fopen("empleados.dat","ab");
if(pArchivo!=NULL){

    printf("Ingrese un numero, para terminar 0 (cero): ");
    scanf("%d",&unapersona.leg);
    fflush(stdin);
       while(unapersona.leg > 0){
        printf("Ingrese un apellido: ");
        scanf("%s",unapersona.ape);
        fflush(stdin);
        printf("Ingrese un sueldo: ");
        scanf("%f",&unapersona.suel);
        fflush(stdin);
        fwrite(&unapersona,sizeof(struct persona),1,pArchivo);
        printf("Ingrese un numero, para terminar 0 (cero): ");
        scanf("%d",&unapersona.leg);
        fflush(stdin);
        }
fclose(pArchivo);
}
else{printf("Error en la apertura del archivo");}
getchar();
return 0;
}
