#include <iostream>
#include <string>

void solve(string &s, int k, int indeks, int preostaloJed){
    int brJed = 0, brTac = 0, indeks1 = -1;
    for(int i = indeks; (i-indeks) < k && i < s.size(); i++){
        if(s[i] == '.')
            brTac++;
        else if(s[i] == '1'){
            brJed++;
            indeks1 = i;
        }
    }
    if(brTac == 0 && brJed == 0)return;
    if(brTac == 0) solve(s, k, indeks1);
    if(brJed == 0 && brTac == 1){
        s[indeks1] = '1';
        solve(s, k, indeks1);
    }else{
        for(int i = indeks; (i - indeks) < k && i < s.size(); i++){
            if(s[i] == '.'){
                s[i] = '1';
                solve(s, k, i);
                s[i] = '2';
                solve(s, k, i);
                solve()
            }
        }


    }
}

using namespace std;

int main(){
    int k;
    cin >> k;
    k++;
    string s;
    cin >> s;
    solve(s, k, 0);
    return 0;
}
