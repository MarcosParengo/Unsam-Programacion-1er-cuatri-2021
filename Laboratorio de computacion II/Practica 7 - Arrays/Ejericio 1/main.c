#include <stdio.h>
#include <stdlib.h>

void a(int *vector,int m);
double b (int *vector,int m);
int c (int *vector,int m);
void e(int *vector,int m,int promedio);
void f(int *vector,int m);
void g(int *vector,int m);
void h(int *vector,int m);
void i(int *vector,int m);
void j(int *vector,int m);
int k(int *vector,int m);
void ma(int *vector,int m);
void n(int *vector,int m);
int main()
{
    char opcion;
    int m=4;
    int vecesk;
    int vector[m];
    while(opcion!=48){
        opcion=NULL;
        printf("Que funcion desea realizar?(\"a\" hasta \"n\", 0 para salir\n)");
        scanf("%c",&opcion);
        fflush(stdin);
        switch(opcion){
            case 97:
                a(vector,m);
                break;
            case 98:
                printf("La suma de todos los elementos es: %.0f\n",b(vector,m));
                break;
            case 99:
                printf("El menor de todos los elementos es: %i\n",c(vector,m));
            break;
            case 100:
                printf("El promedio de todos los elementos es: %.2f\n",(b(vector,m))/m);
            break;
            case 101:
                printf("Los valores de los elementos mayores que el promedio (%.2f) son:\n",(b(vector,m))/m);
                e(vector,m,((b(vector,m))/m));
            break;
            case 102:
                printf("los valores del vector que son multiplos del ultimo numero ingresado en el mismo (%d) son:\n",vector[m-1]);
                f(vector,m);
            break;
            case 103:
                g(vector,m);
            break;
            case 104:
                printf("los valores pares del vector son:\n");
                h(vector,m);
            break;
            case 105:
                printf("los valores que estan en posiciones pares del vector son:\n");
                i(vector,m);
            break;
            case 106:
                printf("los valores que estan en posiciones impares del vector son:\n");
                j(vector,m);
            break;
            case 107:
                vecesk=k(vector,m);
                if(vecesk!=0){
                    printf("Ha leido %d elementos hasta que encontro el numero\n",vecesk);
                }else{
                    printf("Se recorrio todo el array y no se encontro su numero, esperamos que lo encuentre\n");
                }
            break;
            case 109:
                ma(vector,m);
            break;
            case 110:
                n(vector,m);
            break;

            default:
                printf("Las opciones disponibles son de la \"a\" hasta \"n\", a continuacion se especifica que hace cada una: \n");
                printf("a. Cargar un vector de m elementos por teclado. Debes considerar que no podrá superar el máximo de elementos");
                printf("de vector (m=dimensión). \n");
                printf("b. Calcular y emitir la suma de sus elementos.\n");
                printf("c. Calcular y emitir el mínimo del vector.\n");
                printf("d. Calcular y emitir el promedio de los valores del vectorn\n");
                printf("e. Emitir los valores de aquellos que superaron ese promedio.\n");
                printf("f. Emitir los valores del vector que son múltiplos del último número ingresado en el mismo.\n");
                printf("g. Emitir el valor máximo e indicar la cantidad de veces que apareció y el número de orden en que fue ingresado.\n");
                printf("h. Emitir los valores que son pares.\n");
                printf("i. Emitir los valores que están en posiciones impares.\n");
                printf("j. Emitir aquellos que estén ubicados en posición par.\n");
                printf("k. Recorrer los elementos del vector hasta encontrar el número entero a. Deberá retornar el número de ");
                printf("elementos que ha leído hasta encontrar a.\n");
                printf("l. Dado un elemento y dado un vector de enteros, realice una función que devuelva el número de apariciones del ");
                printf("elemento en el vector. Utiliza el ciclo while para esta función.\n");
                printf("m. Invertir los elementos del vector sin utilizar otro vector. Por ejemplo, el vector formado por los enteros: 1 2 3, ");
                printf("debe quedar 3 2 1.\n");
            break;
        }
    }
}

void a(int *vector,int m){
    for(int i=0;i<m;i++){
        printf("Por favor, ingrese el %d numero del array\n",i+1);
        scanf("%i",vector+i);
        fflush(stdin);
    }
}
double b(int *vector,int m){
    double aux=0;
    for(int i=0;i<m;i++){
        aux=aux+(double)(*(vector+i));
    }
    return aux;
}
int c(int *vector,int m){
    int aux=*(vector);
    for(int i=0;i<m;i++){
        if(*(vector+i)<=aux){
            aux=*(vector+i);
        }
    }
    return aux;
}
void e(int *vector,int m,int promedio){
    for(int i=0;i<m;i++){
        if(*(vector+i)>promedio){
            printf("%d%c numero del array: %d\n",i+1,167,*(vector+i));
        }
    }
}
void f(int *vector,int m){
    for(int i=0;i<m-1;i++){
        if(*(vector+i)%*(vector+m-1)==0){
            printf("%d%c numero del array: %d\n",i+1,167,*(vector+i));
        }
    }
}
void g(int *vector,int m){
    int max=0;
    int veces=0;
    for(int i=0;i<m;i++){
        if(*(vector+i)==max){
            veces++;
        }
        if(*(vector+i)>max){
            max=*(vector+i);
            veces=1;
        }
    }
    printf("El mayor fue el  numero %d y aparecio %d vez/veces\n",max,veces);
}
void h(int *vector,int m){
    for(int i=0;i<m;i++){
        if(*(vector+i)%2==0){
            printf("%d%c numero del array: %d\n",i+1,167,*(vector+i));
        }
    }
}
void i(int *vector,int m){
    for(int i=0;i<m;i++){
        if(i%2==0){
            printf("%d%c posicion del array: %d\n",i,167,*(vector+i));
        }
    }
}
void j(int *vector,int m){
    for(int i=0;i<m;i++){
        if(i%2==1){
            printf("%d%c posicion del array: %d\n",i,167,*(vector+i));
        }
    }
}
int k(int *vector,int m){
    int buscado=NULL;
    char flag=0;
    printf("Que numero desea buscar en el array?\n");
    scanf("%d",&buscado);
    fflush(stdin);
    for(int i=0;i<m;i++){
        if((*(vector+i))!=buscado && flag==0){
            printf("el %d%c numero del array (%d) no es el buscado (%d)\n",i+1,167,*(vector+i),buscado);
        }else{
            printf("numero encontrado en la %d%c posicion del array: %d\n",i,167,*(vector+i));
            flag=1;
            return i+1;
        }
    }
    return 0;
}
void ma(int *vector,int m){
    int p=0;
    int q=m-1;
    while(p<q){
        *(vector+p)=*(vector+p)+*(vector+q);
        *(vector+q)=*(vector+p)-*(vector+q);
        *(vector+p)=*(vector+p)-*(vector+q);
        p++;
        q--;
    }
}
void n(int *vector,int m){
    for(int i=0;i<m;i++){
        printf("%d%c numero del array: %d\n",i+1,167,*(vector+i));
    }
}
