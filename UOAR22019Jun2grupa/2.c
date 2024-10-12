#include <stdio.h>
#include <stdlib.h>

extern unsigned polukvadrat(unsigned x);
extern void filtriraj(unsigned* a, unsigned* b, unsigned n, unsigned * c, unsigned *m);

int main(){
    unsigned n; unsigned m;
    scanf("%u", &n);
    unsigned *a = (unsigned*)malloc(n*sizeof(unsigned));
    unsigned *b = (unsigned*)malloc(n*sizeof(unsigned));
    unsigned *c = (unsigned*)malloc(n*sizeof(unsigned));
    for(int i = 0; i < n; i++)scanf("%u", &a[i]);
    int i;
    for(i = 0; i < n; i++)scanf("%u", &b[i]);
    filtriraj(a, b, n, c, &m);
    for(i = 0; i < m; i++)printf("%u ", c[i]);
    exit(EXIT_SUCCESS);
}
