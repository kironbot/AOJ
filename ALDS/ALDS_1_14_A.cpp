#include <iostream>
#include <string>

using namespace std;

int main(){
    string S, T;
    cin >> S >> T;

    if(S.size() >= T.size()){
        for(int i=0; i<=S.size() - T.size(); i++){
            // Sの部分文字列のうち，i番目からTの長さだけ取り出して比較
            if(T == S.substr(i, T.size())){
                cout << i << endl;
            }
        }
    }
    return 0;
}
