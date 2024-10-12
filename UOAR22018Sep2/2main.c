#include <stdio.h>
#include <stdlib.h>
#define MAX 30

extern unsigned prost(unsigned a);
extern unsigned transformisi_niz(int niz[], int n);

int main(){
    unsigned n;
    scanf("%u", &n);
    unsigned a[MAX];
    int i;
    for(i = 0; i < n; i++){
        scanf("%u", &a[i]);
    }
    n = transformisi_niz(a, n);
    for(i = 0; i < n; i++)printf("%u ", a[i]);
    exit(EXIT_SUCCESS);
}
