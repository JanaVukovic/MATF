#include <stdio.h>
#include <stdlib.h>

extern unsigned izraz(unsigned a, unsigned b);
extern void filtriraj(unsigned* A, unsigned* B, unsigned n, unsigned* C, unsigned* m);

int main(){
    unsigned n;
    scanf("%u", &n);
    unsigned *a = (unsigned*)malloc(n*sizeof(unsigned));
    unsigned *b = (unsigned*)malloc(n*sizeof(unsigned));
    unsigned *c = (unsigned*)malloc(n*sizeof(unsigned));
    int i;

    for(i = 0; i < n; i++)scanf("%u", &a[i]);
    for(i = 0; i < n; i++)scanf("%u", &b[i]);

    unsigned m;
    filtriraj(a, b, n, c, &m);
    if(m > 0)
        for(i = 0; i < 1; i++) printf("%u ", c[i]);

    free(a); free(b); free(c);
    exit(EXIT_SUCCESS);
}
