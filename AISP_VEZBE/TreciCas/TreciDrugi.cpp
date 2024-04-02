//glasanje

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<string> a(n);
    for(int i = 0 ; i < n ; i++){
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    int duzina = 1;
    int maks = 1;
    for(int i = 1; i < n; i++){
        if(a[i] != a[i-1]){
            duzina = 1;
        }else{
            duzina++;
            if(duzina > maks){
                maks = duzina;
            }
        }
    }
    cout << maks << endl;
}
