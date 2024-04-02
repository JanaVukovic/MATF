#include <iostream>
#include <string>

using namespace std;

string post(string pre, string in){
    if(pre == "")
        return "";

    char koren = pre[0];
    int indeks = in.find(koren);

    string preLevo = pre.substr(1, indeks);
    string inLevo = in.substr(0, indeks);

    string preDesno = pre.substr(indeks+1);
    string inDesno = in.substr(1 + indeks);

    return post(preLevo, inLevo) + post(preDesno, inDesno) + koren;
}

int main(){
    string p, i;
    cin >> p >> i;
    cout << post(p, i);
    return 0;
}
