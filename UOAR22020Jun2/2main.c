#include <stdio.h>
#include <stdlib.h>

extern int prost(unsigned n);
extern int izbaci_proste(unsigned* a, unsigned n);

int main(){
    unsigned n;
    scanf("%u", &n);
    unsigned *a = (unsigned*)malloc(n*sizeof(unsigned));
    int i;
    for(i = 0; i < n; i++){
        scanf("%u", &a[i]);
        //if(prost(a[i]) == 1) printf("Prost!\n");
    }
    n = izbaci_proste(a, n);
    for(i = 0; i < n; i++) printf("%u ", a[i]);
    free(a);
    return 0;

}
