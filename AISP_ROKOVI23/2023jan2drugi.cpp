#include <iostream>

using namespace std;

int main(){
    int t, n;
    cin >> t >> n;
    int a, b, c;
    vector<int> k(n+1, 0);
    for(int i = 0; i < n; i++){
        cin >> a >> b >> c;
        if(b+1 > k.size())
            k.resize(b+1);
        k[a] += c;
        k[b+1] -= c;
    }
    for(int i = 1; i < k.size(); i++){
        k[i] = k[i] + k[i-1];
    }
    int rez = -1;
    for(int i = k.size()-2; i >= 0; i++){
        k[i] = k[i] + k[i+1];
        if(k[i] <= t){
            rez = i;
        }
    }
    cout << rez;
    return 0;
}

/*6 3
0 2 1
1 3 2
1 4 1

2  4

13_12__8__4__1__
    4  4  3  1
    3  3  2
    2  2  1
 1  1  1
 0  1  2  3  4
*/
