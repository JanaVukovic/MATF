#include <stdio.h>
#include <stdlib.h>

extern int suma_negativnih(int * a, int n);
extern int suma(int* a, int na, int* b, int ba);

int main(){
    int na, nb;
    int i;
    scanf("%d", &na);
    int* a = (int*)malloc(na*sizeof(int));
    for(i = 0; i < na; i++) scanf("%d", &a[i]);
    scanf("%d", &nb);
    int* b = (int*)malloc(nb*sizeof(int));
    for(i = 0; i < nb; i++) scanf("%d", &b[i]);
    printf("%d\n", suma(a, na, b, nb));
    free(a);
    free(b);
    return 0;
}
