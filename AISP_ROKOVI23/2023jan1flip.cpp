#include <iostream>
#include <vector>

using namespace std;

int main(){
    int64_t n;
    cin >> n;
    vector<int> a(n);
    int k;
    cin >> k;
    for(int i = 0; i < n; i ++){
        cin >> a[i];
    }
    int l = 0, d;
    for(d = 0; d < n; d++){
        if(a[d] == 0)k--;
        if(k < 0 && a[l++] == 0)k++;
    }
    cout << d-l << endl;
    return 0;
}

//8 2 1 1 0 0 1 0 1 1
