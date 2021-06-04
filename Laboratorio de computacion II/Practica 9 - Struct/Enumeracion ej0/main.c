#include <stdio.h>
#include <stdlib.h>

enum color{
    blanco, amarillo, rojo, verde, azul, marron, negro
};
int main(){
enum color color_coche;
printf("Ingrese el color del coche, valores enteros de 0 a 6\n");
scanf("%d", &color_coche);
fflush(stdin);
while((color_coche>=0)&& (color_coche>=0)){
        switch(color_coche){
            case blanco: printf("El coche es de color blanco\n"); break;
            case amarillo: printf("El coche es de color amarillo\n"); break;
            case rojo: printf("El coche es de color rojo\n"); break;
            case verde: printf("El cochees de color verde\n"); break;
            case azul: printf("El coche es de color azul\n"); break;
            case marron: printf("El coche es de color marron\n"); break;
            case negro:printf("El coche es de color negro\n"); break;
        }
    printf("ingrese el color del coche\n");
    scanf("%d", &color_coche);
    }
    getchar();
    return 0;
}
