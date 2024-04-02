#include <iostream>
#include <map>

using namespace std;

int main(){
    int z, n, x;
    cin >> z >> n;
    map<int, int> brPr;
    brPr[0] = 1;
    int suma = 0, brSeg = 0;
    while(n--){
        cin >> x;
        suma += x;
        brSeg += brPr[suma-z];
        brPr[suma]++;
    }
    cout << brSeg << '\n';
    return 0;
}
