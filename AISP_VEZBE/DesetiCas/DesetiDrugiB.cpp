#include <iostream>
#include <string>

using namespace std;


int main(){
    string s;
    cin >> s;

    int N = s.size();
    vector<uint64_t> dp(N+1);
    dp[0] = dp[1] = 1;
    for(int n = 2; n <= N; n++){
        int b1 = s[n-1] - '0';
        int b2 = (s[n-2] - '0')*10 + b1;

        if(b1 != 0)
            dp[n] += dp[n-1];
        if(b2 >= 10 && b2 <= 26)
            dp[n] += dp[n-2];
    }
    cout << dp[N] << '\n';
    return 0;
}
