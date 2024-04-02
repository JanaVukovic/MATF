//
#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> zarade(n+1);
    zarade[0] = 0;
    for(int i = 1; i <= n; i++){
        cin >> zarade[i];
        zarade[i] += zarade[i-1];
    }
    int q;
    cin >> q;
    int a, b;
    while(q--){
        cin >> a >> b;
        b++;
        cout << zarade[b] - zarade[a] << endl;
    }
    return 0;
}
