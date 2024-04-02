#include <iostream>
#include <set>

using namespace std;

int main(){
    int n, m, x;
    cin >> n;
    multiset<int> a;
    while(n--){
        cin >> x;
        a.insert(x);
    }
    cin >> m;
    multiset<int> b;
    while(m--){
        cin >> x;
        b.insert(x);
    }
    cout << (a == b ? "da" : "ne") << '\n';
    return 0;
}
