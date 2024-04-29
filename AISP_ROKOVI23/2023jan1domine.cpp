#include <iostream>
#include <vector>

//Javilo mi se u snu Gl hf ljudi

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> h(n);
    vector<int> dp(n, 0);
    for(int i = 0; i < n; i++){
        cin >> h[i];
    }
    for(int i = 1; i < n; i++){
        int j = i-1;
        while(j >= 0 && (h[j] >= i - j)){
            dp[i]++;
            j--;
        }
        if(i != n-1 && dp[i] > 1)dp[n-1] += dp[i];
    }
    cout << dp[n-1];
    return 0;
}
