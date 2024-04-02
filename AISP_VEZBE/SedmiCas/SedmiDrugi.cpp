#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> a;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    set<int> brojevi;
    int br = 0;
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++)
            if(brojevi.find(-a[i]-a[j])!=end(brojevi))
                br++;
        brojevi.insert(a[i]);
    }
    cout << br << '\n';
    return 0;
}
