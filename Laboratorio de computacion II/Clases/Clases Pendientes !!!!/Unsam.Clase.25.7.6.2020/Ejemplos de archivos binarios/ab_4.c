#include <stdio.h>

int main(){
int nReg;
FILE *pArchivo;
pArchivo=fopen("numeros.dat","rb");
if(pArchivo!=NULL){
      fseek(pArchivo,0,SEEK_END);
      nReg=ftell(pArchivo)/sizeof(int);
      printf("No de registros en el archivo = %d\n",nReg);
fclose(pArchivo);
}
else{printf("Error en la apertura del archivo");}
getchar();
return 0;
}
