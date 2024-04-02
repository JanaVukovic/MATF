#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<double> krug(n);
    for(int i = 0; i < n; i++){
        cin >> krug[i];
        if(i > 0)
            krug[i] += krug[i-1];
    }
    int m;
    cin >> m;
    double x, y;
    double d;
    while(m--){
        cin >> x >> y;
        d = sqrt(x*x + y*y);
        auto it = lower_bound(krug.begin(), krug.end(), d);
        if(it == krug.end())
            cout << "izvan" << endl;
        else
            cout << it - krug.begin() << endl;
    }
    return 0;
}
