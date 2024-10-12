#include <stdio.h>
#include <stdlib.h>

extern void saberi(unsigned *a, unsigned *b, unsigned* c, unsigned n);
extern void saberi_neparne(unsigned *a, unsigned *b, unsigned* c, unsigned n);

int main(){
    unsigned n;
    scanf("%u", &n);
    unsigned *a = (unsigned*)malloc(n*sizeof(unsigned));
    unsigned *b = (unsigned*)malloc(n*sizeof(unsigned));
    unsigned *c = (unsigned*)malloc(n*sizeof(unsigned));
    int i;
    for(i = 0; i < n; i++) scanf("%u", &a[i]);
    for(i = 0; i < n; i++) scanf("%u", &b[i]);
    saberi_neparne(a, b, c, n);
    for(i = 0; i < n; i++) printf("%u ", c[i]);
    free(a); free(b); free(c);
    return 0;
}
