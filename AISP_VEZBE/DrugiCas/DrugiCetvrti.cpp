//Ruter
#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    uint64_t l = 0;
    uint64_t d = 0;
    uint64_t minimum = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        minimum += i*a[i];
        d += a[i];
    }
    uint64_t trenutni = minimum;
    for(int i = 1; i < n; i++){
        l += a[i-1];
        d -= a[i-1];
        trenutni += l - d;
        if(trenutni < minimum){
            minimum = trenutni;
        }
    }
    cout << minimum << endl;
}
