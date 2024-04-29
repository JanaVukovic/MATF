#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main(){
    int n, x;
    cin >> n;
    vector<int> priv(n);
    vector<int> a(n);
    vector<int> b(n);

    for(int i = 0; i < n; i++){
        cin >> priv[i];
        a[i] = priv[i];
    }
    sort(begin(priv), end(priv));

    for(int i = 0; i < n; i++){
        a[i] = find(priv.begin(), priv.end(), a[i]) - priv.begin();
        cin >> x;
        b[i] = find(priv.begin(), priv.end(), x)- priv.begin();
    }

    vector<int> c(n);
    vector<int> d(c);
    for(int i = 0; i < n; i++){
        c[a[i]] = i;
        d[b[i]] = i;
    }
    map<int, int> pre;
    for(int i = 0; i < n; i++){
        pre[c[i]] = d[i];
    }

    for(int i = 0; i < n; i++){
        cin >> a[i];
        priv[i] = a[i];
    }
    sort(priv.begin(), priv.end());
    for(int i = 0; i < n; i++){
        a[i] = find(priv.begin(), priv.end(), a[i]) - priv.begin();
        c[a[i]] = i;
    }
    for(int i = 0; i < n; i++){
        b[i] = pre[c[i]];
        b[i] = priv[b[i]];
    }
    for(int i = 0; i < n; i++)
        cout << b[i] << " ";
    return 0;
}
/*
5
4 3 1 0 2
1 3 2 4 0
3 2 0 4 1
*/

/*
4
1 2 5 7
5 2 1 7
3 4 1 5
*/
