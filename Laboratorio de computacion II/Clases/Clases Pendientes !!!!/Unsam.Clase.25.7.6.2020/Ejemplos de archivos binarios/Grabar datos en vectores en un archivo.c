#include <stdio.h>
typedef struct cliente
{
char nombre[20];
float deuda;
int ID;
} cliente;

int main()
{
 cliente VEC[3];
  float suma;
 int i,j;
 FILE *fo;
 printf("Ingrese los datos \n");
   for (i=0; i<3; i++)
	{
    printf("\n Ingrese nombre:");
    scanf("%s", VEC[i].nombre);
    printf("\n Ingrese deuda:");
    scanf("%f", &VEC[i].deuda);
    printf("\n Ingrese ID:");
    scanf("%i", &VEC[i].ID);
         }
fo=fopen("clientes.dat","w");
fwrite(VEC,sizeof(cliente),3,fo);
fclose(fo);

getchar();
return 0;

}
