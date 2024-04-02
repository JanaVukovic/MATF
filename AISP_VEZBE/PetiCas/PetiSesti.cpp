#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

int visina(Cvor* koren){
    if(koren == nullptr)
        return 0;
    return 1 + max(visina(koren->levo), visina(koren->desno));
}

int maxFaktor(Cvor* koren){
    if(koren == nullptr)
        return 0;
    int l = visina(koren->levo);
    int d = visina(koren->desno);
    int faktor = abs(l - d);
    int maxFaktorL = maxFaktor(koren->levo);
    int maxFaktorD = maxFaktor(koren->desno);
    return max({faktor, maxFaktorD, maxFaktorL});
}

void maxFaktoriVisina(Cvor* koren, int& visina, int& maxFaktor){
    if(koren == nullptr){
        visina = maxFaktor = 0;
        return;
    }
    int visinaL, maxFaktorL;
    maxFaktoriVisina(koren->levo, visinaL, maxFaktorL);
    int visinaD, maxFaktorD;
    maxFaktoriVisina(koren->desno, visinaD, maxFaktorD);
    int faktor = abs(visinaL - visinaD);
    maxFaktor = max({faktor, maxFaktorL, maxFaktorD});
    visina = 1 + max(visinaL, visinaD);

}


int main(){


    return 0;
}
