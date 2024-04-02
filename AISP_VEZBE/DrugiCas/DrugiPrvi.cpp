//[a, b] deljivi sa k
#include <iostream>

using namespace std;

int main(){
    int a, b;
    cin >> a >> b;
    int k;
    cin >> k;
    b = b/k +1;
    if(a != 0)a = (a-1)/k +1;
    cout << (b-a) << endl;
}
