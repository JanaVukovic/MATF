#include <iostream>
#include <map>

using namespace std;

map<int, int> m;
int uvecanje = 0;

int vrednost(int x){
    return m[x] + uvecanje;
}

void dodaj(int x, int y){
    m[x] = y - uvecanje;
}

void uvecaj(int x, int y){
    m[x] += y;
}

void obrisi(int x){
    m.erase(x);
}

int uvecajSve(int y){
    uvecanje += y;
}

int main(){
    int n;
    cin >> n;
    string op;
    int x, y;
    while(n--){
        cin >> op;
        if(op == "vrednost"){
            cin >> x;
            cout << vrednost(x) << endl;
        }
        else if(op == "uvecajSve"){
            cin >> y;
            uvecajSve(y);
        }else if(op == "obrisi"){
            cin >> x;
            obrisi(x);
        }else if(op == uvecaj){
            cin >> x >> y;
            uvecaj(x, y);
        }
    }
    return 0;
}
