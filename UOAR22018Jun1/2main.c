#include <stdio.h>
#include <stdlib.h>
#define MAX 30

extern void transformisi_niz(unsigned niz[], unsigned n, unsigned a);
extern unsigned stepen(unsigned n, unsigned a);

int main(){
    unsigned int a;
    unsigned int n;
    scanf("%u %u", &a, &n);
    unsigned niz[MAX];
    int i;
    for(i = 0; i < n; i++)
        scanf("%u", &niz[i]);
    transformisi_niz(niz, n, a);
    for(i = 0; i < n; i++) printf("%u ", niz[i]);
    exit(EXIT_SUCCESS);
}
