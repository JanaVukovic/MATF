#include <stdio.h>
#include <stdlib.h>

extern int sve_jedinice(unsigned n);

int main(){
    unsigned n;
    scanf("%u", &n);
    printf("%d\n", sve_jedinice(n));
    exit(EXIT_SUCCESS);
}
