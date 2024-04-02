// 1
// 2 3 4
// 5 6 7 8 9
// 10 11 12 13 14 15 16
//Ispisuje sumu k-tog reda ovakvog trougla
#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    int m = n-1;
    n*=n;
    m*=m;
    int suma = n*(n+1)/2 - (m+1)*m/2;
    cout << suma;
}
