#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    int s;
    int n;
    cin >> s;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];
    sort(a.begin(), a.end());
    int l = 0, d = n-1;
    int broj_parova = 0;
    while(l < d){
        int suma = a[l] + a[d];
        if(suma == s){
            broj_parova++;
            l++;
            d--;
        }else if(suma < s){
            l++;
        }else{
            d--;
        }
    }
    cout << broj_parova << '\n';
    return 0;
}
