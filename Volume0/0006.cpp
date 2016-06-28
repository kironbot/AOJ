#include <iostream>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    string s;
    cin >> s;
    reverse(s.begin(), s.end());
    cout << s;
    return 0;
}
