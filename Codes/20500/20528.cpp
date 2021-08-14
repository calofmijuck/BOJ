#include <bits/stdc++.h>
using namespace std;

int alpha[26];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    string str;
    for (int i = 0; i < n; ++i) {
        cin >> str;
        ++alpha[str[0] - 'a'];
    }
    int cnt = 0;
    for (int i = 0; i < 26; ++i) {
        if (alpha[i] > 0) {
            ++cnt;
        }
    }
    cout << ((cnt == 1) ? 1 : 0);
    return 0;
}
