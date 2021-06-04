//invertir el vector
#include <stdio.h>
#include <time.h>
#define N 10

int main(){
int tnum[N], i, aux;
srand(time(NULL));
// carga
for(i=0;i<N;i++)
tnum[i]=10+rand()%99;

// Mostrar
for (i=0;i<N;i++) printf("%d  ",tnum[i]);
printf("\n");

// Invertir: EL ciclo se hace N/2
for (i=0;i<N/2;i++) {
   aux=tnum[i];
   tnum[i]=tnum[N -i-1];
   tnum[N-i-1]=aux;
   }

// Mostrar
for (i=0;i<N;i++) printf("%d  ",tnum[i]);
printf("\n");

getchar();
return 0;
}
