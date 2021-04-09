#include <stdio.h>
#include <stdlib.h>

int main()
{
    float numero;
    printf("ingrese un numero\n");
    scanf ("%f", &numero);
    printf(( numero==0 ) ? ("El numero es 0\n"):( ( numero>0) ? ("El numero es positivo\n"):("El numero es negativo\n")));
}
