#include <iostream>
#include <vector>

using namespace std;

void particije(int n, int maxSabirak, vector<int>& particija){
    if(n == 0){
        for(int x : particija)
            cout << x << '\n';
        cout << '\n';
        return;
    }
    if(maxSabirak > 1)
        particije(n, maxSabirak - 1, particija);
    if(maxSabirak <= n){
        particija.push_back(maxSabirak);
        particije(n-maxSabirak, maxSabirak, particija);
        particija.pop_back();
    }
}

int main(){
    int n;
    cin >> n;

    vector<int> particija(n);
    particije(n, n, particija);
    return 0;
}
