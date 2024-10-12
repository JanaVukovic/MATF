#include <stdio.h>
#include <stdlib.h>

extern void uzastopni(int *a, int *b, int* c, unsigned n);
extern void minus1(int *a, int *b, int* c, unsigned n);

int main(){
    unsigned n;
    scanf("%u", &n);
    int *a = (int*)malloc(n*sizeof(int));
    int *b = (int*)malloc(n*sizeof(int));
    int *c = (int*)malloc(n*sizeof(int));
    int i;
    for(i = 0; i < n; i++) scanf("%d", &a[i]);
    for(i = 0; i < n; i++) scanf("%d", &b[i]);
    minus1(a, b, c, n);
    n--;
    for(i = 0; i < n; i++) printf("%d ", c[i]);
    free(a); free(b); free(c);
    return 0;
}
