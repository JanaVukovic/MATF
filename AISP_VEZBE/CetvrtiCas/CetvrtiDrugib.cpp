#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int64_t> a(n);
    for(int i = 0; i < n; i++)cin >> a[i];
    int64_t granica;
    cin >> granica;
    sort(a.begin(), a.end());
    int j = 0;
    int maksimum  = 0;
    int64_t razlika = 0;
    for(int i = 0; i < n; i++){
        int k = i - j + 1;
        while(k*(a[i]-a[j]) > granica)
            j++;
        if(k > maksimum || (k == maksimum &&
            k*(a[i]-a[j]) < razlika)){
            maksimum = k;
            razlika = k*(a[i]-a[j]);
        }
    }

    cout << maksimum << ' ' << razlika << '\n';

    return 0;
}
