//Niz elemenata od n elemenata, svi brojevi su izmedu [0, n-1]
//5 5 0 2 1 2 2 niz
//0 1 2 2 5 5 2 sortirano
//Naci duplikate i elemente koji su ne ponavljaju

#include <iostream>
#include <vector>

using namespace std;

void sasaviSort(vector<int>& a, int n){
    int i = 0;
    while(i < n){
        if(a[i] == a[a[i]])
            i++;
        else
            swap(a[i], a[a[i]]);
    }
}

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    sasaviSort(a, n);

    for(int i = 0; i < n; i++){
        if(a[i] != i)cout << "Nedostaje " << i << endl << "Duplikat je " << a[i] << endl;

    }

}
