#include <iostream>
#include <string>
#include <vector>

using namespace std;

void solve(vector<char> &s, int k, int index){
    if(k < 0)return;
    if(index == s.size() && k == 0){
        for(int i = 0 ; i < s.size(); i++)
            cout << s[i];
        cout << endl;
        return;
    }else if(k != 0 && index == s.size())return;

    if(s[index] == '1'){
        solve(s, k-1, index+1);
    }else if(s[index] != '.'){
        solve(s, k, index+1);
    }else{
        s[index] = '1';
        solve(s, k-1, index+1);
        s[index] = '2';
        solve(s, k, index+1);
        s[index] = '3';
        solve(s, k, index+1);
        s[index] = '.';
    }
    return;
}

int main(){
    int k;
    string v;
    cin >> k >> v;
    vector<char> s;
    for(int i = 0; i < v.size(); i++)
        s.push_back(v[i]);
    solve(s, k, 0);
    return 0;
}
