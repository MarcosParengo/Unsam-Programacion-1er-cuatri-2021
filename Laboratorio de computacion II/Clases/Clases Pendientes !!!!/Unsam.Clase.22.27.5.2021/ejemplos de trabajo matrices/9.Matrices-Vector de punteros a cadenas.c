#include <stdio.h>

#define CANT 5

// vector de punteros a cadenas
void leer_vec(char * VN[]);
void impr_vec(char * VN[]);

int main() {
char cad0[10];
char cad1[20];
char cad2[10];
char cad3[30];
char cad4[20];
char * VNom[CANT]={cad0,cad1,cad2,cad3,cad4};

	leer_vec(VNom);
	impr_vec(VNom);

	getchar();
	return 0;
}

void leer_vec(char * VN[]){
int i;
		for (i=0;i<CANT;i++)
		{
			printf("ingrese nom: \n");
			scanf("%s",VN[i]);
            fflush(stdin);
		}
}

void impr_vec(char * VN[]){
    int i;
	for (i=0;i<CANT;i++)
	     printf("%s\n",VN[i]);
}


