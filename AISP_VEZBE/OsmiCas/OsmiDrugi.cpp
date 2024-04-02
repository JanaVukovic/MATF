#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for(int i = 0; i < n; i++)
        cin >> v[i];
    int l = 0, d = n-1;
    while(l < d){
        int s = l;
        for(int i = l+1; i <= d; i++){
            if(v[i] >= v[l])
                swap(v[i], v[++s]);
        }
        swap(v[l], v[s]);
        if(s < k)
            l = s+1;
        else if(s > k)
            d = s-1;
        else
            break;
    }
    int sum = 0;
    for(int i = 0; i < k; i++)
        sum+=v[i];
    cout << sum << '\n';
    return 0;
}
