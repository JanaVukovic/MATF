#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main(){
    stack<char> opStek;
    stack<int> vrStek;
    string mojString;
    cin >> mojString;
    for(char c : mojString){
        if(c == 'm' || c == 'M'){
            opStek.push(c);
        }else if(c == ')'){
            int a = vrStek.top();
            vrStek.pop();
            int b = vrStek.top();
            vrStek.pop();
            int c;
            if(opStek.top() == 'm'){
                c = min(a, b);
            }else{
                c = max(a, b);
            }
            vrStek.push(c);
            opStek.pop();
        }else if(isdigit(c)){
            vrStek.push(c-'0');
        }
    }
    cout << vrStek.top();
    return 0;
}
