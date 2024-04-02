#include <iostream>
#include <vector>

using namespace std;

/*
vector<vector<int>> memo;

int brParticija(int n, int maxSabirak){
    if(memo[n][maxSabirak] != -1)
        return memo[n][maxSabirak];

    if(n == 0)
        return memo[n][maxSabirak] = 1;

    int br = 0;
    if(maxSabirak > 1)
        br += brParticija(n, maxSabirak-1);
    if(maxSabirak <= n)
        br+= brParticija(n-maxSabirak, maxSabirak);

    return memo[n][maxSabirak] = br;
}
*/

int main(){
    int n;
    cin >> n;

    vector<vector<int>> dp =
    vector<vector<int>>(n+1, vector<int>(n+1, 0));

    dp[0] = vector<int>(n+1, 1);
    for(int i = 1; i <= n; i++){
        for(int maxSabirak = 1; maxSabirak <= n; maxSabirak++){
            int br = 0;
            if(maxSabirak > 1)
                dp[i][maxSabirak] += dp[i][maxSabirak-1];
            if(maxSabirak <= n)
                dp[i][maxSabirak] += dp[i-maxSabirak][maxSabirak];
            dp[i][maxSabirak] = br;
        }
    }
    cout << dp[n][n] << '\n';
    return 0;
}
