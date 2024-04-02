#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){
    string a, b;
    cin >> a;
    b = a;

    int N = a.size();

    for(int i = 0; i < N; i++){
        b[i] = a[N-1-i];
    }

    vector<vector<int>> dp(N+1, vector<int>(N+1, 0));
    for(int n = 1; n <= N; n++){
        for(int m = 1; m <= N; m++){
            if(a[n-1] != b[m-1])
                dp[n][m] = max(dp[n-1][m], dp[n][m-1]);
            else
                dp[n][m] = 1+ dp[n-1][m-1];
        }
    }
    cout << dp[N][N] << '\n';
    return 0;
}

