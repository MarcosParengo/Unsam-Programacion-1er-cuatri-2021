/*
se desea un programa que permite al usuario un menu de opciones.
El usuario debe ingresar la opcion solicitada.
Luego de emitido por pantalla el resultado;se vuelve a presentar el menu.
Para salir debe ingresar un 5, que es la salida.
Opciones:
1-Ingresar un número para determinar si es o no primo;
2-Ingresar un número para determinar si es o no un numero perfecto;
3-Ingresar un número para determinar si es o no un numero narcisista;
4-emitir un número para mostrar su numero fósil
5-salir
nota:
-un número es perfecto si es suma de los divisores menores que el;
-un número es narcisista si tiene n cifras y es igual a la suma de
cada cifra elevada a la n;
-el fósil de un número se obtiene multiplicando sus cifras de cada
resultado, hasta que quede un número de una sola cifra
*/
#include <stdio.h>
#include <stdlib.h>

int esPrimo(int x){
int div=2;
    while(div<=x-1){
        if(x%div==0){
            return(0);
        } else {
            div++;
        }
    }
    return(1);
}

int perfecto (int n){
    int suma=0;
    for(int i=1;i<n;i++)
            if(n%i==0){suma+=i;}
    if (n==suma)return 1;
    else return 0;
}

int potencia (int x, int y){
int x1,i;
x1=x;
if (y>=2){
    for(i=2;i<=y;i++)
    x = x1 * x;
    return x;
   }
else return x;
}

int separa (int NUM, int pos){
int aux, pot;
if (pos==1){
pot=potencia(10,pos);
aux = NUM%pot;
return aux;}
else{
pot=potencia(10,pos);
aux = NUM%pot;
pot=potencia(10,pos-1);
aux=aux/pot;
return aux;}
}

int calcularcanti(int y){
int c=0;
while (y>=1){
    y = (y/10);
    c++;
}
return c;
}

int narcisista(int x){
    int canticifras, i, unacifra,acum=0;
    canticifras = calcularcanti(x);//ok
    for(i=1;i<=canticifras;i++) {
    unacifra = separa(x,i);
    acum = acum + potencia(unacifra,canticifras);
    }
    if (x==acum) return 1;
    else return 0;
}

int fosil(int x){
int canticifras,i,acprod;
canticifras=calcularcanti(x);
while (canticifras>1){
          acprod=1;
          for(i=1;i<=canticifras;i++) {
            acprod = acprod*separa(x,i);
            }
    x=acprod;
    canticifras=calcularcanti(x);
    }
return x;
}

void LeerVal(int*p){
    scanf("%d", p);
    while((*p<4)||(*p%2!=0)) {
    printf("El n%cmero ingresado no cumple las condiciones.\nIngr%cselo nuevamente:\n",163,130);
    scanf("%d", p);
    }
}

void sumaPrimos(){
int N,listo = 0, x1=3, x2;
printf("Ingrese un n%cmero par positivo mayor a 4:\n",163);
LeerVal(&N);
    while (listo==0) {
    if (esPrimo(x1)==1){
                x2=N-x1;
            if(esPrimo(x2)==1) listo=1;
            else x1=x1+1;
    } else x1=x1+1;
    }
printf("%d = %d + %d\n",N,x1,x2);
}

void capicua(int num){
int num_inv, num_aux;
num_aux=num;
num_inv=num_aux%10;
while(num_aux>9) {
                num_aux=num_aux/10;
                num_inv=num_inv*10+num_aux%10;
}
if (num==num_inv) printf("Es capic%ca\n",163);
else printf("No es capic%ca\n",163);
}

int main(){
int opcion,num;
    printf("1-Ingresar un n%cmero para determinar si es o no primo:\n",163);
    printf("2-Ingresar un n%cmero para determinar si es o no un n%cmero perfecto:\n",163,163);
    printf("3-Ingresar un n%cmero para determinar si es o no un n%cmero narcisista:\n",163,163);
    printf("4-Emitir un n%cmero para mostrar su n%cmero f%csil: \n",163,163,162);
    printf("5-Determinar si un n%cmero par es suma de 2 n%cmeros primos:\n",163,163);
    printf("6-Determinar si un n%cmero es capic%ca:\n",163,163);
    printf("7-salir\n\n");
do{
    printf("Ingrese la opci%cn deseada:\n",162);
    scanf ("%d",&opcion);
        while ((opcion<=0) && (opcion>7)) {
        printf("Ingrese una opci%cn v%clida\n",163,160);
        scanf ("%d",&opcion);
        }
    if (opcion!=5){
    printf("Ingrese el n%cmero a analizar:\n",163);
    scanf("%d",&num);
        while (num<=0){
        printf("Ingrese un n%cmero positivo por favor\n",163);
        scanf ("%d",&num);
        }
    }

        switch (opcion){
        case 1: if((num>0)&&(num!=1)){
                esPrimo(num);
                if(esPrimo(num)==1){
                    printf("El n%cmero ingresado es primo\n",163);
                } else {
                    printf("El n%cmero ingresado no es primo\n",163);
                }
                } else if(num==1){
                printf("No se puede analizar la primalidad del n%c 1");
                } else
                printf("Se ha ingresado un n%cmero inv%clido. No se puede realizar el an%clisis.",163,160,160);
                break;
        case 2: if (perfecto(num)==1) printf("El n%cmero es perfecto\n",163);
                else printf("El n%cmero no es perfecto\n",163);
                break;
        case 3: if (narcisista(num)==1) printf("El n%cmero es narcisista\n",163);
                else printf("El n%cmero no es narcisista\n",163);
                break;
        case 4: printf("Su n%cmero f%csil es: %d\n",163,162,fosil(num));
                break;
        case 5: sumaPrimos();
                break;
        case 6: capicua(num);
                break;
        default: exit(1);
        }

    }while (opcion<6);

getchar();
return 0;
}
