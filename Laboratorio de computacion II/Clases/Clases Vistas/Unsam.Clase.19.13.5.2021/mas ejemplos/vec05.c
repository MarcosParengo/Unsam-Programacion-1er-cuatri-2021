/*3. Cargar un arrays de 10 palabras y ordenarlas alfabéticamente*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef char palabra[20];

void Cargar (palabra v[], int d){
int i;

for(i=0;i<d;i++){
    printf("Ingresar palabra %d\n",i+1);
    scanf("%s", v[i]);
}
}

void Emitir (palabra v[], int d){
int i;
printf("\n");
for(i=0;i<d;i++)
    printf("Palabra %d: %s\n",i+1, v[i]);
}

void Ordenar (palabra v[], int d){
int i, j;
palabra aux;

for(i=0;i<d-1;i++)
    for(j=i+1;j<d;j++)
if (strcmp(v[i],v[j])>0)
    {
    strcpy(aux,v[i]);
    strcpy(v[i],v[j]);
    strcpy(v[j],aux);
}
}

int main(){
const int N=10;
palabra  vpalabra[N];

Cargar(vpalabra, N);
Emitir(vpalabra, N);
Ordenar(vpalabra, N);
Emitir(vpalabra, N);
getchar();
return 0;
}

