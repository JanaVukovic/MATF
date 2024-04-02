#include<iostream>
#include<set>

using namespace std;

int main(){
    int s, n;
    cin >> s >> n;
    set<int> levo;
    int br = 0, x;
    while(n--){
        cin >> x;
        if(levo.find(s-x) != end(levo))
            br++;
        levo.insert(x);
    }
    cout << br << endl;
    return 0;
}
