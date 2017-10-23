#include <iostream>
#include <string>

using namespace std;

int main(){
    string S, T;
    cin >> S >> T;

    if(S.size() >= T.size()){
        for(int i=0; i<=S.size() - T.size(); i++){
            if(T == S.substr(i, T.size())){
                printf("%d\n", i);
            }
        }
    }
    return 0;
}
