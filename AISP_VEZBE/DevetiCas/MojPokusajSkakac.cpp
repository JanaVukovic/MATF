#include <iostream>
#include <vector>

/*Kaze mi Petlja da ne radi Ne vidim zasto Ali ovo je
sigurno dobra ideja*/

using namespace std;

int n, m;

void solve(vector<vector<int>> &v, int indeks, int pos){
    int x = pos/m, y = pos%m;
    if(v[x][y] != 0)return;
    v[x][y] = indeks;
    indeks++;
    if(indeks == m*n+1){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(v[i][j] / 10 == 0) cout << ' ';
                cout << v[i][j] << ' ';
            }
            cout << '\n';
        }
        cout << '\n';
        v[x][y] = 0;
        indeks--;
        return;
    }
    if(x+2 <= n-1){
        if(y+1 < m) solve(v, indeks, m*(x+2)+y+1);
        if(y-1 >= 0) solve(v, indeks, m*(x+2)+y-1);
    }
    if(x-2 >= 0){
        if(y+1 < m) solve(v, indeks, m*(x-2)+y+1);
        if(y-1 >= 0) solve(v, indeks, m*(x-2)+y-1);
    }
    if(x+1 <= n-1){
        if(y+2 < m) solve(v, indeks, m*(x+1)+y+2);
        if(y-2 >= 0) solve(v, indeks, m*(x+1)+y-2);
    }
    if(x-1 >= 0){
        if(y+2 < m) solve(v, indeks, m*(x-1)+y+2);
        if(y-2 >= 0) solve(v, indeks, m*(x-1)+y-2);
    }
    v[x][y] = 0;
    indeks--;
    return;
}

int main(){
    cin >> n >> m;
    vector<vector<int>> v(n, vector<int> (m, 0));
    solve(v, 1, 0);
    return 0;
}
