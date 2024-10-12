#include <stdio.h>
#include <stdlib.h>

extern int iste_cifre(unsigned n);

int main(){
    unsigned n;
    scanf("%u", &n);
    printf("%d", iste_cifre(n));
    exit(EXIT_SUCCESS);
}
