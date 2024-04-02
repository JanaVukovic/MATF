#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>

using namespace std;

string grej(unsigned n, unsigned k){
    if(n == 0)return "";
    if(k < pow(2, n-1)){
        return "0"+grej(n-1, k);
    }else{
        return "1"+ grej(n-1, pow(2, n)-1-k);
    }
}

int main(){
    int n, k;
    cin >> n >> k;
    int64_t t = pow(2, n);
    vector<int> a;
    while(t > 1){
        if(k >= t/2){
            a.push_back(1);
            k = t - 1 - k;
        }
        else
            a.push_back(0);
        t /= 2;
    }
    for(int i = 0; i < n; i++){
        cout << a[i];
    }
    return 0;
}
