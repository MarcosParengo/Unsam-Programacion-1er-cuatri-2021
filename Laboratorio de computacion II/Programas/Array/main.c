#include <stdio.h>

int main(){
    printf("Hello, what is your name?\n");
    char name[20];
    scanf("%s", &name);
    printf("Hello %s\n",name);
    return 0;
}
