#include <iostream>
#include <cmath>
#include <set>


using namespace std;

set<int> s;

void dodaj(int x){
    s.insert(x);
}

void obrisi(int x){
    s.erase(x);
}

int najblizi(int x){
    auto it = s.lower_bound(x);
    if(it == end(s))
        return *(--it);
    if(it == begin(s))
        return *it;

    int a = *it;
    int b = *(--it);
    if(abs(a-x) < abs(b-x))
        return a;
    return b;
}

int main(){
    int n;
    cin >> n;
    while(n--){
        string op;
        cin >> op;
        int x;
        cin >> x;
        if(op == "dodaj")
            dodaj(x);
        else if(op == "obrisi")
            obrisi(x);
        else
            cout << "Najblizi je " << najblizi(x) << endl;
    }
    return 0;
}
