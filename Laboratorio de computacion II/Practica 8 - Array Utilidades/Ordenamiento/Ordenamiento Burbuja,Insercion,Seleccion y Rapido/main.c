#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
int main()
{
    int vector[30]={10,20,1,1,1,3,2,5,6,84,52,12,35,48,8,11,21,3,1,9,25,29};
    int vector2[30]={10,20,3,2,5,6,84,52,12,35,48,8,11,21,3,1,9,25,29};
    int vector3[30]={10,20,3,2,5,6,84,52,12,35,48,8,11,21,3,1,9,25,29};
    int vector4[30]={10,20,3,2,5,6,84,52,12,35,48,8,11,21,3,1,9,25,29};
    int size= sizeof(vector) / sizeof(int);

    bubble_sort(vector,size);
    Insertion_sort(vector2,size);
    selection_sort(vector3,size);
    quick_sort(vector4,size);

    printf("Vector con bubble sort:\n");
    for(int i=0;i<size;i++){
        printf("%d:%d\n",i+1,vector[i]);
    }
    printf("Vector con insertion sort:\n");
    for(int i=0;i<size;i++){
        printf("%d:%d\n",i+1,vector2[i]);
    }
    printf("Vector con selection sort:\n");
    for(int i=0;i<size;i++){
        printf("%d:%d\n",i+1,vector3[i]);
    }
    printf("Vector con quick sort:\n");
    for(int i=0;i<size;i++){
        printf("%d:%d\n",i+1,vector4[i]);
    }
    return 0;
}

void bubble_sort(int* vector,int size)
{
    int iteracion = 0;
    bool permutation = true;
    int actual;

    while ( permutation) {
        permutation = false;
        iteracion ++;
        for (actual=0;actual<30-iteracion;actual++) {
            if (vector[actual]>vector[actual+1]){
                permutation = true;
                // Intercambiamos los dos elementos
                int temp = vector[actual];
                vector[actual] = vector[actual+1];
                vector[actual+1] = temp;
            }
        }
    }
}
void Insertion_sort(int* t,int size)
{
    int i, j;
    int actual;

    for (i = 1; i < size; i++) {
        actual = t[i];
        for (j = i; j > 0 && t[j - 1] > actual; j--) {
            t[j] = t[j - 1];
        }
        t[j] = actual;
    }
}
void selection_sort(int *vector, int size)
{
     int actual, mas_pequeno, j, temp;

     for (int actual = 0; actual < size - 1; actual++){
         mas_pequeno = actual;
         for (j = actual; j < size; j++)
              if (vector[j] < vector[mas_pequeno])
                  mas_pequeno = j;
          temp = vector[actual];
          vector[actual] = vector[mas_pequeno];
          vector[mas_pequeno] = temp;
     }
}
void quick_sort (int *vector, int tamano) {
    int pared, actual, pivote, tmp;
    if (tamano < 2) return;
    // el elemento de pivote es la más a la derecha
    pivote = vector[tamano - 1];
    pared  = actual = 0;
    while (actual<tamano) {
        if (vector[actual] <= pivote) {
            if (pared != actual) {
                tmp=vector[actual];
                vector[actual]=vector[pared];
                vector[pared]=tmp;
            }
            pared ++;
        }
        actual ++;
    }
    quick_sort(vector, pared - 1);
    quick_sort(vector + pared - 1, tamano - pared + 1);
}
