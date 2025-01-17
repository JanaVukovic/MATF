#include <iostream>
#include <vector>

using namespace std;

int main(){
    int N;
    cin >> N;

    vector<vector<int>> mat(N, vector<int>(N));
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++)
            cin >> mat[i][j];
    }

    vector<vector<int>> maxZbir(N+1, vector<int>(N+1, 0));

    for(int n = 1; n <= N; n++){
        for(int m = 1; m <= N; m++){
            maxZbir[n][m] = max(maxzbir[n-1][m], maxZbir[n][m-1]);
            + mat[n-1][m-1];
        }
    }
    cout << maxZbir[N][N] << '\n';
    return 0;
}
