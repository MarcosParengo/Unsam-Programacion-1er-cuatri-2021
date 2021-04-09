#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a = 5;
    float b = 13.546;
    unsigned char c = 'A';
    unsigned char d = 'a';
    int e = 5>1;

    printf("valores reales:\na=%d,b=%.3f c=%c d=%c \n", a,b,c,d);

    printf("1. a vale %d \n", a);//Imprime el valor de "a" en el sistema decimal (El original)
    printf("2. a vale %o\n",a);//Imprime el valor de "a" en el sistema octal
    printf("3. a vale %x\n",a);//Imprime el valor de "a" en el sistema hexadecimal
    printf("4. a vale %f\n", a);//Imprime el valor de "a" en float (No corresponde ya que es un int)
    printf("5. a vale %c\n", a);//Imprime el caracter que representa "a"
    printf("1. b vale %d\n",b);//Imprime el valor de "b" en el sistema decimal (No corresponde, sirve para int)
    printf("2. b vale %5.2d\n",b);//Imprime el valor de "b" en el sistema decimal con coma(No corresponde, sirve para int)
    printf("3. b vale %f\n", b);//Imprime el valor de "b" con 6 decimales (&f default)
    printf("4. b vale %.1f\n",b);//Imprime el valor de "b" con 1 decimal (lo especifica al poner &.1f)
    printf("5. b vale %.2f\n",b);//Imprime el valor de "b" con 2 decimales (lo especifica al poner &.2f)
    printf("6. b vale %6.4f\n",b); //Imprime el float con hasta 6 digitos antes del decimal y 4 digitos decimales.
    printf("7. b vale %6.1f\n",b);//Imprime el float con hasta 6 digitos antes del decimal y 1 digito decimal.
    printf("8. b vale %c\n", b);//Imprime el caracter que representa "b" (no corresponde, es para valores de 0-255(unsigned char))
    printf("9. b vale %o\n",b);//Imprime el valor de "b" en el sistema octal (No corresponde, sirve para int)
    printf("10. b vale %x\n",b); //Imprime el valor de "b" en el sistema hexadecimal (No corresponde, sirve para int)
    printf("1. c vale %d\n", c); //Imprime el valor decimal del caracter guardado en "c" (ascii de A=65)
    printf("2. c vale %f\n",c);//Imprime el valor real del caracter guardado en "c" (no corresponde)
    printf("3. c vale %c\n",c);//Imprime el caracter que representa "c"
    printf("4. c vale %o\n", c);//Imprime el valor octal del caracter guardado en "c" (ascii de A=65 65d=101o)
    printf("5. c vale %x\n", c);//Imprime el valor hexadecimal del caracter guardado en "c" (ascii de A=65 65d=41h)
    printf("1. d vale %d\n", d);//Imprime el valor decimal del caracter guardado en "d" (ascii de a=97)
    printf("2. d vale %f\n", d);//Imprime el valor real del caracter guardado en "d" (no corresponde)
    printf("3. d vale %c\n", d);//Imprime el caracter que representa "d"
    printf("4. d vale %o\n",d);//Imprime el valor octal del caracter guardado en "d" (ascii de a=97 97d=141o)
    printf("5. d vale %x\n", d);//Imprime el valor hexadecimal del caracter guardado en "d" (ascii de a=97 97d=61h)
    printf("1. e vale %d\n",e); //Imprime el valor decimal de la condicion caracter guardada en "e" (5>1 = true = 1)
    printf("2. e vale %f\n",e);//Imprime el valor real del caracter guardado en "c" (no corresponde)
    printf("3. e vale %c\n", e);//Imprime el caracter que representa "e" (1 ascii = ☺)
    printf("4. e vale %o\n",e);//Imprime el valor octal de la condicion caracter guardada en "e" (5>1 = true = 1d = 1o)
    printf("5. e vale %x\n", e);//Imprime el valor hexadecimal de la condicion caracter guardada en "e" (5>1 = true = 1d = 1h)
}
