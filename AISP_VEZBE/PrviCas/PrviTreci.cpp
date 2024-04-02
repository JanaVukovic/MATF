//dvobojka
//?????????
//ppp????nnn

#include <iostream>
#include <vector>

using namespace std;

void dvobojka(vector<int> & a, int n){
    int l = 0, d = n-1;
    while(l <= d){
        if(a[l]%2 == 0)
            l++;
        else if(a[d] % 2 != 0)
            d--;
        else{
            swap(a[l++], a[d--]);
        }
    }
}

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];
    dvobojka(a, n);
    for(int i = 0; i < n; i++){
        cout << a[i] << " ";
    }
    cout << '\n';
}
