#include <stdio.h>
#include <stdlib.h>

extern int armstrong(unsigned n);
extern int armstrongovi(unsigned* a, unsigned n);

int main(){
    unsigned n;
    scanf("%u", &n);
    unsigned* a = (unsigned*)malloc(n*sizeof(unsigned));
    int i;
    for(i = 0; i < n; i++) scanf("%u", &a[i]);
    n = armstrongovi(a, n);
    for(i = 0; i < n; i++) printf("%u ", a[i]);
    return 0;
}
