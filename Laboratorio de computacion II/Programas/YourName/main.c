#include <stdio.h>

int main(){
    char name[20];
    char surname[20];
    printf("Hello, what is your name and your surname?\n");
    scanf("%s %s", &name, &surname);
    printf("Hello %s %s\n",name,surname);
    printf("Name %s\n",name);
    printf("surName %s\n",surname);
    return 0;
}


