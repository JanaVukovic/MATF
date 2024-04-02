//3 1 5 3 2
//Minimalan broj pomeranja ulevo tako da je zbir 0*a0 + a1 + 2a2 + 3a3 maksimalan

#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    int64_t suma = 0;
    int64_t faktor = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        suma+=i*a[i];
        faktor += a[i];
    }
    faktor *= -1;
    int64_t maks = suma;
    int h = 0;
    for(int i = 1; i < n; i++){
        suma = suma + faktor + n*a[i-1];
        if(suma > maks){
            maks = suma;
            h = i;
        }
    }
    cout << h << endl;
}
