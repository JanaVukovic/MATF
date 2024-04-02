#include <iostream>
#include <set>

using namespace std;

int main(){
    int n, x;
    cin >> n;
    set<int> brojevi;
    int najveci = 0;
    while(n--0){
        cin >> x;
        if(x > najveci && brojevi.find(x)
           != end(brojevi))
           najveci = x;

        brojevi.insert(x);
    }
    if(najveci > 0)
        cout << najveci << '\n';
    else
        cout << "nema\n";
    return 0;
}
