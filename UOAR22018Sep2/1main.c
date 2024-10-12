#include <stdio.h>
#include <stdlib.h>

extern unsigned stepen(unsigned n);

int main(){
    unsigned n;
    scanf("%u", &n);
    printf("%u\n", stepen(n));
    exit(EXIT_SUCCESS);
}
