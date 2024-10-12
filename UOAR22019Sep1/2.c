#include <stdio.h>
#include <stdlib.h>

extern int trougao(int a, int b, int c);
extern int stranice(int* a, int* b, int* c, int n);

int main(){
    int n;
    scanf("%d", &n);
    int i;
    int* a = (int*)malloc(n*sizeof(int));
    int* b = (int*)malloc(n*sizeof(int));
    int* c = (int*)malloc(n*sizeof(int));

    for(i = 0; i < n; i++) scanf("%d", &a[i]);
    for(i = 0; i < n; i++) scanf("%d", &b[i]);
    for(i = 0; i < n; i++) scanf("%d", &c[i]);

    printf("%d\n", stranice(a, b, c, n));
    free(a); free(b); free(c);
    exit(EXIT_SUCCESS);
}
