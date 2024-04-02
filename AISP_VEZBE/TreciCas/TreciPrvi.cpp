//sortiranje takmicara

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct takmicar{
    int poeni;
    string ime;
};

bool poredi(takmicar a, takmicar b){
    if(a.poeni > b.poeni) return true;
    else if(a.poeni < b.poeni)return false;
    return a.ime < b.ime;
}

int main(){
    int n;
    cin >> n;
    vector<takmicar> niz(n);
    for(int i = 0; i < n; i++){
        cin >> niz[i].ime;
        cin >> niz[i].poeni;
    }
    sort(niz.begin(), niz.end(), poredi);

    for(int i = 0; i < n; i++){
        cout << niz[i].ime << " ";
        cout << niz[i].poeni << endl;
    }
    return 0;
}
