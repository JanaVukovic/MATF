#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main(){
    int k, vr;
    cin >> k;
    int64_t n;
    cin >> n;
    vector<int> vrStek;
    vector<int> brStek;
    while(n--){
        cin >> vr;
        if(!vrStek.empty() && vrStek.back() != vr && brStek.back() >= k){
            vrStek.pop_back();
            brStek.pop_back();
        }
        if(!vrStek.empty() && vrStek.back() == vr){
            brStek.back()++;
        }else{
            vrStek.push_back(vr);
            brStek.push_back(1);
        }
    }
    if(!vrStek.empty() && brStek.back() >= k){
        brStek.pop_back();
        vrStek.pop_back();
    }
    for(int i = 0; i < vrStek.size(); i++){
        while(brStek[i]--)
            cout << vrStek[i] << ' ';
    }
    cout << endl;
    return 0;
}
