#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    int64_t s;
    int n;
    cin >> s >> n;
    vector<int64_t> a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];
    sort(a.begin(), a.end());
    auto it = unique(a.begin(), a.end());
    a.erase(it, a.end());
    n = a.size();
    int64_t med = (s%2 == 0)? s/2 : (s-1)/2;
    int brojac = 0;
    int pocetak = 0;
    while(a[pocetak] < med)pocetak++;

    for(int i = 0; i < pocetak; i++){
        if(binary_search(a.begin()+pocetak, a.end(), (s-a[i]))){
            brojac++;
        }

    }
    cout << brojac << endl;
    return 0;
}
