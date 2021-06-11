#include <stdio.h>

struct persona{
int leg;
char ape[20];
float suel;
};

int main(){
struct persona unapersona;
FILE *pArchivo;
pArchivo=fopen("empleados.dat","rb");

if(pArchivo!=NULL){
fread(&unapersona,sizeof(struct persona),1,pArchivo);
while(!feof(pArchivo)){
	printf("%d%10s%10.2f\n", unapersona.leg,unapersona.ape,unapersona.suel);
    fread(&unapersona,sizeof(struct persona),1,pArchivo);
	}
fclose(pArchivo);
}
else{printf("Error en la apertura del archivo");}
getchar();
return 0;
}
