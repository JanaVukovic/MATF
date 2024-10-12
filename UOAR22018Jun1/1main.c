#include <stdio.h>
#include <stdlib.h>

extern int bits(unsigned long n);

int main(){
    printf("Broj: ");
    unsigned long n;
    scanf("%lu", &n);
    if(bits(n) == 0){
        printf("Broj jedinica u binarnom zapisu broja je paran!");
    }
    else printf("Broj jedinica u binarnom zapisu broja nije paran!");
    exit(EXIT_SUCCESS);
}
