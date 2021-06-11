#include <stdio.h>

int main(){
int num, nReg;
FILE *pArchivo;
pArchivo=fopen("numeros.dat","r+b");
if(pArchivo!=NULL){
      fseek(pArchivo,0,SEEK_END);
      nReg=ftell(pArchivo)/sizeof(int);
      printf("No de registros en el archivo = %d\n",nReg);
      fseek(pArchivo,0,SEEK_SET);
      fseek(pArchivo,3*sizeof(int),SEEK_SET);
      fread(&num,sizeof(int),1,pArchivo);
			printf("4to valor: %d\n",num);
fclose(pArchivo);
}
else{printf("Error en la apertura del archivo");}
getchar();
return 0;
}
