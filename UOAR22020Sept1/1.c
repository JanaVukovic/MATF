#include <stdio.h>
#include <stdlib.h>

extern int izracunaj(int a, int b, int c);

int main(){
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    printf("%d\n", izracunaj(a, b, c));
    return 0;

}
