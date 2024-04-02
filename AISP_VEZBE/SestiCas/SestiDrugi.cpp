#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> a;
    for(int i = 0; i < n; i++){
        int priv;
        cin >> priv;
        a.push_back(priv);
    }
    deque<int> sredjeno;
    sredjeno.push_front(a[0]);
    for(int i = 1; i < n; i++){
        if(a[i-1] < a[i])
            sredjeno.push_back(a[i]);
        else
            sredjeno.push_front(a[i]);
    }
    for(int i = 0 ; i < n; i++){
        cout << sredjeno.front() << " ";
        sredjeno.pop_front();
    }
    return 0;
}
