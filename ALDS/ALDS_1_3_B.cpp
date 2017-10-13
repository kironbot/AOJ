#include <iostream>
#include <queue>
#include <string>
#include <cstdlib>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    const int MAX = 100000;
    int n, q, time=0;
    cin >> n >> q;
    pair<string, int> S[MAX], A[MAX];
    queue<int> q_num;
    queue<string> q_str;

    for(int i=0; i<n; i++){
            cin >> S[i].first >> S[i].second;
            q_str.push(S[i].first);
            q_num.push(S[i].second);
    }

    while(! q_str.empty()){
        int a = q_num.front();
        string s = q_str.front();
        q_num.pop();
        q_str.pop();
        if(a <= q){
            time = time + a;
            cout << s << " " << time << endl;
        }
        else{
            time = time + q;
            q_num.push(a - q);
            q_str.push(s);
        }
    }
   return 0;
}
