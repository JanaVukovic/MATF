#include <iostream>
#include <vector>
#include <limits>
#include <iomanip>
#include <cmath>

using namespace std;

double podele(vector<double> &v, vector<bool> & podela){
    if(podela.size() == v.size()){
        double zbir1 = 0, zbir2 = 0;
        for(int i = 0; i < v.size(); i++){
            if(podela[i])
                zbir+=v[i];
            else zbir2 += v[i];
        }
        return abs(zbir1 - zbir2);
    }
    podela.push_back(0);
    double resLevo = podele(v, podela);
    podela.pop_back();

    podela.push_back(1);
    double resD = podele(v, podela);
    podela.pop_back();

    return min(resLevo, resD);
}
int main(){
    int n;
    cin >> n;

    vector<double> v(n);
    for(int i = 0; i < n; i++)
        cin >> v[i];
    vector<bool> podela;
    cout << fixed << setprecision(2) << podele(v, podela); << '\n';
    return 0;
}
