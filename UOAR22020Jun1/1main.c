#include <stdio.h>
extern unsigned obrni(unsigned n);
int main(){
    unsigned n;
    scanf("%u", &n);
    printf("%u\n", obrni(n));
    return 0;
}
