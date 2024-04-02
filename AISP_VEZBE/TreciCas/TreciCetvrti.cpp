//niz int-ova, koliko postoji brojeva koji se pojavljuju paran broj puta

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    int brojac = 0;
    int tr = 1;
    for(int i = 1; i < n; i++){
        if(a[i] == a[i-1])
            tr++;
        else{
            if(tr%2 == 0) brojac++;
            tr = 1;
        }
    }
    if(tr%2 == 0)brojac++;
    cout << brojac << endl;
}
