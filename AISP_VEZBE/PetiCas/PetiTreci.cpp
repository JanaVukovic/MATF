#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> poznaje(n);
    vector<int> poznaju(n);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            int priv;
            cin >> priv;
            poznaje[i] += priv;
            poznaju[j] += priv;
        }
    }
    for(int i = 0; i < n; i++){
        if(poznaje[i] == 1 && poznaju[i] == n){
            cout << i << '\n';
            return 0;
        }
    }
    return 0;
}
