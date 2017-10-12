#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);

    stack<int> stk;
    string s;
    while(cin >> s){
        if(s == "+"){
            int a = stk.top();
            stk.pop();
            int b = stk.top();
            stk.pop();
            stk.push(a + b);
        }
        else if(s == "-"){
            int a = stk.top();
            stk.pop();
            int b = stk.top();
            stk.pop();
            stk.push(b - a);
        }
        else if(s == "*"){
            int a = stk.top();
            stk.pop();
            int b = stk.top();
            stk.pop();
            stk.push(a * b);
        }
        else{
            stk.push(stoi(s));
        }
    }
    cout << stk.top() << endl;
    return 0;
}
