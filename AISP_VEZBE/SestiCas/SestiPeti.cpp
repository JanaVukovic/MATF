#include <iostream>
#include <functional>
#include <queue>
#include <vector>

using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    int i, a;
    priority_queue<int, vector<int>, greater<int>> kju;
    for(int i = 0; i < k ;i++){
        cin >> a;
        kju.push(a);
    }
    int b;
    for(;i < n; i++){
        cin >> a;
        if(a > kju.top()){
            kju.pop();
            kju.push(a);
        }
    }
    int suma;
    while(!kju.empty()){
        suma+= kju.top();
        kju.pop();
    }
    cout << suma << endl;
    return 0;
}
