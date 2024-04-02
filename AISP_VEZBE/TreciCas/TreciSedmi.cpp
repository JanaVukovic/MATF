#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
        b[i] = a[i];
    }
    sort(b.begin(), b.end());
    for(int i = 0 ; i < n ; i++){
        auto it = lower_bound(b.begin(), b.end(), a[i]);
        cout << it - b.begin() << endl;
    }
    return 0;
}
