#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];
    sort(a.begin(), a.end());
    auto it = unique(a.begin(), a.end());
    a.erase(it, a.end());
    n = a.size();

    int l = 1;
    int maks = 1;
    int indeks_maks = 0;
    int indeks = 0;
    for(int i = 1; i < n; i++){
        if(a[i] == (a[i-1]+1)){
            l++;
            if(l > maks){
                maks = l;
                indeks_maks = indeks;
            }
        }else{
            l = 1;
            indeks = i;
        }
    }
    for(int i = indeks_maks; i < (indeks_maks+maks); i++){
        cout << a[i] << endl;
    }
    return 0;
}
