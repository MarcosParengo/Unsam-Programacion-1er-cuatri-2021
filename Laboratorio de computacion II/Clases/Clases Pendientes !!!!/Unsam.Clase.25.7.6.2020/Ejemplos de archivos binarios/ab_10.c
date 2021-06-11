#include <stdio.h>
#include <string.h>
struct persona{
    int leg;
    char ape[20];
    float suel;
};

int main(){
struct persona unapersona;
FILE *pArchivo;
int registro, nReg;
char apenuevo[20];
pArchivo=fopen("empleados.dat","r+b");
if(pArchivo!=NULL){
     fseek(pArchivo,0,SEEK_END);
     nReg=ftell(pArchivo)/sizeof(struct persona);
     printf("No de registros en el archivo = %d\n",nReg);
     printf("Ingrese el número de registro que quiere modificar: ");
     scanf("%d",&registro);
     fseek(pArchivo,0,SEEK_SET);
     fseek(pArchivo,(registro-1)*sizeof(struct persona),SEEK_SET);
     fread(&unapersona,sizeof(struct persona),1,pArchivo);
     printf("%d%10s%10.2f\n", unapersona.leg,unapersona.ape,unapersona.suel);
     printf("Ingrese el apellido nuevo:\n");
     scanf("%s",apenuevo);
     strcpy(unapersona.ape, apenuevo);

     fseek(pArchivo,-sizeof(struct persona),SEEK_CUR);
     fwrite(&unapersona,sizeof(struct persona),1,pArchivo);
     fclose(pArchivo);
     }
else { printf("Error en la apertura del archivo");}
getchar();
return 0;
}
