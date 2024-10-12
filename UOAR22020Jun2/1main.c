#include <stdio.h>

extern int izracunaj(unsigned n, int a, int b);

int main(){
    unsigned n;
    int a, b;
    scanf("%u %d %d", &n, &a, &b);
    printf("%d\n", izracunaj(n, a, b));
    return 0;
}
