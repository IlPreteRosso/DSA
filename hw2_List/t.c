#include<stdio.h>

int main(){
    int a = 1, *b = &a, **c = &b;
    printf("%d %d %d", a, *b, **c);
    return(0);
}