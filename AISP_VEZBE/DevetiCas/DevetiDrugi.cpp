#include <iostream>
#include <vector>
#include <limits>
#include <iomanip>
#include <cmath>

using namespace std;

bool sledecaPodela(vector<bool>& podela){
    int i = podela.size() - 1;
    while(i >= 0 && podela[i] == 1)
        podela[i--] = 0;
    if(i < 0)
        return false;
    podela[i] = 1;
    return true;
}

double svePodele(vector<double>& v){
    vector<bool> podela(v.size());
    double res = numeric_limits<double>::max();
    do{
        double zbir1 = 0, zbir2 = 0;
        for(int i = 0; i < v.size(); i++){
            if(podela[i])
                zbir1+= v[i];
            else
                zbir2+=v[i];
        }
        res = min(res, abs(zbir1 - zbir2));
    }while(sledecaPodela(podela));
    return res;
}

int main(){
    int n;
    cin >> n;

    vector<double> v(n);
    for(int i = 0; i < n; i++)
        cin >> v[i];
    cout << fixed << setprecision(2) << svePodele(v) << '\n';
    return 0;
}
