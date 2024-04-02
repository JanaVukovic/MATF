//Za n sve faktorijele od 1 do n

#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    uint64_t S = 1;
    for(int i = 1; i <= n; i++){
        cout << S << endl;
        S *= (i+1);
    }
}
