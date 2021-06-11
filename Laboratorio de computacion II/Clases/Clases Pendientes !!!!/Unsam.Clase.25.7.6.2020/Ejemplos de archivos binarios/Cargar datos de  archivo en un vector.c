#include <stdio.h>
typedef struct cliente
{
char nombre[20];
float deuda;
int ID;
} cliente;

int main()
{
 cliente VEC[3];float suma;
 int i,j; cliente *pvec;
 FILE *fi;

fi=fopen("clientes.dat","r");
fread(VEC,sizeof(cliente),3,fi);// observar que se cargan todos los datos del vector en una sola instrucción
fclose(fi);
pvec=VEC;
// emito los datos recorriendo con un puntero auxiliar
for(i=0;i<3;i++)
   printf("Nombre: %s Deuda: %6.2f ID:%d \n", (pvec+i)->nombre,(pvec+i)->deuda,(pvec+i)->ID);

suma=0;
// sumo las deudas en un proceso
for(j=0;j<3;j++)
suma=suma+(pvec+j)->deuda;
printf("Deuda total = %6.2f \n", suma);
getchar();
return 0;

}
