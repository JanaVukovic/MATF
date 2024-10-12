#include <stdio.h>
#include <stdlib.h>

extern long faktorijel(long n);

int main(){
    long n;
    scanf("%li", &n);
    printf("%li\n", faktorijel(n));
    exit(EXIT_SUCCESS);
}
