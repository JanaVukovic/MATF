//Ispisuje broj n zapisan binarno
#include <iostream>

using namespace std;

int main(){
    unsigned n;
    cin >> n;
    string s = "";
    while(n > 0){
        s = to_string(n%2) + s;
        n /= 2;
    }
    cout << s;
}
