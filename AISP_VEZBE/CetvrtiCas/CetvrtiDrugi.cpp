#include <iostream>
#include <algorithm>
#include <vector>
#include <limits>

using namespace std;

int64_t rezultat(int k, int n, vector<int64_t>& figurice){
    int64_t minRazlika = numeric_limits<int64_t>::max();
    for(int i = 0; i + k - 1 < n; i++){
        minRazlika = min(minRazlika, k*(figurice[i+k-1]-figurice[i]));
    }
    return minRazlika;
}

bool test(int k, int n, vector<int64_t>& figurice, int64_t t){
    for(int i = 0; i + k - 1 < n; i++){
        if(k*(figurice[i+k-1]-figurice[i]) <= t)
            return true;
    }
    return false;
}

int main(){
    int n;
    cin >> n;
    vector<int64_t> jacine(n);
    for(int i = 0; i < n; i++)cin >> jacine[i];
    int64_t granica;
    cin >> granica;
    sort(jacine.begin(), jacine.end());

    int k = -1;
    int l = 1, d = n;
    while(l <= d){
        int s = (l+d)/2;
        if(!test(s, n, jacine, granica)){
            d = s-1;
        }else{
            k = s;
            l = s+1;
        }
    }
    cout << k << " " << rezultat(k, n, jacine) << '\n';
    return 0;
}
