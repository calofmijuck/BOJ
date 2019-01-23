#include <bits/stdc++.h>
using namespace std;

int main() {
    string str;
    cin >> str;
    int res = 0, exp = 1;
    if(str.at(0) == '0') {
        int k = str.size() - 1;
        if(str.at(1) == 'x') {
            for(; k >= 2; --k, exp *= 16) {
                char c = str.at(k);
                if('a' <= c && c <= 'f') res += ((c & 15) + 9) * exp;
                else res += (c & 15) * exp;
            }
        } else {
            for(; k >= 1; --k, exp *= 8) res += (str.at(k) & 15) * exp;
        }
        cout << res;
    } else cout << str;
    return 0;
}
