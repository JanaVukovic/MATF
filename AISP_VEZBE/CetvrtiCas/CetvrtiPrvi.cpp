#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool ispitajRastojanje(int x, int m, vector<int>& lokacije, int n){
    m--;
    int poslednjaLokacija = lokacije[0];
    for(int i = 1; i < n && m > 0; i++){
        if(lokacije[i] - poslednjaLokacija >= x){
            m--;
            poslednjaLokacija = lokacije[i];
        }
    }
    return m == 0;
}

int main(){
    int m, n;
    cin >> m >> n;

    vector<int> a(n);
    for(int i = 0; i < n ; i++) cin >> a[i];
    sort(a.begin(), a.end());
    int l = 1;
    int d = a[m-1];
    int resenje = -1;
    while(l <= d){
        int s = (l+d)/2;
        if(ispitajRastojanje(s, m, a, n)){
            l = s+1;
            resenje = s;
        }else{
            d = s-1;
        }
    }

    cout << resenje << '\n';
    return 0;
}
