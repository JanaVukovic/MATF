#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 1000000

using namespace std;

int main(){
    int64_t n, x;
    cin >> n;
    vector<int64_t> c(MAX, 0);
    for(int64_t i = 0; i < n; i++){
        cin >> x;
        c[x-1]++;
    }
    for(int64_t i = 1; i < MAX; i++){
        c[i] = c[i]+c[i-1];
    }
    int k;
    cin >> k;
    int a, b;
    for(int64_t i = 0; i < k; i++){
        cin >> a >> b;
        int rez;
        if(a != 0 && b != 0) rez = c[b-1] - c[a-1]+1;
        else if(a == 0 && b == 0) rez = 0;
        else rez = c[b-1];
        cout << rez << endl;
    }
    return 0;
}

//7 1 3 1 3 2 4 1 1 2 4
//1 1 1 2 3 3 4
//3 1 2 1
//3 4 6 7
