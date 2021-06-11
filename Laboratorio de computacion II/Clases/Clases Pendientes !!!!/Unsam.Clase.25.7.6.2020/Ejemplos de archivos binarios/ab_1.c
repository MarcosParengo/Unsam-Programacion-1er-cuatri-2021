#include <stdio.h>

int main(){
int num;
FILE *pArchivo;
pArchivo=fopen("numeros.dat","wb");
if(pArchivo!=NULL){
do{
    printf("Ingrese un numero, para terminar 0 (cero): ");
    scanf("%d",&num);
    fwrite(&num,sizeof(int),1,pArchivo);
    }while (num > 0);
    fclose(pArchivo);
    }
else{printf("Error en la apertura del archivo");}
getchar();
return 0;
}
