#include <bits/stdc++.h>
using namespace std;

int main() {
    string str;
    cin >> str;
    int k = str[0] ^ 'C';
    for(int i = 0; i < (int) str.size(); ++i) {
        cout << (char) (str[i] ^ k);
    }
    return 0;
}
