#include <stdio.h>
//Forma de usar menos memoria para alojar datos. Solo un dato persiste, el ultimo asignado. El espacio q ocupa en memoria corresponde al espacio de
//memoria que ocupa la variable con el tipo de dato mas grande
union numero{
    int x;
    double y;
};
int main(){
    union numero valor;
    valor.x=100;
    printf("Coloca un valor en el miembro flotante e imprime ambos miembros:\n int x %d, double y %f\n",valor.x,valor.y);
    valor.y=100.0;
    printf("Coloca un valor en el miembro flotante e imprime ambos miembros:\n int x %d, double y %f\n",valor.x,valor.y);
}
