#include <iostream>
#include <map>
#include <string>

using namespace std;

int main(){
    int n;
    cin >> n;
    map<string, int> glas;
    string x;
    while(n--){
        cin >> x;
        if(glas.find(x) != glas.end()){
            glas.insert({x, 1});
        }else{
            glas[x]++;
        }
    }
    int maxGlasova = 0;
    string predsednik;
    for(auto p : m){
        if(p.second > maxGlasova){
            predsednik = p.first;
            maxGlasova = p.second;
        }
    }
    cout << predsednik << '\n';
    return 0;
}
