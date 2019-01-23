#include <bits/stdc++.h>
using namespace std;

int main() {
    int k, n, t, lim = 210;
    string s;
    cin >> k >> n;
    for(int i = 0; i < n; ++i) {
        cin >> t >> s;
        lim -= t;
        if(lim < 0) {
            cout << k;
            return 0;
        }
        if(s.at(0) == 'T') {
            k++;
            if(k == 9) k = 1;
        }
    }
    return 0;
}
