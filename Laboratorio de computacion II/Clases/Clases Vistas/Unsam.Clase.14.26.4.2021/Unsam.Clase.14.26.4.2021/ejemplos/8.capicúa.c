#include <stdio.h>
#include <stdlib.h>

int alreves(int n, int digitos){
  int resto, cocie;
  if (n<10)     // Si tenemos un número de dígitos menor a 2, devolvemos n
    return n;
  else {
      resto = n % 10;
      cocie = n / 10;
  return resto*digitos + alreves(cocie, digitos/10);
    }
}

int main(){
  int num, rev;
  int digitos = 1;
  int tmp;
  printf("Ingrese un número: ");
  scanf("%d", &num);
  // Hacemos un número 10^(numero de cifras-1) con esto alreves determinará el
  // número de cifras que tiene el número dado.
  tmp =num;
  while (tmp>=10){
      tmp=tmp/10;
      digitos=digitos*10;
    }
  rev = alreves(num, digitos);
  // Capicúa o no ?
  if (rev==num)
    printf("\nEs capicua");
  else
    printf("\nNO es capicua");
  return 0;
}


