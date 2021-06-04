#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define p printf
#define s scanf
#define FIL 5
#define COL 5

void menu(int m[][COL]);
void cargarmat_alea(int m[][COL]);
void cargarmat_xtec(int m[][COL]);
void emitirmat(int m[][COL]);
void triang(int m[][COL]);
void inf(int m[][COL]);
void trans(int m[][COL]);

int main(){
int mat[FIL][COL];
menu(mat);
getchar();
return(0);
}

/* -------------------------------------------------------------------*/
/* menu*/
/* -------------------------------------------------------------------*/
void menu(int m[][COL]){
int op, *pm;
do{
do{
printf("1.Generar elementos aleatoriamente (positivos)\n");
printf("2.Generar elementos ingresando por teclado\n");
printf("3.Emitir elementos\n");
printf("4.Matriz transpuesta\n");
printf("5.Matriz triangular\n");
printf("6.Matriz inferior\n");
scanf("%d",&op);
printf("\n");
}while ((op>6) || (op<1));

switch(op){
case 1:cargarmat_alea(m);
       printf("\n");
    break;
case 2:cargarmat_xtec(m);
       printf("\n");
    break;
case 3:emitirmat(m);
       printf("\n");
    break;
case 4:printf("La matriz transpuesta es:\n");
       trans(m);
       emitirmat(m);
       printf("\n");
    break;
case 5:printf("La matriz triangular es:\n");
       triang(m);
       printf("\n");
    break;
case 6: printf("La matriz inferior es:\n");
        inf(m);
       printf("\n");
    break;
}
}while ((op>0) || (op<15));
}

/* -------------------------------------------------------------------*/
/* Matriz triangular*/
/* -------------------------------------------------------------------*/
void triang(int m[][COL]){
int i,j;
 for(i=0;i<FIL;i++){
		for(j=0;j<i;j++)
        p("\t");
		for(j=i;j<FIL;j++)
		p("%d\t",m[i][j]);
		p("\n");
	}
}
/* -------------------------------------------------------------------*/
/* Matriz inferior*/
/* -------------------------------------------------------------------*/
void inf(int m[][COL]){
int i, j;
 for(i=1;i<FIL;i++){
		for(j=0;j<i;j++)
		 p("%d\t",m[i][j]);
		p("\n");
	}
}

/* -------------------------------------------------------------------*/
/* Matriz transpuesta*/
/* -------------------------------------------------------------------*/
void trans(int m[][COL]){
int i,j,aux;
   for(i=0;i<FIL;i++)
		for(j=i;j<FIL;j++){
			aux=m[i][j];
			m[i][j]=m[j][i];
			m[j][i]=aux;
		}
}

/* -------------------------------------------------------------------*/
/* Matriz carga aleatoria*/
/* -------------------------------------------------------------------*/
void cargarmat_alea(int m[][COL]){
int i,j;
srand(time(NULL));
	for(i=0;i<FIL;i++)
		for(j=0;j<COL;j++)
		 m[i][j]= 1 + rand()% 10;
}

/* -------------------------------------------------------------------*/
/* Matriz carga por teclado*/
/* -------------------------------------------------------------------*/
void cargarmat_xtec(int m[][COL]){
int i,j;
	for(i=0;i<FIL;i++)
		for(j=0;j<COL;j++){
          printf("Ingrese el elemento [%d][%d] de la matriz\n",i,j);
          scanf("%d",&m[i][j]);
		}
}

/* -------------------------------------------------------------------*/
/* Matriz emisión*/
/* -------------------------------------------------------------------*/
void emitirmat(int m[][COL]){
int i, j;
for(i=0;i<FIL;i++) {
	for(j=0;j<COL;j++)
		p("%d ",m[i][j]);
	p("\n");
	}
}
